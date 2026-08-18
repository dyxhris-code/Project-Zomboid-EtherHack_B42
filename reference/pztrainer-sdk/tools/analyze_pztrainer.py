from __future__ import annotations

import argparse
import csv
import hashlib
import json
import math
import os
import re
import struct
from collections import Counter
from datetime import datetime, timezone
from pathlib import Path

import pefile


ASCII_RE = re.compile(rb"[\x20-\x7e]{4,}")
UTF16_RE = re.compile(rb"(?:[\x20-\x7e]\x00){4,}")
JNI_SIGNATURE_RE = re.compile(r"^(?:\(|\[|L).*[;VZBCSIJFD)]$")
JNI_CLASS_RE = re.compile(r"^(?:[a-zA-Z_$][\w$]*/)+[A-Za-z_$][\w$]*(?:\$[\w$]+)*$")
JNI_NAME_RE = re.compile(r"^[A-Za-z_$<>][A-Za-z0-9_$<>]{2,}$")


def sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(block)
    return digest.hexdigest().upper()


def entropy(data: bytes) -> float:
    if not data:
        return 0.0
    counts = Counter(data)
    length = len(data)
    return -sum((count / length) * math.log2(count / length) for count in counts.values())


def hex_value(value: int) -> str:
    return f"0x{value:X}"


def extract_strings(data: bytes) -> list[dict[str, object]]:
    rows: list[dict[str, object]] = []
    for encoding, pattern in (("ascii", ASCII_RE), ("utf-16le", UTF16_RE)):
        for match in pattern.finditer(data):
            rows.append(
                {
                    "offset": match.start(),
                    "encoding": encoding,
                    "value": match.group().decode(encoding, errors="replace"),
                }
            )
    return sorted(rows, key=lambda row: (int(row["offset"]), str(row["encoding"])))


def parse_tls_callbacks(pe: pefile.PE) -> list[str]:
    if not hasattr(pe, "DIRECTORY_ENTRY_TLS"):
        return []
    address = pe.DIRECTORY_ENTRY_TLS.struct.AddressOfCallBacks
    if not address:
        return []
    offset = pe.get_offset_from_rva(address - pe.OPTIONAL_HEADER.ImageBase)
    width = 8 if pe.PE_TYPE == pefile.OPTIONAL_HEADER_MAGIC_PE_PLUS else 4
    fmt = "<Q" if width == 8 else "<I"
    callbacks: list[str] = []
    while offset + width <= len(pe.__data__):
        value = struct.unpack(fmt, pe.__data__[offset : offset + width])[0]
        if not value:
            break
        callbacks.append(hex_value(value))
        offset += width
    return callbacks


def build_summary(path: Path, pe: pefile.PE) -> dict[str, object]:
    machine_names = {0x14C: "x86", 0x8664: "x64", 0xAA64: "ARM64"}
    imports: dict[str, list[str]] = {}
    for entry in getattr(pe, "DIRECTORY_ENTRY_IMPORT", []):
        imports[entry.dll.decode("latin1")] = [
            item.name.decode("latin1") if item.name else f"ordinal:{item.ordinal}"
            for item in entry.imports
        ]

    exports = []
    if hasattr(pe, "DIRECTORY_ENTRY_EXPORT"):
        exports = [
            {
                "ordinal": item.ordinal,
                "rva": hex_value(item.address),
                "name": item.name.decode("latin1") if item.name else None,
            }
            for item in pe.DIRECTORY_ENTRY_EXPORT.symbols
        ]

    debug = []
    for item in getattr(pe, "DIRECTORY_ENTRY_DEBUG", []):
        row: dict[str, object] = {"type": item.struct.Type, "size": item.struct.SizeOfData}
        if item.struct.Type == 2:
            raw = pe.get_data(item.struct.AddressOfRawData, item.struct.SizeOfData)
            if raw.startswith(b"RSDS") and len(raw) > 24:
                row["pdb"] = raw[24:].split(b"\0", 1)[0].decode("latin1", errors="replace")
                row["pdb_age"] = struct.unpack("<I", raw[20:24])[0]
                row["pdb_guid_raw"] = raw[4:20].hex().upper()
        debug.append(row)

    sections = []
    for section in pe.sections:
        raw = section.get_data()
        sections.append(
            {
                "name": section.Name.rstrip(b"\0").decode("latin1"),
                "rva": hex_value(section.VirtualAddress),
                "virtual_size": section.Misc_VirtualSize,
                "raw_size": section.SizeOfRawData,
                "entropy": round(entropy(raw), 3),
                "characteristics": hex_value(section.Characteristics),
            }
        )

    last_section_byte = max(
        (section.PointerToRawData + section.SizeOfRawData for section in pe.sections), default=0
    )
    return {
        "path": str(path.resolve()),
        "size": path.stat().st_size,
        "sha256": sha256(path),
        "machine": machine_names.get(pe.FILE_HEADER.Machine, hex_value(pe.FILE_HEADER.Machine)),
        "compile_timestamp_utc": datetime.fromtimestamp(
            pe.FILE_HEADER.TimeDateStamp, tz=timezone.utc
        ).isoformat(),
        "image_base": hex_value(pe.OPTIONAL_HEADER.ImageBase),
        "entry_rva": hex_value(pe.OPTIONAL_HEADER.AddressOfEntryPoint),
        "entry_va": hex_value(pe.OPTIONAL_HEADER.ImageBase + pe.OPTIONAL_HEADER.AddressOfEntryPoint),
        "subsystem": pe.OPTIONAL_HEADER.Subsystem,
        "size_of_image": pe.OPTIONAL_HEADER.SizeOfImage,
        "characteristics": hex_value(pe.FILE_HEADER.Characteristics),
        "dll_characteristics": hex_value(pe.OPTIONAL_HEADER.DllCharacteristics),
        "sections": sections,
        "imports": imports,
        "exports": exports,
        "tls_callbacks": parse_tls_callbacks(pe),
        "debug": debug,
        "overlay_bytes": max(0, path.stat().st_size - last_section_byte),
    }


def classify_jni(value: str) -> str | None:
    if JNI_SIGNATURE_RE.match(value):
        return "signature"
    if JNI_CLASS_RE.match(value):
        return "class"
    if JNI_NAME_RE.match(value) and not value.startswith("ImGui"):
        return "member-candidate"
    return None


def write_tsv(path: Path, fieldnames: list[str], rows: list[dict[str, object]]) -> None:
    with path.open("w", encoding="utf-8", newline="") as stream:
        writer = csv.DictWriter(
            stream,
            delimiter="\t",
            fieldnames=fieldnames,
            extrasaction="ignore",
        )
        writer.writeheader()
        writer.writerows(rows)


def main() -> int:
    parser = argparse.ArgumentParser(description="Statically inspect pztrainer.dll without loading it")
    parser.add_argument("binary", type=Path)
    parser.add_argument("output", type=Path)
    args = parser.parse_args()

    args.output.mkdir(parents=True, exist_ok=True)
    data = args.binary.read_bytes()
    pe = pefile.PE(data=data, fast_load=False)
    summary = build_summary(args.binary, pe)
    (args.output / "pe-summary.json").write_text(
        json.dumps(summary, indent=2, ensure_ascii=False) + "\n", encoding="utf-8"
    )

    strings = extract_strings(data)
    for row in strings:
        row["offset_hex"] = hex_value(int(row["offset"]))
        try:
            row["va"] = hex_value(pe.OPTIONAL_HEADER.ImageBase + pe.get_rva_from_offset(int(row["offset"])))
        except pefile.PEFormatError:
            row["va"] = ""
    write_tsv(args.output / "strings.tsv", ["offset_hex", "va", "encoding", "value"], strings)

    jni_rows = []
    for row in strings:
        kind = classify_jni(str(row["value"]))
        if kind:
            jni_rows.append(
                {
                    "offset_hex": row["offset_hex"],
                    "va": row["va"],
                    "kind": kind,
                    "value": row["value"],
                }
            )
    write_tsv(
        args.output / "jni-candidates.tsv",
        ["offset_hex", "va", "kind", "value"],
        jni_rows,
    )
    print(f"Wrote {len(strings)} strings and {len(jni_rows)} JNI candidates to {args.output}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

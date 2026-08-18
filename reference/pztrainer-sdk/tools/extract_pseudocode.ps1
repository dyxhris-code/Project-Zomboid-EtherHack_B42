param(
    [string]$Binary = "D:\Data\QQFile\pztrainer.dll",
    [string]$Radare2 = "D:\Develope\Tools\radare2-6.2.0\radare2-6.2.0-w64\bin\radare2.exe",
    [string]$Output = "$PSScriptRoot\..\analysis\pseudocode"
)

$ErrorActionPreference = "Stop"

if (-not (Test-Path -LiteralPath $Binary -PathType Leaf)) {
    throw "Missing binary: $Binary"
}
if (-not (Test-Path -LiteralPath $Radare2 -PathType Leaf)) {
    throw "Missing Radare2: $Radare2"
}

$targets = [ordered]@{
    "01-user-dllmain" = "0x180001780"
    "02-hook-worker" = "0x18003e740"
    "03-render-init" = "0x18003ade0"
    "04-jni-core-esp" = "0x180001df0"
    "05-jni-skills" = "0x180009f30"
    "06-jni-items-weapons" = "0x18000d220"
    "07-jni-character-stats" = "0x18001d190"
    "08-jni-player-damage" = "0x180021840"
    "09-jni-climate" = "0x180022ed0"
    "10-jni-ballistics" = "0x18002a7c0"
}

New-Item -ItemType Directory -Force -Path $Output | Out-Null

foreach ($target in $targets.GetEnumerator()) {
    $command = "e scr.color=false; aaa; af @ $($target.Value); pdc @ $($target.Value)"
    $destination = Join-Path $Output "$($target.Key)-$($target.Value.Substring(2)).c"
    $content = & $Radare2 -2 -q -c $command $Binary
    if ($LASTEXITCODE -ne 0) {
        throw "Radare2 failed for $($target.Key) at $($target.Value)"
    }
    if (-not $content) {
        throw "Radare2 returned no pseudocode for $($target.Key) at $($target.Value)"
    }
    $content | Set-Content -LiteralPath $destination -Encoding utf8
}

if ((Get-ChildItem -LiteralPath $Output -Filter "*.c").Count -ne $targets.Count) {
    throw "Pseudocode output count does not match target count"
}

Write-Output "Exported $($targets.Count) functions to $Output"

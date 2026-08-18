// Exports semantically named Ghidra decompilation with evidence-oriented indexes.
// @category PZTrainer

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Data;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.Listing;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceManager;
import ghidra.program.model.symbol.SourceType;
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.SymbolTable;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.LinkedHashSet;
import java.util.List;
import java.util.Set;

public class ExportReadableSdk extends GhidraScript {
    private record Target(String address, String name, String module, String confidence, String summary) {
    }

    private record DataTarget(String address, String name, String module, String confidence, String summary) {
    }

    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length != 3) {
            throw new IllegalArgumentException(
                    "Expected: <output-directory> <semantic-functions.tsv> <semantic-data.tsv>");
        }

        Path outputRoot = Paths.get(args[0]).toAbsolutePath().normalize();
        Path manifest = Paths.get(args[1]).toAbsolutePath().normalize();
        Path dataManifest = Paths.get(args[2]).toAbsolutePath().normalize();
        Files.createDirectories(outputRoot);

        List<Target> targets = loadTargets(manifest);
        List<DataTarget> dataTargets = loadDataTargets(dataManifest);
        FunctionManager functions = currentProgram.getFunctionManager();
        SymbolTable symbols = currentProgram.getSymbolTable();
        DecompInterface decompiler = new DecompInterface();
        decompiler.toggleCCode(true);
        decompiler.toggleSyntaxTree(true);
        if (!decompiler.openProgram(currentProgram)) {
            throw new IllegalStateException("Ghidra decompiler could not open " + currentProgram.getName());
        }

        for (Target target : targets) {
            monitor.checkCancelled();
            Function function = findFunction(functions, target);
            if (function == null) {
                printerr("No function found at " + target.address());
                continue;
            }
            function.setName(target.name(), SourceType.USER_DEFINED);
            function.setComment(target.summary());
        }

        for (DataTarget target : dataTargets) {
            monitor.checkCancelled();
            Address address = parseManifestAddress(target.address());
            Symbol symbol = symbols.createLabel(address, target.name(), SourceType.USER_DEFINED);
            symbol.setPrimary();
        }

        List<String> index = new ArrayList<>();
        index.add("# Ghidra semantic export");
        index.add("");
        index.add("Program: `" + currentProgram.getName() + "`");
        index.add("");
        index.add("| Address | Semantic name | Module | Confidence | Callers | Callees | Strings |");
        index.add("| --- | --- | --- | --- | ---: | ---: | ---: |");

        for (Target target : targets) {
            monitor.checkCancelled();
            Function function = findFunction(functions, target);
            if (function == null) {
                printerr("No function found at " + target.address());
                continue;
            }

            Set<Function> callers = function.getCallingFunctions(monitor);
            Set<Function> callees = function.getCalledFunctions(monitor);
            Set<String> strings = collectReferencedStrings(function);
            String c = decompile(decompiler, function);

            Path moduleDirectory = outputRoot.resolve(target.module());
            Files.createDirectories(moduleDirectory);
            String addressToken = target.address().replace("0x", "");
            Path cFile = moduleDirectory.resolve(target.name() + "-" + addressToken + ".c");
            Files.writeString(cFile, buildHeader(target, function, callers, callees, strings) + c,
                    StandardCharsets.UTF_8);

            index.add("| `" + target.address() + "` | `" + target.name() + "` | " + target.module()
                    + " | " + target.confidence() + " | " + callers.size() + " | " + callees.size()
                    + " | " + strings.size() + " |");
        }

        index.add("");
        index.add("Function names are curated in `metadata/semantic-functions.tsv`; generated C remains decompiler output and is not source code.");
        index.add("Data names are curated in `metadata/semantic-data.tsv` and are backed by initializer and use-site evidence.");
        Files.write(outputRoot.resolve("INDEX.md"), index, StandardCharsets.UTF_8);
        writeDataIndex(outputRoot, dataTargets);
        decompiler.dispose();
        println("Exported " + targets.size() + " semantic functions to " + outputRoot);
    }

    private List<Target> loadTargets(Path manifest) throws IOException {
        List<Target> targets = new ArrayList<>();
        List<String> lines = Files.readAllLines(manifest, StandardCharsets.UTF_8);
        for (int i = 1; i < lines.size(); i++) {
            String line = lines.get(i).strip();
            if (line.isEmpty() || line.startsWith("#")) {
                continue;
            }
            String[] fields = line.split("\\t", 5);
            if (fields.length != 5) {
                throw new IOException("Invalid semantic manifest row " + (i + 1) + ": " + line);
            }
            targets.add(new Target(fields[0], fields[1], fields[2], fields[3], fields[4]));
        }
        return targets;
    }

    private List<DataTarget> loadDataTargets(Path manifest) throws IOException {
        List<DataTarget> targets = new ArrayList<>();
        List<String> lines = Files.readAllLines(manifest, StandardCharsets.UTF_8);
        for (int i = 1; i < lines.size(); i++) {
            String line = lines.get(i).strip();
            if (line.isEmpty() || line.startsWith("#")) {
                continue;
            }
            String[] fields = line.split("\\t", 5);
            if (fields.length != 5) {
                throw new IOException("Invalid data manifest row " + (i + 1) + ": " + line);
            }
            targets.add(new DataTarget(fields[0], fields[1], fields[2], fields[3], fields[4]));
        }
        return targets;
    }

    private void writeDataIndex(Path outputRoot, List<DataTarget> targets) throws IOException {
        List<String> index = new ArrayList<>();
        index.add("# Semantic data symbols");
        index.add("");
        index.add("| Address | Name | Module | Confidence | Summary |");
        index.add("| --- | --- | --- | --- | --- |");
        for (DataTarget target : targets) {
            index.add("| `" + target.address() + "` | `" + target.name() + "` | " + target.module()
                    + " | " + target.confidence() + " | " + target.summary() + " |");
        }
        Files.write(outputRoot.resolve("DATA_SYMBOLS.md"), index, StandardCharsets.UTF_8);
    }

    private Address parseManifestAddress(String value) {
        String normalized = value.startsWith("0x") ? value.substring(2) : value;
        long offset = Long.parseUnsignedLong(normalized, 16);
        return currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(offset);
    }

    private Function findFunction(FunctionManager functions, Target target) {
        Address address = parseManifestAddress(target.address());
        Function function = functions.getFunctionAt(address);
        return function != null ? function : functions.getFunctionContaining(address);
    }

    private String decompile(DecompInterface decompiler, Function function) {
        DecompileResults results = decompiler.decompileFunction(function, 180, monitor);
        if (!results.decompileCompleted() || results.getDecompiledFunction() == null) {
            return "/* Decompilation failed: " + results.getErrorMessage() + " */\n";
        }
        return results.getDecompiledFunction().getC();
    }

    private Set<String> collectReferencedStrings(Function function) {
        Set<String> values = new LinkedHashSet<>();
        Listing listing = currentProgram.getListing();
        ReferenceManager references = currentProgram.getReferenceManager();
        Instruction instruction = listing.getInstructionAt(function.getEntryPoint());
        while (instruction != null && function.getBody().contains(instruction.getAddress())) {
            for (Reference reference : references.getReferencesFrom(instruction.getAddress())) {
                Data data = listing.getDataAt(reference.getToAddress());
                if (data != null && data.hasStringValue()) {
                    Object value = data.getValue();
                    if (value != null) {
                        values.add(value.toString().replace("\r", "\\r").replace("\n", "\\n"));
                    }
                }
            }
            instruction = instruction.getNext();
        }
        return values;
    }

    private String buildHeader(Target target, Function function, Set<Function> callers,
            Set<Function> callees, Set<String> strings) {
        StringBuilder out = new StringBuilder();
        out.append("/*\n");
        out.append(" * Semantic name: ").append(target.name()).append("\n");
        out.append(" * Address: ").append(target.address()).append("\n");
        out.append(" * Module: ").append(target.module()).append("\n");
        out.append(" * Confidence: ").append(target.confidence()).append("\n");
        out.append(" * Summary: ").append(target.summary()).append("\n");
        out.append(" * Ghidra function: ").append(function.getName()).append("\n");
        appendFunctions(out, "Callers", callers);
        appendFunctions(out, "Callees", callees);
        if (!strings.isEmpty()) {
            out.append(" * Referenced strings:\n");
            for (String value : strings) {
                out.append(" *   - ").append(value).append("\n");
            }
        }
        out.append(" */\n\n");
        return out.toString();
    }

    private void appendFunctions(StringBuilder out, String label, Set<Function> functions) {
        List<Function> sorted = functions.stream()
                .sorted(Comparator.comparing(Function::getEntryPoint))
                .toList();
        out.append(" * ").append(label).append(":");
        if (sorted.isEmpty()) {
            out.append(" none\n");
            return;
        }
        out.append("\n");
        for (Function function : sorted) {
            out.append(" *   - ").append(function.getName()).append(" @ 0x")
                    .append(function.getEntryPoint()).append("\n");
        }
    }
}

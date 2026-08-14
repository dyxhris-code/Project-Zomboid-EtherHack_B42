package EtherHack.migration;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Stream;

public final class ForbiddenArtifactTest {
    private static final Path JAVA_ROOT = Path.of("src/main/java");
    private static final List<String> FORBIDDEN_CLASSES = List.of(
            "EtherHack/Ether/EventProtector.java",
            "EtherHack/Ether/ProtectionManagerX.java",
            "EtherHack/Ether/SafeAPI.java",
            "EtherHack/GameClientPatcher.java",
            "EtherHack/GameClientWrapper.java",
            "EtherHack/protection/EnhancedProtectionSystem.java");
    private static final List<String> FORBIDDEN_SYMBOLS = List.of(
            "EventProtector",
            "ProtectionManagerX",
            "SafeAPI",
            "GameClientPatcher",
            "GameClientWrapper",
            "EnhancedProtectionSystem",
            "generateVerificationKey",
            "getAntiCheat12Status",
            "getAntiCheat8Status",
            "AntiCheatProtectionType",
            "methodCache");

    private ForbiddenArtifactTest() {
    }

    public static void main(String[] args) throws Exception {
        rejectsAbandonedProtectionArtifacts();
        preservesLuaCompilerControls();
    }

    private static void rejectsAbandonedProtectionArtifacts() throws IOException {
        List<String> failures = new ArrayList<>();

        for (String relativePath : FORBIDDEN_CLASSES) {
            if (Files.exists(JAVA_ROOT.resolve(relativePath))) {
                failures.add(relativePath + " still exists");
            }
        }

        for (Path file : javaFiles()) {
            String source = Files.readString(file);
            for (String symbol : FORBIDDEN_SYMBOLS) {
                if (source.contains(symbol)) {
                    failures.add(relative(file) + " contains " + symbol);
                }
            }
        }

        require(failures.isEmpty(),
                "Abandoned protection or multiplayer artifacts remain:\n" + String.join("\n", failures));
    }

    private static void preservesLuaCompilerControls() throws IOException {
        require(Files.isRegularFile(JAVA_ROOT.resolve("EtherHack/Ether/EtherLuaCompiler.java")),
                "EtherLuaCompiler must remain part of the B41 architecture");
        String patcher = Files.readString(JAVA_ROOT.resolve("EtherHack/GamePatcher.java"));
        require(patcher.contains("patchLuaManager()"),
                "GamePatcher must preserve the LuaManager compiler hook");
    }

    private static List<Path> javaFiles() throws IOException {
        try (Stream<Path> files = Files.walk(JAVA_ROOT)) {
            return files.filter(path -> path.toString().endsWith(".java")).toList();
        }
    }

    private static String relative(Path file) {
        return JAVA_ROOT.relativize(file).toString().replace('\\', '/');
    }

    private static void require(boolean condition, String message) {
        if (!condition) {
            throw new AssertionError(message);
        }
    }
}

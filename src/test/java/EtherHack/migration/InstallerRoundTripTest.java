package EtherHack.migration;

import java.io.IOException;
import java.io.InputStream;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.StandardCopyOption;
import java.net.URLClassLoader;
import java.io.PrintWriter;
import java.io.StringWriter;
import java.security.MessageDigest;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import org.objectweb.asm.AnnotationVisitor;
import org.objectweb.asm.ClassReader;
import org.objectweb.asm.ClassVisitor;
import org.objectweb.asm.MethodVisitor;
import org.objectweb.asm.Opcodes;
import org.objectweb.asm.util.CheckClassAdapter;

public final class InstallerRoundTripTest {
    private static final String INJECTED_DESCRIPTOR = "LEtherHack/annotations/Injected;";
    private static final List<String> PATCHED_CLASSES = List.of(
            "zombie/GameWindow.class",
            "zombie/characters/IsoPlayer.class",
            "zombie/inventory/ItemContainer.class",
            "zombie/Lua/LuaEventManager.class",
            "zombie/Lua/LuaManager.class");

    private InstallerRoundTripTest() {
    }

    public static void main(String[] args) throws Exception {
        require(args.length == 2, "Expected installer JAR and Project Zomboid JAR arguments");
        Path installer = Path.of(args[0]).toAbsolutePath();
        Path gameJar = Path.of(args[1]).toAbsolutePath();
        Path fixture = Files.createTempDirectory("etherhack-b42-round-trip-");

        try {
            Path fixtureGameJar = Files.copy(
                    gameJar,
                    fixture.resolve("projectzomboid.jar"),
                    StandardCopyOption.REPLACE_EXISTING);
            Path fixtureInstaller = Files.copy(
                    installer,
                    fixture.resolve(installer.getFileName()),
                    StandardCopyOption.REPLACE_EXISTING);
            String originalHash = sha256(fixtureGameJar);

            runInstaller(fixture, fixtureInstaller, "--install");

            require(originalHash.equals(sha256(fixtureGameJar)),
                    "Installation must not modify projectzomboid.jar");
            for (String className : PATCHED_CLASSES) {
                Path looseClass = fixture.resolve(className);
                require(Files.isRegularFile(looseClass), "Missing loose override " + className);
                require(hasInjectedAnnotation(looseClass), className + " has no injection marker");
                verifyBytecode(looseClass, fixture, fixtureGameJar, fixtureInstaller);
            }
            require(Files.isRegularFile(fixture.resolve("EtherHack/lua/EtherHackMenu.lua")),
                    "Installer did not extract root EtherHack resources");
            require(!Files.exists(fixture.resolve("Zomboid/mods/EtherHack")),
                    "Installer must not create a standalone mod");

            runInstaller(fixture, fixtureInstaller, "--uninstall");

            require(originalHash.equals(sha256(fixtureGameJar)),
                    "Uninstall must not modify projectzomboid.jar");
            for (String className : PATCHED_CLASSES) {
                require(!Files.exists(fixture.resolve(className)),
                        "Uninstall left loose override " + className);
                require(!Files.exists(fixture.resolve(className + ".bkup")),
                        "Uninstall left backup " + className + ".bkup");
            }
            require(!Files.exists(fixture.resolve("EtherHack")),
                    "Uninstall left extracted EtherHack resources");
        } finally {
            deleteTree(fixture);
        }
    }

    private static void runInstaller(Path fixture, Path installer, String operation) throws Exception {
        String javaExecutable = Path.of(System.getProperty("java.home"), "bin", "java.exe").toString();
        Process process = new ProcessBuilder(javaExecutable, "-jar", installer.toString(), operation)
                .directory(fixture.toFile())
                .redirectErrorStream(true)
                .start();
        String output;
        try (InputStream stream = process.getInputStream()) {
            output = new String(stream.readAllBytes());
        }
        int exitCode = process.waitFor();
        require(exitCode == 0, operation + " exited with " + exitCode + ":\n" + output);
    }

    private static boolean hasInjectedAnnotation(Path classFile) throws IOException {
        boolean[] found = {false};
        try (InputStream input = Files.newInputStream(classFile)) {
            new ClassReader(input).accept(new ClassVisitor(Opcodes.ASM9) {
                @Override
                public MethodVisitor visitMethod(
                        int access,
                        String name,
                        String descriptor,
                        String signature,
                        String[] exceptions) {
                    return new MethodVisitor(Opcodes.ASM9) {
                        @Override
                        public AnnotationVisitor visitAnnotation(String descriptor, boolean visible) {
                            if (INJECTED_DESCRIPTOR.equals(descriptor)) {
                                found[0] = true;
                            }
                            return null;
                        }
                    };
                }
            }, ClassReader.SKIP_CODE | ClassReader.SKIP_DEBUG | ClassReader.SKIP_FRAMES);
        }
        return found[0];
    }

    private static void verifyBytecode(Path classFile, Path fixture, Path gameJar, Path installer)
            throws Exception {
        StringWriter diagnostics = new StringWriter();
        try (URLClassLoader loader = new URLClassLoader(
                new java.net.URL[] {
                        fixture.toUri().toURL(),
                        gameJar.toUri().toURL(),
                        installer.toUri().toURL()
                },
                InstallerRoundTripTest.class.getClassLoader());
             InputStream input = Files.newInputStream(classFile)) {
            CheckClassAdapter.verify(
                    new ClassReader(input),
                    loader,
                    false,
                    new PrintWriter(diagnostics));
        }
        require(diagnostics.toString().isBlank(),
                "Invalid transformed bytecode in " + classFile + ":\n" + diagnostics);
    }

    private static String sha256(Path file) throws Exception {
        MessageDigest digest = MessageDigest.getInstance("SHA-256");
        try (InputStream input = Files.newInputStream(file)) {
            byte[] buffer = new byte[1024 * 1024];
            int count;
            while ((count = input.read(buffer)) >= 0) {
                if (count > 0) {
                    digest.update(buffer, 0, count);
                }
            }
        }
        StringBuilder value = new StringBuilder();
        for (byte next : digest.digest()) {
            value.append(String.format("%02X", next));
        }
        return value.toString();
    }

    private static void deleteTree(Path root) throws IOException {
        if (!Files.exists(root)) {
            return;
        }
        List<Path> paths = new ArrayList<>();
        try (var stream = Files.walk(root)) {
            stream.sorted(Comparator.reverseOrder()).forEach(paths::add);
        }
        for (Path path : paths) {
            Files.deleteIfExists(path);
        }
    }

    private static void require(boolean condition, String message) {
        if (!condition) {
            throw new AssertionError(message);
        }
    }
}

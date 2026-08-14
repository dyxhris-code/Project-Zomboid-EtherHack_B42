package EtherHack.utils;

import java.io.IOException;
import java.io.InputStream;
import java.net.URL;
import java.net.URLClassLoader;
import java.nio.file.AtomicMoveNotSupportedException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.StandardCopyOption;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.function.Consumer;
import java.util.jar.JarEntry;
import java.util.jar.JarFile;
import org.objectweb.asm.AnnotationVisitor;
import org.objectweb.asm.ClassReader;
import org.objectweb.asm.ClassVisitor;
import org.objectweb.asm.ClassWriter;
import org.objectweb.asm.MethodVisitor;
import org.objectweb.asm.Opcodes;
import org.objectweb.asm.tree.AnnotationNode;
import org.objectweb.asm.tree.ClassNode;
import org.objectweb.asm.tree.MethodNode;

public final class Patch {
    private static final String INJECTED_DESCRIPTOR = "LEtherHack/annotations/Injected;";
    private static final Map<String, ClassNode> CLASS_NODES = new HashMap<>();
    private static Path gameRoot;
    private static Path gameArchive;

    private Patch() {
    }

    public static void configure(Path root, Path archive) {
        gameRoot = root.toAbsolutePath().normalize();
        gameArchive = archive.toAbsolutePath().normalize();
        CLASS_NODES.clear();
    }

    public static boolean classExists(String className) {
        requireConfigured();
        if (Files.isRegularFile(looseClassPath(className))) {
            return true;
        }
        try (JarFile jar = new JarFile(gameArchive.toFile())) {
            return jar.getJarEntry(classEntry(className)) != null;
        } catch (IOException exception) {
            throw new IllegalStateException("Failed to inspect " + gameArchive, exception);
        }
    }

    public static void injectIntoClass(
            String className,
            String methodName,
            String descriptor,
            boolean isStatic,
            Consumer<MethodNode> injector) {
        Logger.print("Injection into '" + className + "' method '" + methodName + descriptor + "'");
        ClassNode classNode = CLASS_NODES.computeIfAbsent(className, Patch::readClass);
        MethodNode target = null;

        for (MethodNode method : classNode.methods) {
            boolean staticMethod = (method.access & Opcodes.ACC_STATIC) != 0;
            if (method.name.equals(methodName)
                    && method.desc.equals(descriptor)
                    && staticMethod == isStatic) {
                if (target != null) {
                    throw new IllegalStateException(
                            "Multiple matching methods in " + className + ": " + methodName + descriptor);
                }
                target = method;
            }
        }

        if (target == null) {
            throw new IllegalStateException(
                    "Required B42.20.2 method not found in " + className + ": " + methodName + descriptor);
        }
        if (hasInjectedAnnotation(target)) {
            throw new IllegalStateException(
                    "Method is already patched in " + className + ": " + methodName + descriptor);
        }

        injector.accept(target);
        addInjectedAnnotation(target);
    }

    public static boolean isInjectedAnnotationPresent(String className) {
        requireConfigured();
        Path looseClass = looseClassPath(className);
        if (!Files.isRegularFile(looseClass)) {
            return false;
        }

        try (InputStream input = Files.newInputStream(looseClass)) {
            boolean[] found = {false};
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
            return found[0];
        } catch (IOException exception) {
            throw new IllegalStateException("Failed to inspect " + looseClass, exception);
        }
    }

    public static void saveModifiedClasses() {
        requireConfigured();
        try (URLClassLoader hierarchyLoader = createHierarchyLoader()) {
            for (Map.Entry<String, ClassNode> entry : CLASS_NODES.entrySet()) {
                Path output = looseClassPath(entry.getKey());
                Files.createDirectories(output.getParent());

                ClassWriter writer = new HierarchyClassWriter(
                        ClassWriter.COMPUTE_MAXS | ClassWriter.COMPUTE_FRAMES,
                        hierarchyLoader);
                entry.getValue().accept(writer);
                writeAtomically(output, writer.toByteArray());
            }
        } catch (IOException exception) {
            throw new IllegalStateException("Failed to save patched classes", exception);
        } finally {
            CLASS_NODES.clear();
        }
    }

    private static ClassNode readClass(String className) {
        requireConfigured();
        Path looseClass = looseClassPath(className);
        try (InputStream input = Files.isRegularFile(looseClass)
                ? Files.newInputStream(looseClass)
                : openArchiveClass(className)) {
            ClassNode node = new ClassNode(Opcodes.ASM9);
            new ClassReader(input).accept(node, ClassReader.EXPAND_FRAMES);
            return node;
        } catch (IOException exception) {
            throw new IllegalStateException("Failed to read game class " + className, exception);
        }
    }

    private static InputStream openArchiveClass(String className) throws IOException {
        JarFile jar = new JarFile(gameArchive.toFile());
        JarEntry entry = jar.getJarEntry(classEntry(className));
        if (entry == null) {
            jar.close();
            throw new IOException("Missing " + classEntry(className) + " in " + gameArchive);
        }
        InputStream input = jar.getInputStream(entry);
        return new InputStream() {
            @Override
            public int read() throws IOException {
                return input.read();
            }

            @Override
            public int read(byte[] bytes, int offset, int length) throws IOException {
                return input.read(bytes, offset, length);
            }

            @Override
            public void close() throws IOException {
                try {
                    input.close();
                } finally {
                    jar.close();
                }
            }
        };
    }

    private static URLClassLoader createHierarchyLoader() throws IOException {
        URL gameUrl = gameArchive.toUri().toURL();
        URL etherHackUrl = Patch.class.getProtectionDomain().getCodeSource().getLocation();
        return new URLClassLoader(new URL[] {gameUrl, etherHackUrl}, Patch.class.getClassLoader());
    }

    private static void writeAtomically(Path output, byte[] bytes) throws IOException {
        Path temporary = Files.createTempFile(output.getParent(), output.getFileName().toString(), ".tmp");
        try {
            Files.write(temporary, bytes);
            try {
                Files.move(
                        temporary,
                        output,
                        StandardCopyOption.ATOMIC_MOVE,
                        StandardCopyOption.REPLACE_EXISTING);
            } catch (AtomicMoveNotSupportedException ignored) {
                Files.move(temporary, output, StandardCopyOption.REPLACE_EXISTING);
            }
        } finally {
            Files.deleteIfExists(temporary);
        }
    }

    private static void addInjectedAnnotation(MethodNode method) {
        if (method.visibleAnnotations == null) {
            method.visibleAnnotations = new LinkedList<>();
        }
        method.visibleAnnotations.add(new AnnotationNode(INJECTED_DESCRIPTOR));
    }

    private static boolean hasInjectedAnnotation(MethodNode method) {
        return method.visibleAnnotations != null
                && method.visibleAnnotations.stream()
                        .anyMatch(annotation -> INJECTED_DESCRIPTOR.equals(annotation.desc));
    }

    private static Path looseClassPath(String className) {
        return gameRoot.resolve(classEntry(className));
    }

    private static String classEntry(String className) {
        return className + ".class";
    }

    private static void requireConfigured() {
        if (gameRoot == null || gameArchive == null) {
            throw new IllegalStateException("Patch.configure must be called before patching");
        }
    }

    private static final class HierarchyClassWriter extends ClassWriter {
        private final ClassLoader hierarchyLoader;

        private HierarchyClassWriter(int flags, ClassLoader hierarchyLoader) {
            super(flags);
            this.hierarchyLoader = hierarchyLoader;
        }

        @Override
        protected String getCommonSuperClass(String type1, String type2) {
            try {
                Class<?> first = Class.forName(type1.replace('/', '.'), false, hierarchyLoader);
                Class<?> second = Class.forName(type2.replace('/', '.'), false, hierarchyLoader);
                if (first.isAssignableFrom(second)) {
                    return type1;
                }
                if (second.isAssignableFrom(first)) {
                    return type2;
                }
                if (first.isInterface() || second.isInterface()) {
                    return "java/lang/Object";
                }
                do {
                    first = first.getSuperclass();
                } while (first != null && !first.isAssignableFrom(second));
                return first == null ? "java/lang/Object" : first.getName().replace('.', '/');
            } catch (ClassNotFoundException | LinkageError ignored) {
                return "java/lang/Object";
            }
        }
    }
}

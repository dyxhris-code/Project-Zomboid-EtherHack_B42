package EtherHack;

import EtherHack.utils.Info;
import EtherHack.utils.Logger;
import EtherHack.utils.Patch;
import java.io.IOException;
import java.io.InputStream;
import java.net.URISyntaxException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardCopyOption;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.jar.JarFile;

import org.objectweb.asm.Opcodes;
import org.objectweb.asm.tree.*;

/**
 * Класс, отвечающий за установку и удаление чита из кодов игры
 */
public class GamePatcher {

   /**
    * Список всех файлов, подлежащих инъекции
    */
   private final String[] patchClasses = new String[]{
           "zombie/GameWindow",
           "zombie/characters/IsoPlayer",
           "zombie/inventory/ItemContainer",
           "zombie/Lua/LuaEventManager",
           "zombie/Lua/LuaManager"
   };

   private final Path gameRoot;
   private final Path gameArchive;

   /**
    * Папки и файлы, которые нужно экспортировать в корневую директорию игры
    */
   private final String whiteListPathEtherFiles = "EtherHack";

   public GamePatcher() {
      this(Paths.get(System.getProperty("user.dir")));
   }

   GamePatcher(Path gameRoot) {
      this.gameRoot = gameRoot.toAbsolutePath().normalize();
      this.gameArchive = this.gameRoot.resolve("projectzomboid.jar");
      Patch.configure(this.gameRoot, this.gameArchive);
   }

   /**
    * Экспортирование файлов EtherHack в корневую директорию игры
    */
   public void extractEtherHack() {
      try {
         String jarFilePath = Main.class.getProtectionDomain().getCodeSource().getLocation().toURI().getPath();
         try (JarFile jarFile = new JarFile(jarFilePath)) {
            jarFile.stream().filter((entry) -> entry.getName().startsWith(whiteListPathEtherFiles))
                    .forEach((entry) -> {
                       try {
                          Path extractPath = gameRoot.resolve(entry.getName()).normalize();
                          if (!extractPath.startsWith(gameRoot)) {
                             throw new IOException("Refusing to extract outside the game root: " + entry.getName());
                          }

                          if (entry.isDirectory()) {
                             Files.createDirectories(extractPath);
                          } else {
                             Files.createDirectories(extractPath.getParent());

                             try (InputStream inputStream = jarFile.getInputStream(entry)) {
                                Files.copy(inputStream, extractPath, StandardCopyOption.REPLACE_EXISTING);
                             }
                          }
                       } catch (IOException e) {
                          e.printStackTrace();
                       }
                    });
            Logger.print("Extraction completed successfully");
         }
      } catch (URISyntaxException | IOException e) {
         e.printStackTrace();
      }
   }


   /**
    *  Удаление всех экспортированных файлов EtherHack из директории игры
    */
   public void uninstallEtherHackFiles() {
      Logger.print("Deleting all EtherHack files...");

      try {
         Path targetPath = gameRoot.resolve(whiteListPathEtherFiles);
         if (Files.exists(targetPath)) {
            try (var paths = Files.walk(targetPath)) {
               for (Path path : paths.sorted(Comparator.reverseOrder()).toList()) {
                  Files.deleteIfExists(path);
               }
            }
         }
         Logger.print("Deletion EtherHack files completed successfully");
      } catch (IOException except) {
         except.printStackTrace();
      }

   }

   /**
    * Создает резервные копии игровых файлов, если они еще не существуют.
    * Файлы будут сохранены с расширением .bkup в той же папке, что и оригиналы.
    */
   public void backupGameFiles() {
      for (int i = 0; i < patchClasses.length; i++) {
         String iteration = "[" + (i + 1) + "/" + patchClasses.length + "]";
         Path originalFilePath = gameRoot.resolve(patchClasses[i] + ".class");
         Logger.print("Preserving loose class '" + patchClasses[i] + ".class' " + iteration);

         if (Files.exists(originalFilePath)) {
            try {
               Path backupFilePath = Path.of(originalFilePath + ".bkup");

               if (Files.exists(backupFilePath)) {
                  Logger.print("Backup of the file already exists. Skipping backup.");
               } else {
                  Files.copy(originalFilePath, backupFilePath);
               }
            } catch (IOException e) {
               Logger.print("Error while creating backup file: " + e.getMessage());
            }
         }
      }

      Logger.print("Backups of game files have been completed!");
   }

   /**
    * Внедрение в файл игрового окна
    */
   public void patchGameWindow() {
      Patch.injectIntoClass("zombie/GameWindow", "InitDisplay", "()V", true, (method) -> {
         String oldTitle = "Project Zomboid";
         String newTitle = "Project Zomboid" + Info.CHEAT_WINDOW_TITLE_SUFFIX;
         AbstractInsnNode[] nodes = method.instructions.toArray();
         int replacements = 0;

         for (AbstractInsnNode insn : nodes) {
            if (insn instanceof LdcInsnNode ldcInsnNode) {
               if (ldcInsnNode.cst.equals(oldTitle)) {
                  ldcInsnNode.cst = newTitle;
                  replacements++;
               }
            }
         }
         if (replacements != 1) {
            throw new IllegalStateException("Expected one Project Zomboid title constant, found " + replacements);
         }
      });
      Patch.injectIntoClass("zombie/GameWindow", "init", "()V", true, (method) -> {
         AbstractInsnNode insertionPoint = null;

         // Find the point of injection
         for (AbstractInsnNode insn : method.instructions.toArray()) {
            if (insn instanceof MethodInsnNode) {
               MethodInsnNode methodInsn = (MethodInsnNode) insn;
               if (methodInsn.getOpcode() == Opcodes.INVOKESTATIC
                       && methodInsn.owner.equals("zombie/Lua/LuaManager")
                       && methodInsn.name.equals("init")
                       && methodInsn.desc.equals("()V")) {
                  if (insertionPoint != null) {
                     throw new IllegalStateException("Found multiple LuaManager.init() calls in GameWindow.init()");
                  }
                  insertionPoint = insn;
               }
            }
         }

         if (insertionPoint != null) {
            InsnList initEtherLuaInstructions = new InsnList();
            initEtherLuaInstructions.add(new MethodInsnNode(Opcodes.INVOKESTATIC, "EtherHack/Ether/EtherLuaCompiler", "getInstance", "()LEtherHack/Ether/EtherLuaCompiler;", false));
            initEtherLuaInstructions.add(new MethodInsnNode(Opcodes.INVOKEVIRTUAL, "EtherHack/Ether/EtherLuaCompiler", "init", "()V", false));
            method.instructions.insert(insertionPoint, initEtherLuaInstructions);
         } else {
            throw new IllegalStateException("Cannot find LuaManager.init() invocation in the method when patching the Game window");
         }
         List<AbstractInsnNode> returns = Arrays.stream(method.instructions.toArray())
                 .filter(instruction -> instruction.getOpcode() == Opcodes.RETURN)
                 .toList();
         if (returns.size() == 1) {
            AbstractInsnNode returnInstruction = returns.getFirst();
            InsnList initLogoInstructions = new InsnList();
            initLogoInstructions.add(new MethodInsnNode(Opcodes.INVOKESTATIC, "EtherHack/Ether/EtherLogo", "getInstance", "()LEtherHack/Ether/EtherLogo;", false));
            initLogoInstructions.add(new MethodInsnNode(Opcodes.INVOKEVIRTUAL, "EtherHack/Ether/EtherLogo", "init", "()V", false));
            method.instructions.insertBefore(returnInstruction, initLogoInstructions);

            InsnList initEtherInstructions = new InsnList();
            initEtherInstructions.add(new MethodInsnNode(Opcodes.INVOKESTATIC, "EtherHack/Ether/EtherMain", "getInstance", "()LEtherHack/Ether/EtherMain;", false));
            initEtherInstructions.add(new MethodInsnNode(Opcodes.INVOKEVIRTUAL, "EtherHack/Ether/EtherMain", "init", "()V", false));
            method.instructions.insertBefore(returnInstruction, initEtherInstructions);
         } else {
            throw new IllegalStateException("Expected one RETURN in GameWindow.init(), found " + returns.size());
         }
      });

   }

   /**
    * Внедрение в файлы игровых предметов
    */
   public void patchItemContainer() {
      Patch.injectIntoClass("zombie/inventory/ItemContainer", "getCapacityWeight", "()F", false, (method) -> {
         InsnList newInstructions = new InsnList();
         LabelNode carryOnLabel = new LabelNode();
         newInstructions.add(new MethodInsnNode(Opcodes.INVOKESTATIC, "EtherHack/Ether/EtherMain", "getInstance", "()LEtherHack/Ether/EtherMain;", false));
         newInstructions.add(new JumpInsnNode(Opcodes.IFNULL, carryOnLabel));
         newInstructions.add(new MethodInsnNode(Opcodes.INVOKESTATIC, "EtherHack/Ether/EtherMain", "getInstance", "()LEtherHack/Ether/EtherMain;", false));
         newInstructions.add(new FieldInsnNode(Opcodes.GETFIELD, "EtherHack/Ether/EtherMain", "etherAPI", "LEtherHack/Ether/EtherAPI;"));
         newInstructions.add(new JumpInsnNode(Opcodes.IFNULL, carryOnLabel));
         newInstructions.add(new MethodInsnNode(Opcodes.INVOKESTATIC, "EtherHack/Ether/EtherMain", "getInstance", "()LEtherHack/Ether/EtherMain;", false));
         newInstructions.add(new FieldInsnNode(Opcodes.GETFIELD, "EtherHack/Ether/EtherMain", "etherAPI", "LEtherHack/Ether/EtherAPI;"));
         newInstructions.add(new FieldInsnNode(Opcodes.GETFIELD, "EtherHack/Ether/EtherAPI", "isUnlimitedCarry", "Z"));
         newInstructions.add(new JumpInsnNode(Opcodes.IFEQ, carryOnLabel));
         newInstructions.add(new InsnNode(Opcodes.FCONST_0));
         newInstructions.add(new InsnNode(Opcodes.FRETURN));
         newInstructions.add(carryOnLabel);
         method.instructions.insert(newInstructions);
      });
      Patch.injectIntoClass("zombie/inventory/ItemContainer", "getContentsWeight", "()F", false, (method) -> {
         InsnList newInstructions = new InsnList();
         LabelNode carryOnLabel = new LabelNode();
         newInstructions.add(new MethodInsnNode(Opcodes.INVOKESTATIC, "EtherHack/Ether/EtherMain", "getInstance", "()LEtherHack/Ether/EtherMain;", false));
         newInstructions.add(new JumpInsnNode(Opcodes.IFNULL, carryOnLabel));
         newInstructions.add(new MethodInsnNode(Opcodes.INVOKESTATIC, "EtherHack/Ether/EtherMain", "getInstance", "()LEtherHack/Ether/EtherMain;", false));
         newInstructions.add(new FieldInsnNode(Opcodes.GETFIELD, "EtherHack/Ether/EtherMain", "etherAPI", "LEtherHack/Ether/EtherAPI;"));
         newInstructions.add(new JumpInsnNode(Opcodes.IFNULL, carryOnLabel));
         newInstructions.add(new MethodInsnNode(Opcodes.INVOKESTATIC, "EtherHack/Ether/EtherMain", "getInstance", "()LEtherHack/Ether/EtherMain;", false));
         newInstructions.add(new FieldInsnNode(Opcodes.GETFIELD, "EtherHack/Ether/EtherMain", "etherAPI", "LEtherHack/Ether/EtherAPI;"));
         newInstructions.add(new FieldInsnNode(Opcodes.GETFIELD, "EtherHack/Ether/EtherAPI", "isUnlimitedCarry", "Z"));
         newInstructions.add(new JumpInsnNode(Opcodes.IFEQ, carryOnLabel));
         newInstructions.add(new InsnNode(Opcodes.FCONST_0));
         newInstructions.add(new InsnNode(Opcodes.FRETURN));
         newInstructions.add(carryOnLabel);
         method.instructions.insert(newInstructions);
      });
   }

   public void patchIsoPlayerAim() {
      Patch.injectIntoClass(
              "zombie/characters/IsoPlayer",
              "calculateAimVector",
              "(Lzombie/iso/Vector2;)Lzombie/iso/Vector2;",
              false,
              (method) -> {
                 List<AbstractInsnNode> returns = Arrays.stream(method.instructions.toArray())
                         .filter(instruction -> instruction.getOpcode() == Opcodes.ARETURN)
                         .toList();
                 if (returns.size() != 1) {
                    throw new IllegalStateException(
                            "Expected one ARETURN in IsoPlayer.calculateAimVector, found " + returns.size());
                 }

                 int resultLocal = method.maxLocals++;
                 InsnList adjustAimInstructions = new InsnList();
                 adjustAimInstructions.add(new VarInsnNode(Opcodes.ASTORE, resultLocal));
                 adjustAimInstructions.add(new VarInsnNode(Opcodes.ALOAD, 0));
                 adjustAimInstructions.add(new VarInsnNode(Opcodes.ALOAD, resultLocal));
                 adjustAimInstructions.add(new MethodInsnNode(
                         Opcodes.INVOKESTATIC,
                         "EtherHack/features/AutoAimController",
                         "adjustAimVector",
                         "(Lzombie/characters/IsoPlayer;Lzombie/iso/Vector2;)Lzombie/iso/Vector2;",
                         false));
                 method.instructions.insertBefore(returns.getFirst(), adjustAimInstructions);
              });
   }

   public void patchIsoPlayerTimedAction() {
      Patch.injectIntoClass(
              "zombie/characters/IsoPlayer",
              "isTimedActionInstant",
              "()Z",
              false,
              (method) -> {
                 LabelNode useNativeResult = new LabelNode();
                 InsnList instantActionOverride = new InsnList();
                 instantActionOverride.add(new VarInsnNode(Opcodes.ALOAD, 0));
                 instantActionOverride.add(new MethodInsnNode(
                         Opcodes.INVOKESTATIC,
                         "EtherHack/features/LocalPlayerCheatController",
                         "isTimedActionInstant",
                         "(Lzombie/characters/IsoPlayer;)Z",
                         false));
                 instantActionOverride.add(new JumpInsnNode(Opcodes.IFEQ, useNativeResult));
                 instantActionOverride.add(new InsnNode(Opcodes.ICONST_1));
                 instantActionOverride.add(new InsnNode(Opcodes.IRETURN));
                 instantActionOverride.add(useNativeResult);
                 method.instructions.insert(instantActionOverride);
              });
   }

   /**
    * Внедрение в файл LuaEventManager
    */
   public void patchLuaEventManager() {
      for (int argumentCount = 1; argumentCount <= 9; argumentCount++) {
         String descriptor = "(" + "Ljava/lang/String;" + "Ljava/lang/Object;".repeat(argumentCount - 1) + ")V";
         Patch.injectIntoClass("zombie/Lua/LuaEventManager", "triggerEvent", descriptor, true, (method) -> {
            InsnList toInject = new InsnList();
            toInject.add(new VarInsnNode(Opcodes.ALOAD, 0));
            toInject.add(new MethodInsnNode(Opcodes.INVOKESTATIC, "EtherHack/utils/EventSubscriber", "invokeSubscriber", "(Ljava/lang/String;)V", false));
            method.instructions.insert(toInject);
         });
      }
   }

   /**
    * Внедрение в файл LuaManager
    */
   public void patchLuaManager() {
      Patch.injectIntoClass("zombie/Lua/LuaManager", "RunLua", "(Ljava/lang/String;Z)Ljava/lang/Object;", true, (method) -> {
         InsnList newInstructions = new InsnList();
         LabelNode endOfMethodLabel = new LabelNode();

         newInstructions.add(new MethodInsnNode(Opcodes.INVOKESTATIC, "EtherHack/Ether/EtherLuaCompiler", "getInstance", "()LEtherHack/Ether/EtherLuaCompiler;", false));
         newInstructions.add(new VarInsnNode(Opcodes.ALOAD, 0));
         newInstructions.add(new MethodInsnNode(Opcodes.INVOKEVIRTUAL, "EtherHack/Ether/EtherLuaCompiler", "isShouldLuaCompile", "(Ljava/lang/String;)Z", false));

         newInstructions.add(new JumpInsnNode(Opcodes.IFNE, endOfMethodLabel));

         newInstructions.add(new InsnNode(Opcodes.ACONST_NULL));
         newInstructions.add(new InsnNode(Opcodes.ARETURN));

         newInstructions.add(endOfMethodLabel);

         method.instructions.insert(newInstructions);
      });
   }

   /**
    * Проверяет, содержит ли хотя бы один из заданных файлов аннотацию @Injected.
    * @return true, если аннотация @Injected найдена хотя бы в одном файле. false в противном случае.
    */
   public boolean checkInjectedAnnotations() {
      return Arrays.stream(patchClasses).anyMatch(Patch::isInjectedAnnotationPresent);
   }

   /**
    * Проверяет наличие игровой папки и определенных файлов внутри.
    * @return true, если игровая папка и все требуемые файлы присутствуют. false в противном случае.
    */
   public boolean isGameFolder() {
      return Files.isRegularFile(gameArchive) && Arrays.stream(patchClasses).allMatch(Patch::classExists);
   }

   /**
    * Патчинг игровых bytecode файлов игры
    * для реализации собственного фунционала
    */
   public void patchGame() {
      Logger.printCredits();

      Logger.print("Preparing to install the EtherHack...");

      if (!isGameFolder()) {
         Logger.print("No game files were found in this directory. Place the cheat in the root folder of the game");
         return;
      }

      Logger.print("Checking for injections in game files");

      if (checkInjectedAnnotations()) {
         Logger.print("Signs of interference were found in the game files. If you have installed this cheat before, run it with the '--uninstall' flag. Otherwise, check the integrity of the game files via Steam");
         return;
      }
      Logger.print("No signs of injections were found. Preparing for backup...");
      backupGameFiles();
      Logger.print("Preparation for injection into game file...");

      patchGameWindow();
      patchIsoPlayerAim();
      patchIsoPlayerTimedAction();
      patchItemContainer();
      patchLuaEventManager();
      patchLuaManager();

      Patch.saveModifiedClasses();

      Logger.print("The injections were completed!");

      Logger.print("Extracting EtherHack files to the current directory...");

      extractEtherHack();

      Logger.print("The cheat installation is complete, you can enter the game!");
   }

   /**
    * Восстановление оригинальных файлов игры
    */
   public void restoreFiles() {
      Logger.printCredits();
      Logger.print("Restoring files...");
      for(int i = 0; i < patchClasses.length; ++i) {
         String fileName = patchClasses[i] + ".class";
         String iteration = "[" + (i + 1) + "/" + patchClasses.length + "]";
         Logger.print("Restoring the file '" + fileName + "' " + iteration);
         Path originalFilePath = gameRoot.resolve(fileName);
         Path backupFilePath = Path.of(originalFilePath + ".bkup");
         if (Files.exists(backupFilePath)) {
            try {
               Files.move(backupFilePath, originalFilePath, StandardCopyOption.REPLACE_EXISTING);
            } catch (IOException e) {
               Logger.print("Error when restoring the game file '" + fileName + "': " + e.getMessage());
            }
         } else {
            try {
               Files.deleteIfExists(originalFilePath);
            } catch (IOException e) {
               Logger.print("Error deleting generated game file '" + fileName + "': " + e.getMessage());
            }
         }
      }

      Logger.print("Files restoration completed!");
      uninstallEtherHackFiles();
   }
}

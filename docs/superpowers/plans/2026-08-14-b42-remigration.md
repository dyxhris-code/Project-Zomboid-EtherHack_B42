# Project Zomboid B42.20.2 Remigration Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Port the original B41 EtherHack design to Project Zomboid B42.20.2 without the abandoned standalone Mod, multiplayer legality detection, or custom client/server command architecture.

**Architecture:** Keep the B41 installation model: read original classes from `projectzomboid.jar`, emit verified loose override classes into the game directory, and extract runtime resources under the game-root `EtherHack/` directory. Preserve the original Lua compiler controls, logo state, and UI architecture while changing only APIs and injection anchors required by B42.20.2.

**Tech Stack:** Java 25, Gradle 8.13+, ASM 9.9+, JUnit 5, Project Zomboid B42.20.2 runtime libraries, Lua resource validation.

## Global Constraints

- Target Project Zomboid Build is `42.20.2` using local runtime `D:\Apps\Steam\steamapps\common\ProjectZomboid`.
- Compile with JDK 25 because the target game classes use class-file major version 69.
- Do not modify or redistribute `projectzomboid.jar` or other game-owned libraries.
- Do not generate `Zomboid/mods/EtherHack`, `mod.info`, `common/media`, or `42/media` layouts.
- Do not add `EtherDebugClient.lua`, `EtherDebugServer.lua`, multiplayer legality detection, or custom anti-cheat compatibility layers.
- Preserve `EtherLuaCompiler`, `patchLuaManager`, `EtherLogoState`, and the B41 game-root `EtherHack/` resource layout.
- Every bytecode injection must assert its exact owner, name, descriptor, and expected match count.
- Generated `build/` content and local game libraries must remain untracked.

---

### Task 1: Reproducible B42 Build And Migration Gates

**Files:**
- Modify: `.gitignore`
- Modify: `build.gradle.kts`
- Modify: `gradle/wrapper/gradle-wrapper.properties`
- Create: `lib/README.md`
- Create: `src/test/java/EtherHack/migration/ForbiddenArtifactTest.java`
- Create: `src/test/java/EtherHack/migration/LuaModuleManifestTest.java`

**Interfaces:**
- Consumes: local Project Zomboid directory from Gradle property `pzGameDir` or environment variable `PZ_GAME_DIR`.
- Produces: `pzRuntime` file collection, Java 25 compilation, JUnit migration gates, and a JAR that excludes local game libraries.

- [ ] **Step 1: Write failing migration-gate tests**

  Add tests that fail while forbidden protection/debug classes, stale Lua modules, `sendAddXp`, or `getPlayerCraftingUI` remain. Add a manifest test that parses `etherModules` and verifies every project resource exists.

- [ ] **Step 2: Run tests and capture expected failures**

  Run: `gradle test --tests "EtherHack.migration.*" --no-daemon`

  Expected: failures list the existing protection classes and stale B41 Lua references.

- [ ] **Step 3: Configure the current game runtime without committing jars**

  Resolve `projectzomboid.jar` from `-PpzGameDir`, then `PZ_GAME_DIR`, then the documented local Steam path. Use the game's required dependency jars as compile-only inputs and keep ASM/Lombok as normal build dependencies.

- [ ] **Step 4: Upgrade the build runtime**

  Set Java toolchain and release to 25, update the wrapper to an installed Gradle version that runs on Java 25, enable JUnit Platform, and update ASM/Lombok to versions supporting Java 25.

- [ ] **Step 5: Verify the build environment**

  Run: `gradle clean test --no-daemon -PpzGameDir="D:\Apps\Steam\steamapps\common\ProjectZomboid"`

  Expected: compilation reaches only genuine B42 API errors; dependency resolution does not use tracked `lib/*.jar` files.

### Task 2: Restore The B41 Patcher Model On B42

**Files:**
- Modify: `src/main/java/EtherHack/utils/Patch.java`
- Modify: `src/main/java/EtherHack/GamePatcher.java`
- Create: `src/test/java/EtherHack/utils/PatchTest.java`
- Create: `src/test/java/EtherHack/GamePatcherTest.java`

**Interfaces:**
- Consumes: `projectzomboid.jar` and a supplied game-root path.
- Produces: strict class loading, verified ASM transformations, loose override output, and reversible install/uninstall behavior.

- [ ] **Step 1: Write failing patcher round-trip tests**

  Use a temporary game root containing a fixture JAR. Assert the source JAR hash never changes, loose classes are emitted, backup/restore is idempotent, and paths cannot escape the supplied game root.

- [ ] **Step 2: Write failing injection contract tests**

  Assert each hook matches exactly one expected method or an explicit overload set. Verify missing descriptors and missing `LuaManager.init()` anchors fail installation with a clear message.

- [ ] **Step 3: Implement JAR-backed class reads and loose output**

  Adapt `Patch` to read class bytes from `projectzomboid.jar`, retain transformed bytes in memory, verify them with ASM, and save them beneath the game root without modifying the JAR.

- [ ] **Step 4: Port B42 injection anchors**

  Preserve `GameWindow.InitDisplay`, `GameWindow.init`, `LuaManager.RunLua`, and `LuaEventManager.triggerEvent`. Remove only the nonexistent `ItemContainer.getWeight()` hook; keep strict hooks for `getCapacityWeight()` and `getContentsWeight()`.

- [ ] **Step 5: Verify install and restore**

  Run the patcher tests and ASM verification against the current B42.20.2 JAR. Expected: exact hook counts, valid output bytecode, unchanged source JAR, and clean restoration.

### Task 3: Preserve Core Startup, Lua Compiler, And Logo

**Files:**
- Modify: `src/main/java/EtherHack/Ether/EtherMain.java`
- Modify: `src/main/java/EtherHack/Ether/EtherLogo.java`
- Modify: `src/main/java/EtherHack/states/EtherLogoState.java`
- Modify: `src/main/java/EtherHack/utils/Logger.java`
- Test: `src/test/java/EtherHack/Ether/EtherMainTest.java`

**Interfaces:**
- Consumes: injected calls from `GameWindow` and `LuaManager`.
- Produces: idempotent EtherHack initialization, B42-compatible logging, logo state insertion, and the original Lua compiler behavior.

- [ ] **Step 1: Write failing initialization tests**

  Assert repeated initialization does not register duplicate subscribers and one component failure is logged without leaving a partially initialized singleton.

- [ ] **Step 2: Port logging and state-machine names**

  Use `DebugLog.log(DebugType.General, message)`, `GameWindow.states`, and `GameWindow.states.loopToState` while preserving `EtherLogoState`.

- [ ] **Step 3: Add idempotent initialization**

  Implement a guarded `initSafe()` used by injected startup paths. Keep `EtherLuaCompiler` initialization and resource loading in the B41 order unless a test proves an ordering dependency.

- [ ] **Step 4: Verify startup bytecode and unit tests**

  Assert transformed startup classes reference `initSafe`, logo classes remain in the output JAR, and Lua compiler patching is still enabled.

### Task 4: Port Core Java Gameplay APIs

**Files:**
- Modify: `src/main/java/EtherHack/Ether/EtherAPI.java`
- Modify: `src/main/java/EtherHack/Ether/EtherLuaMethods.java`
- Modify: `src/main/java/EtherHack/utils/PlayerUtils.java`
- Modify: `src/main/java/EtherHack/utils/VehicleUtils.java`
- Modify: `src/main/java/EtherHack/utils/ZombieUtils.java`
- Create: `src/test/java/EtherHack/Ether/CharacterStatMappingTest.java`
- Create: `src/test/java/EtherHack/utils/ScreenCoordinateTest.java`
- Create: `src/test/java/EtherHack/Ether/PlayerPacketDispatchTest.java`

**Interfaces:**
- Consumes: B42.20.2 `CharacterStat`, `PlayerPacket`, entity-coordinate, weapon, and vehicle APIs.
- Produces: compatible status locks, teleport updates, ESP screen coordinates, weapon editing, and vehicle iteration.

- [ ] **Step 1: Write failing API mapping tests**

  Cover weapon critical multiplier names, every status flag to `CharacterStat`, fake infection reset, and the unresolved distinction between fear and panic.

- [ ] **Step 2: Port direct API calls**

  Use `get/setCriticalDamageMultiplier`, `Stats.set(CharacterStat, float)`, B42 fake-infection methods, `Set` or `Collection` for vehicles, and `&&` in all collection null/empty guards.

- [ ] **Step 3: Port teleport packet dispatch**

  Import the B42 `PlayerPacket`, call `set(player)`, and use its returned `PacketType` for `doPacket` and `send`; never hard-code `PlayerUpdateReliable`.

- [ ] **Step 4: Preserve the B41 screen-coordinate formula**

  Replace inaccessible coordinate fields and `Core.TileScale`, but retain camera offsets, zoom, and the vertical tile offset. Verify golden values at multiple zoom levels.

- [ ] **Step 5: Compile and run focused tests**

  Expected: no unresolved B41 Java APIs and all mapping, packet, and coordinate tests pass against B42.20.2.

### Task 5: Remove Abandoned Protection And Multiplayer Layers

**Files:**
- Delete: `src/main/java/EtherHack/Ether/EventProtector.java`
- Delete: `src/main/java/EtherHack/Ether/ProtectionManagerX.java`
- Delete: `src/main/java/EtherHack/Ether/SafeAPI.java`
- Delete: `src/main/java/EtherHack/GameClientPatcher.java`
- Delete: `src/main/java/EtherHack/GameClientWrapper.java`
- Delete: `src/main/java/EtherHack/protection/EnhancedProtectionSystem.java`
- Modify: Java callers identified by CodeGraph impact analysis
- Modify: Lua callers identified by the migration gates

**Interfaces:**
- Consumes: the original B41 direct local gameplay operations.
- Produces: no legality-detection subsystem, no custom multiplayer protocol, and no dead protection references.

- [ ] **Step 1: Confirm failing forbidden-artifact tests**

  Verify the Task 1 gate enumerates every class and method scheduled for removal.

- [ ] **Step 2: Remove the abandoned classes and call sites**

  Delete verification-key generation, anti-cheat probes, admin escalation helpers, packet interception wrappers, and their startup wiring. Preserve unrelated Lua compiler controls.

- [ ] **Step 3: Run CodeGraph impact and compilation checks**

  Run `codegraph affected` for deleted files, then compile. Expected: no references to removed protection APIs and no accidental removal of `EtherLuaCompiler`.

### Task 6: Minimal Lua B42 Compatibility

**Files:**
- Modify: `src/main/resources/EtherHack/lua/EtherHackMenu.lua`
- Delete: `src/main/resources/EtherHack/lua/components/override/EtherAdminMenu.lua`
- Delete: `src/main/resources/EtherHack/lua/components/override/EtherDebugMenu.lua`
- Modify: `src/main/resources/EtherHack/lua/components/override/EtherEditInventoryItem.lua`
- Modify: `src/main/resources/EtherHack/lua/components/panels/EtherExploitPanel.lua`
- Modify: `src/main/resources/EtherHack/lua/components/ui/UIModalAddXP.lua`
- Modify: `src/main/resources/EtherHack/lua/components/ui/UIMechanics.lua`
- Create: `src/test/java/EtherHack/migration/LuaCompatibilityTest.java`

**Interfaces:**
- Consumes: B42 native `ISDebugMenu`, `ISItemEditorUI`, vehicle commands, and current Lua resource tree.
- Produces: the original EtherHack UI loading without stale B41 overrides or removed global functions.

- [ ] **Step 1: Keep the static tests red for stale B41 symbols**

  Assert project Lua contains no `sendAddXp`, `getPlayerCraftingUI`, `EtherAdminMenu`, `EtherDebugMenu`, `EtherDebugClient`, or `EtherDebugServer` references.

- [ ] **Step 2: Remove stale overrides and XP dispatch**

  Stop loading and delete the two copied B41 native menus. Keep local XP application and remove the missing multiplayer `sendAddXp` call.

- [ ] **Step 3: Port item editor and vehicle nil handling**

  Open the native B42 item editor through `ISItemEditorUI.OpenPanel(player, item)` and retain the B41 vehicle operations with explicit missing-player/missing-vehicle guards.

- [ ] **Step 4: Disable the obsolete crafting-material action**

  Remove or disable the action that depends on `getPlayerCraftingUI`. Do not add the abandoned custom server protocol. A later feature branch may implement B42 `CraftRecipeManager` support.

- [ ] **Step 5: Validate Lua modules**

  Resolve each project `require` against project resources or the installed B42 Lua tree and run available Lua syntax parsing. Expected: no missing modules or forbidden symbols.

### Task 7: Packaging, Documentation, And Acceptance

**Files:**
- Modify: `README.md`
- Modify: `.github/workflows/gradle.yml`
- Modify: `src/main/resources/EtherHack/EtherHack.properties`
- Create: `docs/B42_ACCEPTANCE.md`

**Interfaces:**
- Consumes: all prior migration tasks.
- Produces: distributable installer JAR, reproducible local verification, and a manual in-game acceptance checklist.

- [ ] **Step 1: Document local dependencies and original architecture**

  Explain JDK 25, `PZ_GAME_DIR`, loose class overrides, game-root resources, install/uninstall commands, and the absence of a standalone Mod or legality detector.

- [ ] **Step 2: Build a clean installer JAR**

  Ensure the fat JAR includes EtherHack runtime dependencies and resources but excludes Project Zomboid-owned JARs and generated build trees.

- [ ] **Step 3: Run full automated acceptance**

  Run clean tests, full build, JAR content checks, ASM verification, install/restore round trip, forbidden-artifact scan, and `git diff --check`.

- [ ] **Step 4: Perform isolated game-root smoke installation**

  Install into a copied minimal fixture first, then verify the real game only with explicit backup and hash checks. Confirm no `Zomboid/mods/EtherHack` path is created.

- [ ] **Step 5: Complete manual game checklist**

  Verify main-menu startup, logo, Lua reset, Insert menu toggle, every tab construction, status locks, weapon edit, XP, vehicle operations, teleport, ESP alignment, uninstall, and absence of console errors.

- [ ] **Step 6: Final review and commits**

  Review each task diff against this plan, run fresh verification, commit by accepted work package, push `codex/b42-remigration`, and report any game-only checks that still require user observation.

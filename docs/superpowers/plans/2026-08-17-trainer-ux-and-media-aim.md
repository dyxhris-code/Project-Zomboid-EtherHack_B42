# EtherTrainer Media, Item Navigation, Layout, and Aim Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:executing-plans to implement this plan task-by-task.

**Goal:** Make television XP reliable on B42.20.3, give the item creator module/category/item navigation, stabilize window geometry, and expose configurable auto-aim as its own page.

**Architecture:** Keep the existing root `EtherMain` and Lua panel architecture. Move item grouping into `EtherItemCreator` with a three-level breadcrumb/state flow, keep item rows focused on selection and grant actions, persist only validated window geometry, and add an `EtherAimPanel` backed by explicit Java getters/setters on the existing `AutoAimController`. Replace the current media path's unreliable direct broadcast call with a native device/television selection and guarded transmission path that reports a reason when unavailable.

**Tech Stack:** Project Zomboid B42.20.3 Java API, Kahlua Lua UI, existing Gradle/JDK25 checks, source-level integration tests.

## Global Constraints

- Preserve existing user-owned changes and do not add a standalone server extension.
- Target Project Zomboid B42.20.3 and JDK25.
- Use existing EtherTrainer Lua panels and `ISLayoutManager`; no new UI framework.
- Every behavior change gets a focused failing source-level test before implementation.
- Multiplayer media/item actions remain permission-aware and must fall back without crashing.

### Task 1: Rebuild Television XP Route

**Files:**
- Modify: `src/main/java/EtherHack/features/MediaXpController.java`
- Modify: `src/main/java/EtherHack/Ether/EtherLuaMethods.java`
- Modify: `src/main/resources/EtherHack/lua/components/ui/UIModalAddXP.lua`
- Modify: `src/main/resources/EtherHack/translations/CN.txt`
- Modify: `src/main/resources/EtherHack/translations/EN.txt`
- Test: `src/test/java/EtherHack/features/MediaXpIntegrationTest.java`

**Steps:**
- [x] Add and run the failing media-route assertion.
- [x] Implement the mode-aware B42 radio dispatcher, television selection, and Lua failure reason.
- [x] Update the dialog to show the failure reason.
- [x] Run focused media and Lua tests.

### Task 2: Three-Level Item Navigation

**Files:**
- Modify: `src/main/resources/EtherHack/lua/components/panels/EtherItemCreator.lua`
- Modify: `src/main/resources/EtherHack/lua/components/ui/UIItemTables.lua`
- Modify: `src/main/resources/EtherHack/translations/CN.txt`
- Modify: `src/main/resources/EtherHack/translations/EN.txt`
- Test: `src/test/java/EtherHack/ui/LuaUiArchitectureTest.java`

**Steps:**
- [x] Add and run failing source assertions for module/category/item navigation.
- [x] Implement module index -> category index -> item table flow with breadcrumb/back control.
- [x] Keep filters and grant controls scoped to the selected category list.
- [x] Run focused UI and Lua tests.

### Task 3: Stable Resizing and Layout Persistence

**Files:**
- Modify: `src/main/resources/EtherHack/lua/EtherHackMenu.lua`
- Modify: `src/main/resources/EtherHack/lua/components/ui/UIButtonsPanel.lua`
- Modify: `src/main/resources/EtherHack/lua/components/panels/EtherItemCreator.lua`
- Test: `src/test/java/EtherHack/migration/LuaCompatibilityTest.java`

**Steps:**
- [x] Add and run failing resize-coalescing assertions.
- [x] Add resize re-entry/duplicate-size guards and persist validated dimensions through the existing layout manager.
- [x] Run UI/migration tests and inspect the diff.

### Task 4: Dedicated Configurable Aim Page

**Files:**
- Modify: `src/main/java/EtherHack/features/AutoAimController.java`
- Modify: `src/main/java/EtherHack/Ether/EtherAPI.java`
- Modify: `src/main/java/EtherHack/Ether/EtherLuaMethods.java`
- Create: `src/main/resources/EtherHack/lua/components/panels/EtherAimPanel.lua`
- Modify: `src/main/resources/EtherHack/lua/EtherHackMenu.lua`
- Modify: `src/main/resources/EtherHack/lua/components/panels/EtherCharacterPanel.lua`
- Modify: `src/main/resources/EtherHack/translations/CN.txt`
- Modify: `src/main/resources/EtherHack/translations/EN.txt`
- Test: `src/test/java/EtherHack/features/AutoAimIntegrationTest.java`

**Steps:**
- [x] Add and run failing aim integration assertions.
- [x] Add normalized target-part/target-display settings, persistence, Lua bridge, dedicated page, and navigation registration.
- [x] Add the existing overlay's locked-target status line.
- [x] Run focused aim tests, Lua syntax, and full `gradlew check` with JDK25.

### Task 5: Package and Runtime Verification

**Files:**
- No source changes unless verification finds a regression.

**Steps:**
- [x] Run `git diff --check`.
- [x] Run direct feature tests for media, items, UI, and aim.
- [x] Run `gradlew.bat check -PpzHome=D:\Apps\Steam\steamapps\common\ProjectZomboid` with JDK25.
- [x] Rebuild and extract the verified `EtherHack/` directory into the current game root without deleting user config, then verify deployed Lua hashes and required classes.

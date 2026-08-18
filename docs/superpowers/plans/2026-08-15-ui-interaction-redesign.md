# EtherHack UI Interaction Redesign Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use subagent-driven development to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** 将 EtherHack 的 B42 Lua 界面升级为清晰、可发现、状态可保持且有即时反馈的工具型界面。

**Architecture:** 在现有 ISUI 架构上增加轻量设计令牌与复用控件，不引入外部运行时。主窗口负责 shell、标题、导航和状态反馈；页面继续保留现有业务边界，通过统一 section、布局和安全选择契约渐进迁移。

**Tech Stack:** Project Zomboid B42.20.2 ISUI Lua、Java 25 静态契约测试、现有 Gradle migration test suite。

## Global Constraints

- 保留现有黑灰工具风格和用户可配置 accent color。
- 不覆盖工作区已有的 B42 迁移、自动瞄准和权限修复改动。
- 所有页面必须在 `760x520` 最小窗口和更大窗口中保持可用。
- CN/EN 翻译键必须对称；RU 缺失时继续使用现有英文回退。
- 所有危险操作必须确认，所有无选择操作必须禁用或安全返回。
- 页面切换必须保留滚动、筛选和选择状态。

---

### Task 1: UI Theme And Shell

**Files:**
- Create: `src/main/resources/EtherHack/lua/components/ui/UITheme.lua`
- Modify: `src/main/resources/EtherHack/lua/EtherHackMenu.lua`
- Modify: `src/main/resources/EtherHack/lua/components/ui/UIButtonsPanel.lua`
- Modify: `src/main/resources/EtherHack/translations/CN.txt`
- Modify: `src/main/resources/EtherHack/translations/EN.txt`

**Interfaces:**
- Produces: `UITheme.colors`, `UITheme.spacing`, `UITheme.metrics`, `UITheme.resolveAccent()`.
- Produces: `UIButtonsPanel:addButton(iconPath, title, tooltip, panelTag)` and cached `self.panels[id]`.

- [ ] **Step 1: Write failing UI shell contract tests**

Add assertions that the theme module is required first, navigation entries include title/tooltip keys, panels are cached, the close button exists, and the resize widget follows the lower-right corner.

- [ ] **Step 2: Run the focused test and confirm the missing contracts fail**

Run: `java -cp build/classes/java/test EtherHack.ui.LuaUiArchitectureTest`

- [ ] **Step 3: Implement theme tokens and the main shell**

Use a 176px labelled navigation rail, 36px title bar, explicit close button, active-page title, hoverable navigation rows, clamped screen position, and anchored resize handle.

- [ ] **Step 4: Cache panels instead of recreating them**

Create each panel once, hide/show on tab changes, and preserve selection, filters and scrolling.

- [ ] **Step 5: Run focused tests**

Expected: shell contracts pass and Lua syntax remains valid.

### Task 2: Interactive Common Controls

**Files:**
- Modify: `src/main/resources/EtherHack/lua/components/ui/UIButton.lua`
- Modify: `src/main/resources/EtherHack/lua/components/ui/UICheckbox.lua`
- Modify: `src/main/resources/EtherHack/lua/components/ui/UISlider.lua`
- Create: `src/main/resources/EtherHack/lua/components/ui/UISection.lua`
- Create: `src/main/resources/EtherHack/lua/components/ui/UIFeedback.lua`

**Interfaces:**
- `UIButton:setEnabled(enabled, reason)`, `UIButton:isEnabled()`, `UIButton:setTooltip(text)`.
- `UICheckbox:setChecked(value, notify)`, `UICheckbox:getChecked()`, `UICheckbox:setEnabled(enabled, reason)`.
- `UISlider:setValue(value, notify)`, `UISlider:getValue()`, `UISlider:setEnabled(enabled, reason)`.
- `UIFeedback.show(message, kind)` for success, warning and error status.

- [ ] **Step 1: Add failing control contracts**

Assert consistent enabled APIs, corrected checkbox hit width, slider range protection, hover state, tooltip support and compatibility aliases.

- [ ] **Step 2: Implement normal/hover/pressed/focused/disabled states**

Keep controls at least 28px high, avoid constructor-driven overflow, and provide visible disabled reasons.

- [ ] **Step 3: Correct input behavior**

Fix boolean-precedence guards, checkbox naming, slider clamping/step/maximum-thumb bounds and callback duplication.

- [ ] **Step 4: Run focused contracts and Lua parsing**

Expected: controls pass static contracts and all Lua modules parse.

### Task 3: High-Frequency Page Hierarchy

**Files:**
- Modify: `src/main/resources/EtherHack/lua/components/panels/EtherCharacterPanel.lua`
- Modify: `src/main/resources/EtherHack/lua/components/panels/EtherVisualsPanel.lua`
- Modify: `src/main/resources/EtherHack/lua/components/panels/EtherExploitPanel.lua`
- Modify: `src/main/resources/EtherHack/lua/components/panels/EtherSettingsPanel.lua`
- Modify: `src/main/resources/EtherHack/translations/CN.txt`
- Modify: `src/main/resources/EtherHack/translations/EN.txt`

**Interfaces:**
- Pages consume `UISection` and `UIFeedback`.
- Top-flow controls anchor to top/left and use relayout rather than bottom-only anchors.

- [ ] **Step 1: Add failing page hierarchy tests**

Assert section titles, top anchors, status feedback calls, safe config selection, confirmation for delete/reset, and no direct admin-role claims.

- [ ] **Step 2: Group Character controls**

Create protection, combat, movement/world, inventory and needs sections with compact two-column layout where width permits.

- [ ] **Step 3: Group Visuals and Tools**

Separate global rendering, entities and labels; rename Exploit presentation to Tools and separate local utilities from server-controlled/debug operations.

- [ ] **Step 4: Rebuild Settings hierarchy**

Create profile, appearance and maintenance sections; show feedback after save/load/delete; guard empty selection and confirm destructive actions.

- [ ] **Step 5: Run page contracts**

Expected: sections, safe actions and feedback contracts pass.

### Task 4: Data Views, Map And Modals

**Files:**
- Modify: `src/main/resources/EtherHack/lua/components/ui/UIItemTables.lua`
- Modify: `src/main/resources/EtherHack/lua/components/ui/UISkillTable.lua`
- Modify: `src/main/resources/EtherHack/lua/components/ui/UITraitsTable.lua`
- Modify: `src/main/resources/EtherHack/lua/components/panels/EtherItemCreator.lua`
- Modify: `src/main/resources/EtherHack/lua/components/panels/EtherPlayerEditor.lua`
- Modify: `src/main/resources/EtherHack/lua/components/panels/EtherMapPanel.lua`
- Modify: `src/main/resources/EtherHack/lua/components/ui/UIModalAddXP.lua`
- Modify: `src/main/resources/EtherHack/lua/components/ui/UIModalAddTrait.lua`

**Interfaces:**
- All list actions guard `selected` before dereference.
- Selected row rendering wins over alternating-row rendering.
- Complex panels expose `layoutChildren()` or `onResize()`.

- [ ] **Step 1: Add failing safety and layout contracts**

Assert no unguarded selected-item dereference, selected-row priority, map nil guards, modal validation and responsive relayout hooks.

- [ ] **Step 2: Fix list selection and empty states**

Disable actions until selection exists and display an explicit empty result message.

- [ ] **Step 3: Make Player Editor and Map responsive**

Reflow summary fields, resize table columns, keep map controls attached to the content bounds and guard the no-player state.

- [ ] **Step 4: Standardize modal interaction**

Add title, initial focus, Enter confirmation, Escape close, validation and inline error feedback.

- [ ] **Step 5: Run focused tests**

Expected: empty-state and resize contracts pass.

### Task 5: Acceptance Verification

**Files:**
- Create: `src/test/java/EtherHack/ui/LuaUiArchitectureTest.java`
- Modify: `src/test/java/EtherHack/migration/MigrationTestSuite.java`

- [ ] **Step 1: Run `gradlew check` with JDK 25 and B42.20.2**

Run: `gradlew check -PpzHome=D:\Apps\Steam\steamapps\common\ProjectZomboid`

Expected: environment, compile, Lua parsing, migration, installer round-trip, ASM verification and JAR hygiene all pass.

- [ ] **Step 2: Run diff hygiene checks**

Run: `git diff --check`

Expected: no whitespace errors.

- [ ] **Step 3: Perform visual acceptance**

Verify 760x520 and expanded layouts, CN/EN text, main-menu/in-game empty states, navigation state retention, disabled reasons and destructive confirmations. Record any item that cannot be exercised without launching a dedicated B42 session as residual manual validation.

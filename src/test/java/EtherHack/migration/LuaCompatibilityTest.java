package EtherHack.migration;

import java.io.IOException;
import java.io.InputStream;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.stream.Stream;

public final class LuaCompatibilityTest {
    private static final Path LUA_ROOT = Path.of("src/main/resources/EtherHack/lua");
    private static final Path GAME_LUA_ROOT = Path.of(
            System.getenv().getOrDefault(
                    "PZ_GAME_DIR",
                    "D:/Apps/Steam/steamapps/common/ProjectZomboid"))
            .resolve("media/lua");
    private static final Pattern REQUIRE = Pattern.compile("(?m)^\\s*require\\s*[\\( ]?\\s*[\"']([^\"']+)[\"']");
    private static final Pattern TRANSLATION_KEY = Pattern.compile("(?m)^\\s*([A-Za-z0-9_]+)\\s*=");

    private LuaCompatibilityTest() {
    }

    public static void main(String[] args) throws Exception {
        rejectsStaleB41Symbols();
        usesNativeB42ItemEditor();
        guardsVehicleLookup();
        usesServerAuthoritativeItemGrant();
        avoidsNativeAdminPowerSynchronization();
        guardsB42UiLifecycleState();
        guardsOptionalB42WorldSystems();
        usesNativeB42CenteredTextDrawing();
        rejectsRemovedInfoPanelAntiCheatStatus();
        supportsResizableMainWindow();
        anchorsSizeSensitivePanelContent();
        guardsB42PlayerEditorProfileData();
        usesB42CharacterTraitsApi();
        labelsRoleIndependentTimedActions();
        usesQuietEnglishTranslationFallback();
        providesCurrentChineseTranslations();
        resolvesLuaRequires();
        parsesLuaSyntaxWhenCompilerIsAvailable();
    }

    private static void rejectsStaleB41Symbols() throws IOException {
        List<String> forbidden = List.of(
                "sendAddXp",
                "getPlayerCraftingUI",
                "EtherAdminMenu",
                "EtherDebugMenu",
                "EtherDebugClient",
                "EtherDebugServer");
        List<String> failures = new ArrayList<>();

        for (Path file : luaFiles()) {
            String source = Files.readString(file);
            for (String symbol : forbidden) {
                if (source.contains(symbol)) {
                    failures.add(relative(file) + " contains " + symbol);
                }
            }
        }

        require(failures.isEmpty(), "Stale B41 Lua references:\n" + String.join("\n", failures));
    }

    private static void usesNativeB42ItemEditor() throws IOException {
        String source = read("components/override/EtherEditInventoryItem.lua");
        require(source.contains("ISItemEditorUI.OpenPanel("),
                "EtherEditInventoryItem must call the B42 native ISItemEditorUI.OpenPanel API");
        require(!source.contains("ISItemEditorUI:new("),
                "EtherEditInventoryItem must not construct the copied B41 editor directly");
    }

    private static void guardsVehicleLookup() throws IOException {
        String mechanics = read("components/ui/UIMechanics.lua");
        require(mechanics.contains("local function getEtherMechanicsVehicle(player)"),
                "UIMechanics must centralize B42 vehicle lookup");
        require(mechanics.contains("if player == nil then return nil end"),
                "UIMechanics vehicle lookup must guard a missing player");
        require(!mechanics.contains("self.localPlayer:getNearVehicle()"),
                "UIMechanics must not dereference a missing player or vehicle directly");
    }

    private static void usesServerAuthoritativeItemGrant() throws IOException {
        String source = read("components/ui/UIItemTables.lua");
        require(source.contains("SendCommandToServer(\"/additem"),
                "Multiplayer item grants must use the B42 server-authoritative additem command");
        require(source.contains("if isClient() then"),
                "Item grants must preserve the local single-player path");
    }

    private static void avoidsNativeAdminPowerSynchronization() throws IOException {
        String source = read("components/panels/EtherCharacterPanel.lua");
        require(source.contains("toggleBuildCheat(isChecked)"),
                "Build cheat must use EtherHack's role-independent local toggle");
        require(source.contains("toggleFarmingCheat(isChecked)"),
                "Farming cheat must use EtherHack's role-independent local toggle");
        require(!source.contains("sendPlayerExtraInfo(player)"),
                "Local cheat toggles must not require server admin-power synchronization");
    }

    private static void guardsB42UiLifecycleState() throws IOException {
        String editor = read("components/panels/EtherPlayerEditor.lua");
        require(editor.contains("if profession ~= nil then"),
                "Player editor must handle removed or unknown B42 professions");

        String exploit = read("components/panels/EtherExploitPanel.lua");
        require(!exploit.contains("isBypassDebugMode")
                        && !exploit.contains("toggleBypassDebugMode"),
                "Exploit panel must not call the removed B42 debug-bypass API");
        require(exploit.contains("if CharacterCreationProfession.instance ~= nil then"),
                "Trait-point controls must only access the character-creation screen while it exists");
    }

    private static void guardsOptionalB42WorldSystems() throws IOException {
        String source = read("components/override/EtherEditWorldObjects.lua");
        require(source.contains("CMetalDrumSystem.instance ~= nil"),
                "World debug menu must guard the optional B42 metal-drum client system");
        require(source.contains("CRainBarrelSystem.instance ~= nil"),
                "World debug menu must guard the optional B42 rain-barrel client system");
    }

    private static void usesNativeB42CenteredTextDrawing() throws IOException {
        String source = read("components/panels/EtherInfoPanel.lua");
        require(source.contains("self:drawTextCentre("),
                "Information panel must use the native B42 centered-text API");
        require(!source.contains("function EtherInfoPanel:drawTextCentered"),
                "Information panel must not retain its fragile legacy centered-text wrapper");
    }

    private static void rejectsRemovedInfoPanelAntiCheatStatus() throws IOException {
        String source = read("components/panels/EtherInfoPanel.lua");
        require(!source.contains("getAntiCheat12Status")
                        && !source.contains("getAntiCheat8Status")
                        && !source.contains("AntiCheatStatus"),
                "EtherInfoPanel must not render the removed anti-cheat detection subsystem");
    }

    private static void supportsResizableMainWindow() throws IOException {
        String menu = read("EtherHackMenu.lua");
        require(menu.contains("require \"ISUI/ISResizeWidget\""),
                "EtherHack menu must use the native B42 resize widget");
        require(menu.contains("EtherMain.minimumWidth") && menu.contains("EtherMain.minimumHeight"),
                "EtherHack menu must enforce usable minimum dimensions");
        require(menu.contains("ISResizeWidget:new("),
                "EtherHack menu must expose a bottom-right resize handle");
        require(menu.contains("function EtherMain:resizeTo(width, height)"),
                "EtherHack menu must centralize resize layout updates");
        require(menu.contains("if self.isResizing then return end")
                        && menu.contains("self.lastResizeWidth")
                        && menu.contains("self.lastResizeHeight"),
                "EtherHack menu must coalesce resize callbacks to prevent UI jitter");
        require(menu.contains("ISLayoutManager.RegisterWindow(\"EtherHackMain\""),
                "EtherHack menu must persist its geometry through the B42 layout manager");

        String buttons = read("components/ui/UIButtonsPanel.lua");
        require(buttons.contains("panel:setAnchorRight(false)")
                        && buttons.contains("function UIButtonsPanel:layoutPanel(panel)"),
                "The active EtherHack tab must use explicit root-window layout without anchor drift");
    }

    private static void anchorsSizeSensitivePanelContent() throws IOException {
        String itemCreator = read("components/panels/EtherItemCreator.lua");
        require(itemCreator.contains("function EtherItemCreator:layoutChildren()")
                        && itemCreator.contains("self.itemTable:setWidth(itemWidth)"),
                "Item-creator columns must be recalculated from the current panel size");
        String itemTables = read("components/ui/UIItemTables.lua");
        require(itemTables.contains("self.datas:setAnchorRight(true)")
                        && itemTables.contains("self.datas:setAnchorBottom(true)"),
                "Item-creator lists must grow with their tab view");

        String map = read("components/panels/EtherMapPanel.lua");
        require(map.contains("self.map:setAnchorRight(true)")
                        && map.contains("self.map:setAnchorBottom(true)"),
                "The world map must grow with its panel");

        String editor = read("components/panels/EtherPlayerEditor.lua");
        require(editor.contains("self.traitsPanel:setAnchorRight(true)")
                        && editor.contains("self.skillPanel:setAnchorRight(true)"),
                "Player-editor tables must grow horizontally with their panel");
        require(editor.contains("self:setScrollChildren(true)")
                        && editor.contains("self:addScrollBars()"),
                "The player editor must remain usable at the minimum window height");
        String traits = read("components/ui/UITraitsTable.lua");
        String skills = read("components/ui/UISkillTable.lua");
        require(traits.contains("self.datas:setAnchorRight(true)")
                        && skills.contains("self.datas:setAnchorRight(true)"),
                "Player-editor list contents must grow with their table containers");
    }

    private static void guardsB42PlayerEditorProfileData() throws IOException {
        String editor = read("components/panels/EtherPlayerEditor.lua");
        require(editor.contains("local descriptor = self.localPlayer:getDescriptor()")
                        && editor.contains("if descriptor ~= nil then"),
                "Player editor must tolerate a temporarily unavailable multiplayer descriptor");
        require(editor.contains("descriptor:getCharacterProfession()")
                        && editor.contains("CharacterProfessionDefinition.getCharacterProfessionDefinition"),
                "Player editor must use the B42 character-profession API");
        require(!editor.contains(":getProfession()")
                        && !editor.contains("ProfessionFactory.getProfession"),
                "Player editor must not call the removed B41 profession API");
    }

    private static void usesB42CharacterTraitsApi() throws IOException {
        String traitsTable = read("components/ui/UITraitsTable.lua");
        require(traitsTable.contains("getCharacterTraits():getKnownTraits()")
                        && traitsTable.contains("CharacterTraitDefinition.getCharacterTraitDefinition")
                        && traitsTable.contains("getCharacterTraits():remove("),
                "Traits table must use B42 character-traits accessors");
        require(!traitsTable.contains("getTraits()") && !traitsTable.contains("TraitFactory"),
                "Traits table must not call B41 trait APIs");

        String modal = read("components/ui/UIModalAddTrait.lua");
        require(modal.contains("CharacterTraitDefinition.getTraits()")
                        && modal.contains("getCharacterTraits():get(")
                        && modal.contains("getCharacterTraits():add("),
                "Trait picker must use B42 character-traits definitions and mutations");
        require(!modal.contains("self.localPlayer:getTraits()") && !modal.contains("TraitFactory"),
                "Trait picker must not call B41 trait APIs");
    }

    private static void labelsRoleIndependentTimedActions() throws IOException {
        Path translations = Path.of("src/main/resources/EtherHack/translations");
        String chinese = Files.readString(translations.resolve("CN.txt"));
        String english = Files.readString(translations.resolve("EN.txt"));
        require(chinese.contains("UI_CharacterPanel_TimedActionCheat = \"动作瞬间完成\""),
                "Chinese timed-action label must describe the role-independent feature");
        require(english.contains("UI_CharacterPanel_TimedActionCheat = \"Instant timed actions\""),
                "English timed-action label must describe the role-independent feature");
    }

    private static void usesQuietEnglishTranslationFallback() throws IOException {
        String source = Files.readString(
                Path.of("src/main/java/EtherHack/Ether/EtherTranslator.java"));
        require(!source.contains("No translations for language code"),
                "Missing-language fallback must not log once per translated label and rendered frame");
        require(source.contains("this.translations.get(\"EN\")"),
                "Unsupported game languages must retain the English fallback");
    }

    private static void providesCurrentChineseTranslations() throws IOException {
        Path translations = Path.of("src/main/resources/EtherHack/translations");
        Path chinese = translations.resolve("CN.txt");
        require(Files.isRegularFile(chinese),
                "The B42 migration must include the Chinese translation from the B42.18 branch");

        String englishSource = Files.readString(translations.resolve("EN.txt"));
        String chineseSource = Files.readString(chinese);
        List<String> missing = translationKeys(englishSource).stream()
                .filter(key -> !translationKeys(chineseSource).contains(key))
                .toList();
        require(missing.isEmpty(), "Chinese translation is missing keys: " + missing);
        require(!chineseSource.contains("EtherDebug")
                        && !chineseSource.contains("AntiCheatStatus"),
                "Chinese text must describe the current B41-style architecture");
    }

    private static List<String> translationKeys(String source) {
        List<String> keys = new ArrayList<>();
        Matcher matcher = TRANSLATION_KEY.matcher(source);
        while (matcher.find()) {
            keys.add(matcher.group(1));
        }
        return keys;
    }

    private static void resolvesLuaRequires() throws IOException {
        List<String> missing = new ArrayList<>();
        for (Path file : luaFiles()) {
            Matcher matcher = REQUIRE.matcher(Files.readString(file));
            while (matcher.find()) {
                String module = matcher.group(1);
                if (!moduleExists(module)) {
                    missing.add(relative(file) + " requires missing module " + module);
                }
            }
        }
        require(missing.isEmpty(), "Missing Lua modules:\n" + String.join("\n", missing));
    }

    private static void parsesLuaSyntaxWhenCompilerIsAvailable() throws Exception {
        Class<?> compiler;
        Class<?> table;
        try {
            compiler = Class.forName("se.krka.kahlua.luaj.compiler.LuaCompiler");
            table = Class.forName("se.krka.kahlua.vm.KahluaTable");
        } catch (ClassNotFoundException ignored) {
            return;
        }

        Method load = compiler.getMethod("loadis", InputStream.class, String.class, table);
        List<String> failures = new ArrayList<>();
        for (Path file : luaFiles()) {
            try (InputStream input = Files.newInputStream(file)) {
                load.invoke(null, input, relative(file), null);
            } catch (InvocationTargetException exception) {
                failures.add(relative(file) + ": " + exception.getCause());
            }
        }
        require(failures.isEmpty(), "Lua syntax errors:\n" + String.join("\n", failures));
    }

    private static boolean moduleExists(String module) {
        String normalized = module.endsWith(".lua") ? module : module + ".lua";
        if (Path.of("src/main/resources").resolve(normalized).toFile().isFile()) {
            return true;
        }
        return Stream.of("client", "shared", "server")
                .map(GAME_LUA_ROOT::resolve)
                .map(root -> root.resolve(normalized))
                .anyMatch(Files::isRegularFile);
    }

    private static List<Path> luaFiles() throws IOException {
        try (Stream<Path> files = Files.walk(LUA_ROOT)) {
            return files.filter(path -> path.toString().endsWith(".lua")).toList();
        }
    }

    private static String read(String relativePath) throws IOException {
        return Files.readString(LUA_ROOT.resolve(relativePath));
    }

    private static String relative(Path file) {
        return LUA_ROOT.relativize(file).toString().replace('\\', '/');
    }

    private static void require(boolean condition, String message) {
        if (!condition) {
            throw new AssertionError(message);
        }
    }
}

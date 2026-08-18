package EtherHack.ui;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;

public final class LuaUiArchitectureTest {
    private static final Path LUA_ROOT = Path.of("src/main/resources/EtherHack/lua");

    private LuaUiArchitectureTest() {
    }

    public static void main(String[] args) throws IOException {
        usesAThemeDrivenApplicationShell();
        keepsNavigationDiscoverableAndStateful();
        providesConsistentInteractiveControls();
        groupsHighFrequencyPages();
        guardsSelectionAndEmptyStates();
    }

    private static void usesAThemeDrivenApplicationShell() throws IOException {
        String menu = read("EtherHackMenu.lua");
        require(Files.isRegularFile(LUA_ROOT.resolve("components/ui/UITheme.lua")),
                "The UI must provide shared theme tokens");
        require(menu.contains("UITheme.lua")
                        && menu.contains("EtherMain.minimumWidth      = 760")
                        && menu.contains("EtherMain.minimumHeight     = 520"),
                "The main shell must load the theme and enforce the redesigned usable minimum size");
        require(menu.contains("self.closeButton")
                        && menu.contains("function EtherMain:layoutChildren()")
                        && menu.contains("self.closeButton:setX(")
                        && menu.contains("self.resizeWidget:setY("),
                "The shell must use one explicit layout pass for close and resize controls");
        require(menu.contains("EtherMain.instance:close()"),
                "Keyboard and title-bar close actions must share the same cleanup path");
    }

    private static void keepsNavigationDiscoverableAndStateful() throws IOException {
        String menu = read("EtherHackMenu.lua");
        String navigation = read("components/ui/UIButtonsPanel.lua");
        require(menu.contains("UI_Navigation_Overview")
                        && menu.contains("UI_Navigation_Character")
                        && menu.contains("UI_Navigation_Items")
                        && menu.contains("UI_Navigation_Player")
                        && menu.contains("UI_Navigation_Visuals")
                        && menu.contains("UI_Navigation_Map")
                        && menu.contains("UI_Navigation_Tools")
                        && menu.contains("UI_Navigation_Settings"),
                "Every navigation icon must have a translated accessible title");
        require(menu.contains("getTranslate(\"UI_Navigation_Overview\")")
                        && menu.contains("getTranslate(\"UI_Navigation_Overview_Tooltip\")")
                        && menu.contains("getTranslate(\"UI_Common_Close\")")
                        && !menu.contains("getText(\"UI_Navigation_"),
                "The shell must resolve EtherHack navigation and close text through its own translator");
        require(navigation.contains("menuTableData.panels = {}")
                        && navigation.contains("self.panels[id]")
                        && navigation.contains("if id == nil or id < 1 or id > #self.buttons then"),
                "Navigation must validate IDs and cache panel instances so page state survives tab changes");
        require(navigation.contains("button.tooltip"),
                "Navigation controls must explain their destination on hover");
    }

    private static void providesConsistentInteractiveControls() throws IOException {
        String button = read("components/ui/UIButton.lua");
        String checkbox = read("components/ui/UICheckbox.lua");
        String slider = read("components/ui/UISlider.lua");

        for (String source : new String[] {button, checkbox, slider}) {
            require(source.contains("function ") && source.contains(":setEnabled("),
                    "Every custom control must expose setEnabled");
            require(source.contains(":isEnabled()"),
                    "Every custom control must expose isEnabled");
        }
        require(button.contains("self.mouseOver") && button.contains("self.tooltip"),
                "Buttons must have hover and tooltip feedback");
        require(checkbox.contains("function UICheckbox:setChecked(")
                        && checkbox.contains("function UICheckbox:getChecked(")
                        && !checkbox.contains("setCheked")
                        && checkbox.contains("uiTableData.width = uiTableData.textureWidth"),
                "Checkbox state and hit bounds must use the corrected public API");
        require(slider.contains("function UISlider:setValue(")
                        && slider.contains("function UISlider:getValue(")
                        && slider.contains("self.width - self.sliderThumbSize.width")
                        && slider.contains("if self.maxValue <= self.minValue then"),
                "Sliders must clamp values and keep the thumb inside a valid track");
    }

    private static void groupsHighFrequencyPages() throws IOException {
        String character = read("components/panels/EtherCharacterPanel.lua");
        String visuals = read("components/panels/EtherVisualsPanel.lua");
        String tools = read("components/panels/EtherExploitPanel.lua");
        String settings = read("components/panels/EtherSettingsPanel.lua");

        require(character.contains("UI_CharacterSection_Protection")
                        && character.contains("UI_CharacterSection_Combat")
                        && character.contains("UI_CharacterSection_Needs"),
                "Character toggles must be divided into meaningful sections");
        require(visuals.contains("UI_VisualsSection_Global")
                        && visuals.contains("UI_VisualsSection_Entities")
                        && visuals.contains("UI_VisualsSection_Labels"),
                "Visual controls must be grouped by responsibility");
        require(tools.contains("UI_ToolsSection_Local")
                        && tools.contains("UI_ToolsSection_Debug")
                        && tools.contains("UI_ToolsSection_Server"),
                "Tools must distinguish local, debug and server-controlled operations");
        require(settings.contains("UI_SettingsSection_Profiles")
                        && settings.contains("UI_SettingsSection_Appearance")
                        && settings.contains("UI_SettingsSection_Maintenance"),
                "Settings must separate profiles, appearance and maintenance");
    }

    private static void guardsSelectionAndEmptyStates() throws IOException {
        String items = read("components/ui/UIItemTables.lua");
        String itemCreator = read("components/panels/EtherItemCreator.lua");
        String map = read("components/panels/EtherMapPanel.lua");
        String settings = read("components/panels/EtherSettingsPanel.lua");
        require(items.contains("function UIItemTables:getSelectedItem()")
                        && items.contains("local selectedItem = self:getSelectedItem()")
                        && items.contains("if selectedItem == nil then return end"),
                "Item actions must safely handle an empty selection");
        require(itemCreator.contains("self.moduleList = ISScrollingListBox:new(")
                        && itemCreator.contains("self.categoryList = ISScrollingListBox:new(")
                        && itemCreator.contains("self.itemTable = UIItemTables:new(")
                        && itemCreator.contains("function EtherItemCreator:layoutChildren()")
                        && itemCreator.contains("function EtherItemCreator:onModuleSelected(moduleEntry)")
                        && itemCreator.contains("function EtherItemCreator:onCategorySelected(categoryEntry)"),
                "Item creator must provide a scrollable module/category/item master-detail layout");
        require(map.contains("if self.map == nil then return false end"),
                "Map input must tolerate the no-player empty state");
        require(settings.contains("function EtherSettingsPanel:getSelectedConfig()")
                        && settings.contains("local configName = self:getSelectedConfig()"),
                "Configuration actions must guard an empty selection");
    }

    private static String read(String relativePath) throws IOException {
        return Files.readString(LUA_ROOT.resolve(relativePath));
    }

    private static void require(boolean condition, String message) {
        if (!condition) {
            throw new AssertionError(message);
        }
    }
}

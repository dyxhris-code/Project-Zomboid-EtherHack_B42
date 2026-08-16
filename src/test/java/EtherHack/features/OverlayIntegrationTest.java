package EtherHack.features;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;

public final class OverlayIntegrationTest {
    private OverlayIntegrationTest() {
    }

    public static void main(String[] args) throws IOException {
        addsRuntimeOverlayRenderer();
        persistsOverlayTogglesAndExposesLuaApi();
        registersOverlayPanelAndTranslations();
    }

    private static void addsRuntimeOverlayRenderer() throws IOException {
        String source = read("src/main/java/EtherHack/Ether/EtherOverlay.java");
        require(source.contains("@SubscribeLuaEvent(eventName = \"OnPostUIDraw\")"),
                "Overlay must render on the post-UI draw event");
        require(source.contains("getBodyDamage().getHealth()")
                        && source.contains("getCurrentAmmoCount()")
                        && source.contains("getZombieList()")
                        && source.contains("getVehicles()"),
                "Overlay must surface pztrainer-style player and entity diagnostics");
        require(source.contains("Rendering.drawText("),
                "Overlay must use the shared B42 rendering helper");
    }

    private static void persistsOverlayTogglesAndExposesLuaApi() throws IOException {
        String api = read("src/main/java/EtherHack/Ether/EtherAPI.java");
        String lua = read("src/main/java/EtherHack/Ether/EtherLuaMethods.java");
        require(api.contains("isOverlayStatusEnable")
                        && api.contains("isOverlayWeaponInfo")
                        && api.contains("isOverlayEntityCounts"),
                "EtherAPI must own the new overlay toggles");
        require(api.contains("isOverlayStatusEnable\", Boolean.toString(this.isOverlayStatusEnable)")
                        && api.contains("isOverlayWeaponInfo\", Boolean.toString(this.isOverlayWeaponInfo)")
                        && api.contains("isOverlayEntityCounts\", Boolean.toString(this.isOverlayEntityCounts)"),
                "Overlay toggles must be persisted with profiles");
        require(lua.contains("name = \"isOverlayStatusEnable\"")
                        && lua.contains("name = \"toggleOverlayStatus\"")
                        && lua.contains("name = \"isOverlayWeaponInfo\"")
                        && lua.contains("name = \"toggleOverlayWeaponInfo\"")
                        && lua.contains("name = \"isOverlayEntityCounts\"")
                        && lua.contains("name = \"toggleOverlayEntityCounts\""),
                "Overlay toggles must be available to Lua");
    }

    private static void registersOverlayPanelAndTranslations() throws IOException {
        String menu = read("src/main/resources/EtherHack/lua/EtherHackMenu.lua");
        String panel = read("src/main/resources/EtherHack/lua/components/panels/EtherOverlayPanel.lua");
        require(menu.contains("EtherOverlayPanel.lua")
                        && menu.contains("UI_Navigation_Overlay")
                        && menu.contains("EtherOverlayPanel"),
                "Main menu must register the Overlay panel");
        require(panel.contains("toggleOverlayStatus(isChecked)")
                        && panel.contains("toggleOverlayWeaponInfo(isChecked)")
                        && panel.contains("toggleOverlayEntityCounts(isChecked)"),
                "Overlay panel must expose the runtime diagnostics controls");
        for (String language : new String[]{"EN", "CN"}) {
            String translations = read("src/main/resources/EtherHack/translations/" + language + ".txt");
            require(translations.contains("UI_Navigation_Overlay")
                            && translations.contains("UI_OverlayPanel_Status"),
                    language + " translations must include Overlay labels");
        }
    }

    private static String read(String relativePath) throws IOException {
        return Files.readString(Path.of(relativePath));
    }

    private static void require(boolean condition, String message) {
        if (!condition) {
            throw new AssertionError(message);
        }
    }
}

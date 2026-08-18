package EtherHack.features;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;

public final class AutoAimIntegrationTest {
    private AutoAimIntegrationTest() {
    }

    public static void main(String[] args) throws IOException {
        usesTheB42AimingAndVisibilityApis();
        exposesADefaultOffPersistentToggle();
        addsTheDedicatedAimPanelAndTranslations();
    }

    private static void usesTheB42AimingAndVisibilityApis() throws IOException {
        String source = Files.readString(Path.of("src/main/java/EtherHack/features/AutoAimController.java"));

        require(source.contains("player.isAimControlActive()"),
                "Auto aim must only run while the native B42 aim control is active");
        require(source.contains("weapon.isRanged()"),
                "Auto aim must only alter ranged-weapon aiming");
        require(source.contains("IsoWorld.instance == null")
                        && source.contains("IsoWorld.instance.getCell() == null"),
                "Auto aim must guard the B42 world and cell lifecycle");
        require(source.contains("player.CanSee(zombie)"),
                "Auto aim must use the native B42 line-of-sight test");
        require(source.contains("zombie.isVisibleToPlayer[player.getIndex()]"),
                "Auto aim must reject zombies that B42 has not marked visible to the local player");
        require(source.contains("zombie.isAlive()")
                        && source.contains("zombie.isFakeDead()"),
                "Auto aim must reject dead and fake-dead zombies");
        require(source.contains("MAX_TARGET_DISTANCE = 15.0F")
                        && source.contains("MINIMUM_AIM_DOT = 0.70F"),
                "Auto aim must have a finite distance and view cone");
        require(source.contains("player.setTargetAndCurrentDirection("),
                "Auto aim must use the B42 direction API for immediate visual and animation alignment");
        require(source.contains("targetPart")
                        && source.contains("showTarget")
                        && source.contains("getLockedTargetName()"),
                "Auto aim must expose hit-part and locked-target display settings");
        require(!source.contains(".Hit(") && !source.contains("AttemptAttack"),
                "Auto aim must not synthesize attacks or bypass native hit processing");
    }

    private static void exposesADefaultOffPersistentToggle() throws IOException {
        String api = Files.readString(Path.of("src/main/java/EtherHack/Ether/EtherAPI.java"));
        String luaMethods = Files.readString(Path.of("src/main/java/EtherHack/Ether/EtherLuaMethods.java"));
        String patcher = Files.readString(Path.of("src/main/java/EtherHack/GamePatcher.java"));

        require(api.contains("new AutoAimController()"),
                "EtherAPI must own the auto-aim controller");
        require(patcher.contains("patchIsoPlayerAim()")
                        && patcher.contains("\"calculateAimVector\"")
                        && patcher.contains("\"EtherHack/features/AutoAimController\"")
                        && patcher.contains("\"adjustAimVector\""),
                "The installer must pass B42's native aim vector through the auto-aim controller");
        require(api.contains("\"isAutoAimEnabled\", false"),
                "Auto aim must default to disabled when loading configuration");
        require(api.contains("\"isAutoAimEnabled\", Boolean.toString(this.autoAim.isEnabled())"),
                "Auto aim must be saved with the rest of the profile");
        require(luaMethods.contains("name = \"isAutoAimEnabled\"")
                        && luaMethods.contains("name = \"toggleAutoAim\"")
                        && luaMethods.contains("name = \"getAutoAimTargetPart\"")
                        && luaMethods.contains("name = \"setAutoAimTargetPart\"")
                        && luaMethods.contains("name = \"isAutoAimShowTarget\"")
                        && luaMethods.contains("name = \"toggleAutoAimShowTarget\""),
                "Auto aim must expose the standard Lua getter and toggle methods");
    }

    private static void addsTheDedicatedAimPanelAndTranslations() throws IOException {
        String panel = Files.readString(Path.of(
                "src/main/resources/EtherHack/lua/components/panels/EtherAimPanel.lua"));
        String menu = Files.readString(Path.of("src/main/resources/EtherHack/lua/EtherHackMenu.lua"));
        String overlay = Files.readString(Path.of("src/main/java/EtherHack/Ether/EtherOverlay.java"));
        require(panel.contains("setAutoAimTargetPart")
                        && panel.contains("toggleAutoAimShowTarget")
                        && panel.contains("toggleAutoAim(isChecked)"),
                "The dedicated aim panel must provide configuration controls");
        require(menu.contains("EtherAimPanel"),
                "The dedicated aim panel must be registered in EtherTrainer navigation");
        require(overlay.contains("getLockedTargetName()")
                        && overlay.contains("UI_Overlay_AimTarget"),
                "The existing overlay must be able to display the locked target");

        for (String language : new String[]{"EN", "CN"}) {
            String translations = Files.readString(Path.of(
                    "src/main/resources/EtherHack/translations/" + language + ".txt"));
            require(translations.contains("UI_AimPanel_Title")
                            && translations.contains("UI_AimPanel_TargetPart"),
                    language + " translations must include the auto-aim label");
        }
    }

    private static void require(boolean condition, String message) {
        if (!condition) {
            throw new AssertionError(message);
        }
    }
}

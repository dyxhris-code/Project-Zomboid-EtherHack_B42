package EtherHack.features;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;

public final class LocalCheatIntegrationTest {
    private LocalCheatIntegrationTest() {
    }

    public static void main(String[] args) throws IOException {
        patchesTheMultiplayerTimedActionRoleGate();
        appliesCharacterCheatsWithoutCapabilityCheckedSetters();
        routesBuildAndFarmingCheatsThroughTheLocalController();
    }

    private static void patchesTheMultiplayerTimedActionRoleGate() throws IOException {
        String patcher = read("src/main/java/EtherHack/GamePatcher.java");
        require(patcher.contains("patchIsoPlayerTimedAction()")
                        && patcher.contains("\"isTimedActionInstant\"")
                        && patcher.contains("\"EtherHack/features/LocalPlayerCheatController\"")
                        && patcher.contains("\"isTimedActionInstant\""),
                "The installer must let the local EtherHack toggle override B42's None-role timed-action gate");
    }

    private static void appliesCharacterCheatsWithoutCapabilityCheckedSetters() throws IOException {
        String controller = read("src/main/java/EtherHack/features/LocalPlayerCheatController.java");
        String api = read("src/main/java/EtherHack/Ether/EtherAPI.java");

        for (String cheat : new String[] {
                "TIMED_ACTION_INSTANT",
                "GOD_MODE",
                "NO_CLIP",
                "INVISIBLE",
                "ZOMBIES_DONT_ATTACK",
                "UNLIMITED_CARRY",
                "UNLIMITED_ENDURANCE",
                "UNLIMITED_AMMO"}) {
            require(controller.contains("CheatType." + cheat),
                    "Local cheat controller must support " + cheat);
        }
        require(controller.contains("player.getCheats().set(type, enabled)"),
                "Local character cheats must write B42 PlayerCheats directly");
        require(api.contains("LocalPlayerCheatController.applyCharacterCheats("),
                "EtherAPI must apply character toggles through the local cheat controller");
        require(!api.contains("var1.setTimedActionInstantCheat(")
                        && !api.contains("var1.setGodMod(")
                        && !api.contains("var1.setNoClip(")
                        && !api.contains("var1.setInvisible(")
                        && !api.contains("var1.setZombiesDontAttack(")
                        && !api.contains("var1.setUnlimitedCarry(")
                        && !api.contains("var1.setUnlimitedEndurance(")
                        && !api.contains("var1.setUnlimitedAmmo("),
                "EtherAPI must not use B42 setters that clear cheats for roles without capabilities");
    }

    private static void routesBuildAndFarmingCheatsThroughTheLocalController() throws IOException {
        String luaMethods = read("src/main/java/EtherHack/Ether/EtherLuaMethods.java");
        String panel = read("src/main/resources/EtherHack/lua/components/panels/EtherCharacterPanel.lua");

        require(luaMethods.contains("name = \"toggleBuildCheat\"")
                        && luaMethods.contains("name = \"toggleFarmingCheat\""),
                "Build and farming cheats must expose local, role-independent Lua methods");
        require(panel.contains("toggleBuildCheat(isChecked)")
                        && panel.contains("toggleFarmingCheat(isChecked)"),
                "The character panel must use the local build and farming cheat methods");
        require(!panel.contains("player:setBuildCheat(isChecked)")
                        && !panel.contains("player:setFarmingCheat(isChecked)")
                        && !panel.contains("sendPlayerExtraInfo(player)"),
                "The character panel must not use capability-checked or server-admin synchronization paths");
    }

    private static String read(String path) throws IOException {
        return Files.readString(Path.of(path));
    }

    private static void require(boolean condition, String message) {
        if (!condition) {
            throw new AssertionError(message);
        }
    }
}

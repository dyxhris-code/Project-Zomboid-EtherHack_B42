package EtherHack.migration;

import java.nio.file.Files;
import java.nio.file.Path;

public final class B42JavaApiCompatibilityTest {
    private static final Path JAVA_ROOT = Path.of("src/main/java/EtherHack");

    private B42JavaApiCompatibilityTest() {
    }

    public static void main(String[] args) throws Exception {
        verifiesGameplayApiMigration();
        verifiesLogoAndUiMigration();
        verifiesProductBranding();
        verifiesLoggingMigration();
        verifiesScreenCoordinateMigration();
    }

    private static void verifiesGameplayApiMigration() throws Exception {
        String source = read("Ether/EtherAPI.java");

        require(source.contains("import zombie.characters.CharacterStat;"),
                "EtherAPI must use B42 CharacterStat keys");
        require(source.contains("import zombie.characters.Stats;"),
                "EtherAPI must use the B42 Stats container");
        require(source.contains("getCriticalDamageMultiplier()"),
                "Weapon reads must use getCriticalDamageMultiplier");
        require(source.contains("setCriticalDamageMultiplier("),
                "Weapon writes must use setCriticalDamageMultiplier");
        require(!source.contains("CritDmgMultiplier"),
                "Removed B41 critical-damage method names remain");
        require(source.contains("setCharacterStat(var1, CharacterStat.ENDURANCE, 1.0F)"),
                "Endurance must be written through Stats.set");
        require(source.contains("SyncPlayerStatsPacket.getBitMaskForStat(stat)"),
                "Multiplayer body-stat changes must use the B42 stat bit mask");
        require(source.contains("INetworkPacket.send(PacketTypes.PacketType.SyncPlayerStats"),
                "Multiplayer body-stat changes must be sent to the authoritative server");
        require(source.contains("LocalPlayerCheatController.applyCharacterCheats("),
                "Character cheats must bypass B42 capability-checked admin setters locally");
        require(!source.contains("GameClient.sendPlayerExtraInfo(var1);"),
                "Local character cheats must not depend on server admin-power synchronization");
        require(source.contains("this.isDisableFear || this.isDisablePanic"),
                "Fear and panic must have one explicit B42 PANIC policy");
        require(source.contains("CharacterStat.PANIC"),
                "The B42 fear/panic policy must target CharacterStat.PANIC");
        require(source.contains("Set<BaseVehicle>"),
                "B42 IsoCell.getVehicles returns a Set");
        require(!source.contains("!= null || !"),
                "Collection guards must not dereference null values");
        require(source.contains("setIsFakeInfected(false)"),
                "Fake infection reset must use the B42 BodyDamage API");
        require(source.contains("setReduceFakeInfection(true)"),
                "Fake infection reduction must use the B42 BodyDamage API");
    }

    private static void verifiesLogoAndUiMigration() throws Exception {
        String logo = read("Ether/EtherLogo.java");
        String state = read("states/EtherLogoState.java");

        require(logo.contains("GameWindow.states.states"),
                "EtherLogo must use GameStateMachine.states");
        require(logo.contains("GameWindow.states.loopToState"),
                "EtherLogo must use GameStateMachine.loopToState");
        require(!logo.contains(".States") && !logo.contains(".LoopToState"),
                "Removed B41 state-machine fields remain");
        require(state.contains("UIManager.suspend"),
                "EtherLogoState must use UIManager.suspend");
        require(state.contains("UIManager.useUiFbo"),
                "EtherLogoState must use UIManager.useUiFbo");
        require(!state.contains("UIManager.bSuspend") && !state.contains("UIManager.useUIFBO"),
                "Removed B41 UIManager fields remain");
    }

    private static void verifiesLoggingMigration() throws Exception {
        String source = read("utils/Logger.java");

        require(source.contains("DebugLog.log(DebugType.General, message)"),
                "Logger must use the B42 DebugLog API");
        require(source.contains("System.out.println(message)"),
                "Logger must retain a startup-safe console fallback");
        require(!source.contains("DebugLog.General"),
                "Removed B41 DebugLog.General access remains");
    }

    private static void verifiesProductBranding() throws Exception {
        String info = read("utils/Info.java");
        String credits = read("Ether/EtherCredits.java");

        require(info.contains("CHEAT_NAME = \"EtherTrainer\""),
                "Visible product name must be EtherTrainer");
        require(info.contains("CHEAT_TAG = \"[EtherTrainer]: \""),
                "Log watermark must use the EtherTrainer tag");
        require(credits.contains("Info.CHEAT_CREDITS_TITLE"),
                "On-screen watermark must use the centralized product title");
        require(credits.contains("Info.CHEAT_CREDITS_AUTHOR"),
                "On-screen watermark must use centralized credits metadata");
    }

    private static void verifiesScreenCoordinateMigration() throws Exception {
        for (String relative : new String[] {
                "utils/PlayerUtils.java",
                "utils/VehicleUtils.java",
                "utils/ZombieUtils.java"}) {
            String source = read(relative);
            require(source.contains("IsoUtils.XToScreen(var0.getX(), var0.getY(), var0.getZ(), 0)"),
                    relative + " must preserve B41 world-to-screen X projection");
            require(source.contains("IsoUtils.YToScreen(var0.getX(), var0.getY(), var0.getZ(), 0)"),
                    relative + " must preserve B41 world-to-screen Y projection");
            require(source.contains("IsoCamera.getOffX()"),
                    relative + " must preserve the camera X offset");
            require(source.contains("IsoCamera.getOffY()"),
                    relative + " must preserve the camera Y offset");
            require(source.contains("Core.getInstance().getZoom(var1)"),
                    relative + " must preserve player zoom scaling");
            require(source.contains("Core.getTileScale()"),
                    relative + " must use the B42 tile-scale API");
            require(!source.contains("var0.x") && !source.contains("var0.y"),
                    relative + " must not access protected entity coordinates");
        }
    }

    private static String read(String relativePath) throws Exception {
        return Files.readString(JAVA_ROOT.resolve(relativePath));
    }

    private static void require(boolean condition, String message) {
        if (!condition) {
            throw new AssertionError(message);
        }
    }
}

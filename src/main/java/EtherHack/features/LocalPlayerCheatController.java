package EtherHack.features;

import EtherHack.Ether.EtherMain;
import zombie.characters.CheatType;
import zombie.characters.IsoPlayer;

public final class LocalPlayerCheatController {
    private LocalPlayerCheatController() {
    }

    public static boolean isTimedActionInstant(IsoPlayer player) {
        EtherMain etherMain = EtherMain.getInstance();
        return player != null
                && player.isLocalPlayer()
                && etherMain != null
                && etherMain.etherAPI != null
                && etherMain.etherAPI.isTimedActionCheat;
    }

    public static void applyCharacterCheats(
            IsoPlayer player,
            boolean timedActionInstant,
            boolean godMode,
            boolean noClip,
            boolean invisible,
            boolean zombiesDontAttack,
            boolean unlimitedCarry,
            boolean unlimitedEndurance,
            boolean unlimitedAmmo) {
        set(player, CheatType.TIMED_ACTION_INSTANT, timedActionInstant);
        set(player, CheatType.GOD_MODE, godMode);
        set(player, CheatType.NO_CLIP, noClip);
        set(player, CheatType.INVISIBLE, invisible);
        set(player, CheatType.ZOMBIES_DONT_ATTACK, zombiesDontAttack);
        set(player, CheatType.UNLIMITED_CARRY, unlimitedCarry);
        set(player, CheatType.UNLIMITED_ENDURANCE, unlimitedEndurance);
        set(player, CheatType.UNLIMITED_AMMO, unlimitedAmmo);
    }

    public static boolean isBuildCheatEnabled() {
        return isSet(IsoPlayer.getInstance(), CheatType.BUILD);
    }

    public static void setBuildCheatEnabled(boolean enabled) {
        set(IsoPlayer.getInstance(), CheatType.BUILD, enabled);
    }

    public static boolean isFarmingCheatEnabled() {
        return isSet(IsoPlayer.getInstance(), CheatType.FARMING);
    }

    public static void setFarmingCheatEnabled(boolean enabled) {
        set(IsoPlayer.getInstance(), CheatType.FARMING, enabled);
    }

    private static boolean isSet(IsoPlayer player, CheatType type) {
        return player != null && player.getCheats().isSet(type);
    }

    private static void set(IsoPlayer player, CheatType type, boolean enabled) {
        if (player != null && player.getCheats().isSet(type) != enabled) {
            player.getCheats().set(type, enabled);
        }
    }
}

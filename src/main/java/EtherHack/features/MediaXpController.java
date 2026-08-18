package EtherHack.features;

import java.util.IdentityHashMap;
import java.util.Locale;
import java.util.Map;
import zombie.characters.IsoPlayer;
import zombie.characters.skills.PerkFactory;
import zombie.network.GameClient;
import zombie.network.GameServer;
import zombie.radio.ZomboidRadio;
import zombie.radio.devices.DeviceData;
import zombie.radio.devices.WaveSignalDevice;

public final class MediaXpController {
    private static final float MAX_DEVICE_DISTANCE = 5.0F;
    private static final Map<PerkFactory.Perk, String> MEDIA_INTERACTION_CODES = createInteractionCodes();
    private static volatile String lastFailureReason = "";

    private MediaXpController() {
    }

    public static boolean sendXpBroadcast(IsoPlayer player, PerkFactory.Perk perk, float amount) {
        if (player == null || perk == null || amount <= 0.0F || !ZomboidRadio.hasInstance()) {
            lastFailureReason = "TV media bridge is unavailable";
            return false;
        }

        WaveSignalDevice device = findNearestBroadcastDevice(player);
        if (device == null) {
            lastFailureReason = "No powered television with audible volume is nearby";
            return false;
        }

        String interactionCode = MEDIA_INTERACTION_CODES.get(perk);
        if (interactionCode == null) {
            lastFailureReason = "The selected perk cannot receive television XP";
            return false;
        }

        try {
            DeviceData deviceData = device.getDeviceData();
            float xpBefore = player.getXp().getXP(perk);
            String payload = String.format(Locale.ROOT, "%s+%.3f", interactionCode, amount / 50.0F);
            ZomboidRadio.getInstance().SendTransmission(
                    (int) Math.floor(device.getX()) + 1,
                    (int) Math.floor(device.getY()) + 1,
                    deviceData.getChannel(),
                    "",
                    null,
                    payload,
                    0.82F,
                    0.88F,
                    1.0F,
                    -1,
                    deviceData.getIsTelevision());

            if (!GameClient.client && !GameServer.server) {
                float deliveredAmount = player.getXp().getXP(perk) - xpBefore;
                float remainingAmount = amount - deliveredAmount;
                if (remainingAmount > 0.001F) {
                    player.getXp().AddXP(perk, remainingAmount);
                }
            }
            lastFailureReason = "";
            return true;
        } catch (RuntimeException exception) {
            lastFailureReason = "TV transmission failed: " + exception.getMessage();
            return false;
        }
    }

    public static String getLastFailureReason() {
        return lastFailureReason;
    }

    private static WaveSignalDevice findNearestBroadcastDevice(IsoPlayer player) {
        WaveSignalDevice nearest = null;
        float nearestDistance = Float.MAX_VALUE;

        for (WaveSignalDevice device : ZomboidRadio.getInstance().getDevices()) {
            if (device == null || device.getDeviceData() == null) {
                continue;
            }

            DeviceData deviceData = device.getDeviceData();
            if (!deviceData.getIsTelevision()
                    || !deviceData.getIsTurnedOn()
                    || deviceData.getDeviceVolume() <= 0.0F
                    || deviceData.isPlayingMedia()
                    || deviceData.isNoTransmit()) {
                continue;
            }

            float xDistance = Math.abs(player.getX() - device.getX());
            float yDistance = Math.abs(player.getY() - device.getY());
            if (xDistance > MAX_DEVICE_DISTANCE
                    || yDistance > MAX_DEVICE_DISTANCE
                    || Math.floor(player.getZ()) != Math.floor(device.getZ())) {
                continue;
            }

            float distance = xDistance + yDistance;
            if (distance < nearestDistance) {
                nearest = device;
                nearestDistance = distance;
            }
        }

        return nearest;
    }

    private static Map<PerkFactory.Perk, String> createInteractionCodes() {
        Map<PerkFactory.Perk, String> codes = new IdentityHashMap<>();
        codes.put(PerkFactory.Perks.Sprinting, "SPR");
        codes.put(PerkFactory.Perks.Lightfoot, "LFT");
        codes.put(PerkFactory.Perks.Nimble, "NIM");
        codes.put(PerkFactory.Perks.Sneak, "SNE");
        codes.put(PerkFactory.Perks.Axe, "BAA");
        codes.put(PerkFactory.Perks.Blunt, "BUA");
        codes.put(PerkFactory.Perks.Woodwork, "CRP");
        codes.put(PerkFactory.Perks.Cooking, "COO");
        codes.put(PerkFactory.Perks.Farming, "FRM");
        codes.put(PerkFactory.Perks.Doctor, "DOC");
        codes.put(PerkFactory.Perks.Electricity, "ELC");
        codes.put(PerkFactory.Perks.MetalWelding, "MTL");
        codes.put(PerkFactory.Perks.FlintKnapping, "FKN");
        codes.put(PerkFactory.Perks.Carving, "CRV");
        codes.put(PerkFactory.Perks.Aiming, "AIM");
        codes.put(PerkFactory.Perks.Reloading, "REL");
        codes.put(PerkFactory.Perks.Fishing, "FIS");
        codes.put(PerkFactory.Perks.Trapping, "TRA");
        codes.put(PerkFactory.Perks.PlantScavenging, "FOR");
        codes.put(PerkFactory.Perks.Tailoring, "TAI");
        codes.put(PerkFactory.Perks.Mechanics, "MEC");
        codes.put(PerkFactory.Perks.Combat, "CMB");
        codes.put(PerkFactory.Perks.Spear, "SPE");
        codes.put(PerkFactory.Perks.SmallBlunt, "SBU");
        codes.put(PerkFactory.Perks.LongBlade, "LBA");
        codes.put(PerkFactory.Perks.SmallBlade, "SBA");
        codes.put(PerkFactory.Perks.Masonry, "MAS");
        codes.put(PerkFactory.Perks.Pottery, "POT");
        codes.put(PerkFactory.Perks.Blacksmith, "BLA");
        codes.put(PerkFactory.Perks.Glassmaking, "GLA");
        codes.put(PerkFactory.Perks.Husbandry, "HUS");
        codes.put(PerkFactory.Perks.Butchering, "BUT");
        codes.put(PerkFactory.Perks.Tracking, "TRK");
        return codes;
    }
}

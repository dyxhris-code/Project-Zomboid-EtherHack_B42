package EtherHack.features;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;

public final class MediaXpIntegrationTest {
    private MediaXpIntegrationTest() {
    }

    public static void main(String[] args) throws IOException {
        routesXpThroughANearbyBroadcastDevice();
        exposesTheBroadcastRouteToTheXpDialog();
        registersBroadcastXpTranslations();
    }

    private static void routesXpThroughANearbyBroadcastDevice() throws IOException {
        String controller = read("src/main/java/EtherHack/features/MediaXpController.java");
        require(controller.contains("ZomboidRadio.getInstance().getDevices()")
                        && controller.contains("getIsTurnedOn()")
                        && controller.contains("getDeviceVolume()")
                        && controller.contains("isPlayingMedia()")
                        && controller.contains("isNoTransmit()"),
                "Media XP must use a nearby active broadcast device, matching pztrainer's route");
        require(controller.contains("MEDIA_INTERACTION_CODES")
                        && controller.contains("PerkFactory.Perks.Woodwork, \"CRP\"")
                        && controller.contains("PerkFactory.Perks.Cooking, \"COO\"")
                        && controller.contains("PerkFactory.Perks.Aiming, \"AIM\"")
                        && controller.contains("%s+%.3f")
                        && controller.contains("amount / 50.0F")
                        && !controller.contains("perk.getName()"),
                "Media XP must encode the selected perk with the vanilla three-letter interaction code");
        require(controller.contains("deviceData.getChannel()")
                        && controller.contains("ZomboidRadio.getInstance().SendTransmission(")
                        && controller.contains("-1,")
                        && controller.contains("deviceData.getIsTelevision()"),
                "Media XP must submit the interaction code on the selected device channel through the mode-aware dispatcher");
        require(controller.contains("player.getXp().getXP(perk)")
                        && controller.contains("player.getXp().AddXP(perk, remainingAmount)"),
                "Single-player media XP must verify delivery and fill any amount rejected by media cutoff or cooldown rules");
        require(!controller.contains("!GameClient.client || GameClient.connection == null"),
                "Media XP must remain available in single-player without a network client connection");
        require(controller.contains("0.82F")
                        && controller.contains("0.88F")
                        && controller.contains("1.0F")
                        && controller.contains("deviceData.getIsTelevision()"),
                "Media XP must preserve the native broadcast color and television flag");
    }

    private static void exposesTheBroadcastRouteToTheXpDialog() throws IOException {
        String luaMethods = read("src/main/java/EtherHack/Ether/EtherLuaMethods.java");
        String xpModal = read("src/main/resources/EtherHack/lua/components/ui/UIModalAddXP.lua");
        String mediaModal = read("src/main/resources/EtherHack/lua/components/ui/UIModalMediaXP.lua");
        String skills = read("src/main/resources/EtherHack/lua/components/ui/UISkillTable.lua");
        require(luaMethods.contains("name = \"addXpFromNearbyBroadcast\"")
                        && luaMethods.contains("MediaXpController.sendXpBroadcast("),
                "The media XP controller must be exposed to Lua");
        require(!xpModal.contains("addXpFromNearbyBroadcast")
                        && mediaModal.contains("addXpFromNearbyBroadcast(perk:getType(), amount)")
                        && mediaModal.contains("selectedPerks")
                        && mediaModal.contains("getMediaXpFailureReason()")
                        && skills.contains("UIModalMediaXP:new(selectedItem.perk)"),
                "Television XP must be a separate skill action and dialog");
    }

    private static void registersBroadcastXpTranslations() throws IOException {
        for (String language : new String[]{"EN", "CN"}) {
            String translations = read("src/main/resources/EtherHack/translations/" + language + ".txt");
            require(translations.contains("UI_PlayerEditor_PlayerSkills_AddMediaXP"),
                    language + " translations must include the media XP action");
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

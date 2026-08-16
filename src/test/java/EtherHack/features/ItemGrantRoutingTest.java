package EtherHack.features;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;

public final class ItemGrantRoutingTest {
    private static final Path ROOT = Path.of("src/main");

    private ItemGrantRoutingTest() {
    }

    public static void main(String[] args) throws IOException {
        persistsTheSelectedGrantMode();
        routesItemGrantsWithoutAServerExtension();
        usesAOneShotServerWorldObjectForTheThirdRoute();
        removesTheServerExtensionPackage();
        exposesTheModeInSettings();
    }

    private static void persistsTheSelectedGrantMode() throws IOException {
        String api = read("java/EtherHack/Ether/EtherAPI.java");
        String methods = read("java/EtherHack/Ether/EtherLuaMethods.java");
        require(api.contains("ITEM_GRANT_MODE_LOCAL_NATIVE")
                        && api.contains("ITEM_GRANT_MODE_ADMIN_COMMAND")
                        && api.contains("ITEM_GRANT_MODE_SERVER_WORLD_ACTION")
                        && api.contains("itemGrantMode")
                        && api.contains("setProperty(\"itemGrantMode\"")
                        && api.contains("normalizeItemGrantMode("),
                "EtherAPI must persist and normalize the item grant mode");
        require(api.contains("\"automatic\"")
                        && api.contains("\"server-authorized\"")
                        && api.contains("return ITEM_GRANT_MODE_SERVER_WORLD_ACTION"),
                "Legacy automatic and server-authorized profiles must migrate to the server-world-action mode");
        require(methods.contains("name = \"getItemGrantMode\"")
                        && methods.contains("name = \"setItemGrantMode\""),
                "Lua must be able to read and update the item grant mode");
    }

    private static void routesItemGrantsWithoutAServerExtension() throws IOException {
        String items = read("resources/EtherHack/lua/components/ui/UIItemTables.lua");
        require(items.contains("ITEM_GRANT_MODE_LOCAL_NATIVE")
                        && items.contains("ITEM_GRANT_MODE_ADMIN_COMMAND")
                        && items.contains("ITEM_GRANT_MODE_SERVER_WORLD_ACTION"),
                "The item table must route all supported grant modes explicitly");
        require(items.contains("giveItem(itemType, count)")
                        && items.contains("SendCommandToServer(\"/additem")
                        && items.contains("grantItemThroughServerWorldAction(player, itemType, count)"),
                "Each grant mode must use its dedicated native route without an extension");
        require(!items.contains("sendClientCommand(player, \"EtherHack\", \"grantItem\""),
                "Item grants must not depend on an EtherHack server command");
    }

    private static void usesAOneShotServerWorldObjectForTheThirdRoute() throws IOException {
        String items = read("resources/EtherHack/lua/components/ui/UIItemTables.lua");
        String methods = read("java/EtherHack/Ether/EtherLuaMethods.java");
        require(items.contains("require \"TimedActions/ISTakeBricks\"")
                        && methods.contains("PacketTypes.PacketType.AddExplosiveTrap")
                        && methods.contains("new AddExplosiveTrapPacket()")
                        && methods.contains("packet.sendToServer("),
                "The third route must create a server world object through the native explosive-trap packet");
        require(methods.contains("\"Base.Hammer\"")
                        && methods.contains("\"Base.RollingPin\"")
                        && methods.contains("\"Base.Saucepan\"")
                        && methods.contains("\"Base.Fork\"")
                        && methods.contains("hasNoWorldEffects(carrier)")
                        && methods.contains("getExplosionPower() <= 0")
                        && methods.contains("getFireRange() <= 0")
                        && methods.contains("getSmokeRange() <= 0")
                        && methods.contains("getNoiseRange() <= 0")
                        && methods.contains("getSensorRange() <= 0"),
                "The temporary server object must use a verified effect-free carrier");
        require(methods.contains("setRemoteControlID(ITEM_GRANT_PALLET_MARKER)")
                        && items.contains("carrier:getRemoteControlID() == request.marker")
                        && items.contains("carrier:getFullType() == request.carrierType"),
                "The returned server object must support marker and type matching when its item id changes");
        require(items.contains("local pallet = createItemGrantPallet(player)"),
                "Lua must request and track the disposable server pallet");
        require(items.contains("ISTakeBricks:new(player, pallet, pallet:getSquare(), nil, itemType, count)"),
                "The returned server object must be passed as a disposable pallet with target type and count");
    }

    private static void removesTheServerExtensionPackage() throws IOException {
        Path extensionRoot = ROOT.resolve("resources/EtherHack/server-extension");
        if (!Files.exists(extensionRoot)) {
            return;
        }
        try (var entries = Files.walk(extensionRoot)) {
            require(entries.noneMatch(Files::isRegularFile),
                    "The distribution must not contain a separately installed server extension");
        }
    }

    private static void exposesTheModeInSettings() throws IOException {
        String settings = read("resources/EtherHack/lua/components/panels/EtherSettingsPanel.lua");
        require(settings.contains("ISComboBox")
                        && settings.contains("UI_Settings_ItemGrantMode")
                        && settings.contains("setItemGrantMode(")
                        && settings.contains("\"server-world-action\"")
                        && !settings.contains("\"server-authorized\""),
                "Settings must expose the item grant route selector");
    }

    private static String read(String relativePath) throws IOException {
        return Files.readString(ROOT.resolve(relativePath));
    }

    private static void require(boolean condition, String message) {
        if (!condition) {
            throw new AssertionError(message);
        }
    }
}

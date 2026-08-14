package EtherHack.migration;

import java.nio.file.Files;
import java.nio.file.Path;

public final class PlayerPacketDispatchTest {
    private static final Path SOURCE = Path.of(
            "src/main/java/EtherHack/Ether/EtherLuaMethods.java");

    private PlayerPacketDispatchTest() {
    }

    public static void main(String[] args) throws Exception {
        String source = Files.readString(SOURCE);

        require(source.contains("import zombie.network.packets.character.PlayerPacket;"),
                "PlayerPacket must use the B42 character packet package");
        require(!source.contains("PlayerPacket.l_send"),
                "B42 no longer exposes PlayerPacket.l_send");
        require(source.contains("PacketTypes.PacketType packetType = playerPacket.set(player);"),
                "Teleport dispatch must use PlayerPacket.set(player)'s returned packet type");
        require(source.contains("packetType.doPacket(writer);"),
                "Teleport dispatch must frame the packet with the returned packet type");
        require(source.contains("packetType.send(GameClient.connection);"),
                "Teleport dispatch must send with the returned packet type");
        require(!source.contains("PacketTypes.PacketType.PlayerUpdateReliable"),
                "Teleport dispatch must not hard-code PlayerUpdateReliable");
        require(!source.contains("player.setLx(")
                        && !source.contains("player.setLy(")
                        && !source.contains("player.setLz("),
                "B42 removed the legacy setLx/setLy/setLz methods");
        require(source.contains("player.setLastX(player.getX());")
                        && source.contains("player.setLastY(player.getY());")
                        && source.contains("player.setLastZ(player.getZ());"),
                "Teleport must update B42 last-position fields");
        require(source.contains("public static void hackAdminAccess()"),
                "The original B41 direct admin helper must remain available");
    }

    private static void require(boolean condition, String message) {
        if (!condition) {
            throw new AssertionError(message);
        }
    }
}

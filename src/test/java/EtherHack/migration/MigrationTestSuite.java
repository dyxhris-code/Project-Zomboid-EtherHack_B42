package EtherHack.migration;

import EtherHack.features.AutoAimTargetSelectorTest;
import EtherHack.features.AutoAimIntegrationTest;
import EtherHack.features.LocalCheatIntegrationTest;
import EtherHack.features.ItemGrantRoutingTest;
import EtherHack.features.OverlayIntegrationTest;
import EtherHack.ui.LuaUiArchitectureTest;

public final class MigrationTestSuite {
    private MigrationTestSuite() {
    }

    public static void main(String[] args) throws Exception {
        require(args.length == 2, "Expected installer JAR and Project Zomboid JAR arguments");
        ForbiddenArtifactTest.main(new String[0]);
        PlayerPacketDispatchTest.main(new String[0]);
        B42JavaApiCompatibilityTest.main(new String[0]);
        LuaCompatibilityTest.main(new String[0]);
        AutoAimTargetSelectorTest.main(new String[0]);
        AutoAimIntegrationTest.main(new String[0]);
        LocalCheatIntegrationTest.main(new String[0]);
        ItemGrantRoutingTest.main(new String[0]);
        OverlayIntegrationTest.main(new String[0]);
        LuaUiArchitectureTest.main(new String[0]);
        InstallerRoundTripTest.main(args);
    }

    private static void require(boolean condition, String message) {
        if (!condition) {
            throw new AssertionError(message);
        }
    }
}

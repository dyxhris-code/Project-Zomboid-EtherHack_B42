package EtherHack.migration;

public final class MigrationTestSuite {
    private MigrationTestSuite() {
    }

    public static void main(String[] args) throws Exception {
        require(args.length == 2, "Expected installer JAR and Project Zomboid JAR arguments");
        ForbiddenArtifactTest.main(new String[0]);
        PlayerPacketDispatchTest.main(new String[0]);
        B42JavaApiCompatibilityTest.main(new String[0]);
        LuaCompatibilityTest.main(new String[0]);
        InstallerRoundTripTest.main(args);
    }

    private static void require(boolean condition, String message) {
        if (!condition) {
            throw new AssertionError(message);
        }
    }
}

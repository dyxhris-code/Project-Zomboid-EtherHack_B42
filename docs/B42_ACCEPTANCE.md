# B42.20.3 Acceptance

## Automated gates

Run from the repository root with JDK 25:

```powershell
$env:PZ_HOME = 'D:\Apps\Steam\steamapps\common\ProjectZomboid'
gradlew.bat clean check jar --no-daemon
```

The build verifies the pinned `projectzomboid.jar` SHA-256 and Java class major, compile-only dependency isolation, forbidden protection artifacts, Lua module compatibility, ASM output validity, and an install/uninstall round trip in a temporary game root. The round trip confirms that the source JAR hash is unchanged, loose overrides are emitted, root `EtherHack/` resources are extracted, and no `Zomboid/mods/EtherHack` directory is created.

## Installation model

The release JAR follows the original B41 EtherHack layout:

- read target classes from the game-root `projectzomboid.jar`;
- write patched `zombie/...class` files as loose classpath overrides;
- extract `EtherHack/` Java and Lua resources into the game root;
- leave all game-owned JARs untouched.

There is no standalone Mod package, custom multiplayer command channel, or legality/anti-cheat detection subsystem in this branch. Third-party server anti-cheat remains a separate server concern.

## Manual smoke checklist

1. Install into a backed-up B42.20.3 game root and record the original JAR hash.
2. Start the game and confirm the EtherHack logo appears before the normal logo.
3. Confirm the title suffix and the Insert menu toggle.
4. Open each visible Lua panel once, including item editor, player editor, vehicle mechanics, map, and visuals.
5. Exercise status locks, weapon critical multiplier editing, XP/trait controls, teleport, vehicle operations, and ESP alignment in a disposable save.
6. Press Home after closing EtherHack panels and confirm Lua reload succeeds.
7. Run `--uninstall`, confirm loose `zombie/...class` files and `EtherHack/` are removed, and verify the original JAR hash again.
8. For multiplayer testing, use a server where you have permission to test and evaluate only the server's existing rules; this installer does not attempt to classify or bypass server anti-cheat.

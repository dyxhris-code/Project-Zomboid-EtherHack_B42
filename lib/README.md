This directory is for local compile-time Project Zomboid libraries.

The Gradle build expects these files:

- `zombie.jar`
- `Kahlua.jar`
- `fmod.jar`
- `org.jar`

They are intentionally not tracked in Git because they come from the local
Project Zomboid installation/runtime and may not be redistributable.

Copy them into this directory before running:

```powershell
Copy-Item "D:\Apps\Steam\steamapps\common\ProjectZomboid\projectzomboid.jar" .\lib\zombie.jar
.\gradlew.bat build
```

Project Zomboid Build 42.18.0 uses Java 25 class files. Compile this branch
with a Java 25 JDK or allow Gradle to provision one through toolchains.

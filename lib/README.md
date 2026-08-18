# Local Project Zomboid API

The build consumes the locally installed B42.20.3 `projectzomboid.jar` as a
compile-time-only dependency. It is not redistributed and must not be committed.

Set the game directory using either environment variable or Gradle property:

```powershell
$env:PZ_HOME = "D:\Apps\Steam\steamapps\common\ProjectZomboid"
.\gradlew.bat clean check jar

# Equivalent per-invocation form
.\gradlew.bat -PpzHome="D:\Apps\Steam\steamapps\common\ProjectZomboid" clean check jar
```

The environment gate verifies the B42.20.3 SHA-256, Java 25 class files, and
required API entries. A full JDK 25 is required; the game's bundled `jre64`
runtime is not a compiler toolchain.

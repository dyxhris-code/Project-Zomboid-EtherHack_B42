import org.gradle.api.GradleException
import org.gradle.jvm.tasks.Jar
import java.nio.ByteBuffer
import java.nio.file.Files
import java.security.MessageDigest
import java.util.Properties
import java.util.zip.ZipFile

plugins {
    java
}

group = "EtherTrainer"

java {
    toolchain {
        languageVersion.set(JavaLanguageVersion.of(25))
    }
}

tasks.withType<JavaCompile>().configureEach {
    options.encoding = "UTF-8"
    options.release.set(25)
}

fun loadProperties(): Properties = Properties().apply {
    project.file("src/main/resources/EtherHack/EtherHack.properties").inputStream().use(::load)
}

version = loadProperties().getProperty("version").replace("'", "")

repositories {
    mavenCentral()
}

val configuredPzHome = providers.gradleProperty("pzHome").orNull
    ?: System.getenv("PZ_HOME")
val pzJar = configuredPzHome?.let { home ->
    val candidate = file(home)
    if (candidate.isFile && candidate.name.equals("projectzomboid.jar", ignoreCase = true)) {
        candidate
    } else {
        candidate.resolve("projectzomboid.jar")
    }
} ?: file("projectzomboid.jar")

dependencies {
    compileOnly(files(pzJar))
    compileOnly("org.projectlombok:lombok:1.18.42")
    annotationProcessor("org.projectlombok:lombok:1.18.42")
    implementation("org.ow2.asm:asm:9.9.1")
    implementation("org.ow2.asm:asm-tree:9.9.1")
    testImplementation("org.ow2.asm:asm-util:9.9.1")
}

val pzVersionProperties = Properties().apply {
    project.file("gradle/pz-version.properties").inputStream().use(::load)
}
val expectedPzVersion = pzVersionProperties.getProperty("version")
val expectedPzSha256 = pzVersionProperties.getProperty("sha256").uppercase()
val expectedPzClassMajor = pzVersionProperties.getProperty("classMajor").toInt()
val requiredPzEntries = listOf(
    "zombie/GameWindow.class",
    "zombie/network/GameClient.class",
    "se/krka/kahlua/vm/KahluaTable.class",
    "fmod/FMODRecordPosition.class"
)

fun sha256(file: java.io.File): String {
    val digest = MessageDigest.getInstance("SHA-256")
    Files.newInputStream(file.toPath()).use { input ->
        val buffer = ByteArray(1024 * 1024)
        var count: Int
        while (input.read(buffer).also { count = it } >= 0) {
            if (count > 0) digest.update(buffer, 0, count)
        }
    }
    return digest.digest().joinToString("") { "%02X".format(it) }
}

fun classMajor(zip: ZipFile, entryName: String): Int {
    val bytes = zip.getInputStream(zip.getEntry(entryName)).use { it.readNBytes(8) }
    if (bytes.size < 8 || ByteBuffer.wrap(bytes).int != 0xCAFEBABE.toInt()) {
        throw GradleException("Invalid class header for $entryName")
    }
    return ((bytes[6].toInt() and 0xFF) shl 8) or (bytes[7].toInt() and 0xFF)
}

tasks.register("verifyPzEnvironment") {
    doLast {
        if (JavaVersion.current().majorVersion != "25") {
            throw GradleException("B42.20.2 requires JDK 25; Gradle is running on Java ${JavaVersion.current().majorVersion}")
        }
        if (!pzJar.isFile) {
            throw GradleException("Missing B42.20.2 projectzomboid.jar. Set PZ_HOME or pass -PpzHome=<Project Zomboid directory>")
        }
        if (sha256(pzJar) != expectedPzSha256) {
            throw GradleException("Unsupported Project Zomboid build: ${pzJar.absolutePath} (expected B42.20.2 SHA-256 $expectedPzSha256)")
        }
        ZipFile(pzJar).use { zip ->
            requiredPzEntries.forEach { entry ->
                if (zip.getEntry(entry) == null) throw GradleException("B42 API entry is missing: $entry")
                if (classMajor(zip, entry) != expectedPzClassMajor) {
                    throw GradleException("$entry is not a Java 25 class")
                }
            }
        }
        logger.lifecycle("Verified Project Zomboid $expectedPzVersion API: ${pzJar.absolutePath}")
    }
}

tasks.register("verifyDependencyIsolation") {
    dependsOn("verifyPzEnvironment")
    doLast {
        val pzPath = pzJar.canonicalFile
        val compileFiles = configurations.compileClasspath.get().files.map { it.canonicalFile }.toSet()
        val runtimeFiles = configurations.runtimeClasspath.get().files.map { it.canonicalFile }.toSet()
        if (pzPath !in compileFiles) {
            throw GradleException("projectzomboid.jar is missing from compileClasspath")
        }
        if (pzPath in runtimeFiles) {
            throw GradleException("projectzomboid.jar must remain compileOnly")
        }
        val legacyNames = setOf("zombie.jar", "Kahlua.jar", "fmod.jar", "org.jar")
        val legacyRuntime = runtimeFiles.filter { it.name in legacyNames }
        if (legacyRuntime.isNotEmpty()) {
            throw GradleException("Legacy B41 libraries leaked into runtimeClasspath: $legacyRuntime")
        }
        logger.lifecycle("Verified compile-only Project Zomboid dependency isolation")
    }
}

tasks.named<JavaCompile>("compileJava") {
    dependsOn("verifyPzEnvironment")
}

tasks.named<Jar>("jar") {
    dependsOn("verifyDependencyIsolation")
    destinationDirectory.set(layout.buildDirectory)
    archiveFileName.set("EtherTrainer-${version}.jar")
    manifest.attributes["Main-Class"] = "EtherHack.Main"
    duplicatesStrategy = DuplicatesStrategy.EXCLUDE
    isPreserveFileTimestamps = false
    isReproducibleFileOrder = true
    from(configurations.runtimeClasspath.get().map { file ->
        if (file.isDirectory) file else zipTree(file)
    })
}

tasks.register("verifyJarHygiene") {
    dependsOn("jar")
    doLast {
        val archive = tasks.named<Jar>("jar").get().archiveFile.get().asFile
        ZipFile(archive).use { zip ->
            val names = zip.entries().asSequence().map { it.name }.toList()
            val forbiddenPrefixes = listOf("zombie/", "se/krka/kahlua/", "fmod/", "lombok/")
            val forbidden = names.filter { name -> forbiddenPrefixes.any(name::startsWith) }
            if (forbidden.isNotEmpty()) {
                throw GradleException("Release JAR contains game/runtime classes: ${forbidden.take(5)}")
            }
            listOf("EtherHack/Main.class", "org/objectweb/asm/ClassReader.class").forEach { required ->
                if (required !in names) throw GradleException("Release JAR is missing $required")
            }
        }
        logger.lifecycle("Verified release JAR hygiene: ${archive.name}")
    }
}

val migrationTests by tasks.registering(JavaExec::class) {
    dependsOn("jar", "testClasses")
    group = "verification"
    description = "Runs B42 source compatibility and installer round-trip acceptance tests"
    classpath = sourceSets.test.get().runtimeClasspath + files(pzJar)
    mainClass.set("EtherHack.migration.MigrationTestSuite")
    args(
        tasks.named<Jar>("jar").flatMap { it.archiveFile }.get().asFile.absolutePath,
        pzJar.absolutePath
    )
    environment("PZ_GAME_DIR", configuredPzHome ?: pzJar.parentFile.absolutePath)
}

tasks.named<Test>("test") {
    enabled = false
}

tasks.named("check") {
    dependsOn("verifyPzEnvironment", "verifyDependencyIsolation", "verifyJarHygiene", migrationTests)
}

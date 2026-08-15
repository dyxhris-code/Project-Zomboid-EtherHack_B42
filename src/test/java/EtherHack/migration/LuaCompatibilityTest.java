package EtherHack.migration;

import java.io.IOException;
import java.io.InputStream;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.stream.Stream;

public final class LuaCompatibilityTest {
    private static final Path LUA_ROOT = Path.of("src/main/resources/EtherHack/lua");
    private static final Path GAME_LUA_ROOT = Path.of(
            System.getenv().getOrDefault(
                    "PZ_GAME_DIR",
                    "D:/Apps/Steam/steamapps/common/ProjectZomboid"))
            .resolve("media/lua");
    private static final Pattern REQUIRE = Pattern.compile("(?m)^\\s*require\\s*[\\( ]?\\s*[\"']([^\"']+)[\"']");

    private LuaCompatibilityTest() {
    }

    public static void main(String[] args) throws Exception {
        rejectsStaleB41Symbols();
        usesNativeB42ItemEditor();
        guardsVehicleLookup();
        rejectsRemovedInfoPanelAntiCheatStatus();
        usesQuietEnglishTranslationFallback();
        resolvesLuaRequires();
        parsesLuaSyntaxWhenCompilerIsAvailable();
    }

    private static void rejectsStaleB41Symbols() throws IOException {
        List<String> forbidden = List.of(
                "sendAddXp",
                "getPlayerCraftingUI",
                "EtherAdminMenu",
                "EtherDebugMenu",
                "EtherDebugClient",
                "EtherDebugServer");
        List<String> failures = new ArrayList<>();

        for (Path file : luaFiles()) {
            String source = Files.readString(file);
            for (String symbol : forbidden) {
                if (source.contains(symbol)) {
                    failures.add(relative(file) + " contains " + symbol);
                }
            }
        }

        require(failures.isEmpty(), "Stale B41 Lua references:\n" + String.join("\n", failures));
    }

    private static void usesNativeB42ItemEditor() throws IOException {
        String source = read("components/override/EtherEditInventoryItem.lua");
        require(source.contains("ISItemEditorUI.OpenPanel("),
                "EtherEditInventoryItem must call the B42 native ISItemEditorUI.OpenPanel API");
        require(!source.contains("ISItemEditorUI:new("),
                "EtherEditInventoryItem must not construct the copied B41 editor directly");
    }

    private static void guardsVehicleLookup() throws IOException {
        String mechanics = read("components/ui/UIMechanics.lua");
        require(mechanics.contains("local function getEtherMechanicsVehicle(player)"),
                "UIMechanics must centralize B42 vehicle lookup");
        require(mechanics.contains("if player == nil then return nil end"),
                "UIMechanics vehicle lookup must guard a missing player");
        require(!mechanics.contains("self.localPlayer:getNearVehicle()"),
                "UIMechanics must not dereference a missing player or vehicle directly");
    }

    private static void rejectsRemovedInfoPanelAntiCheatStatus() throws IOException {
        String source = read("components/panels/EtherInfoPanel.lua");
        require(!source.contains("getAntiCheat12Status")
                        && !source.contains("getAntiCheat8Status")
                        && !source.contains("AntiCheatStatus"),
                "EtherInfoPanel must not render the removed anti-cheat detection subsystem");
    }

    private static void usesQuietEnglishTranslationFallback() throws IOException {
        String source = Files.readString(
                Path.of("src/main/java/EtherHack/Ether/EtherTranslator.java"));
        require(!source.contains("No translations for language code"),
                "Missing-language fallback must not log once per translated label and rendered frame");
        require(source.contains("this.translations.get(\"EN\")"),
                "Unsupported game languages must retain the English fallback");
    }

    private static void resolvesLuaRequires() throws IOException {
        List<String> missing = new ArrayList<>();
        for (Path file : luaFiles()) {
            Matcher matcher = REQUIRE.matcher(Files.readString(file));
            while (matcher.find()) {
                String module = matcher.group(1);
                if (!moduleExists(module)) {
                    missing.add(relative(file) + " requires missing module " + module);
                }
            }
        }
        require(missing.isEmpty(), "Missing Lua modules:\n" + String.join("\n", missing));
    }

    private static void parsesLuaSyntaxWhenCompilerIsAvailable() throws Exception {
        Class<?> compiler;
        Class<?> table;
        try {
            compiler = Class.forName("se.krka.kahlua.luaj.compiler.LuaCompiler");
            table = Class.forName("se.krka.kahlua.vm.KahluaTable");
        } catch (ClassNotFoundException ignored) {
            return;
        }

        Method load = compiler.getMethod("loadis", InputStream.class, String.class, table);
        List<String> failures = new ArrayList<>();
        for (Path file : luaFiles()) {
            try (InputStream input = Files.newInputStream(file)) {
                load.invoke(null, input, relative(file), null);
            } catch (InvocationTargetException exception) {
                failures.add(relative(file) + ": " + exception.getCause());
            }
        }
        require(failures.isEmpty(), "Lua syntax errors:\n" + String.join("\n", failures));
    }

    private static boolean moduleExists(String module) {
        String normalized = module.endsWith(".lua") ? module : module + ".lua";
        if (Path.of("src/main/resources").resolve(normalized).toFile().isFile()) {
            return true;
        }
        return Stream.of("client", "shared", "server")
                .map(GAME_LUA_ROOT::resolve)
                .map(root -> root.resolve(normalized))
                .anyMatch(Files::isRegularFile);
    }

    private static List<Path> luaFiles() throws IOException {
        try (Stream<Path> files = Files.walk(LUA_ROOT)) {
            return files.filter(path -> path.toString().endsWith(".lua")).toList();
        }
    }

    private static String read(String relativePath) throws IOException {
        return Files.readString(LUA_ROOT.resolve(relativePath));
    }

    private static String relative(Path file) {
        return LUA_ROOT.relativize(file).toString().replace('\\', '/');
    }

    private static void require(boolean condition, String message) {
        if (!condition) {
            throw new AssertionError(message);
        }
    }
}

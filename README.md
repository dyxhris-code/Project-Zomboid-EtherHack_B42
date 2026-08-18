<h1 align="center">EtherTrainer</h1>
<img src="demo/EtherLogo.png" alt="EtherTrainer Logo">
<p align="center">
  <img src="https://img.shields.io/github/v/release/Yeet-Masta/Project-Zomboid-EtherHack" alt="GitHub release (latest by date)">
  <img src="https://img.shields.io/github/license/Yeet-Masta/Project-Zomboid-EtherHack" alt="GitHub">
  <img src="https://img.shields.io/github/commit-activity/t/Yeet-Masta/Project-Zomboid-EtherHack" alt="GitHub commit activity (branch)">
  <img src="https://img.shields.io/badge/Java-25-green" alt="Java 25">
  <img src="https://img.shields.io/github/issues/Yeet-Masta/Project-Zomboid-EtherHack" alt="GitHub issues">
</p>

## Upgrade!!!
I'm currecntly converting all the code to kotlin. I want to do this for several reasons. The code is much cleaner, and personally, I like kotlin better. so if this repo doesn't get updated in a while. you know why :)

## NOTICE!!!
There are repo's going around pretending to be EtherHack or just a PZ cheat (https://github.com/ayhantunay/Project-Zomboid-Cheat) and I HIGHLY ADVISE YOU DON"T DOWNLOAD THESE!!! They are asking you to download completely arbitrary DLL files and disable your fucking anti-virus!!! Please for the love of god, don't download this shit. Use your head!!!

This is a cheat written in Java(API) and LUA(GUI) for Project Zomboid. It is aimed at providing the game with additional functionality that allows users to get some benefits. Please use responsibly and understand the consequences that may arise as a result of improper use.
The B42 migration targets Project Zomboid `42.20.3` (Steam). EtherTrainer reads classes from `projectzomboid.jar`, emits loose `zombie/...` overrides, and extracts runtime resources under the game-root `EtherHack/` directory.

This branch does not create a standalone Mod, modify `projectzomboid.jar`, or implement a multiplayer legality detector. Server-side anti-cheat remains independent of the original client-side modification route.

Edit: Finally after all this time! the project has been restored!!! I know the code quality is shit, but lest be honest it's better than nothing. And as a wise man once said "It Just Works" soooooooo. But, if any of you guys want to contribute, PLEASE! my dumb ass can't code that well and I really want this project to live on so any contrabutions would be helpful and apreaciated! Also, FUCK https://github.com/asledgehammer/EtherHammer !!! EAT SHIT!

Edit edit: wtf is [this???](https://imgur.com/a/rat1-v5T7l31)

Warning!!! Please check out [this github repo](https://github.com/Yeet-Masta/Project-Zomboid/tree/arkiease)

[Check this out!!!](https://www.unknowncheats.me/forum/other-mmorpg-and-strategy/645408-project-zomboid-cheat-valkur.html) This is freaking dope!!!

You can watch the cheat [installation video](https://www.youtube.com/watch?v=Olx7O3HyeZc) and see its main functions in action.

## Table of Contents
- [Cheat functionality](#cheat-functionality)
- [Demo](#demo)
- [Getting Started](#getting-started)
- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Uninstallation](#uninstallation)
- [Usage](#usage)
- [For developer](#for-developer)
- [Contributing](#contributing)
- [Disclaimer](#disclaimer)
- [License](#license)
- [Contact](#contact)

## Cheat functionality

| Function                   |  Working in multiplayer  | Working in a co-op  | Description                                                                                                                                                                                                                                                     |
|----------------------------|:------------------------:|:-------------------:|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Debug Mode Bypass          |          -/+(*)          |          +          | Allows you to use the developer mode in multiplayer (when starting the game with -debug connection is not possible). When you click the right mouse button, additional menus appear, including changing clothes, repairing cars, teleporting on the map, etc.   |
| MultiHit Zombie            |            +             |          +          | Enables multi-hit zombie mode                                                                                                                                                                                                                                   |
| Invisible                  |          -/+(*)          |          +          | Allows you to become invisible to everyone                                                                                                                                                                                                                      |
| God Mode                   |          -/+(*)          |          +          | Gives immortality to the character                                                                                                                                                                                                                              |
| No Clip                    |          -/+(*)          |          +          | Ability to pass through walls and objects                                                                                                                                                                                                                       |
| Unlimited Carry            |            +             |          +          | Enable infinite load capacity, including for third-party containers                                                                                                                                                                                             |
| Unlimited Endurance        |            +             |          +          | Enable unlimited endurance                                                                                                                                                                                                                                      |
| Disable Fatigue            |            +             |          +          | Disables the need for sleep                                                                                                                                                                                                                                     |
| Disable Hunger             |            +             |          +          | Disables the need for food                                                                                                                                                                                                                                      |
| Disable Thirst             |            +             |          +          | Disables the need for water                                                                                                                                                                                                                                     |
| Disable Character Needs    |            +             |          +          | Disables all the needs of the character, sets its characteristics to the maximum - positive - level (stress, panic, etc.)                                                                                                                                       |
| Add x100 Trait Point(beta) |         -/+ (**)         |          +          | Adds +100 points to the character creation menu                                                                                                                                                                                                                 |
| Game Debugger              |            +             |          +          | Opens the debugging window                                                                                                                                                                                                                                      |
| Items Creator              |            +             |          +          | The item creation menu, the ability to sort, search, etc.                                                                                                                                                                                                       |
| Player Editor              |            +             |          +          | The character editing menu, the ability to add skills, perks, etc.                                                                                                                                                                                              |
| Get Admin Access           |          -/+(*)          |          +          | Obtaining administrator rights on the server                                                                                                                                                                                                                    |
| Open Admin Menu            |          -/+(*)          |          +          | Opens the admin window                                                                                                                                                                                                                                          |

(*) - Multiplayer behavior is determined by the server and its existing anti-cheat configuration. This project does not detect, disable, or bypass server-side anti-cheat.

(**) - It only works when creating a character from the main menu, that is, points will not be added to the menu after death. Solution: after death, log out of the server and connect again.


## Demo
![1](demo/1.jpg)
![2](demo/2.jpg)
![3](demo/3.jpg)
![4](demo/4.jpg)
![5](demo/5.jpg)
![6](demo/6.jpg)
![7](demo/7.jpg)
![8](demo/8.jpg)
![9](demo/9.jpg)

## Getting Started

This section will provide information on how to get a local copy of the project up and running.

### Prerequisites

This tool requires:

-   JDK 25 (the B42.20.3 classes use class-file major version 69)
-   Steam copy of [Project Zomboid](https://store.steampowered.com/app/108600/Project_Zomboid/)

### Installation

1. Install JDK 25 and make sure `java` is available on `PATH`

(For Windows: `WIN + X` -> `System` -> `Advanced System Parameters` -> `Environment Variables` -> edit `Path` and add the JDK 25 `bin` directory.)

2. Clone the repository and build with the local game path:

```
gradlew.bat clean check jar -PpzHome="C:\\Steam\\steamapps\\common\\ProjectZomboid"
```

3. Move the created `build/EtherTrainer-Re.1.0.2.jar` to the root folder of the game

(For example, `c:\Steam\steamapps\common\ProjectZomboid`)

4. Open a console in the game root and run:

```
java -jar ./EtherTrainer-{yourVersion}.jar --install
```

The generated filename is currently `EtherTrainer-Re.1.0.2.jar`.
### Uninstallation
Open the console in the root folder and run the following command:
```
java -jar ./EtherTrainer-{yourVersion}.jar --uninstall
```

Use the same generated JAR filename for uninstallation.

## Usage

After successfully installing the cheat, you need to log in to the game. When loading, the cheat logo will appear in front of the main logo, in the game itself (menu and in the game session) in the lower left corner there will be information about the cheat. The name of the game window will also change.

To open the cheat menu, press `Insert`

To reload the LuaGUI, press `Home`, but first make sure that all the cheat windows are closed, otherwise an error will appear.

## For developer
If you are a developer and want to expand the functionality, you can do it as follows:

In the project folder located on the path `src/main/resources/EtherHack/lua` there is a single file responsible for rendering the entire user interface of the cheat. You can edit it using examples from game files.

Also, Eterhack provides the ability to add custom methods from Java to lua, for this in the `src/main/java/EtherHack/Ether/EtherAPI.java` needs to find the `public static class GlobalEtherAPI` and add it according to the available examples:

```java
@LuaMethod(
         name = "yourMethodName",
        global = true
)
public static String yourMethodName() {
    return "Test!";
}
```
After adding and reassembling the cheat, you will be able to call this method in lua:

```lua
print(yourMethodName());
--Output log: Test!
```
In addition, you can load third-party Lua in any other Lua through the `EtherRequire` method:

```lua
EtherRequire "path/to/your.lua"
```

The path to Lua must be specified relative to the root folder of the game

See [docs/B42_ACCEPTANCE.md](docs/B42_ACCEPTANCE.md) for the migration gates and manual smoke checklist.
## Contributing

We welcome contributions from the community. If you want to contribute, please fork the repository and create a pull request with your changes.

### Contributor

The original author and upstream project remain credited to [Yeet-Masta](https://github.com/Yeet-Masta/Project-Zomboid-EtherHack).

The B42 migration and current maintenance contributions in this repository are by `ljy87`, in [ljy87263621/Project-Zomboid-EtherHack_B42](https://github.com/ljy87263621/Project-Zomboid-EtherHack_B42).

## Disclaimer

This software is provided 'as-is', without any express or implied warranty. In no event will the author be held liable for any damages arising from the use of this software. Use of this software may also violate the terms of service of the game and could lead to your account being banned. Use at your own risk.

## License

This project is under `MIT License` - see the LICENSE file for details.

## Contact

If you have any questions, feel free to reach out to me at `spaceguy234@gmail.com`
Also here's the unofficial official [discord](https://discord.gg/4CMAVqEey2) server

# EtherTrainer

![EtherTrainer Logo](demo/EtherLogo.png)

<p align="center">
  <img src="https://img.shields.io/github/v/release/ljy87263621/Project-Zomboid-EtherHack_B42" alt="Latest release">
  <img src="https://img.shields.io/github/license/ljy87263621/Project-Zomboid-EtherHack_B42" alt="License">
  <img src="https://img.shields.io/badge/Project%20Zomboid-B42.20.3-blue" alt="Project Zomboid B42.20.3">
  <img src="https://img.shields.io/badge/Java-25-green" alt="Java 25">
</p>

## 中文说明

EtherTrainer 是面向 Project Zomboid B42 的 Java API + Lua UI 修改器。当前迁移目标为 Steam 版 Project Zomboid `42.20.3`，发行版本为 [Re.1.0.2](https://github.com/ljy87263621/Project-Zomboid-EtherHack_B42/releases/tag/Re.1.0.2)。

本项目会读取游戏目录中的 `projectzomboid.jar`，生成独立的 `EtherTrainer-Re.1.0.2.jar`，并在游戏根目录释放 `EtherHack/` 运行时资源。它不是独立 Mod，不会修改原始 `projectzomboid.jar`。

### 主要功能

- 调试菜单与角色编辑
- 物品管理器：模块、类别、物品筛选与批量给予
- 技能、特征和身体状态编辑
- 电视/收音机节目经验：一次选择多个技能并提交经验
- 自瞄模式、无后座、无扩散、无限弹药等射击相关选项
- 小地图、传送查询和其他可视化工具

多人游戏中的实际行为由服务器权限和服务器反作弊配置决定。本项目不检测、关闭或绕过服务器端反作弊。请确认你理解游戏服务条款及使用风险。

### 环境要求

- Windows 原生环境
- JDK 25（B42.20.3 使用 Java class-file major version 69）
- Steam 版 [Project Zomboid](https://store.steampowered.com/app/108600/Project_Zomboid/)

### 构建与安装

在仓库根目录执行：

```powershell
gradlew.bat clean check jar -PpzHome="C:\\Steam\\steamapps\\common\\ProjectZomboid"
```

构建产物为 `build/EtherTrainer-Re.1.0.2.jar`。将其复制到 Project Zomboid 游戏根目录，然后执行：

```powershell
java -jar .\EtherTrainer-Re.1.0.2.jar --install
```

卸载：

```powershell
java -jar .\EtherTrainer-Re.1.0.2.jar --uninstall
```

进入游戏后按 `Insert` 打开菜单；按 `Home` 重新加载 Lua UI（重载前请关闭 EtherTrainer 窗口）。

### 作者与贡献者

原作者及上游项目： [Yeet-Masta/Project-Zomboid-EtherHack](https://github.com/Yeet-Masta/Project-Zomboid-EtherHack)。

B42 迁移与当前维护贡献者：`ljy87`，对应仓库为 [ljy87263621/Project-Zomboid-EtherHack_B42](https://github.com/ljy87263621/Project-Zomboid-EtherHack_B42)。

### 开发资料

- [B42 验收与手动冒烟清单](docs/B42_ACCEPTANCE.md)
- Lua UI：`src/main/resources/EtherHack/lua`
- Java API：`src/main/java/EtherHack`

## English

EtherTrainer is a Java API + Lua UI trainer for Project Zomboid B42. The current migration target is Steam Project Zomboid `42.20.3`, and the current release is [Re.1.0.2](https://github.com/ljy87263621/Project-Zomboid-EtherHack_B42/releases/tag/Re.1.0.2).

The builder reads `projectzomboid.jar`, creates `EtherTrainer-Re.1.0.2.jar`, and extracts runtime resources under the game root in `EtherHack/`. It is not a standalone Mod and does not modify the original `projectzomboid.jar`.

### Features

- Debug menu and player editor
- Item manager with module/category navigation, filtering, and batch grants
- Skill, trait, and body-stat editing
- TV/radio program XP with multi-skill selection in one dialog
- Configurable auto-aim modes and shooting options such as no recoil, no spread, and unlimited ammo
- Minimap, teleport lookup, and visual tools

Multiplayer behavior depends on server permissions and server-side anti-cheat configuration. This project does not detect, disable, or bypass server-side anti-cheat. Use it only where permitted and at your own risk.

### Requirements

- Native Windows environment
- JDK 25 (B42.20.3 uses class-file major version 69)
- Steam [Project Zomboid](https://store.steampowered.com/app/108600/Project_Zomboid/)

### Build and install

From the repository root:

```powershell
gradlew.bat clean check jar -PpzHome="C:\\Steam\\steamapps\\common\\ProjectZomboid"
```

The artifact is `build/EtherTrainer-Re.1.0.2.jar`. Copy it to the Project Zomboid game root and run:

```powershell
java -jar .\EtherTrainer-Re.1.0.2.jar --install
```

To uninstall:

```powershell
java -jar .\EtherTrainer-Re.1.0.2.jar --uninstall
```

Press `Insert` in-game to open the menu. Press `Home` to reload the Lua UI after closing EtherTrainer windows.

### Original author and contributor

Original author and upstream project: [Yeet-Masta/Project-Zomboid-EtherHack](https://github.com/Yeet-Masta/Project-Zomboid-EtherHack).

B42 migration and current maintenance contributor: `ljy87`, in [ljy87263621/Project-Zomboid-EtherHack_B42](https://github.com/ljy87263621/Project-Zomboid-EtherHack_B42).

### Documentation

- [B42 acceptance and manual smoke checklist](docs/B42_ACCEPTANCE.md)
- Lua UI: `src/main/resources/EtherHack/lua`
- Java API: `src/main/java/EtherHack`

## License

This project is distributed under the [MIT License](LICENSE.txt). The software is provided as-is. It may violate the game's terms of service and may result in account sanctions; use it only where authorized.

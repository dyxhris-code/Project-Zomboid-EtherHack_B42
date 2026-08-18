# 架构分析

## 1. 装载与生命周期

用户 `DllMain` 位于 `0x180001780`：

1. 仅处理 `DLL_PROCESS_ATTACH`。
2. 调用 `DisableThreadLibraryCalls(hModule)`。
3. 保存模块句柄到全局状态。
4. 用 `CreateThread` 启动 `0x18003E740`，随后立即关闭线程句柄。

工作线程不会在 loader lock 内执行复杂初始化。它先记录日志，然后每 100 ms 查询 `gdi32.dll`，解析 `SwapBuffers`，初始化 MinHook，创建并启用 `SwapBuffers -> 0x18003B390` 的钩子。

这个设计可借鉴之处是：`DllMain` 保持极小，只负责派发；渲染 API 尚未装载时采用有界职责的延迟探测；Hook 的创建和启用分别记录错误。

## 2. 渲染与输入

首次呈现时，初始化函数 `0x18003ADE0` 完成以下工作：

- 从 HDC 取得游戏窗口。
- 初始化 ImGui Win32 与 OpenGL3 后端，GLSL 版本为 `#version 130`。
- 尝试加载 `C:\Windows\Fonts\msyh.ttc`，失败则使用默认字体。
- 替换游戏窗口过程以接收输入，Insert 控制菜单显示。
- 初始化玻璃模糊效果；失败可降级。
- 初始化原生模型 chams OpenGL Hook；支持延迟重试。

OpenGL 动态符号包含 draw call、uniform、VAO/VBO 和 3D texture 操作。字符串显示它会识别 `MatrixPalette`、`ModelViewProjection`、`TintColour`、`TexturePainColor` 等 uniform，并统计普通、实例化、车辆、轮廓等 draw call。

## 3. JVM/JNI 桥

JNI 初始化函数按模块缓存 `jclass`、`jfieldID` 和 `jmethodID`。类查找不是每帧重复执行，而是在模块首次使用时完成，并以全局状态记录成功或失败。已观察到的核心类包括：

- 世界与实体：`IsoWorld`、`IsoCell`、`IsoMovingObject`、`IsoZombie`、`IsoAnimal`、`BaseVehicle`。
- 玩家与战斗：`IsoPlayer`、`IsoGameCharacter`、`CombatManager`、`Safety`、`LosUtil`。
- 物品与武器：`ItemContainer`、`InventoryItem`、`HandWeapon`、`WeaponPart`、`ScriptManager`。
- 状态与技能：`Stats`、`CharacterStat`、`XP`、`PerkFactory`。
- 环境与 UI：`ClimateManager`、`LightingJNI`、`UIManager`、`FBORenderObjectOutline`。
- 弹道：`BallisticsController`、`Vector2`、`Vector3`、`SwipeStatePlayer`。

缓存层的价值在于减少 JNI 查找开销，并把“版本不兼容”集中为初始化失败。建议在自己的实现中为每个模块维护显式的 `ready` 状态和失败原因，不要使用散落的裸 `jmethodID`。

## 4. 功能执行与同步

二进制同时存在三类状态修改路径：

1. 本地 Java 方法调用，例如 `RestoreToFullHealth`、`setGodMod`、`setAvoidDamage`、`AddXP`。
2. 游戏网络 API，例如 `sendPlayerDamage`、`sendPlayerHit`、`sendIsoWaveSignal`。
3. B42 网络包，例如 `SyncHandWeaponFieldsPacket`、`AddExplosiveTrapPacket`、`SyncItemFieldsPacket`、`SyncPlayerStatsPacket`。

这说明作者区分了本地状态和服务器可见状态。可复用的设计原则是把每项能力声明为 `local-only`、`server-sync` 或 `permission-gated`，并在 UI 中显示运行时状态，而不是假设本地写入一定有效。

## 5. 安全与稳定性观察

- 没有导出函数，不能通过常规 `LoadLibrary + GetProcAddress` 作为 SDK 调用。
- 使用 `CreateThread`、线程挂起/恢复、上下文读写和 `VirtualProtect`，主要来自 Hook 实现，仍需避免在线环境误用。
- DLL 未签名，且当前仅做静态分析；不能据此断言运行时安全。
- 未观察到高熵自定义节区、overlay、TLS 回调或少量导入等典型壳特征。
- PDB 不在样本旁边，因此函数名主要是地址名；若能取得匹配 GUID `A5B08D2D-F441-43FA-860C-6710190684E6`、age 83（十六进制 `0x53`）的 PDB，可显著提高恢复质量。


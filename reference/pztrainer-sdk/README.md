# pztrainer 本地参考 SDK

此目录是对 `pztrainer.dll` 的静态逆向参考，不是原作者源码，也不是可直接链接的二进制 SDK。

## 样本身份

- 原始路径：`D:\Data\QQFile\pztrainer.dll`
- SHA-256：`3AD7B518FFEA72BF49124F6FC9199C89115FBF2D21845F06517308C2A999EC22`
- 文件大小：1,078,784 字节
- 格式：Windows x64 PE32+ DLL，MSVC C++
- 签名：无 Authenticode 签名
- 导出：无
- PDB 路径：`H:\SteamLibrary\steamapps\common\ProjectZomboid\pztrainer\bin\x64\Release\pztrainer.pdb`
- PE 编译时间戳：2026-08-16 11:57:07 UTC（北京时间 19:57:07）

## 结论摘要

该 DLL 没有传统导出 ABI。`DllMain` 在 `DLL_PROCESS_ATTACH` 时关闭线程通知并创建工作线程；工作线程轮询 `gdi32.dll!SwapBuffers`，然后通过 MinHook 安装 OpenGL 呈现钩子。首次进入钩子后初始化 ImGui Win32/OpenGL 后端、窗口输入钩子以及模型 chams/ESP 桥。

游戏数据访问主要通过 JNI 完成。程序缓存 Project Zomboid Build 42.20 的 Java 类、字段和方法 ID，覆盖角色、僵尸、动物、车辆、物品、技能、角色状态、天气、主线程任务、世界对象、弹道和 OpenGL 模型数据。部分修改会调用游戏网络包或服务端同步方法，而不是只改本地内存。

节区、导入表、PDB 信息和整体熵没有显示常见压缩壳特征，因此本次“解包”实际是原生反编译与符号恢复，不需要脱壳。

## 目录

- `analysis/architecture.md`：启动、Hook、JNI、渲染与同步架构。
- `analysis/modules.md`：按功能整理的模块和可借鉴点。
- `analysis/pseudocode/`：Radare2 `pdc` 生成的关键函数伪代码，地址基于映像基址 `0x180000000`。
- `analysis/ghidra/`：Ghidra Headless 生成的语义命名反编译、调用关系和字符串证据索引。
- `analysis/reconstructed/`：在反编译证据之上人工校正的可读参考实现，不作为原始源码声明。
- `analysis/item-grant-evidence.md`：一次性托盘物品路线的地址级证据和不确定性边界。
- `include/pztrainer_symbols.hpp`：可在本地 C++ JNI 原型中复用的类名、方法名和签名常量。
- `metadata/semantic-functions.tsv`：函数地址、语义名称、模块、置信度和摘要清单。
- `metadata/semantic-data.tsv`：全局状态、JNI 类缓存、字段 ID 和方法 ID 的语义标签清单。
- `metadata/pe-summary.json`：PE、节区、导入、调试目录和哈希。
- `metadata/strings.tsv`：样本中的 ASCII/UTF-16 字符串。
- `metadata/jni-candidates.tsv`：疑似 JNI 类、方法、字段和签名字符串。
- `tools/analyze_pztrainer.py`：不加载 DLL 的可重复静态提取脚本。
- `tools/extract_pseudocode.ps1`：使用 Radare2 批量导出关键函数伪代码。
- `tools/validate_readable_sdk.ps1`：验证语义清单唯一性、反编译文件映射、索引和数据标签应用情况。

## 重新生成元数据

```powershell
python reference\pztrainer-sdk\tools\analyze_pztrainer.py `
  D:\Data\QQFile\pztrainer.dll `
  reference\pztrainer-sdk\metadata
```

```powershell
powershell -ExecutionPolicy Bypass -File `
  reference\pztrainer-sdk\tools\extract_pseudocode.ps1
```

生成可读化 Ghidra SDK：

```powershell
powershell -ExecutionPolicy Bypass -File `
  reference\pztrainer-sdk\tools\export_readable_sdk.ps1
```

该流程会保留原始 DLL 地址，在 Ghidra 项目中应用语义函数名，并为每个目标函数输出调用者、被调用者、引用字符串和反编译 C。语义名称来自可审查的 TSV 清单，不会把推断伪装成原作者符号。

导出结束后会自动运行完整性验证。也可以单独执行：

```powershell
powershell -ExecutionPolicy Bypass -File `
  reference\pztrainer-sdk\tools\validate_readable_sdk.ps1
```

## 使用边界

1. 不要把反编译函数签名当成稳定 ABI；原 DLL 没有导出函数。
2. JNI 类名和方法签名强耦合 Project Zomboid 42.20，升级版本必须重新验证。
3. 网络包调用、角色状态同步、物品生成和弹道 Hook 可能受服务端权限与反作弊规则约束。
4. 当前结论来自静态分析；没有加载 DLL、注入游戏或进行在线环境测试。

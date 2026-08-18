# 模块目录与可借鉴点

| 模块 | 静态证据 | 可借鉴设计 |
|---|---|---|
| 生命周期/Hook | `DllMain`、工作线程、`SwapBuffers`、MinHook | loader lock 外初始化；分阶段状态机；失败日志 |
| ImGui UI | ImGui 1.92.5、Win32/OpenGL3 后端、中文字体、Insert | 后端降级；窗口过程接管；运行时诊断 |
| ESP/实体缓存 | 僵尸、玩家、动物、车辆、骨骼、LOS、屏幕坐标 | JNI ID 缓存；实体快照；可见性与骨骼失败计数 |
| 模型 chams | draw calls、program/uniform、矩阵 palette、outline | 在渲染层识别模型；保留并恢复 GL 状态 |
| 技能/XP | `getPerkLevel`、`getXP`、`AddXP`、媒体 XP | 数据驱动技能表；本地调用与等级阈值分离 |
| 物品生成 | `ScriptManager`、`CreateItem`、事务、世界物品 | 脚本定义缓存；容器/世界放置统一路由 |
| 武器同步 | 弹药、弹匣、配件、`SyncHandWeaponFields` | 修改后显式同步；按字段记录成功状态 |
| 爆炸物 | `IsoTrap`、`AddExplosiveTrapPacket`、`SyncItemFields` | 本地对象与网络包成对处理 |
| 角色状态 | `CharacterStat`、范围、默认值、能力检查 | 元数据驱动编辑器；范围钳制；权限门控 |
| 生命保护 | `RestoreToFullHealth`、GodMod、AvoidDamage | 保存原状态；启停幂等；必要时同步伤害 |
| 天气/光照 | Climate float/bool/color、override、lamppost | 统一 override 生命周期；恢复原值 |
| 主线程调度 | `MainThreadQueueItem`、`invokeOnMainThread` | JNI 跨线程操作切回游戏主线程 |
| 弹道/瞄准 | Bullet 原生符号、BallisticsController、spread/hit chance | 功能按 Legit/Rage 策略拆分；配置与执行分层 |
| 全局对象/Lua | KahluaTable、LuaCaller、GlobalObjectSystem | 用游戏已有脚本对象表达复杂数据 |

## 推荐的本地抽象

```cpp
enum class SyncMode { LocalOnly, ServerPacket, CapabilityGated };

struct FeatureStatus {
    bool initialized;
    bool active;
    SyncMode sync_mode;
    std::string last_error;
};

struct JniMember {
    const char* owner;
    const char* name;
    const char* signature;
    bool is_static;
};
```

不要直接复制反编译器推断出来的 C++ 参数类型。应以 JNI 描述符、游戏 B42.20 的类文件和实际调用约定三者交叉验证。


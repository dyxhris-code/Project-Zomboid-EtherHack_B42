#pragma once

#include <array>
#include <string_view>

namespace pztrainer::reference {

struct JniMember {
    std::string_view owner;
    std::string_view name;
    std::string_view signature;
    bool is_static;
};

inline constexpr std::string_view kTargetBuild = "Project Zomboid 42.20";

inline constexpr std::array kCoreMembers{
    JniMember{"zombie/characters/IsoPlayer", "getInstance", "()Lzombie/characters/IsoPlayer;", true},
    JniMember{"zombie/iso/IsoWorld", "getCell", "()Lzombie/iso/IsoCell;", false},
    JniMember{"zombie/iso/IsoCell", "getZombieList", "()Ljava/util/ArrayList;", false},
    JniMember{"zombie/iso/IsoCell", "getObjectList", "()Ljava/util/Set;", false},
    JniMember{"zombie/iso/IsoCell", "getVehicles", "()Ljava/util/ArrayList;", false},
    JniMember{"zombie/iso/LosUtil", "lineClear", "(Lzombie/iso/IsoCell;IIIIIIZ)Lzombie/iso/LosUtil$TestResults;", true},
};

inline constexpr std::array kHealthMembers{
    JniMember{"zombie/characters/IsoPlayer", "getBodyDamage", "()Lzombie/characters/BodyDamage/BodyDamage;", false},
    JniMember{"zombie/characters/BodyDamage/BodyDamage", "RestoreToFullHealth", "()V", false},
    JniMember{"zombie/network/GameClient", "sendPlayerDamage", "(Lzombie/characters/IsoPlayer;)V", true},
    JniMember{"zombie/characters/IsoPlayer", "isGodMod", "()Z", false},
    JniMember{"zombie/characters/IsoPlayer", "setGodMod", "(ZZ)V", false},
    JniMember{"zombie/characters/IsoPlayer", "setAvoidDamage", "(Z)V", false},
};

inline constexpr std::array kSkillMembers{
    JniMember{"zombie/characters/IsoGameCharacter", "getXp", "()Lzombie/characters/IsoGameCharacter$XP;", false},
    JniMember{"zombie/characters/IsoGameCharacter$XP", "getXP", "(Lzombie/characters/skills/PerkFactory$Perk;)F", false},
    JniMember{"zombie/characters/IsoGameCharacter$XP", "AddXP", "(Lzombie/characters/skills/PerkFactory$Perk;F)V", false},
    JniMember{"zombie/characters/IsoGameCharacter", "getPerkLevel", "(Lzombie/characters/skills/PerkFactory$Perk;)I", false},
};

inline constexpr std::array kWeaponMembers{
    JniMember{"zombie/characters/IsoPlayer", "getPrimaryHandItem", "()Lzombie/inventory/InventoryItem;", false},
    JniMember{"zombie/inventory/types/HandWeapon", "getCurrentAmmoCount", "()I", false},
    JniMember{"zombie/inventory/types/HandWeapon", "setCurrentAmmoCount", "(I)V", false},
    JniMember{"zombie/inventory/types/HandWeapon", "setWeaponPart", "(Lzombie/inventory/types/WeaponPart;)V", false},
    JniMember{"zombie/inventory/types/HandWeapon", "getWeaponPart", "(Ljava/lang/String;)Lzombie/inventory/types/WeaponPart;", false},
};

inline constexpr std::array kBallisticsMembers{
    JniMember{"zombie/characters/IsoPlayer", "getBallisticsController", "()Lzombie/core/physics/BallisticsController;", false},
    JniMember{"zombie/core/physics/BallisticsController", "getProjectileSpread", "()F", false},
    JniMember{"zombie/core/physics/BallisticsController", "setProjectileSpread", "(F)V", false},
    JniMember{"zombie/core/physics/BallisticsController", "getHitChance", "()F", false},
    JniMember{"zombie/core/physics/BallisticsController", "setHitChance", "(F)V", false},
};

}  // namespace pztrainer::reference


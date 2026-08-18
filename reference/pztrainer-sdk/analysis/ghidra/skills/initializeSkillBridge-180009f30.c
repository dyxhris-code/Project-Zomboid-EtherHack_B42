/*
 * Semantic name: initializeSkillBridge
 * Address: 0x180009f30
 * Module: skills
 * Confidence: medium
 * Summary: Caches skill and experience JNI methods.
 * Ghidra function: initializeSkillBridge
 * Callers:
 *   - FUN_18000b8a0 @ 0x18000b8a0
 *   - FUN_18000be40 @ 0x18000be40
 *   - FUN_18000c190 @ 0x18000c190
 * Callees:
 *   - findGlobalJniClass @ 0x180009cc0
 * Referenced strings:
 *   - zombie/network/GameClient
 *   - zombie/network/GameServer
 *   - zombie/characters/IsoPlayer
 *   - zombie/characters/IsoGameCharacter$XP
 *   - zombie/characters/skills/PerkFactory$Perks
 *   - zombie/characters/skills/PerkFactory$Perk
 *   - zombie/radio/ZomboidRadio
 *   - zombie/radio/devices/WaveSignalDevice
 *   - zombie/radio/devices/DeviceData
 *   - java/util/ArrayList
 *   - zombie/Lua/LuaManager
 *   - se/krka/kahlua/vm/KahluaTable
 *   - se/krka/kahlua/integration/LuaCaller
 *   - se/krka/kahlua/integration/LuaReturn
 *   - java/lang/Object
 *   - java/lang/Number
 *   - client
 *   - server
 *   - ()Lzombie/characters/IsoPlayer;
 *   - getInstance
 *   - ()Lzombie/iso/IsoGridSquare;
 *   - getCurrentSquare
 *   - ()Lzombie/characters/IsoGameCharacter$XP;
 *   - getXp
 *   - (Lzombie/characters/skills/PerkFactory$Perk;)I
 *   - getPerkLevel
 *   - (Lzombie/characters/skills/PerkFactory$Perk;)F
 *   - getXP
 *   - getMultiplier
 *   - (Lzombie/characters/skills/PerkFactory$Perk;F)V
 *   - AddXP
 *   - getTotalXpForLevel
 *   - ()Lzombie/radio/ZomboidRadio;
 *   - ()Ljava/util/ArrayList;
 *   - getDevices
 *   - (I)Ljava/lang/Object;
 *   - ()Lzombie/radio/devices/DeviceData;
 *   - getDeviceData
 *   - getIsTurnedOn
 *   - getChannel
 *   - getIsTelevision
 *   - getDeviceVolume
 *   - isPlayingMedia
 *   - isNoTransmit
 *   - (IIILjava/lang/String;Ljava/lang/String;Ljava/lang/String;FFFIZ)V
 *   - sendIsoWaveSignal
 *   - (Ljava/lang/String;)Ljava/lang/Object;
 *   - getTableObject
 *   - getFunctionObject
 *   - (Ljava/lang/Object;)Ljava/lang/Object;
 *   - rawget
 *   - Lse/krka/kahlua/integration/LuaCaller;
 *   - caller
 *   - Lse/krka/kahlua/vm/KahluaThread;
 *   - thread
 *   - isSuccess
 *   - ()Ljava/lang/Object;
 *   - getFirst
 *   - intValue
 */


/* Caches skill and experience JNI methods. */

undefined8 initializeSkillBridge(longlong *param_1)

{
  undefined8 in_RAX;
  ulonglong uVar1;
  
  if (DAT_180101270 != '\0') {
    return CONCAT71((int7)((ulonglong)in_RAX >> 8),1);
  }
  DAT_180101278 = findGlobalJniClass(param_1,"zombie/network/GameClient");
  DAT_180101280 = findGlobalJniClass(param_1,"zombie/network/GameServer");
  DAT_180101288 = findGlobalJniClass(param_1,"zombie/characters/IsoPlayer");
  DAT_180101290 = findGlobalJniClass(param_1,"zombie/characters/IsoGameCharacter$XP");
  DAT_180101298 = findGlobalJniClass(param_1,"zombie/characters/skills/PerkFactory$Perks");
  DAT_1801012a0 = findGlobalJniClass(param_1,"zombie/characters/skills/PerkFactory$Perk");
  DAT_1801012a8 = findGlobalJniClass(param_1,"zombie/radio/ZomboidRadio");
  DAT_1801012b0 = findGlobalJniClass(param_1,"zombie/radio/devices/WaveSignalDevice");
  DAT_1801012b8 = findGlobalJniClass(param_1,"zombie/radio/devices/DeviceData");
  DAT_1801012c0 = findGlobalJniClass(param_1,"java/util/ArrayList");
  DAT_1801012c8 = findGlobalJniClass(param_1,"zombie/Lua/LuaManager");
  DAT_1801012d0 = findGlobalJniClass(param_1,"se/krka/kahlua/vm/KahluaTable");
  DAT_1801012d8 = findGlobalJniClass(param_1,"se/krka/kahlua/integration/LuaCaller");
  DAT_1801012e0 = findGlobalJniClass(param_1,"se/krka/kahlua/integration/LuaReturn");
  DAT_1801012e8 = findGlobalJniClass(param_1,"java/lang/Object");
  DAT_1801012f0 = findGlobalJniClass(param_1,"java/lang/Number");
  if (((((DAT_180101278 != 0) && (DAT_180101280 != 0)) && (DAT_180101288 != 0)) &&
      (((DAT_180101290 != 0 && (DAT_180101298 != 0)) &&
       ((DAT_1801012a0 != 0 && ((DAT_1801012a8 != 0 && (DAT_1801012b0 != 0)))))))) &&
     ((DAT_1801012b8 != 0 &&
      (((((DAT_1801012c0 != 0 && (DAT_1801012c8 != 0)) && (DAT_1801012d0 != 0)) &&
        ((DAT_1801012d8 != 0 && (DAT_1801012e0 != 0)))) &&
       ((DAT_1801012e8 != 0 && (DAT_1801012f0 != 0)))))))) {
    DAT_1801012f8 = (**(code **)(*param_1 + 0x480))(param_1,DAT_180101278,"client",&DAT_1800d788c);
    DAT_180101300 = (**(code **)(*param_1 + 0x480))(param_1,DAT_180101280,"server",&DAT_1800d788c);
    DAT_180101308 =
         (**(code **)(*param_1 + 0x388))
                   (param_1,DAT_180101288,"getInstance","()Lzombie/characters/IsoPlayer;");
    DAT_180101310 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180101288,"getCurrentSquare","()Lzombie/iso/IsoGridSquare;");
    DAT_180101318 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180101288,"getXp","()Lzombie/characters/IsoGameCharacter$XP;");
    DAT_180101320 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180101288,"getPerkLevel",
                    "(Lzombie/characters/skills/PerkFactory$Perk;)I");
    DAT_180101328 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180101288,&DAT_1800d79f4,&DAT_1800d79f0);
    DAT_180101330 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180101288,&DAT_1800d79fc,&DAT_1800d79f0);
    DAT_180101338 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180101288,&DAT_1800d7a04,&DAT_1800d79f0);
    DAT_180101340 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180101290,"getXP","(Lzombie/characters/skills/PerkFactory$Perk;)F");
    DAT_180101348 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180101290,"getMultiplier",
                    "(Lzombie/characters/skills/PerkFactory$Perk;)F");
    DAT_180101350 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180101290,"AddXP","(Lzombie/characters/skills/PerkFactory$Perk;F)V")
    ;
    DAT_180101358 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_1801012a0,"getTotalXpForLevel",&DAT_1800d7de0);
    DAT_180101360 =
         (**(code **)(*param_1 + 0x388))
                   (param_1,DAT_1801012a8,"getInstance","()Lzombie/radio/ZomboidRadio;");
    DAT_180101368 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_1801012a8,"getDevices","()Ljava/util/ArrayList;");
    DAT_180101370 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_1801012c0,&DAT_1800d7978,&DAT_1800d7974);
    DAT_180101378 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_1801012c0,&DAT_1800d7998,"(I)Ljava/lang/Object;");
    DAT_180101380 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_1801012b0,"getDeviceData","()Lzombie/radio/devices/DeviceData;");
    DAT_180101388 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_1801012b0,&DAT_1800d79f4,&DAT_1800d79f0);
    DAT_180101390 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_1801012b0,&DAT_1800d79fc,&DAT_1800d79f0);
    DAT_180101398 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_1801012b0,&DAT_1800d7a04,&DAT_1800d79f0);
    DAT_1801013a0 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_1801012b8,"getIsTurnedOn",&DAT_1800d79c4);
    DAT_1801013a8 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_1801012b8,"getChannel",&DAT_1800d7974);
    DAT_1801013b0 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_1801012b8,"getIsTelevision",&DAT_1800d79c4);
    DAT_1801013b8 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_1801012b8,"getDeviceVolume",&DAT_1800d79f0);
    DAT_1801013c0 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_1801012b8,"isPlayingMedia",&DAT_1800d79c4);
    DAT_1801013c8 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_1801012b8,"isNoTransmit",&DAT_1800d79c4);
    DAT_1801013d0 =
         (**(code **)(*param_1 + 0x388))
                   (param_1,DAT_180101278,"sendIsoWaveSignal",
                    "(IIILjava/lang/String;Ljava/lang/String;Ljava/lang/String;FFFIZ)V");
    DAT_1801013d8 =
         (**(code **)(*param_1 + 0x388))
                   (param_1,DAT_1801012c8,"getTableObject","(Ljava/lang/String;)Ljava/lang/Object;")
    ;
    DAT_1801013e0 =
         (**(code **)(*param_1 + 0x388))
                   (param_1,DAT_1801012c8,"getFunctionObject",
                    "(Ljava/lang/String;)Ljava/lang/Object;");
    DAT_1801013e8 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_1801012d0,"rawget","(Ljava/lang/Object;)Ljava/lang/Object;");
    DAT_1801013f0 =
         (**(code **)(*param_1 + 0x480))
                   (param_1,DAT_1801012c8,"caller","Lse/krka/kahlua/integration/LuaCaller;");
    DAT_1801013f8 =
         (**(code **)(*param_1 + 0x480))
                   (param_1,DAT_1801012c8,"thread","Lse/krka/kahlua/vm/KahluaThread;");
    DAT_180101400 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_1801012e0,"isSuccess",&DAT_1800d79c4);
    DAT_180101408 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_1801012e0,"getFirst","()Ljava/lang/Object;");
    DAT_180101410 = (**(code **)(*param_1 + 0x108))(param_1,DAT_1801012f0,"intValue",&DAT_1800d7974)
    ;
    uVar1 = (**(code **)(*param_1 + 0x720))(param_1);
    if ((char)uVar1 == '\0') {
      if (((((((DAT_1801012f8 != 0) && (DAT_180101300 != 0)) &&
             ((DAT_180101308 != 0 &&
              (((DAT_180101310 != 0 && (DAT_180101318 != 0)) && (DAT_180101320 != 0)))))) &&
            (((DAT_180101328 != 0 && (DAT_180101330 != 0)) && (DAT_180101338 != 0)))) &&
           ((DAT_180101340 != 0 && (DAT_180101348 != 0)))) &&
          (((((DAT_180101350 != 0 &&
              (((DAT_180101358 != 0 && (DAT_180101360 != 0)) && (DAT_180101368 != 0)))) &&
             ((DAT_180101370 != 0 && (DAT_180101378 != 0)))) && (DAT_180101380 != 0)) &&
           (((((DAT_180101388 != 0 && (DAT_180101390 != 0)) &&
              ((DAT_180101398 != 0 &&
               (((((DAT_1801013a0 != 0 && (DAT_1801013a8 != 0)) && (DAT_1801013b0 != 0)) &&
                 ((DAT_1801013b8 != 0 && (DAT_1801013c0 != 0)))) && (DAT_1801013c8 != 0)))))) &&
             ((DAT_1801013d0 != 0 && (DAT_1801013d8 != 0)))) &&
            ((DAT_1801013e0 != 0 &&
             (((DAT_1801013e8 != 0 && (DAT_1801013f0 != 0)) && (DAT_1801013f8 != 0)))))))))) &&
         (((DAT_180101400 != 0 && (DAT_180101408 != 0)) && (DAT_180101410 != 0)))) {
        DAT_180101270 = 1;
        return CONCAT71((int7)(uVar1 >> 8),1);
      }
    }
    else {
      uVar1 = (**(code **)(*param_1 + 0x88))(param_1);
    }
    DAT_180101270 = 0;
    return uVar1 & 0xffffffffffffff00;
  }
  return DAT_1801012f0 & 0xffffffffffffff00;
}


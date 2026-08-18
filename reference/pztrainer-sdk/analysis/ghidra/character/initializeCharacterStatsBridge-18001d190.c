/*
 * Semantic name: initializeCharacterStatsBridge
 * Address: 0x18001d190
 * Module: character
 * Confidence: medium
 * Summary: Caches character-stat JNI methods.
 * Ghidra function: initializeCharacterStatsBridge
 * Callers:
 *   - FUN_18001e8d0 @ 0x18001e8d0
 *   - FUN_18001ec30 @ 0x18001ec30
 *   - FUN_18001ef80 @ 0x18001ef80
 *   - FUN_18001f250 @ 0x18001f250
 * Callees:
 *   - findGlobalJniClass @ 0x180009cc0
 * Referenced strings:
 *   - zombie/network/GameClient
 *   - zombie/network/GameServer
 *   - zombie/characters/IsoPlayer
 *   - zombie/characters/Stats
 *   - zombie/characters/CharacterStat
 *   - zombie/characters/Role
 *   - zombie/characters/Capability
 *   - zombie/network/PacketTypes$PacketType
 *   - zombie/network/packets/INetworkPacket
 *   - zombie/network/packets/SyncPlayerStatsPacket
 *   - java/lang/Integer
 *   - java/lang/Object
 *   - client
 *   - server
 *   - [Lzombie/characters/CharacterStat;
 *   - ORDERED_STATS
 *   - Lzombie/characters/Capability;
 *   - CanModifyBodyStats
 *   - Lzombie/network/PacketTypes$PacketType;
 *   - SyncPlayerStats
 *   - ()Lzombie/characters/IsoPlayer;
 *   - getInstance
 *   - ()Lzombie/characters/Stats;
 *   - getStats
 *   - ()Lzombie/characters/Role;
 *   - getRole
 *   - (Lzombie/characters/Capability;)Z
 *   - hasCapability
 *   - (Lzombie/characters/CharacterStat;)F
 *   - (Lzombie/characters/CharacterStat;F)Z
 *   - (Lzombie/characters/CharacterStat;)Z
 *   - reset
 *   - ()Ljava/lang/String;
 *   - getId
 *   - getMinimumValue
 *   - getMaximumValue
 *   - getDefaultValue
 *   - (Lzombie/characters/CharacterStat;)I
 *   - getBitMaskForStat
 *   - (I)Ljava/lang/Integer;
 *   - valueOf
 *   - (Lzombie/network/PacketTypes$PacketType;[Ljava/lang/Object;)V
 *   - getSleepingTabletEffect
 *   - getSleepingTabletDelta
 *   - setSleepingTabletEffect
 *   - setSleepingTabletDelta
 *   - SleepingTablet
 *   - getBetaEffect
 *   - getBetaDelta
 *   - setBetaEffect
 *   - setBetaDelta
 *   - BetaBlockers
 *   - getDepressEffect
 *   - getDepressDelta
 *   - setDepressEffect
 *   - setDepressDelta
 *   - BetaAntiDepress
 *   - getPainEffect
 *   - getPainDelta
 *   - setPainEffect
 *   - setPainDelta
 *   - PainMeds
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Caches character-stat JNI methods. */

undefined8 initializeCharacterStatsBridge(longlong *param_1)

{
  bool bVar1;
  undefined8 in_RAX;
  ulonglong uVar2;
  
  if (DAT_180101ad0 != '\0') {
    return CONCAT71((int7)((ulonglong)in_RAX >> 8),1);
  }
  DAT_180101ad8 = findGlobalJniClass(param_1,"zombie/network/GameClient");
  DAT_180101ae0 = findGlobalJniClass(param_1,"zombie/network/GameServer");
  DAT_180101ae8 = findGlobalJniClass(param_1,"zombie/characters/IsoPlayer");
  DAT_180101af0 = findGlobalJniClass(param_1,"zombie/characters/Stats");
  DAT_180101af8 = findGlobalJniClass(param_1,"zombie/characters/CharacterStat");
  DAT_180101b00 = findGlobalJniClass(param_1,"zombie/characters/Role");
  DAT_180101b08 = findGlobalJniClass(param_1,"zombie/characters/Capability");
  DAT_180101b10 = findGlobalJniClass(param_1,"zombie/network/PacketTypes$PacketType");
  DAT_180101b18 = findGlobalJniClass(param_1,"zombie/network/packets/INetworkPacket");
  DAT_180101b20 = findGlobalJniClass(param_1,"zombie/network/packets/SyncPlayerStatsPacket");
  DAT_180101b28 = findGlobalJniClass(param_1,"java/lang/Integer");
  DAT_180101b30 = findGlobalJniClass(param_1,"java/lang/Object");
  if ((((((DAT_180101ad8 != 0) && (DAT_180101ae0 != 0)) && (DAT_180101ae8 != 0)) &&
       ((DAT_180101af0 != 0 && (DAT_180101af8 != 0)))) && (DAT_180101b00 != 0)) &&
     (((DAT_180101b08 != 0 && (DAT_180101b10 != 0)) &&
      ((DAT_180101b18 != 0 &&
       (((DAT_180101b20 != 0 && (DAT_180101b28 != 0)) && (DAT_180101b30 != 0)))))))) {
    DAT_180101b38 = (**(code **)(*param_1 + 0x480))(param_1,DAT_180101ad8,"client",&DAT_1800d788c);
    DAT_180101b40 = (**(code **)(*param_1 + 0x480))(param_1,DAT_180101ae0,"server",&DAT_1800d788c);
    DAT_180101b48 =
         (**(code **)(*param_1 + 0x480))
                   (param_1,DAT_180101af8,"ORDERED_STATS","[Lzombie/characters/CharacterStat;");
    DAT_180101b50 =
         (**(code **)(*param_1 + 0x480))
                   (param_1,DAT_180101b08,"CanModifyBodyStats","Lzombie/characters/Capability;");
    DAT_180101b58 =
         (**(code **)(*param_1 + 0x480))
                   (param_1,DAT_180101b10,"SyncPlayerStats",
                    "Lzombie/network/PacketTypes$PacketType;");
    DAT_180101b60 =
         (**(code **)(*param_1 + 0x388))
                   (param_1,DAT_180101ae8,"getInstance","()Lzombie/characters/IsoPlayer;");
    DAT_180101b68 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180101ae8,"getStats","()Lzombie/characters/Stats;");
    DAT_180101b70 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180101ae8,"getRole","()Lzombie/characters/Role;");
    DAT_180101b78 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180101b00,"hasCapability","(Lzombie/characters/Capability;)Z");
    DAT_180101b80 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180101af0,&DAT_1800d7998,"(Lzombie/characters/CharacterStat;)F");
    DAT_180101b88 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180101af0,&DAT_1800dec7c,"(Lzombie/characters/CharacterStat;F)Z");
    DAT_180101b90 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180101af0,"reset","(Lzombie/characters/CharacterStat;)Z");
    DAT_180101b98 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180101af8,"getId","()Ljava/lang/String;");
    DAT_180101ba0 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180101af8,"getMinimumValue",&DAT_1800d79f0);
    DAT_180101ba8 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180101af8,"getMaximumValue",&DAT_1800d79f0);
    DAT_180101bb0 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180101af8,"getDefaultValue",&DAT_1800d79f0);
    DAT_180101bb8 =
         (**(code **)(*param_1 + 0x388))
                   (param_1,DAT_180101b20,"getBitMaskForStat","(Lzombie/characters/CharacterStat;)I"
                   );
    DAT_180101bc0 =
         (**(code **)(*param_1 + 0x388))(param_1,DAT_180101b28,"valueOf","(I)Ljava/lang/Integer;");
    DAT_180101bc8 =
         (**(code **)(*param_1 + 0x388))
                   (param_1,DAT_180101b18,&DAT_1800e0728,
                    "(Lzombie/network/PacketTypes$PacketType;[Ljava/lang/Object;)V");
    DAT_180101bd0 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180101ae8,"getSleepingTabletEffect",&DAT_1800d79f0);
    DAT_180101bf0 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180101ae8,"getSleepingTabletDelta",&DAT_1800d79f0);
    DAT_180101c10 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180101ae8,"setSleepingTabletEffect",&DAT_1800d7b10);
    DAT_180101c30 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180101ae8,"setSleepingTabletDelta",&DAT_1800d7b10);
    DAT_180101c50 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180101ae8,"SleepingTablet",&DAT_1800d7b10);
    DAT_180101bd8 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180101ae8,"getBetaEffect",&DAT_1800d79f0);
    DAT_180101bf8 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180101ae8,"getBetaDelta",&DAT_1800d79f0);
    DAT_180101c18 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180101ae8,"setBetaEffect",&DAT_1800d7b10);
    DAT_180101c38 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180101ae8,"setBetaDelta",&DAT_1800d7b10);
    DAT_180101c58 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180101ae8,"BetaBlockers",&DAT_1800d7b10);
    DAT_180101be0 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180101ae8,"getDepressEffect",&DAT_1800d79f0);
    DAT_180101c00 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180101ae8,"getDepressDelta",&DAT_1800d79f0);
    DAT_180101c20 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180101ae8,"setDepressEffect",&DAT_1800d7b10);
    DAT_180101c40 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180101ae8,"setDepressDelta",&DAT_1800d7b10);
    DAT_180101c60 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180101ae8,"BetaAntiDepress",&DAT_1800d7b10);
    DAT_180101be8 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180101ae8,"getPainEffect",&DAT_1800d79f0);
    DAT_180101c08 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180101ae8,"getPainDelta",&DAT_1800d79f0);
    DAT_180101c28 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180101ae8,"setPainEffect",&DAT_1800d7b10);
    DAT_180101c48 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180101ae8,"setPainDelta",&DAT_1800d7b10);
    _DAT_180101c68 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180101ae8,"PainMeds",&DAT_1800d7b10);
    if ((((DAT_180101bd0 == 0) || (DAT_180101bf0 == 0)) ||
        ((DAT_180101c10 == 0 || ((DAT_180101c30 == 0 || (DAT_180101c50 == 0)))))) ||
       ((DAT_180101bd8 == 0 ||
        ((((((DAT_180101bf8 == 0 || (DAT_180101c18 == 0)) || (DAT_180101c38 == 0)) ||
           (((DAT_180101c58 == 0 || (DAT_180101be0 == 0)) ||
            ((DAT_180101c00 == 0 || ((DAT_180101c20 == 0 || (DAT_180101c40 == 0)))))))) ||
          (DAT_180101c60 == 0)) ||
         ((((DAT_180101be8 == 0 || (DAT_180101c08 == 0)) || (DAT_180101c28 == 0)) ||
          ((DAT_180101c48 == 0 || (_DAT_180101c68 == 0)))))))))) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    uVar2 = (**(code **)(*param_1 + 0x720))(param_1);
    if ((char)uVar2 == '\0') {
      if (((((bVar1) && (DAT_180101b38 != 0)) &&
           ((((DAT_180101b40 != 0 &&
              (((DAT_180101b48 != 0 && (DAT_180101b50 != 0)) && (DAT_180101b58 != 0)))) &&
             (((DAT_180101b60 != 0 && (DAT_180101b68 != 0)) && (DAT_180101b70 != 0)))) &&
            (((DAT_180101b78 != 0 && (DAT_180101b80 != 0)) &&
             ((DAT_180101b88 != 0 &&
              (((DAT_180101b90 != 0 && (DAT_180101b98 != 0)) && (DAT_180101ba0 != 0)))))))))) &&
          ((DAT_180101ba8 != 0 && (DAT_180101bb0 != 0)))) &&
         ((DAT_180101bb8 != 0 && ((DAT_180101bc0 != 0 && (DAT_180101bc8 != 0)))))) {
        DAT_180101ad0 = 1;
        return CONCAT71((int7)(uVar2 >> 8),1);
      }
    }
    else {
      uVar2 = (**(code **)(*param_1 + 0x88))(param_1);
    }
    DAT_180101ad0 = 0;
    return uVar2 & 0xffffffffffffff00;
  }
  return DAT_180101b30 & 0xffffffffffffff00;
}


/*
 * Semantic name: initializePlayerDamageBridge
 * Address: 0x180021840
 * Module: player
 * Confidence: medium
 * Summary: Caches player health and damage JNI methods.
 * Ghidra function: initializePlayerDamageBridge
 * Callers:
 *   - FUN_180021c30 @ 0x180021c30
 * Callees:
 *   - findGlobalJniClass @ 0x180009cc0
 * Referenced strings:
 *   - zombie/network/GameClient
 *   - zombie/network/GameServer
 *   - zombie/characters/IsoPlayer
 *   - zombie/characters/BodyDamage/BodyDamage
 *   - zombie/characters/BodyDamage/BodyPart
 *   - java/util/ArrayList
 *   - client
 *   - server
 *   - ()Lzombie/characters/IsoPlayer;
 *   - getInstance
 *   - ()Lzombie/characters/BodyDamage/BodyDamage;
 *   - getBodyDamage
 *   - ()Ljava/util/ArrayList;
 *   - getBodyParts
 *   - (I)Ljava/lang/Object;
 *   - getHealth
 *   - RestoreToFullHealth
 *   - (Lzombie/characters/IsoPlayer;)V
 *   - sendPlayerDamage
 *   - isGodMod
 *   - avoidDamage
 *   - (ZZ)V
 *   - setGodMod
 *   - setAvoidDamage
 */


/* Caches player health and damage JNI methods. */

undefined8 initializePlayerDamageBridge(longlong *param_1)

{
  undefined8 in_RAX;
  ulonglong uVar1;
  
  if (DAT_180101d60 != '\0') {
    return CONCAT71((int7)((ulonglong)in_RAX >> 8),1);
  }
  DAT_180101d68 = findGlobalJniClass(param_1,"zombie/network/GameClient");
  DAT_180101d70 = findGlobalJniClass(param_1,"zombie/network/GameServer");
  DAT_180101d78 = findGlobalJniClass(param_1,"zombie/characters/IsoPlayer");
  DAT_180101d80 = findGlobalJniClass(param_1,"zombie/characters/BodyDamage/BodyDamage");
  DAT_180101d88 = findGlobalJniClass(param_1,"zombie/characters/BodyDamage/BodyPart");
  DAT_180101d90 = findGlobalJniClass(param_1,"java/util/ArrayList");
  if (((((DAT_180101d68 != 0) && (DAT_180101d70 != 0)) && (DAT_180101d78 != 0)) &&
      ((DAT_180101d80 != 0 && (DAT_180101d88 != 0)))) && (DAT_180101d90 != 0)) {
    DAT_180101d98 = (**(code **)(*param_1 + 0x480))(param_1,DAT_180101d68,"client",&DAT_1800d788c);
    DAT_180101da0 = (**(code **)(*param_1 + 0x480))(param_1,DAT_180101d70,"server",&DAT_1800d788c);
    DAT_180101da8 =
         (**(code **)(*param_1 + 0x388))
                   (param_1,DAT_180101d78,"getInstance","()Lzombie/characters/IsoPlayer;");
    DAT_180101db0 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180101d78,"getBodyDamage",
                    "()Lzombie/characters/BodyDamage/BodyDamage;");
    DAT_180101db8 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180101d80,"getBodyParts","()Ljava/util/ArrayList;");
    DAT_180101dc0 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180101d90,&DAT_1800d7978,&DAT_1800d7974);
    DAT_180101dc8 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180101d90,&DAT_1800d7998,"(I)Ljava/lang/Object;");
    DAT_180101dd0 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180101d88,"getHealth",&DAT_1800d79f0);
    DAT_180101dd8 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180101d80,"RestoreToFullHealth",&DAT_1800d8078)
    ;
    DAT_180101de0 =
         (**(code **)(*param_1 + 0x388))
                   (param_1,DAT_180101d68,"sendPlayerDamage","(Lzombie/characters/IsoPlayer;)V");
    DAT_180101de8 = (**(code **)(*param_1 + 0x108))(param_1,DAT_180101d78,"isGodMod",&DAT_1800d79c4)
    ;
    DAT_180101df0 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180101d78,"avoidDamage",&DAT_1800d79c4);
    DAT_180101df8 = (**(code **)(*param_1 + 0x108))(param_1,DAT_180101d78,"setGodMod","(ZZ)V");
    DAT_180101e00 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180101d78,"setAvoidDamage",&DAT_1800de9e4);
    uVar1 = (**(code **)(*param_1 + 0x720))(param_1);
    if ((char)uVar1 == '\0') {
      if (((((DAT_180101d98 != 0) && (DAT_180101da0 != 0)) &&
           ((DAT_180101da8 != 0 &&
            (((DAT_180101db0 != 0 && (DAT_180101db8 != 0)) && (DAT_180101dc0 != 0)))))) &&
          ((DAT_180101dc8 != 0 && (DAT_180101dd0 != 0)))) &&
         ((DAT_180101dd8 != 0 &&
          (((DAT_180101de0 != 0 && (DAT_180101de8 != 0)) &&
           ((DAT_180101df0 != 0 && ((DAT_180101df8 != 0 && (DAT_180101e00 != 0)))))))))) {
        DAT_180101d60 = 1;
        return CONCAT71((int7)(uVar1 >> 8),1);
      }
    }
    else {
      uVar1 = (**(code **)(*param_1 + 0x88))(param_1);
    }
    DAT_180101d60 = 0;
    return uVar1 & 0xffffffffffffff00;
  }
  return DAT_180101d90 & 0xffffffffffffff00;
}


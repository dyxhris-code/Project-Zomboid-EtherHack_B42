/*
 * Semantic name: initializeBallisticsBridge
 * Address: 0x18002a7c0
 * Module: ballistics
 * Confidence: medium
 * Summary: Caches projectile and ballistics JNI methods.
 * Ghidra function: initializeBallisticsBridge
 * Callers:
 *   - FUN_18002d670 @ 0x18002d670
 * Callees:
 *   - findGlobalJniClass @ 0x180009cc0
 * Referenced strings:
 *   - zombie/characters/IsoPlayer
 *   - zombie/inventory/InventoryItem
 *   - zombie/inventory/types/HandWeapon
 *   - zombie/core/physics/BallisticsController
 *   - zombie/iso/Vector3
 *   - zombie/iso/Vector2
 *   - zombie/input/Mouse
 *   - zombie/iso/IsoUtils
 *   - zombie/network/GameClient
 *   - zombie/core/raknet/UdpConnection
 *   - zombie/CombatManager
 *   - zombie/ai/states/SwipeStatePlayer
 *   - ()Lzombie/characters/IsoPlayer;
 *   - getInstance
 *   - getID
 *   - ()Lzombie/inventory/InventoryItem;
 *   - getPrimaryHandItem
 *   - isAiming
 *   - setIsAiming
 *   - isForceAim
 *   - setForceAim
 *   - isCharging
 *   - updateBallistics
 *   - setAngleFromAim
 *   - isAttackStarted
 *   - ()Lzombie/core/physics/BallisticsController;
 *   - getBallisticsController
 *   - setRecoilVarX
 *   - setRecoilVarY
 *   - getAimOriginPosX
 *   - getAimOriginPosY
 *   - getAimOriginPosZ
 *   - getForwardDirectionX
 *   - getForwardDirectionY
 *   - (FF)V
 *   - setForwardDirection
 *   - setTargetVerticalAimAngle
 *   - setCurrentVerticalAimAngle
 *   - setMoveDelta
 *   - setMoving
 *   - setRunning
 *   - setSprinting
 *   - isAllowRun
 *   - setAllowRun
 *   - isAllowSprint
 *   - setAllowSprint
 *   - isIgnoreInputsForDirection
 *   - setIgnoreInputsForDirection
 *   - setForceRun
 *   - setForceSprint
 *   - isBlockMovement
 *   - setBlockMovement
 *   - Lzombie/iso/Vector2;
 *   - playerMoveDir
 *   - ()Lzombie/iso/Vector2;
 *   - getMoveForwardVec
 *   - ()Ljava/lang/String;
 *   - getFullType
 *   - getCurrentAmmoCount
 *   - isRanged
 *   - getMaxRange
 *   - getProjectileSpread
 *   - setProjectileSpread
 *   - getHitChance
 *   - setHitChance
 *   - getMinDamage
 *   - setMinDamage
 *   - getMaxDamage
 *   - setMaxDamage
 *   - getAimingTime
 *   - setAimingTime
 *   - setAimingDelay
 *   - setBeenMovingFor
 *   - ()Lzombie/iso/Vector3;
 *   - getIsoAimingPosition
 *   - Lzombie/iso/Vector3;
 *   - targetPosition
 *   - (FFF)Lzombie/iso/Vector3;
 *   - (FF)Lzombie/iso/Vector2;
 *   - getXA
 *   - getYA
 *   - (FFFI)F
 *   - XToScreenExact
 *   - YToScreenExact
 *   - client
 *   - Lzombie/core/raknet/UdpConnection;
 *   - connection
 *   - getAveragePing
 *   - ()Lzombie/CombatManager;
 *   - ()Lzombie/ai/states/SwipeStatePlayer;
 *   - instance
 *   - ()Lzombie/AttackType;
 *   - getAttackType
 */


/* Caches projectile and ballistics JNI methods. */

undefined8 initializeBallisticsBridge(longlong *param_1)

{
  undefined8 in_RAX;
  ulonglong uVar1;
  
  if (DAT_180102490 != '\0') {
    return CONCAT71((int7)((ulonglong)in_RAX >> 8),1);
  }
  DAT_180102498 = findGlobalJniClass(param_1,"zombie/characters/IsoPlayer");
  DAT_1801024a0 = findGlobalJniClass(param_1,"zombie/inventory/InventoryItem");
  DAT_1801024a8 = findGlobalJniClass(param_1,"zombie/inventory/types/HandWeapon");
  DAT_1801024b0 = findGlobalJniClass(param_1,"zombie/core/physics/BallisticsController");
  DAT_1801024b8 = findGlobalJniClass(param_1,"zombie/iso/Vector3");
  DAT_1801024c0 = findGlobalJniClass(param_1,"zombie/iso/Vector2");
  DAT_1801024c8 = findGlobalJniClass(param_1,"zombie/input/Mouse");
  DAT_1801024d0 = findGlobalJniClass(param_1,"zombie/iso/IsoUtils");
  DAT_1801024d8 = findGlobalJniClass(param_1,"zombie/network/GameClient");
  DAT_1801024e0 = findGlobalJniClass(param_1,"zombie/core/raknet/UdpConnection");
  DAT_1801024e8 = findGlobalJniClass(param_1,"zombie/CombatManager");
  DAT_1801024f0 = findGlobalJniClass(param_1,"zombie/ai/states/SwipeStatePlayer");
  if (((((((DAT_180102498 != 0) && (DAT_1801024a0 != 0)) && (DAT_1801024a8 != 0)) &&
        ((DAT_1801024b0 != 0 && (DAT_1801024b8 != 0)))) && (DAT_1801024c0 != 0)) &&
      ((DAT_1801024c8 != 0 && (DAT_1801024d0 != 0)))) &&
     ((DAT_1801024d8 != 0 &&
      (((DAT_1801024e0 != 0 && (DAT_1801024e8 != 0)) && (DAT_1801024f0 != 0)))))) {
    DAT_1801024f8 =
         (**(code **)(*param_1 + 0x388))
                   (param_1,DAT_180102498,"getInstance","()Lzombie/characters/IsoPlayer;");
    DAT_1801026f8 = (**(code **)(*param_1 + 0x108))(param_1,DAT_180102498,"getID",&DAT_1800d7974);
    DAT_180102500 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180102498,"getPrimaryHandItem","()Lzombie/inventory/InventoryItem;")
    ;
    DAT_180102508 = (**(code **)(*param_1 + 0x108))(param_1,DAT_180102498,"isAiming",&DAT_1800d79c4)
    ;
    DAT_180102510 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180102498,"setIsAiming",&DAT_1800de9e4);
    DAT_180102518 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180102498,"isForceAim",&DAT_1800d79c4);
    DAT_180102520 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180102498,"setForceAim",&DAT_1800de9e4);
    DAT_180102528 =
         (**(code **)(*param_1 + 0x2f0))(param_1,DAT_180102498,"isCharging",&DAT_1800d788c);
    DAT_180102530 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180102498,"updateBallistics",&DAT_1800d8078);
    DAT_180102538 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180102498,"setAngleFromAim",&DAT_1800d8078);
    DAT_180102540 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180102498,"isAttackStarted",&DAT_1800d79c4);
    DAT_180102548 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180102498,"getBallisticsController",
                    "()Lzombie/core/physics/BallisticsController;");
    DAT_180102550 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180102498,"setRecoilVarX",&DAT_1800d7b10);
    DAT_180102558 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180102498,"setRecoilVarY",&DAT_1800d7b10);
    DAT_180102560 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180102498,"getAimOriginPosX",&DAT_1800d79f0);
    DAT_180102568 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180102498,"getAimOriginPosY",&DAT_1800d79f0);
    DAT_180102570 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180102498,"getAimOriginPosZ",&DAT_1800d79f0);
    DAT_180102578 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180102498,"getForwardDirectionX",&DAT_1800d79f0);
    DAT_180102580 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180102498,"getForwardDirectionY",&DAT_1800d79f0);
    DAT_180102588 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180102498,"setForwardDirection","(FF)V");
    DAT_180102590 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180102498,"setTargetVerticalAimAngle",&DAT_1800d7b10);
    DAT_180102598 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180102498,"setCurrentVerticalAimAngle",&DAT_1800d7b10);
    DAT_1801025a0 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180102498,"setMoveDelta",&DAT_1800d7b10);
    DAT_1801025a8 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180102498,"setMoving",&DAT_1800de9e4);
    DAT_1801025b0 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180102498,"setRunning",&DAT_1800de9e4);
    DAT_1801025b8 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180102498,"setSprinting",&DAT_1800de9e4);
    DAT_1801025c0 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180102498,"isAllowRun",&DAT_1800d79c4);
    DAT_1801025c8 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180102498,"setAllowRun",&DAT_1800de9e4);
    DAT_1801025d0 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180102498,"isAllowSprint",&DAT_1800d79c4);
    DAT_1801025d8 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180102498,"setAllowSprint",&DAT_1800de9e4);
    DAT_1801025e0 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180102498,"isIgnoreInputsForDirection",&DAT_1800d79c4);
    DAT_1801025e8 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180102498,"setIgnoreInputsForDirection",&DAT_1800de9e4);
    DAT_1801025f0 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180102498,"setForceRun",&DAT_1800de9e4);
    DAT_1801025f8 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180102498,"setForceSprint",&DAT_1800de9e4);
    DAT_180102600 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180102498,"isBlockMovement",&DAT_1800d79c4);
    DAT_180102608 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180102498,"setBlockMovement",&DAT_1800de9e4);
    DAT_180102610 =
         (**(code **)(*param_1 + 0x2f0))
                   (param_1,DAT_180102498,"playerMoveDir","Lzombie/iso/Vector2;");
    DAT_180102618 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180102498,"getMoveForwardVec","()Lzombie/iso/Vector2;");
    DAT_180102620 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_1801024a0,"getFullType","()Ljava/lang/String;")
    ;
    DAT_180102628 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_1801024a0,"getCurrentAmmoCount",&DAT_1800d7974)
    ;
    DAT_180102630 = (**(code **)(*param_1 + 0x108))(param_1,DAT_1801024a8,"isRanged",&DAT_1800d79c4)
    ;
    DAT_180102638 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_1801024a8,"getMaxRange",&DAT_1800d79f0);
    DAT_180102640 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_1801024a8,"getProjectileSpread",&DAT_1800d79f0)
    ;
    DAT_180102648 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_1801024a8,"setProjectileSpread",&DAT_1800d7b10)
    ;
    DAT_180102650 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_1801024a8,"getHitChance",&DAT_1800d7974);
    DAT_180102658 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_1801024a8,"setHitChance",&DAT_1800df59c);
    DAT_180102660 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_1801024a8,"getMinDamage",&DAT_1800d79f0);
    DAT_180102668 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_1801024a8,"setMinDamage",&DAT_1800d7b10);
    DAT_180102670 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_1801024a8,"getMaxDamage",&DAT_1800d79f0);
    DAT_180102678 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_1801024a8,"setMaxDamage",&DAT_1800d7b10);
    DAT_180102680 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_1801024a8,"getAimingTime",&DAT_1800d7974);
    DAT_180102688 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_1801024a8,"setAimingTime",&DAT_1800df59c);
    DAT_180102690 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180102498,"setAimingDelay",&DAT_1800d7b10);
    DAT_180102698 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_180102498,"setBeenMovingFor",&DAT_1800d7b10);
    DAT_1801026a0 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_1801024b0,"getIsoAimingPosition","()Lzombie/iso/Vector3;");
    DAT_1801026a8 =
         (**(code **)(*param_1 + 0x2f0))
                   (param_1,DAT_1801024b0,"targetPosition","Lzombie/iso/Vector3;");
    DAT_1801026b0 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_1801024b8,&DAT_1800dec7c,"(FFF)Lzombie/iso/Vector3;");
    DAT_1801026b8 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_1801024c0,&DAT_1800dec7c,"(FF)Lzombie/iso/Vector2;");
    DAT_1801026c0 = (**(code **)(*param_1 + 0x388))(param_1,DAT_1801024c8,"getXA",&DAT_1800d7974);
    DAT_1801026c8 = (**(code **)(*param_1 + 0x388))(param_1,DAT_1801024c8,"getYA",&DAT_1800d7974);
    DAT_1801026d0 =
         (**(code **)(*param_1 + 0x388))(param_1,DAT_1801024d0,"XToScreenExact","(FFFI)F");
    DAT_1801026d8 =
         (**(code **)(*param_1 + 0x388))(param_1,DAT_1801024d0,"YToScreenExact","(FFFI)F");
    DAT_1801026e0 = (**(code **)(*param_1 + 0x480))(param_1,DAT_1801024d8,"client",&DAT_1800d788c);
    DAT_1801026e8 =
         (**(code **)(*param_1 + 0x480))
                   (param_1,DAT_1801024d8,"connection","Lzombie/core/raknet/UdpConnection;");
    DAT_1801026f0 =
         (**(code **)(*param_1 + 0x108))(param_1,DAT_1801024e0,"getAveragePing",&DAT_1800d7974);
    DAT_180102700 =
         (**(code **)(*param_1 + 0x388))
                   (param_1,DAT_1801024e8,"getInstance","()Lzombie/CombatManager;");
    DAT_180102708 =
         (**(code **)(*param_1 + 0x388))
                   (param_1,DAT_1801024f0,"instance","()Lzombie/ai/states/SwipeStatePlayer;");
    DAT_180102710 =
         (**(code **)(*param_1 + 0x108))
                   (param_1,DAT_180102498,"getAttackType","()Lzombie/AttackType;");
    uVar1 = (**(code **)(*param_1 + 0x720))(param_1);
    if ((char)uVar1 == '\0') {
      if ((((((((DAT_1801024f8 != 0) && (DAT_1801026f8 != 0)) &&
              ((DAT_180102500 != 0 && ((DAT_180102508 != 0 && (DAT_180102510 != 0)))))) &&
             (DAT_180102518 != 0)) &&
            (((((DAT_180102520 != 0 && (DAT_180102528 != 0)) && (DAT_180102530 != 0)) &&
              ((DAT_180102538 != 0 && (DAT_180102540 != 0)))) &&
             (((DAT_180102548 != 0 && ((DAT_180102550 != 0 && (DAT_180102558 != 0)))) &&
              ((DAT_180102560 != 0 &&
               (((((DAT_180102568 != 0 && (DAT_180102570 != 0)) && (DAT_180102578 != 0)) &&
                 ((DAT_180102580 != 0 && (DAT_180102588 != 0)))) &&
                ((DAT_180102590 != 0 && ((DAT_180102598 != 0 && (DAT_1801025a0 != 0)))))))))))))) &&
           (DAT_1801025a8 != 0)) &&
          (((((DAT_1801025b0 != 0 && (DAT_1801025b8 != 0)) && (DAT_1801025c0 != 0)) &&
            (((DAT_1801025c8 != 0 && (DAT_1801025d0 != 0)) &&
             ((DAT_1801025d8 != 0 && ((DAT_1801025e0 != 0 && (DAT_1801025e8 != 0)))))))) &&
           (((DAT_1801025f0 != 0 &&
             (((DAT_1801025f8 != 0 && (DAT_180102600 != 0)) && (DAT_180102608 != 0)))) &&
            (((DAT_180102610 != 0 && (DAT_180102618 != 0)) &&
             (((((DAT_180102620 != 0 && ((DAT_180102628 != 0 && (DAT_180102630 != 0)))) &&
                (DAT_180102638 != 0)) &&
               ((((DAT_180102640 != 0 && (DAT_180102648 != 0)) && (DAT_180102650 != 0)) &&
                ((DAT_180102658 != 0 && (DAT_180102660 != 0)))))) &&
              ((DAT_180102668 != 0 && ((DAT_180102670 != 0 && (DAT_180102678 != 0)))))))))))))) &&
         ((((DAT_180102680 != 0 &&
            (((((DAT_180102688 != 0 && (DAT_180102690 != 0)) && (DAT_180102698 != 0)) &&
              (((DAT_1801026a0 != 0 && (DAT_1801026a8 != 0)) &&
               ((DAT_1801026b0 != 0 && ((DAT_1801026b8 != 0 && (DAT_1801026c0 != 0)))))))) &&
             (DAT_1801026c8 != 0)))) &&
           (((DAT_1801026d0 != 0 && (DAT_1801026d8 != 0)) && (DAT_1801026e0 != 0)))) &&
          (((DAT_1801026e8 != 0 && (DAT_1801026f0 != 0)) &&
           ((DAT_180102700 != 0 && ((DAT_180102708 != 0 && (DAT_180102710 != 0)))))))))) {
        DAT_180102490 = 1;
        return CONCAT71((int7)(uVar1 >> 8),1);
      }
    }
    else {
      uVar1 = (**(code **)(*param_1 + 0x88))(param_1);
    }
    DAT_180102490 = 0;
    return uVar1 & 0xffffffffffffff00;
  }
  return DAT_1801024f0 & 0xffffffffffffff00;
}


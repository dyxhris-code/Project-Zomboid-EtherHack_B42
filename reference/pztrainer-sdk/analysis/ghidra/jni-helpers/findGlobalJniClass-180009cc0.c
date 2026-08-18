/*
 * Semantic name: findGlobalJniClass
 * Address: 0x180009cc0
 * Module: jni-helpers
 * Confidence: high
 * Summary: Finds a Java class and promotes it to a cached global JNI reference.
 * Ghidra function: findGlobalJniClass
 * Callers:
 *   - initializeSkillBridge @ 0x180009f30
 *   - FUN_18000c9d0 @ 0x18000c9d0
 *   - initializeItemWeaponBridge @ 0x18000d220
 *   - FUN_1800148e0 @ 0x1800148e0
 *   - FUN_180016370 @ 0x180016370
 *   - FUN_180017910 @ 0x180017910
 *   - initializePalletGrantBridge @ 0x18001a3e0
 *   - FUN_18001bfd0 @ 0x18001bfd0
 *   - initializeCharacterStatsBridge @ 0x18001d190
 *   - FUN_180020250 @ 0x180020250
 *   - initializePlayerDamageBridge @ 0x180021840
 *   - FUN_1800222c0 @ 0x1800222c0
 *   - initializeClimateBridge @ 0x180022ed0
 *   - FUN_180025530 @ 0x180025530
 *   - FUN_180026890 @ 0x180026890
 *   - FUN_180027ad0 @ 0x180027ad0
 *   - initializeBallisticsBridge @ 0x18002a7c0
 *   - FUN_180038320 @ 0x180038320
 * Callees:
 *   - jniCallObjectMethodWithIntArg @ 0x180001810
 *   - jniCallStaticObjectMethodOneArg @ 0x180001930
 *   - FUN_180008090 @ 0x180008090
 *   - destroySmallString @ 0x180008440
 *   - __security_check_cookie @ 0x1800cd520
 *   - strlen @ 0x1800cf652
 * Referenced strings:
 *   - java/lang/ClassLoader
 *   - ()Ljava/lang/ClassLoader;
 *   - getSystemClassLoader
 *   - (Ljava/lang/String;)Ljava/lang/Class;
 *   - loadClass
 */


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Type propagation algorithm not settling */
/* Finds a Java class and promotes it to a cached global JNI reference. */

undefined8 findGlobalJniClass(longlong *param_1,char *param_2)

{
  char cVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  size_t sVar5;
  undefined8 uVar6;
  char *******pppppppcVar7;
  char *******pppppppcVar8;
  undefined1 auStack_78 [32];
  char *******local_58;
  undefined8 uStack_50;
  longlong local_48;
  ulonglong uStack_40;
  ulonglong local_38;
  
  local_38 = DAT_1800ff040 ^ (ulonglong)auStack_78;
  lVar2 = (**(code **)(*param_1 + 0x30))(param_1,"java/lang/ClassLoader");
  if (lVar2 != 0) {
    cVar1 = (**(code **)(*param_1 + 0x720))(param_1);
    if (cVar1 != '\0') {
      (**(code **)(*param_1 + 0x88))(param_1);
      return 0;
    }
    lVar3 = (**(code **)(*param_1 + 0x388))
                      (param_1,lVar2,"getSystemClassLoader","()Ljava/lang/ClassLoader;");
    lVar4 = (**(code **)(*param_1 + 0x108))
                      (param_1,lVar2,"loadClass","(Ljava/lang/String;)Ljava/lang/Class;");
    if (lVar3 == 0) {
      (**(code **)(*param_1 + 0xb8))(param_1,lVar2);
      return 0;
    }
    lVar3 = jniCallStaticObjectMethodOneArg(param_1);
    (**(code **)(*param_1 + 0xb8))(param_1,lVar2);
    if (lVar3 == 0) {
      return 0;
    }
    if (lVar4 != 0) {
      cVar1 = (**(code **)(*param_1 + 0x720))(param_1);
      if (cVar1 == '\0') {
        local_58 = (char *******)0x0;
        uStack_50 = 0;
        local_48 = 0;
        uStack_40 = 0;
        sVar5 = strlen(param_2);
        FUN_180008090(&local_58,param_2,sVar5);
        pppppppcVar7 = local_58;
        if (uStack_40 < 0x10) {
          pppppppcVar7 = (char *******)&local_58;
        }
        pppppppcVar8 = (char *******)((longlong)pppppppcVar7 + local_48);
        for (; pppppppcVar7 != pppppppcVar8;
            pppppppcVar7 = (char *******)((longlong)pppppppcVar7 + 1)) {
          if (*(char *)pppppppcVar7 == '/') {
            *(char *)pppppppcVar7 = '.';
          }
        }
        pppppppcVar7 = (char *******)&local_58;
        if (0xf < uStack_40) {
          pppppppcVar7 = local_58;
        }
        lVar2 = (**(code **)(*param_1 + 0x538))(param_1,pppppppcVar7);
        if (lVar2 == 0) {
          (**(code **)(*param_1 + 0xb8))(param_1,lVar3);
        }
        else {
          lVar4 = jniCallObjectMethodWithIntArg(param_1);
          (**(code **)(*param_1 + 0xb8))(param_1,lVar2);
          (**(code **)(*param_1 + 0xb8))(param_1,lVar3);
          if (lVar4 != 0) {
            cVar1 = (**(code **)(*param_1 + 0x720))(param_1);
            if (cVar1 == '\0') {
              uVar6 = (**(code **)(*param_1 + 0xa8))(param_1,lVar4);
              (**(code **)(*param_1 + 0xb8))(param_1,lVar4);
              goto LAB_180009ecd;
            }
            (**(code **)(*param_1 + 0x88))(param_1);
          }
        }
        uVar6 = 0;
LAB_180009ecd:
        destroySmallString((longlong *)&local_58);
        return uVar6;
      }
      (**(code **)(*param_1 + 0x88))(param_1);
    }
    (**(code **)(*param_1 + 0xb8))(param_1,lVar3);
  }
  return 0;
}


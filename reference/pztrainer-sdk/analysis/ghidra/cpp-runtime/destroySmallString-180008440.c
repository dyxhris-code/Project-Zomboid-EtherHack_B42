/*
 * Semantic name: destroySmallString
 * Address: 0x180008440
 * Module: cpp-runtime
 * Confidence: medium
 * Summary: Releases storage owned by an MSVC small-string value.
 * Ghidra function: destroySmallString
 * Callers:
 *   - FUN_180001b80 @ 0x180001b80
 *   - FUN_180003800 @ 0x180003800
 *   - FUN_180003940 @ 0x180003940
 *   - FUN_180003ad0 @ 0x180003ad0
 *   - FUN_1800067b0 @ 0x1800067b0
 *   - FUN_180007a50 @ 0x180007a50
 *   - FUN_180007b20 @ 0x180007b20
 *   - FUN_180008390 @ 0x180008390
 *   - FUN_180008fc0 @ 0x180008fc0
 *   - FUN_1800090a0 @ 0x1800090a0
 *   - FUN_180009190 @ 0x180009190
 *   - FUN_1800095f0 @ 0x1800095f0
 *   - findGlobalJniClass @ 0x180009cc0
 *   - FUN_18000a930 @ 0x18000a930
 *   - FUN_18000a9f0 @ 0x18000a9f0
 *   - FUN_18000ac60 @ 0x18000ac60
 *   - FUN_18000b8a0 @ 0x18000b8a0
 *   - FUN_18000c390 @ 0x18000c390
 *   - FUN_18000c5f0 @ 0x18000c5f0
 *   - FUN_18000d100 @ 0x18000d100
 *   - FUN_18000e0f0 @ 0x18000e0f0
 *   - FUN_18000ec20 @ 0x18000ec20
 *   - FUN_18000ee60 @ 0x18000ee60
 *   - FUN_18000f2c0 @ 0x18000f2c0
 *   - FUN_18000f790 @ 0x18000f790
 *   - FUN_180010480 @ 0x180010480
 *   - FUN_180011650 @ 0x180011650
 *   - FUN_180012760 @ 0x180012760
 *   - FUN_1800128f0 @ 0x1800128f0
 *   - FUN_180013270 @ 0x180013270
 *   - FUN_180013950 @ 0x180013950
 *   - FUN_180013990 @ 0x180013990
 *   - FUN_180014710 @ 0x180014710
 *   - FUN_180014d30 @ 0x180014d30
 *   - FUN_180015340 @ 0x180015340
 *   - FUN_180015910 @ 0x180015910
 *   - FUN_180016630 @ 0x180016630
 *   - FUN_180016b70 @ 0x180016b70
 *   - FUN_180016f40 @ 0x180016f40
 *   - FUN_1800181c0 @ 0x1800181c0
 *   - FUN_180018e70 @ 0x180018e70
 *   - FUN_180019420 @ 0x180019420
 *   - FUN_180019ac0 @ 0x180019ac0
 *   - beginPalletItemGrant @ 0x18001b510
 *   - pollPalletItemGrant @ 0x18001bc80
 *   - FUN_18001c990 @ 0x18001c990
 *   - FUN_18001db90 @ 0x18001db90
 *   - FUN_18001e410 @ 0x18001e410
 *   - FUN_18001f4b0 @ 0x18001f4b0
 *   - FUN_18001f520 @ 0x18001f520
 *   - FUN_18001f8e0 @ 0x18001f8e0
 *   - FUN_18001ff70 @ 0x18001ff70
 *   - FUN_180020f50 @ 0x180020f50
 *   - FUN_180021320 @ 0x180021320
 *   - FUN_180026380 @ 0x180026380
 *   - FUN_180026f00 @ 0x180026f00
 *   - FUN_180027de0 @ 0x180027de0
 *   - FUN_180029010 @ 0x180029010
 *   - FUN_18002d670 @ 0x18002d670
 *   - FUN_18002f770 @ 0x18002f770
 *   - FUN_180034350 @ 0x180034350
 *   - FUN_180034df0 @ 0x180034df0
 *   - FUN_180036660 @ 0x180036660
 *   - FUN_180036750 @ 0x180036750
 *   - FUN_180037680 @ 0x180037680
 *   - FUN_18003a9f0 @ 0x18003a9f0
 *   - FUN_18003acc0 @ 0x18003acc0
 *   - initializeRenderBridge @ 0x18003ade0
 *   - FUN_18003b390 @ 0x18003b390
 *   - hookWorker @ 0x18003e740
 *   - FUN_180040c40 @ 0x180040c40
 *   - FUN_180049cc0 @ 0x180049cc0
 *   - FUN_18004bc00 @ 0x18004bc00
 *   - FUN_18004bf90 @ 0x18004bf90
 *   - FUN_18004c4b0 @ 0x18004c4b0
 *   - FUN_18004c5d0 @ 0x18004c5d0
 *   - FUN_18004e1e0 @ 0x18004e1e0
 *   - FUN_18004e380 @ 0x18004e380
 *   - FUN_180050ba0 @ 0x180050ba0
 *   - FUN_180051400 @ 0x180051400
 *   - FUN_180056780 @ 0x180056780
 *   - FUN_180056930 @ 0x180056930
 *   - FUN_180057c90 @ 0x180057c90
 *   - FUN_18005ac30 @ 0x18005ac30
 *   - FUN_18005b360 @ 0x18005b360
 *   - FUN_18005bcd0 @ 0x18005bcd0
 *   - FUN_18005c050 @ 0x18005c050
 *   - FUN_18005cb60 @ 0x18005cb60
 *   - FUN_18005d0e0 @ 0x18005d0e0
 *   - FUN_18005d470 @ 0x18005d470
 *   - FUN_18005fc90 @ 0x18005fc90
 *   - FUN_180060080 @ 0x180060080
 *   - FUN_1800610a0 @ 0x1800610a0
 *   - FUN_180063870 @ 0x180063870
 *   - FUN_1800638f0 @ 0x1800638f0
 *   - FUN_180064b70 @ 0x180064b70
 *   - FUN_180065460 @ 0x180065460
 *   - FUN_1800656a0 @ 0x1800656a0
 *   - FUN_180065710 @ 0x180065710
 *   - FUN_180066110 @ 0x180066110
 *   - FUN_180066850 @ 0x180066850
 *   - FUN_180066a10 @ 0x180066a10
 *   - FUN_180067210 @ 0x180067210
 *   - FUN_180068550 @ 0x180068550
 *   - FUN_1800686c0 @ 0x1800686c0
 *   - FUN_180068bb0 @ 0x180068bb0
 *   - FUN_180068e00 @ 0x180068e00
 *   - FUN_180069ed0 @ 0x180069ed0
 *   - FUN_18006b340 @ 0x18006b340
 *   - FUN_18006b570 @ 0x18006b570
 *   - FUN_18006b820 @ 0x18006b820
 *   - FUN_18006b860 @ 0x18006b860
 *   - FUN_18006b8f0 @ 0x18006b8f0
 *   - FUN_18006b9d0 @ 0x18006b9d0
 *   - FUN_18006c070 @ 0x18006c070
 *   - FUN_18006c180 @ 0x18006c180
 *   - FUN_18006c9e0 @ 0x18006c9e0
 *   - FUN_18006dca0 @ 0x18006dca0
 *   - FUN_1800d2d90 @ 0x1800d2d90
 *   - FUN_1800d2e20 @ 0x1800d2e20
 *   - FUN_1800d2ec0 @ 0x1800d2ec0
 *   - FUN_1800d2ed0 @ 0x1800d2ed0
 *   - FUN_1800d2f80 @ 0x1800d2f80
 *   - FUN_1800d2f90 @ 0x1800d2f90
 *   - FUN_1800d2fa0 @ 0x1800d2fa0
 *   - FUN_1800d2fc0 @ 0x1800d2fc0
 *   - FUN_1800d2fd0 @ 0x1800d2fd0
 *   - FUN_1800d2fe0 @ 0x1800d2fe0
 *   - FUN_1800d2ff0 @ 0x1800d2ff0
 *   - FUN_1800d3020 @ 0x1800d3020
 *   - FUN_1800d3030 @ 0x1800d3030
 *   - FUN_1800d3040 @ 0x1800d3040
 *   - FUN_1800d3060 @ 0x1800d3060
 *   - FUN_1800d3080 @ 0x1800d3080
 *   - FUN_1800d3150 @ 0x1800d3150
 *   - FUN_1800d31b0 @ 0x1800d31b0
 *   - FUN_1800d31d0 @ 0x1800d31d0
 *   - FUN_1800d32c0 @ 0x1800d32c0
 *   - FUN_1800d32d0 @ 0x1800d32d0
 *   - FUN_1800d32e0 @ 0x1800d32e0
 *   - FUN_1800d3360 @ 0x1800d3360
 *   - FUN_1800d3470 @ 0x1800d3470
 *   - FUN_1800d3490 @ 0x1800d3490
 *   - FUN_1800d34a0 @ 0x1800d34a0
 *   - FUN_1800d34b0 @ 0x1800d34b0
 * Callees:
 *   - free @ 0x1800cd8ec
 */


/* Releases storage owned by an MSVC small-string value. */

void destroySmallString(longlong *param_1)

{
  void *pvVar1;
  code *pcVar2;
  void *_Memory;
  undefined1 *puVar3;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  if (0xf < (ulonglong)param_1[3]) {
    pvVar1 = (void *)*param_1;
    _Memory = pvVar1;
    puVar3 = auStack_28;
    if ((0xfff < param_1[3] + 1U) &&
       (_Memory = *(void **)((longlong)pvVar1 + -8), puVar3 = auStack_28,
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)_Memory)))) {
      pcVar2 = (code *)swi(0x29);
      _Memory = (void *)(*pcVar2)(5);
      puVar3 = auStack_20;
    }
    *(undefined8 *)(puVar3 + -8) = 0x180008488;
    free(_Memory);
  }
  param_1[2] = 0;
  param_1[3] = 0xf;
  *(undefined1 *)param_1 = 0;
  return;
}


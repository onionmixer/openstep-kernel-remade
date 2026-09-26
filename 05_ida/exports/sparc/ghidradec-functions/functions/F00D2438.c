
/* WARNING: Removing unreachable block (ram,0xf00d24b8) */
/* WARNING: Removing unreachable block (ram,0xf00d248c) */
/* WARNING: Removing unreachable block (ram,0xf00d24f0) */
/* WARNING: Removing unreachable block (ram,0xf00d2454) */

undefined8
-[EventDriver getCharValues:forParameter:count:]
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5)

{
  undefined4 uVar1;
  undefined *puVar2;
  undefined4 unaff_l0;
  int *piVar3;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  uVar1 = *(undefined4 *)(param_1 + 0x170);
  *(undefined4 *)((int)register0x00000038 + -0x14) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x14) = *param_5;
  _objc_msgSend(uVar1,paLock);
  piVar3 = *(int **)(param_1 + 0x174);
  if ((int *)(param_1 + 0x174) == piVar3) {
    uVar1 = *(undefined4 *)(param_1 + 0x170);
    puVar2 = (undefined *)0xfffffd3e;
  }
  else {
    do {
      puVar2 = (undefined *)*piVar3;
      piVar3 = (int *)piVar3[1];
      _objc_msgSend(puVar2,paGetcharvaluesF_0,param_3,param_4,
                    (undefined *)((int)register0x00000038 + -0x14));
      if (puVar2 != (undefined *)0xfffffd3e) break;
      puVar2 = (undefined *)0xfffffd3e;
    } while ((int *)(param_1 + 0x174) != piVar3);
    uVar1 = *(undefined4 *)(param_1 + 0x170);
  }
  _objc_msgSend(uVar1,paUnlock);
  uVar1 = *(undefined4 *)((int)register0x00000038 + -0x14);
  if (puVar2 == (undefined *)0xfffffd3e) {
    *(int *)((int)register0x00000038 + -0x10) = param_1;
    puVar2 = (undefined *)((int)register0x00000038 + -0x10);
    *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf01421e0;
    _objc_msgSendSuper(puVar2,paGetcharvaluesF_0,param_3,param_4,
                       (undefined *)((int)register0x00000038 + -0x14));
    uVar1 = *(undefined4 *)((int)register0x00000038 + -0x14);
  }
  *param_5 = uVar1;
  return CONCAT44(param_2,puVar2);
}

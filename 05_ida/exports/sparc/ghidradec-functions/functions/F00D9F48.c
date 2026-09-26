
/* WARNING: Removing unreachable block (ram,0xf00da05c) */
/* WARNING: Removing unreachable block (ram,0xf00d9fe0) */
/* WARNING: Removing unreachable block (ram,0xf00d9fbc) */
/* WARNING: Removing unreachable block (ram,0xf00d9f9c) */
/* WARNING: Removing unreachable block (ram,0xf00d9fcc) */
/* WARNING: Removing unreachable block (ram,0xf00d9fe8) */
/* WARNING: Removing unreachable block (ram,0xf00da06c) */
/* WARNING: Removing unreachable block (ram,0xf00d9f64) */

undefined8
-[AudioChannel initOnDevice:read:](int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  undefined (*pauVar1) [19];
  undefined (*pauVar2) [13];
  undefined4 uVar3;
  undefined7 *puVar4;
  undefined4 uVar5;
  undefined4 unaff_l0;
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
  *(int *)((int)register0x00000038 + -0x10) = param_1;
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0142280;
  _objc_msgSendSuper((undefined *)((int)register0x00000038 + -0x10),paInit);
  *(undefined4 *)(param_1 + 4) = param_3;
  *(char *)(param_1 + 0x20) = (char)param_4;
  pauVar2 = paOutputstream;
  if ((param_4 & 0xff) != 0) {
    pauVar2 = (undefined (*) [13])paInputstream;
  }
  _objc_msgSend(pauVar2,paClass);
  *(undefined (**) [13])(param_1 + 8) = pauVar2;
  uVar5 = paAlloc;
  *(undefined4 *)(param_1 + 0x14) = 0;
  uVar3 = paList;
  _objc_msgSend(paList,uVar5);
  _objc_msgSend();
  *(undefined4 *)(param_1 + 0xc) = uVar3;
  puVar4 = paNxlock;
  _objc_msgSend(paNxlock,uVar5);
  _objc_msgSend();
  *(undefined7 **)(param_1 + 0x10) = puVar4;
  *(int *)(param_1 + 0x28) = param_1 + 0x24;
  *(int *)(param_1 + 0x24) = param_1 + 0x24;
  *(int *)(param_1 + 0x30) = param_1 + 0x2c;
  *(int *)(param_1 + 0x2c) = param_1 + 0x2c;
  *(undefined4 *)(param_1 + 0x54) = 1;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  uVar5 = _AudioOut_dmaCount;
  uVar3 = _AudioOut_dmaSize;
  if ((param_4 & 0xff) != 0) {
    uVar5 = _AudioIn_dmaCount;
    uVar3 = _AudioIn_dmaSize;
  }
  *(undefined4 *)(param_1 + 0x38) = uVar3;
  *(undefined4 *)(param_1 + 0x3c) = uVar5;
  pauVar1 = paSetdescriptors;
  uVar5 = *(undefined4 *)(param_1 + 0x38);
  .udiv(uVar5,*(undefined4 *)(param_1 + 0x3c));
  _objc_msgSend(param_1,pauVar1,uVar5);
  return CONCAT44(param_2,param_1);
}

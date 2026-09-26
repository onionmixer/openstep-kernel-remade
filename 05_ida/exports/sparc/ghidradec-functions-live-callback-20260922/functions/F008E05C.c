
/* WARNING: Removing unreachable block (ram,0xf008e11c) */
/* WARNING: Removing unreachable block (ram,0xf008e0f0) */
/* WARNING: Removing unreachable block (ram,0xf008e0d0) */
/* WARNING: Removing unreachable block (ram,0xf008e098) */
/* WARNING: Removing unreachable block (ram,0xf008e0c4) */
/* WARNING: Removing unreachable block (ram,0xf008e0e4) */
/* WARNING: Removing unreachable block (ram,0xf008e0fc) */
/* WARNING: Removing unreachable block (ram,0xf008e088) */
/* WARNING: Removing unreachable block (ram,0xf008e06c) */

undefined8 -[KernBusInterrupt dealloc](undefined *param_1,undefined4 param_2)

{
  undefined5 *puVar1;
  undefined8 *puVar2;
  int iVar3;
  int iVar4;
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
  
  puVar2 = paAcquire;
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
  _objc_msgSend(*(undefined4 *)(param_1 + 0x1c),paAcquire);
  if (*(int *)(param_1 + 0x18) < 1) {
    _objc_msgSend(*(undefined4 *)(param_1 + 0x24),puVar2);
    iVar4 = *(int *)(param_1 + 0x20);
    iVar3 = iVar4 + 1;
    *(int *)(param_1 + 0x20) = iVar3;
    if (iVar3 < 0) {
      *(int *)(param_1 + 0x20) = iVar4;
    }
    puVar2 = paRelease;
    _objc_msgSend(*(undefined4 *)(param_1 + 0x24),paRelease);
    _objc_msgSend(*(undefined4 *)(param_1 + 0x1c),puVar2);
    puVar1 = paFree;
    _objc_msgSend(*(undefined4 *)(param_1 + 0x14),paFree);
    _objc_msgSend(*(undefined4 *)(param_1 + 0x24),puVar1);
    _objc_msgSend(*(undefined4 *)(param_1 + 0x1c),puVar1);
    *(undefined **)((int)register0x00000038 + -0x10) = param_1;
    param_1 = (undefined *)((int)register0x00000038 + -0x10);
    *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141c68;
    _objc_msgSendSuper(param_1,paDealloc);
  }
  else {
    _objc_msgSend(*(undefined4 *)(param_1 + 0x1c),paRelease);
  }
  return CONCAT44(param_2,param_1);
}


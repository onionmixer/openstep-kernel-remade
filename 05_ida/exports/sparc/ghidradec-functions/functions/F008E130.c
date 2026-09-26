
/* WARNING: Removing unreachable block (ram,0xf008e1cc) */
/* WARNING: Removing unreachable block (ram,0xf008e170) */
/* WARNING: Removing unreachable block (ram,0xf008e150) */
/* WARNING: Removing unreachable block (ram,0xf008e198) */
/* WARNING: Removing unreachable block (ram,0xf008e1d8) */
/* WARNING: Removing unreachable block (ram,0xf008e13c) */

undefined8
-[KernBusInterrupt attachDeviceInterrupt:](uint param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
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
  uint uVar3;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  iVar1 = *(int *)(param_1 + 0x14);
  _objc_msgSend(iVar1,paIndexof,param_3);
  if (iVar1 == -1) {
    iVar1 = *(int *)(param_1 + 0x14);
    _objc_msgSend(iVar1,paAddobject,param_3);
    if (iVar1 == 0) {
      uVar2 = *(undefined4 *)(param_1 + 0x24);
    }
    else {
      *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
      uVar2 = *(undefined4 *)(param_1 + 0x24);
    }
  }
  else {
    uVar2 = *(undefined4 *)(param_1 + 0x24);
  }
  _objc_msgSend(uVar2,paAcquire);
  uVar2 = paRelease;
  uVar3 = 0;
  if (0 < *(int *)(param_1 + 0x18)) {
    uVar3 = param_1 & (*(int *)(param_1 + 0x20) != 0) - 1;
  }
  _objc_msgSend(*(undefined4 *)(param_1 + 0x24),paRelease);
  _objc_msgSend(*(undefined4 *)(param_1 + 0x1c),uVar2);
  return CONCAT44(param_2,uVar3);
}

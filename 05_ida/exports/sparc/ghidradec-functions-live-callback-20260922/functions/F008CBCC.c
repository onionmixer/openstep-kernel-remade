
/* WARNING: Removing unreachable block (ram,0xf008cc78) */
/* WARNING: Removing unreachable block (ram,0xf008cc48) */
/* WARNING: Removing unreachable block (ram,0xf008cc18) */
/* WARNING: Removing unreachable block (ram,0xf008cc30) */

undefined8 -[KernBusItemResource shareItem:](int param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  undefined4 unaff_l0;
  int iVar2;
  undefined4 unaff_l1;
  int iVar3;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
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
  uVar1 = *(uint *)(param_1 + 0xc);
  iVar3 = *(int *)(param_1 + 0x18);
  if ((param_3 < uVar1) || (uVar1 + *(int *)(param_1 + 8) <= param_3)) {
    iVar4 = 0;
  }
  else {
    iVar2 = (param_3 - uVar1) * 4;
    iVar4 = *(int *)(iVar3 + iVar2);
    if (iVar4 == 0) {
      iVar4 = *(int *)(param_1 + 0x10);
      _objc_msgSend(iVar4,paAlloc);
      _objc_msgSend();
      *(int *)(iVar3 + iVar2) = iVar4;
      if ((iVar4 != 0) &&
         (iVar4 = *(int *)(param_1 + 0x14) + 1, *(int *)(param_1 + 0x14) = iVar4, iVar4 == 1)) {
        _objc_msgSend(*(undefined4 *)(param_1 + 4),paResourceactive);
      }
      iVar4 = *(int *)(iVar3 + iVar2);
    }
    else {
      _objc_msgSend(iVar4,paShare);
    }
  }
  return CONCAT44(param_2,iVar4);
}


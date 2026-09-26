
/* WARNING: Removing unreachable block (ram,0xf008cd44) */
/* WARNING: Removing unreachable block (ram,0xf008cd54) */
/* WARNING: Removing unreachable block (ram,0xf008cce8) */

undefined8 -[KernBusItemResource _destroyItem:](int param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 unaff_l0;
  int iVar3;
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
  iVar3 = *(int *)(param_1 + 0x18);
  uVar1 = param_3;
  _objc_msgSend(param_3,paIskindof,*(undefined4 *)(param_1 + 0x10));
  if ((uVar1 & 0xff) == 0) {
    param_3 = 0;
  }
  else {
    iVar2 = (*(int *)(param_3 + 8) - *(int *)(param_1 + 0xc)) * 4;
    if (*(int *)(iVar3 + iVar2) == 0) {
      param_3 = 0;
    }
    else {
      *(undefined4 *)(iVar3 + iVar2) = 0;
      iVar3 = *(int *)(param_1 + 0x14) + -1;
      *(int *)(param_1 + 0x14) = iVar3;
      if (iVar3 == 0) {
        _objc_msgSend(*(undefined4 *)(param_1 + 4),paResourceinacti);
      }
      _objc_msgSend(param_3,paDealloc);
    }
  }
  return CONCAT44(param_2,param_3);
}


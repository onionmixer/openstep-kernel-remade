
/* WARNING: Removing unreachable block (ram,0xf008cb88) */
/* WARNING: Removing unreachable block (ram,0xf008cbb8) */
/* WARNING: Removing unreachable block (ram,0xf008cb70) */

undefined8 -[KernBusItemResource reserveItem:](int param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  int iVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar5;
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
  uVar2 = *(uint *)(param_1 + 0xc);
  iVar4 = *(int *)(param_1 + 0x18);
  if ((uVar2 <= param_3) && (param_3 < uVar2 + *(int *)(param_1 + 8))) {
    iVar3 = (param_3 - uVar2) * 4;
    if (*(int *)(iVar4 + iVar3) == 0) {
      iVar1 = *(int *)(param_1 + 0x10);
      _objc_msgSend(iVar1,paAlloc);
      _objc_msgSend();
      *(int *)(iVar4 + iVar3) = iVar1;
      if ((iVar1 != 0) &&
         (iVar1 = *(int *)(param_1 + 0x14) + 1, *(int *)(param_1 + 0x14) = iVar1, iVar1 == 1)) {
        _objc_msgSend(*(undefined4 *)(param_1 + 4),paResourceactive);
      }
      uVar5 = *(undefined4 *)(iVar4 + iVar3);
      goto locret_F008CBC4;
    }
  }
  uVar5 = 0;
locret_F008CBC4:
  return CONCAT44(param_2,uVar5);
}


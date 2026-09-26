
/* WARNING: Removing unreachable block (ram,0xf0051308) */
/* WARNING: Removing unreachable block (ram,0xf0051340) */
/* WARNING: Removing unreachable block (ram,0xf00512dc) */

sqword sub_F00512C8(int param_1,int *param_2,int param_3)

{
  word wVar1;
  int iVar2;
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
  iVar2 = (int)*(sword *)(*(int *)(param_1 + 0x128) + 4);
  _iget(iVar2,*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x128) + 0xc) + 0x20),
        *(undefined4 *)(param_3 + 4));
  if (iVar2 == 0) {
    *param_2 = 0;
  }
  else if (*(int *)(iVar2 + 0xd0) == *(int *)(param_3 + 8)) {
    wVar1 = *(word *)(iVar2 + 0x44);
    *(word *)(iVar2 + 0x44) = wVar1 & 0xfffe;
    if ((wVar1 & 0x10) != 0) {
      *(word *)(iVar2 + 0x44) = wVar1 & 0xffee;
      _wakeup(iVar2);
    }
    *param_2 = iVar2 + 0xc;
    if ((*(uint *)(iVar2 + 100) & 0x42400000) == 0x2000000) {
      *(word *)(iVar2 + 0x10) = *(word *)(iVar2 + 0x10) | 0x80;
    }
  }
  else {
    _idrop(iVar2);
    *param_2 = 0;
  }
  return ZEXT48(param_2) << 0x20;
}


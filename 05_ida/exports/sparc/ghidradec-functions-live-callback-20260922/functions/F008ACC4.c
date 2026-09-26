
/* WARNING: Removing unreachable block (ram,0xf008ada4) */
/* WARNING: Removing unreachable block (ram,0xf008ace8) */
/* WARNING: Removing unreachable block (ram,0xf008ae00) */
/* WARNING: Removing unreachable block (ram,0xf008acd0) */

undefined8 _vnode_pager_allocpage(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
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
  _lock_write(param_1 + 0x34);
  if (*(int *)(param_1 + 0x18) == 0) {
    _lock_done(param_1 + 0x34);
    iVar3 = -1;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x24);
    iVar3 = 0;
    if (iVar1 < 0) {
      iVar1 = iVar1 + 7;
    }
    iVar1 = iVar1 >> 3;
    while( true ) {
      iVar2 = *(int *)(param_1 + 0x14) + 7;
      if (iVar2 < 0) {
        iVar2 = *(int *)(param_1 + 0x14) + 0xe;
      }
      if (iVar2 >> 3 <= iVar1) goto loc_F008AD90;
      if (*(char *)(*(int *)(param_1 + 0x10) + iVar1) != -1) break;
      iVar1 = iVar1 + 1;
    }
    iVar3 = 0;
    do {
      iVar2 = iVar3;
      if (iVar3 < 0) {
        iVar2 = iVar3 + 7;
      }
    } while ((((int)*(char *)(*(int *)(param_1 + 0x10) + iVar1 + (iVar2 >> 3)) >>
               ((char)iVar3 + (char)(iVar2 >> 3) * -8 & 0x1fU) & 1U) != 0) &&
            (iVar3 = iVar3 + 1, iVar3 < 8));
loc_F008AD90:
    iVar3 = iVar1 * 8 + iVar3;
    if (*(int *)(param_1 + 0x14) <= iVar3) {
      _panic(aVnodePagerAllo);
    }
    if (*(int *)(param_1 + 0x20) < iVar3) {
      *(int *)(param_1 + 0x20) = iVar3;
    }
    iVar1 = iVar3;
    if (iVar3 < 0) {
      iVar1 = iVar3 + 7;
    }
    iVar1 = iVar1 >> 3;
    *(byte *)(*(int *)(param_1 + 0x10) + iVar1) =
         *(byte *)(*(int *)(param_1 + 0x10) + iVar1) |
         (byte)(1 << ((char)iVar3 + (char)iVar1 * -8 & 0x1fU));
    *(int *)(param_1 + 0x24) = iVar3;
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -1;
    _lock_done(param_1 + 0x34);
  }
  return CONCAT44(param_2,iVar3);
}


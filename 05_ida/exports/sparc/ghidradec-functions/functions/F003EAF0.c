
/* WARNING: Removing unreachable block (ram,0xf003eb68) */
/* WARNING: Removing unreachable block (ram,0xf003eb40) */
/* WARNING: Removing unreachable block (ram,0xf003eb2c) */
/* WARNING: Removing unreachable block (ram,0xf003eb00) */
/* WARNING: Removing unreachable block (ram,0xf003eb38) */
/* WARNING: Removing unreachable block (ram,0xf003eb50) */
/* WARNING: Removing unreachable block (ram,0xf003eb74) */
/* WARNING: Removing unreachable block (ram,0xf003eaf8) */

undefined8 sub_F003EAF0(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  int iVar1;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar2;
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
  iVar1 = *(int *)(param_1 + 0x128);
  _rflush(param_1);
  _rinval(param_1);
  uVar2 = 0x10;
  if ((*(int *)(iVar1 + 0x18) == 1) && (*(sword *)(*(int *)(iVar1 + 0x10) + 6) == 1)) {
    _rp_rmhash(*(undefined4 *)(*(int *)(iVar1 + 0x10) + 0x30));
    _rinactive(*(undefined4 *)(*(int *)(iVar1 + 0x10) + 0x30));
    _vn_rele(*(undefined4 *)(iVar1 + 0x10));
    _vfs_putnum(unk_F012F4F4,*(undefined4 *)(iVar1 + 0x28));
    if (-1 < *(int *)(iVar1 + 0x58)) {
      _kfree(*(undefined4 *)(iVar1 + 0x54));
    }
    _kfree(iVar1,0x70);
    uVar2 = 0;
  }
  return CONCAT44(param_2,uVar2);
}

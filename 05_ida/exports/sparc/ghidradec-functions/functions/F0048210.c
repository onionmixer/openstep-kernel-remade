
/* WARNING: Removing unreachable block (ram,0xf0048288) */
/* WARNING: Removing unreachable block (ram,0xf0048258) */
/* WARNING: Removing unreachable block (ram,0xf0048240) */
/* WARNING: Removing unreachable block (ram,0xf0048270) */
/* WARNING: Removing unreachable block (ram,0xf00482a4) */
/* WARNING: Removing unreachable block (ram,0xf0048220) */

sqword sub_F0048210(int param_1,uint param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  int iVar2;
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
  iVar1 = (int)*(sword *)(*_active_u + 0x30);
  _get_posix_proc();
  *(uint *)(iVar1 + 0x18) = *(uint *)(iVar1 + 0x18) | 0x80000000;
  iVar2 = *(int *)(param_1 + 0x30);
  _sunsave(iVar2);
  if (*(int *)(iVar2 + 0x38) != 0) {
    _spec_fsync(param_1,param_2);
  }
  if (*(int *)(iVar2 + 0x38) != 0) {
    _vn_rele();
    *(undefined4 *)(iVar2 + 0x38) = 0;
    if (*(int *)(iVar2 + 0x3c) != 0) {
      _vn_rele();
    }
  }
  *(uint *)(iVar1 + 0x18) = *(uint *)(iVar1 + 0x18) & 0x7fffffff;
  _kfree(iVar2,0x68);
  return (qword)param_2 << 0x20;
}

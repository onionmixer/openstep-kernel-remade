
/* WARNING: Removing unreachable block (ram,0xf0050858) */
/* WARNING: Removing unreachable block (ram,0xf0050834) */
/* WARNING: Removing unreachable block (ram,0xf0050804) */
/* WARNING: Removing unreachable block (ram,0xf0050820) */
/* WARNING: Removing unreachable block (ram,0xf0050848) */
/* WARNING: Removing unreachable block (ram,0xf0050860) */
/* WARNING: Removing unreachable block (ram,0xf00507cc) */

undefined8 sub_F0050790(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar3;
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
  dword_F010F0B0 = dword_F010F0B0 + 1;
  if (dword_F010F0B0 == 1) {
    iVar1 = (int)_rootdev;
    piVar3 = (int *)0x2;
    if (iVar1 != -1) {
      _bdevvp();
      *param_2 = iVar1;
      if (_rootrw == 0) {
        *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 1;
      }
      piVar3 = param_2;
      sub_F0050874(param_2,&unk_F010F0B8,param_1);
      piVar2 = (int *)0x0;
      if (piVar3 == (int *)0x0) {
        _vfs_add(0,param_1,*(uint *)(param_1 + 0xc) & 1);
        if (piVar2 == (int *)0x0) {
          _vfs_unlock(param_1);
          _inittodr(*(undefined4 *)
                     (*(int *)(*(int *)(*(int *)(param_1 + 0x128) + 0xc) + 0x20) + 0x20));
          piVar3 = (int *)0x0;
          goto locret_F005086C;
        }
        sub_F0050E78(param_1,0);
        piVar3 = piVar2;
      }
      _vn_rele(*param_2);
      *param_2 = 0;
    }
  }
  else {
    piVar3 = (int *)0x10;
  }
locret_F005086C:
  return CONCAT44(param_2,piVar3);
}

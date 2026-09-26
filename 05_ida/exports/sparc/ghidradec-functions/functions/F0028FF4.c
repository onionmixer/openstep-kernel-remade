
/* WARNING: Removing unreachable block (ram,0xf0029070) */
/* WARNING: Removing unreachable block (ram,0xf0029098) */
/* WARNING: Removing unreachable block (ram,0xf002900c) */

undefined8 _vn_close(int *param_1,uint param_2,undefined4 param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar4;
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
  if (param_1[10] == 1) {
    _unmap_vnode(param_1);
  }
  piVar4 = param_1;
  (**(code **)(param_1[7] + 4))(param_1,param_2,param_3,*(undefined4 *)(_active_u + 0x1c));
  iVar3 = *param_1;
  if ((iVar3 != 0) && (piVar1 = *(int **)(iVar3 + 0x34), piVar1 != (int *)0x0)) {
    *(undefined4 *)(iVar3 + 0x34) = 0;
    *(char *)(dword_F0133DDC + 0x38) = (char)piVar1;
    piVar4 = piVar1;
    do {
      uVar2 = param_2 & 0x1000;
      _fspause();
      if (uVar2 == 0) break;
      piVar4 = *(int **)(*param_1 + 0x34);
      *(undefined4 *)(*param_1 + 0x34) = 0;
      *(char *)(dword_F0133DDC + 0x38) = (char)piVar4;
      _mfs_fsync(param_1);
    } while (piVar4 != (int *)0x0);
  }
  return CONCAT44(param_2,piVar4);
}

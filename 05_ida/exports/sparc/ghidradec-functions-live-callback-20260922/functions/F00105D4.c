
/* WARNING: Removing unreachable block (ram,0xf0010680) */
/* WARNING: Removing unreachable block (ram,0xf001065c) */
/* WARNING: Removing unreachable block (ram,0xf0010638) */
/* WARNING: Removing unreachable block (ram,0xf0010600) */
/* WARNING: Removing unreachable block (ram,0xf00105f0) */
/* WARNING: Removing unreachable block (ram,0xf00105e0) */
/* WARNING: Removing unreachable block (ram,0xf00105e8) */
/* WARNING: Removing unreachable block (ram,0xf00105f8) */
/* WARNING: Removing unreachable block (ram,0xf0010608) */
/* WARNING: Removing unreachable block (ram,0xf0010644) */
/* WARNING: Removing unreachable block (ram,0xf0010674) */
/* WARNING: Removing unreachable block (ram,0xf0010694) */
/* WARNING: Removing unreachable block (ram,0xf00105d8) */

undefined8 _unmount_all(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  undefined8 *puVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar3;
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
  _proc_shutdown();
  _kill_tasks();
  _mfs_cache_clear();
  _vm_object_cache_clear();
  _fd_shutdown();
  _vm_object_shutdown();
  _vnode_pager_shutdown();
  piVar1 = (int *)*_rootvfs;
  while (piVar1 != (int *)0x0) {
    _printf(aUnmountingS,piVar1 + 8);
    iVar3 = *piVar1;
    _dounmount();
    puVar2 = &aFailed_0;
    if (piVar1 == (int *)0x0) {
      puVar2 = (undefined8 *)&aDone;
    }
    _printf(puVar2);
    piVar1 = (int *)iVar3;
  }
  _vn_rele(_rootdir);
  piVar1 = _rootvfs;
  _dounmount();
  if (piVar1 != (int *)0x0) {
    _printf(aRootUnmountFai);
  }
  return CONCAT44(param_2,param_1);
}


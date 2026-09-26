
/* WARNING: Removing unreachable block (ram,0xf006cca4) */
/* WARNING: Removing unreachable block (ram,0xf006cc74) */
/* WARNING: Removing unreachable block (ram,0xf006cc38) */
/* WARNING: Removing unreachable block (ram,0xf006cc50) */
/* WARNING: Removing unreachable block (ram,0xf006cc7c) */
/* WARNING: Removing unreachable block (ram,0xf006ccb8) */
/* WARNING: Removing unreachable block (ram,0xf006cc28) */

undefined8 _mfs_map_remove(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar2;
  undefined4 unaff_i1;
  int *piVar3;
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
  if (param_4 != 0) {
    _vmp_push(param_1);
  }
  _lock_write(_mfs_alloc_lock_data);
  _vm_map_remove(_mfs_map,param_2,param_3);
  if (_mfs_alloc_wanted != 0) {
    _mfs_alloc_wanted = 0;
    _thread_wakeup_prim(&_mfs_map,0,0);
  }
  _lock_done(_mfs_alloc_lock_data);
  iVar2 = *(int *)(param_1 + 0x24);
  piVar3 = (int *)(iVar2 + 0x10);
  if (iVar2 != 0) {
    do {
      do {
      } while (*piVar3 != 0);
      piVar1 = piVar3;
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    _vm_object_deactivate_pages(iVar2);
    *(undefined4 *)(iVar2 + 0x10) = 0;
  }
  return CONCAT44(piVar3,iVar2);
}


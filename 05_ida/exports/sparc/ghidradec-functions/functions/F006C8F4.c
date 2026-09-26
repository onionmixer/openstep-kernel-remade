
/* WARNING: Removing unreachable block (ram,0xf006c974) */
/* WARNING: Removing unreachable block (ram,0xf006c940) */
/* WARNING: Removing unreachable block (ram,0xf006c950) */
/* WARNING: Removing unreachable block (ram,0xf006c994) */
/* WARNING: Removing unreachable block (ram,0xf006c910) */

undefined8 _vmp_put(int param_1,undefined4 param_2)

{
  sword sVar1;
  undefined4 *puVar2;
  uint uVar3;
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
  do {
    do {
    } while (_vm_info_lock_data != 0);
    puVar2 = &_vm_info_lock_data;
    _simple_lock_try();
  } while (puVar2 == (undefined4 *)0x0);
  sVar1 = *(sword *)(param_1 + 6);
  *(sword *)(param_1 + 6) = sVar1 + -1;
  if (sVar1 == 1) {
    _vm_info_enqueue(param_1);
  }
  _vm_info_lock_data = 0;
  _lock_done(param_1 + 0x18);
  if (_mfs_files_max < _mfs_files_mapped) {
    _mfs_cache_trim();
    uVar3 = *(uint *)(param_1 + 0x38);
  }
  else {
    uVar3 = *(uint *)(param_1 + 0x38);
  }
  if ((uVar3 & 0x10000000) != 0) {
    *(uint *)(param_1 + 0x38) = uVar3 & 0xefffffff;
    _vmp_invalidate(param_1);
  }
  return CONCAT44(param_2,param_1);
}

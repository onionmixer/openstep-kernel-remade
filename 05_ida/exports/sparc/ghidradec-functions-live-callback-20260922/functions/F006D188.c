
/* WARNING: Removing unreachable block (ram,0xf006d244) */
/* WARNING: Removing unreachable block (ram,0xf006d20c) */
/* WARNING: Removing unreachable block (ram,0xf006d1e4) */
/* WARNING: Removing unreachable block (ram,0xf006d22c) */
/* WARNING: Removing unreachable block (ram,0xf006d274) */
/* WARNING: Removing unreachable block (ram,0xf006d1c0) */

undefined8 _mfs_fsync_invalidate(int *param_1,uint param_2)

{
  sword sVar1;
  undefined4 *puVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar3;
  undefined4 uVar4;
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
  iVar3 = *param_1;
  if ((iVar3 == 0) || ((*(uint *)(iVar3 + 0x38) & 0x8000000) == 0)) {
    uVar4 = 0;
  }
  else {
    do {
      do {
      } while (_vm_info_lock_data != 0);
      puVar2 = &_vm_info_lock_data;
      _simple_lock_try();
    } while (puVar2 == (undefined4 *)0x0);
    if (*(int *)(iVar3 + 0x38) < 0) {
      _vm_info_dequeue(iVar3);
      sVar1 = *(sword *)(iVar3 + 6);
    }
    else {
      sVar1 = *(sword *)(iVar3 + 6);
    }
    *(sword *)(iVar3 + 6) = sVar1 + 1;
    _vm_info_lock_data = 0;
    if ((param_2 & 1) == 0) {
      _vmp_push_all(iVar3);
    }
    if ((param_2 & 2) == 0) {
      *(uint *)(iVar3 + 0x38) = *(uint *)(iVar3 + 0x38) & 0xefffffff;
      _vmp_invalidate(iVar3);
    }
    do {
      do {
      } while (_vm_info_lock_data != 0);
      puVar2 = &_vm_info_lock_data;
      _simple_lock_try();
    } while (puVar2 == (undefined4 *)0x0);
    sVar1 = *(sword *)(iVar3 + 6);
    *(sword *)(iVar3 + 6) = sVar1 + -1;
    if (sVar1 == 1) {
      _vm_info_enqueue(iVar3);
    }
    _vm_info_lock_data = 0;
    uVar4 = *(undefined4 *)(iVar3 + 0x34);
  }
  return CONCAT44(param_2,uVar4);
}


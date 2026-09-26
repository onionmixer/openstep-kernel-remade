
/* WARNING: Removing unreachable block (ram,0xf006cbb4) */
/* WARNING: Removing unreachable block (ram,0xf006cbd0) */
/* WARNING: Removing unreachable block (ram,0xf006cb60) */

undefined8 _mfs_cache_clear(undefined4 param_1,undefined4 param_2)

{
  sword sVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar4;
  int iVar5;
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
  if ((undefined4 **)_vm_info_queue != &_vm_info_queue) {
    sVar1 = *(sword *)(_vm_info_queue + 1);
    puVar2 = _vm_info_queue;
    iVar4 = _vm_info_version;
    while( true ) {
      if (sVar1 == 0) {
        _vm_info_lock_data = 0;
        _mfs_memfree(puVar2,1);
        do {
          do {
          } while (_vm_info_lock_data != 0);
          puVar3 = &_vm_info_lock_data;
          _simple_lock_try();
        } while (puVar3 == (undefined4 *)0x0);
      }
      puVar3 = _vm_info_queue;
      iVar5 = _vm_info_version;
      if (iVar4 == _vm_info_version) {
        puVar3 = (undefined4 *)puVar2[10];
        iVar5 = iVar4;
      }
      if ((undefined4 **)puVar3 == &_vm_info_queue) break;
      sVar1 = *(sword *)(puVar3 + 1);
      puVar2 = puVar3;
      iVar4 = iVar5;
    }
  }
  _vm_info_lock_data = 0;
  return CONCAT44(param_2,param_1);
}

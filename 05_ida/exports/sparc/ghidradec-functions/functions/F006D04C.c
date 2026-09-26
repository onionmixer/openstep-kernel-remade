
/* WARNING: Removing unreachable block (ram,0xf006d0cc) */
/* WARNING: Removing unreachable block (ram,0xf006d0bc) */
/* WARNING: Removing unreachable block (ram,0xf006d0c4) */
/* WARNING: Removing unreachable block (ram,0xf006d0e8) */
/* WARNING: Removing unreachable block (ram,0xf006d068) */

undefined8 _mfs_sync(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
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
    puVar1 = &_vm_info_lock_data;
    _simple_lock_try();
  } while (puVar1 == (undefined4 *)0x0);
  if ((undefined4 **)_vm_info_queue != &_vm_info_queue) {
    uVar2 = _vm_info_queue[0xe];
    puVar1 = _vm_info_queue;
    iVar3 = _vm_info_version;
    while( true ) {
      puVar5 = (undefined4 *)puVar1[10];
      if ((uVar2 & 0x40000000) != 0) {
        _vm_info_lock_data = 0;
        _vmp_get(puVar1);
        _vmp_push(puVar1);
        _vmp_put(puVar1);
        do {
          do {
          } while (_vm_info_lock_data != 0);
          puVar1 = &_vm_info_lock_data;
          _simple_lock_try();
        } while (puVar1 == (undefined4 *)0x0);
        iVar3 = iVar3 + 2;
      }
      puVar1 = _vm_info_queue;
      iVar4 = _vm_info_version;
      if (iVar3 == _vm_info_version) {
        puVar1 = puVar5;
        iVar4 = iVar3;
      }
      if ((undefined4 **)puVar1 == &_vm_info_queue) break;
      uVar2 = puVar1[0xe];
      iVar3 = iVar4;
    }
  }
  _vm_info_lock_data = 0;
  return CONCAT44(param_2,param_1);
}

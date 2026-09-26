
void _mfs_memfree(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  
  do {
    iVar4 = _vm_info_lock_data;
    do {
    } while (iVar4 != 0);
    LOCK();
    iVar4 = _vm_info_lock_data;
    _vm_info_lock_data = 1;
    UNLOCK();
  } while (iVar4 == 1);
  if ((*(byte *)(param_1 + 0x38) & 1) != 0) {
    puVar1 = *(undefined4 **)(param_1 + 0x28);
    puVar2 = *(undefined4 **)(param_1 + 0x2c);
    if (puVar1 == &_vm_info_queue) {
      DAT_001f64d4 = puVar2;
    }
    else {
      puVar1[0xb] = puVar2;
    }
    if (puVar2 == &_vm_info_queue) {
      _vm_info_queue = puVar1;
    }
    else {
      puVar2[10] = puVar1;
    }
    *(byte *)(param_1 + 0x38) = *(byte *)(param_1 + 0x38) & 0xfe;
    uVar3 = _mfs_files_mapped;
    iVar4 = _mfs_files_mapped;
    _mfs_files_mapped = iVar4 + -1;
    uVar3 = _mfs_files_mapped;
    uVar3 = _mfs_files_mapped;
    uVar3 = _mfs_files_mapped;
    uVar3 = _vm_info_version;
    iVar4 = _vm_info_version;
    _vm_info_version = iVar4 + 1;
    uVar3 = _vm_info_version;
    uVar3 = _vm_info_version;
    uVar3 = _vm_info_version;
  }
  LOCK();
  uVar3 = _vm_info_lock_data;
  _vm_info_lock_data = 0;
  UNLOCK();
  _lock_write(param_1 + 0x18);
  if (*(short *)(param_1 + 4) == 0) {
    *(byte *)(param_1 + 0x38) = *(byte *)(param_1 + 0x38) & 0xef;
  }
  _mfs_map_remove(param_1,*(int *)(param_1 + 8),*(int *)(param_1 + 8) + *(int *)(param_1 + 0xc),
                  param_2);
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  iVar4 = 0;
  if (*(short *)(param_1 + 4) == 0) {
    iVar4 = *(int *)(param_1 + 0x24);
    *(undefined4 *)(param_1 + 0x24) = 0;
    if (*(int *)(param_1 + 0x30) != 0) {
      _crfree(*(int *)(param_1 + 0x30));
      *(undefined4 *)(param_1 + 0x30) = 0;
    }
  }
  _lock_done(param_1 + 0x18);
  if (iVar4 != 0) {
    _vm_object_deallocate(iVar4);
  }
  return;
}


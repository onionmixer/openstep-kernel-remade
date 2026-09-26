
void _vmp_get(int param_1)

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
  *(short *)(param_1 + 6) = *(short *)(param_1 + 6) + 1;
  LOCK();
  uVar3 = _vm_info_lock_data;
  _vm_info_lock_data = 0;
  UNLOCK();
  _lock_write(param_1 + 0x18);
  return;
}



void _vmp_put(int param_1)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  
  do {
    iVar3 = _vm_info_lock_data;
    do {
    } while (iVar3 != 0);
    LOCK();
    iVar3 = _vm_info_lock_data;
    _vm_info_lock_data = 1;
    UNLOCK();
  } while (iVar3 == 1);
  sVar1 = *(short *)(param_1 + 6);
  *(short *)(param_1 + 6) = sVar1 + -1;
  if (sVar1 == 1) {
    puVar5 = (undefined4 *)DAT_001f64d4;
    if (puVar5 == &_vm_info_queue) {
      _vm_info_queue = param_1;
    }
    else {
      puVar5[10] = param_1;
    }
    *(undefined4 **)(param_1 + 0x2c) = puVar5;
    *(undefined4 **)(param_1 + 0x28) = &_vm_info_queue;
    DAT_001f64d4 = param_1;
    *(byte *)(param_1 + 0x38) = *(byte *)(param_1 + 0x38) | 1;
    uVar2 = _mfs_files_mapped;
    iVar3 = _mfs_files_mapped;
    _mfs_files_mapped = iVar3 + 1;
    uVar2 = _mfs_files_mapped;
    uVar2 = _mfs_files_mapped;
    uVar2 = _mfs_files_mapped;
    uVar2 = _vm_info_version;
    iVar3 = _vm_info_version;
    _vm_info_version = iVar3 + 1;
    uVar2 = _vm_info_version;
    uVar2 = _vm_info_version;
    uVar2 = _vm_info_version;
  }
  LOCK();
  uVar2 = _vm_info_lock_data;
  _vm_info_lock_data = 0;
  UNLOCK();
  _lock_done(param_1 + 0x18);
  iVar3 = _mfs_files_max;
  iVar4 = _mfs_files_mapped;
  if (iVar3 < iVar4) {
    _mfs_cache_trim();
  }
  if ((*(byte *)(param_1 + 0x38) & 8) != 0) {
    *(byte *)(param_1 + 0x38) = *(byte *)(param_1 + 0x38) & 0xf7;
    _vmp_invalidate(param_1);
  }
  return;
}


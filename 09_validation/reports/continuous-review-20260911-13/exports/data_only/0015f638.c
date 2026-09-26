
undefined4 _mfs_fsync(int *param_1)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  
  iVar2 = *param_1;
  if ((iVar2 == 0) || ((*(byte *)(iVar2 + 0x38) & 0x10) == 0)) {
    uVar7 = 0;
  }
  else {
    do {
    } while (_vm_info_lock_data != 0);
    LOCK();
    UNLOCK();
    if ((*(byte *)(iVar2 + 0x38) & 1) != 0) {
      puVar3 = *(undefined4 **)(iVar2 + 0x28);
      puVar4 = *(undefined4 **)(iVar2 + 0x2c);
      if (puVar3 == &_vm_info_queue) {
        DAT_001f64d4 = puVar4;
      }
      else {
        puVar3[0xb] = puVar4;
      }
      if (puVar4 == &_vm_info_queue) {
        _vm_info_queue = puVar3;
      }
      else {
        puVar4[10] = puVar3;
      }
      *(byte *)(iVar2 + 0x38) = *(byte *)(iVar2 + 0x38) & 0xfe;
      uVar7 = _mfs_files_mapped;
      iVar5 = _mfs_files_mapped;
      _mfs_files_mapped = iVar5 + -1;
      uVar7 = _mfs_files_mapped;
      uVar7 = _mfs_files_mapped;
      uVar7 = _mfs_files_mapped;
      uVar7 = _vm_info_version;
      iVar5 = _vm_info_version;
      _vm_info_version = iVar5 + 1;
      uVar7 = _vm_info_version;
      uVar7 = _vm_info_version;
      uVar7 = _vm_info_version;
    }
    *(short *)(iVar2 + 6) = *(short *)(iVar2 + 6) + 1;
    LOCK();
    _vm_info_lock_data = 0;
    UNLOCK();
    _lock_write(iVar2 + 0x18);
    _vmp_push(iVar2);
    do {
    } while (_vm_info_lock_data != 0);
    LOCK();
    UNLOCK();
    sVar1 = *(short *)(iVar2 + 6);
    *(short *)(iVar2 + 6) = sVar1 + -1;
    if (sVar1 == 1) {
      puVar3 = (undefined4 *)DAT_001f64d4;
      if (puVar3 == &_vm_info_queue) {
        _vm_info_queue = iVar2;
      }
      else {
        puVar3[10] = iVar2;
      }
      *(undefined4 **)(iVar2 + 0x2c) = puVar3;
      *(undefined4 **)(iVar2 + 0x28) = &_vm_info_queue;
      DAT_001f64d4 = iVar2;
      *(byte *)(iVar2 + 0x38) = *(byte *)(iVar2 + 0x38) | 1;
      uVar7 = _mfs_files_mapped;
      iVar5 = _mfs_files_mapped;
      _mfs_files_mapped = iVar5 + 1;
      uVar7 = _mfs_files_mapped;
      uVar7 = _mfs_files_mapped;
      uVar7 = _mfs_files_mapped;
      uVar7 = _vm_info_version;
      iVar5 = _vm_info_version;
      _vm_info_version = iVar5 + 1;
      uVar7 = _vm_info_version;
      uVar7 = _vm_info_version;
      uVar7 = _vm_info_version;
    }
    LOCK();
    _vm_info_lock_data = 0;
    UNLOCK();
    _lock_done(iVar2 + 0x18);
    iVar5 = _mfs_files_max;
    iVar6 = _mfs_files_mapped;
    if (iVar5 < iVar6) {
      _mfs_cache_trim();
    }
    if ((*(byte *)(iVar2 + 0x38) & 8) != 0) {
      *(byte *)(iVar2 + 0x38) = *(byte *)(iVar2 + 0x38) & 0xf7;
      _vmp_invalidate(iVar2);
    }
    uVar7 = *(undefined4 *)(iVar2 + 0x34);
  }
  return uVar7;
}


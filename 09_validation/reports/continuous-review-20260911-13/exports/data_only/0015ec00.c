
undefined4 _mfs_cache_trim(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  while( true ) {
    do {
    } while (_vm_info_lock_data != 0);
    LOCK();
    UNLOCK();
    iVar4 = _mfs_files_max;
    iVar5 = _mfs_files_mapped;
    if (iVar5 <= iVar4) break;
    iVar4 = _vm_info_queue;
    puVar1 = *(undefined4 **)(iVar4 + 0x28);
    puVar2 = *(undefined4 **)(iVar4 + 0x2c);
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
    *(byte *)(iVar4 + 0x38) = *(byte *)(iVar4 + 0x38) & 0xfe;
    uVar3 = _mfs_files_mapped;
    iVar5 = _mfs_files_mapped;
    _mfs_files_mapped = iVar5 + -1;
    uVar3 = _mfs_files_mapped;
    uVar3 = _mfs_files_mapped;
    uVar3 = _mfs_files_mapped;
    uVar3 = _vm_info_version;
    iVar5 = _vm_info_version;
    _vm_info_version = iVar5 + 1;
    uVar3 = _vm_info_version;
    uVar3 = _vm_info_version;
    uVar3 = _vm_info_version;
    LOCK();
    UNLOCK();
    LOCK();
    UNLOCK();
    if ((*(byte *)(iVar4 + 0x38) & 1) != 0) {
      puVar1 = *(undefined4 **)(iVar4 + 0x28);
      puVar2 = *(undefined4 **)(iVar4 + 0x2c);
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
      *(byte *)(iVar4 + 0x38) = *(byte *)(iVar4 + 0x38) & 0xfe;
      uVar3 = _mfs_files_mapped;
      iVar5 = _mfs_files_mapped;
      _mfs_files_mapped = iVar5 + -1;
      uVar3 = _mfs_files_mapped;
      uVar3 = _mfs_files_mapped;
      uVar3 = _mfs_files_mapped;
      uVar3 = _vm_info_version;
      iVar5 = _vm_info_version;
      _vm_info_version = iVar5 + 1;
      uVar3 = _vm_info_version;
      uVar3 = _vm_info_version;
      uVar3 = _vm_info_version;
    }
    LOCK();
    _vm_info_lock_data = 0;
    UNLOCK();
    _lock_write(iVar4 + 0x18);
    if (*(short *)(iVar4 + 4) == 0) {
      *(byte *)(iVar4 + 0x38) = *(byte *)(iVar4 + 0x38) & 0xef;
    }
    _mfs_map_remove(iVar4,*(int *)(iVar4 + 8),*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc),1);
    *(undefined4 *)(iVar4 + 0xc) = 0;
    *(undefined4 *)(iVar4 + 8) = 0;
    iVar5 = 0;
    if (*(short *)(iVar4 + 4) == 0) {
      iVar5 = *(int *)(iVar4 + 0x24);
      *(undefined4 *)(iVar4 + 0x24) = 0;
      if (*(int *)(iVar4 + 0x30) != 0) {
        _crfree(*(int *)(iVar4 + 0x30));
        *(undefined4 *)(iVar4 + 0x30) = 0;
      }
    }
    _lock_done(iVar4 + 0x18);
    if (iVar5 != 0) {
      _vm_object_deallocate(iVar5);
    }
  }
  LOCK();
  _vm_info_lock_data = 0;
  UNLOCK();
  return 1;
}


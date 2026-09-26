
undefined4 _mfs_cache_clear(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  
  do {
    iVar6 = _vm_info_lock_data;
    do {
    } while (iVar6 != 0);
    LOCK();
    iVar6 = _vm_info_lock_data;
    _vm_info_lock_data = 1;
    UNLOCK();
  } while (iVar6 == 1);
  iVar6 = _vm_info_version;
  puVar4 = (undefined4 *)_vm_info_queue;
  while (puVar4 != &_vm_info_queue) {
    if (*(short *)(puVar4 + 1) == 0) {
      LOCK();
      uVar3 = _vm_info_lock_data;
      _vm_info_lock_data = 0;
      UNLOCK();
      do {
        iVar5 = _vm_info_lock_data;
        do {
        } while (iVar5 != 0);
        LOCK();
        iVar5 = _vm_info_lock_data;
        _vm_info_lock_data = 1;
        UNLOCK();
      } while (iVar5 == 1);
      if ((*(byte *)(puVar4 + 0xe) & 1) != 0) {
        puVar1 = (undefined4 *)puVar4[10];
        puVar2 = (undefined4 *)puVar4[0xb];
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
        *(byte *)(puVar4 + 0xe) = *(byte *)(puVar4 + 0xe) & 0xfe;
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
      uVar3 = _vm_info_lock_data;
      _vm_info_lock_data = 0;
      UNLOCK();
      _lock_write(puVar4 + 6);
      if (*(short *)(puVar4 + 1) == 0) {
        *(byte *)(puVar4 + 0xe) = *(byte *)(puVar4 + 0xe) & 0xef;
      }
      _mfs_map_remove(puVar4,puVar4[2],puVar4[2] + puVar4[3],1);
      puVar4[3] = 0;
      puVar4[2] = 0;
      iVar5 = 0;
      if (*(short *)(puVar4 + 1) == 0) {
        iVar5 = puVar4[9];
        puVar4[9] = 0;
        if (puVar4[0xc] != 0) {
          _crfree(puVar4[0xc]);
          puVar4[0xc] = 0;
        }
      }
      _lock_done(puVar4 + 6);
      if (iVar5 != 0) {
        _vm_object_deallocate(iVar5);
      }
      do {
        iVar5 = _vm_info_lock_data;
        do {
        } while (iVar5 != 0);
        LOCK();
        iVar5 = _vm_info_lock_data;
        _vm_info_lock_data = 1;
        UNLOCK();
      } while (iVar5 == 1);
    }
    iVar5 = _vm_info_version;
    if (iVar6 == iVar5) {
      puVar4 = (undefined4 *)puVar4[10];
    }
    else {
      puVar4 = (undefined4 *)_vm_info_queue;
      iVar6 = iVar5;
    }
  }
  LOCK();
  uVar3 = _vm_info_lock_data;
  _vm_info_lock_data = 0;
  UNLOCK();
  return uVar3;
}


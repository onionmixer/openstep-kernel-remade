
undefined4 _mfs_cache_trim(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  
  while( true ) {
    do {
      puVar4 = _vm_info_queue;
      iVar6 = _vm_info_lock_data;
      do {
      } while (iVar6 != 0);
      LOCK();
      iVar6 = _vm_info_lock_data;
      _vm_info_lock_data = 1;
      UNLOCK();
    } while (iVar6 == 1);
    if (_mfs_files_mapped <= _mfs_files_max) break;
    puVar1 = (undefined4 *)_vm_info_queue[10];
    puVar2 = (undefined4 *)_vm_info_queue[0xb];
    puVar5 = puVar2;
    if ((undefined4 **)puVar1 != &_vm_info_queue) {
      puVar1[0xb] = puVar2;
      puVar5 = DAT_001f64d4;
    }
    DAT_001f64d4 = puVar5;
    if ((undefined4 **)puVar2 != &_vm_info_queue) {
      puVar2[10] = puVar1;
      puVar1 = _vm_info_queue;
    }
    _vm_info_queue = puVar1;
    *(byte *)(puVar4 + 0xe) = *(byte *)(puVar4 + 0xe) & 0xfe;
    _mfs_files_mapped = _mfs_files_mapped + -1;
    _vm_info_version = _vm_info_version + 1;
    LOCK();
    uVar3 = _vm_info_lock_data;
    _vm_info_lock_data = 0;
    UNLOCK();
    do {
      iVar6 = _vm_info_lock_data;
      do {
      } while (iVar6 != 0);
      LOCK();
      iVar6 = _vm_info_lock_data;
      _vm_info_lock_data = 1;
      UNLOCK();
    } while (iVar6 == 1);
    if ((*(byte *)(puVar4 + 0xe) & 1) != 0) {
      puVar1 = (undefined4 *)puVar4[10];
      puVar2 = (undefined4 *)puVar4[0xb];
      puVar5 = puVar2;
      if ((undefined4 **)puVar1 != &_vm_info_queue) {
        puVar1[0xb] = puVar2;
        puVar5 = DAT_001f64d4;
      }
      DAT_001f64d4 = puVar5;
      if ((undefined4 **)puVar2 != &_vm_info_queue) {
        puVar2[10] = puVar1;
        puVar1 = _vm_info_queue;
      }
      _vm_info_queue = puVar1;
      *(byte *)(puVar4 + 0xe) = *(byte *)(puVar4 + 0xe) & 0xfe;
      _mfs_files_mapped = _mfs_files_mapped + -1;
      _vm_info_version = _vm_info_version + 1;
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
    iVar6 = 0;
    if (*(short *)(puVar4 + 1) == 0) {
      iVar6 = puVar4[9];
      puVar4[9] = 0;
      if (puVar4[0xc] != 0) {
        _crfree(puVar4[0xc]);
        puVar4[0xc] = 0;
      }
    }
    _lock_done(puVar4 + 6);
    if (iVar6 != 0) {
      _vm_object_deallocate(iVar6);
    }
  }
  LOCK();
  uVar3 = _vm_info_lock_data;
  _vm_info_lock_data = 0;
  UNLOCK();
  return uVar3;
}


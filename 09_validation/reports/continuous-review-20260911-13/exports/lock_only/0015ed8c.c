
undefined4 _mfs_cache_clear(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  
  do {
    iVar7 = _vm_info_lock_data;
    do {
    } while (iVar7 != 0);
    LOCK();
    iVar7 = _vm_info_lock_data;
    _vm_info_lock_data = 1;
    UNLOCK();
    puVar1 = _vm_info_queue;
    iVar6 = _vm_info_version;
  } while (iVar7 == 1);
  while (iVar7 = iVar6, puVar5 = puVar1, (undefined4 **)puVar5 != &_vm_info_queue) {
    if (*(short *)(puVar5 + 1) == 0) {
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
      if ((*(byte *)(puVar5 + 0xe) & 1) != 0) {
        puVar1 = (undefined4 *)puVar5[10];
        puVar2 = (undefined4 *)puVar5[0xb];
        puVar4 = puVar2;
        if ((undefined4 **)puVar1 != &_vm_info_queue) {
          puVar1[0xb] = puVar2;
          puVar4 = DAT_001f64d4;
        }
        DAT_001f64d4 = puVar4;
        if ((undefined4 **)puVar2 != &_vm_info_queue) {
          puVar2[10] = puVar1;
          puVar1 = _vm_info_queue;
        }
        _vm_info_queue = puVar1;
        *(byte *)(puVar5 + 0xe) = *(byte *)(puVar5 + 0xe) & 0xfe;
        _mfs_files_mapped = _mfs_files_mapped + -1;
        _vm_info_version = _vm_info_version + 1;
      }
      LOCK();
      uVar3 = _vm_info_lock_data;
      _vm_info_lock_data = 0;
      UNLOCK();
      _lock_write(puVar5 + 6);
      if (*(short *)(puVar5 + 1) == 0) {
        *(byte *)(puVar5 + 0xe) = *(byte *)(puVar5 + 0xe) & 0xef;
      }
      _mfs_map_remove(puVar5,puVar5[2],puVar5[2] + puVar5[3],1);
      puVar5[3] = 0;
      puVar5[2] = 0;
      iVar6 = 0;
      if (*(short *)(puVar5 + 1) == 0) {
        iVar6 = puVar5[9];
        puVar5[9] = 0;
        if (puVar5[0xc] != 0) {
          _crfree(puVar5[0xc]);
          puVar5[0xc] = 0;
        }
      }
      _lock_done(puVar5 + 6);
      if (iVar6 != 0) {
        _vm_object_deallocate(iVar6);
      }
      do {
        iVar6 = _vm_info_lock_data;
        do {
        } while (iVar6 != 0);
        LOCK();
        iVar6 = _vm_info_lock_data;
        _vm_info_lock_data = 1;
        UNLOCK();
      } while (iVar6 == 1);
    }
    puVar1 = _vm_info_queue;
    iVar6 = _vm_info_version;
    if (iVar7 == _vm_info_version) {
      puVar1 = (undefined4 *)puVar5[10];
      iVar6 = iVar7;
    }
  }
  LOCK();
  uVar3 = _vm_info_lock_data;
  _vm_info_lock_data = 0;
  UNLOCK();
  return uVar3;
}


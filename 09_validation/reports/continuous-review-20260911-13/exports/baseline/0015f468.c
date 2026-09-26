
undefined4 _mfs_sync(void)

{
  short sVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  
  do {
  } while (_vm_info_lock_data != 0);
  LOCK();
  UNLOCK();
  puVar7 = _vm_info_queue;
  iVar5 = _vm_info_version;
  while (iVar8 = iVar5, (undefined4 **)puVar7 != &_vm_info_queue) {
    puVar2 = (undefined4 *)puVar7[10];
    if ((*(byte *)(puVar7 + 0xe) & 2) != 0) {
      LOCK();
      UNLOCK();
      LOCK();
      UNLOCK();
      if ((*(byte *)(puVar7 + 0xe) & 1) != 0) {
        puVar3 = (undefined4 *)puVar7[10];
        puVar4 = (undefined4 *)puVar7[0xb];
        puVar6 = puVar4;
        if ((undefined4 **)puVar3 != &_vm_info_queue) {
          puVar3[0xb] = puVar4;
          puVar6 = DAT_001f64d4;
        }
        DAT_001f64d4 = puVar6;
        if ((undefined4 **)puVar4 != &_vm_info_queue) {
          puVar4[10] = puVar3;
          puVar3 = _vm_info_queue;
        }
        _vm_info_queue = puVar3;
        *(byte *)(puVar7 + 0xe) = *(byte *)(puVar7 + 0xe) & 0xfe;
        _mfs_files_mapped = _mfs_files_mapped + -1;
        _vm_info_version = _vm_info_version + 1;
      }
      *(short *)((int)puVar7 + 6) = *(short *)((int)puVar7 + 6) + 1;
      LOCK();
      _vm_info_lock_data = 0;
      UNLOCK();
      _lock_write(puVar7 + 6);
      _vmp_push(puVar7);
      do {
      } while (_vm_info_lock_data != 0);
      LOCK();
      UNLOCK();
      sVar1 = *(short *)((int)puVar7 + 6);
      *(short *)((int)puVar7 + 6) = sVar1 + -1;
      if (sVar1 == 1) {
        puVar3 = puVar7;
        if ((undefined4 **)DAT_001f64d4 != &_vm_info_queue) {
          DAT_001f64d4[10] = puVar7;
          puVar3 = _vm_info_queue;
        }
        _vm_info_queue = puVar3;
        puVar7[0xb] = DAT_001f64d4;
        puVar7[10] = &_vm_info_queue;
        DAT_001f64d4 = puVar7;
        *(byte *)(puVar7 + 0xe) = *(byte *)(puVar7 + 0xe) | 1;
        _mfs_files_mapped = _mfs_files_mapped + 1;
        _vm_info_version = _vm_info_version + 1;
      }
      LOCK();
      _vm_info_lock_data = 0;
      UNLOCK();
      _lock_done(puVar7 + 6);
      if (_mfs_files_max < _mfs_files_mapped) {
        _mfs_cache_trim();
      }
      if ((*(byte *)(puVar7 + 0xe) & 8) != 0) {
        *(byte *)(puVar7 + 0xe) = *(byte *)(puVar7 + 0xe) & 0xf7;
        _vmp_invalidate(puVar7);
      }
      do {
      } while (_vm_info_lock_data != 0);
      LOCK();
      UNLOCK();
      iVar8 = iVar8 + 2;
    }
    puVar7 = _vm_info_queue;
    iVar5 = _vm_info_version;
    if (iVar8 == _vm_info_version) {
      puVar7 = puVar2;
      iVar5 = iVar8;
    }
  }
  LOCK();
  _vm_info_lock_data = 0;
  UNLOCK();
  return 1;
}



undefined4 _mfs_sync(void)

{
  short sVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  
  do {
    iVar9 = _vm_info_lock_data;
    do {
    } while (iVar9 != 0);
    LOCK();
    iVar9 = _vm_info_lock_data;
    _vm_info_lock_data = 1;
    UNLOCK();
    puVar8 = _vm_info_queue;
    iVar6 = _vm_info_version;
  } while (iVar9 == 1);
  while (iVar9 = iVar6, (undefined4 **)puVar8 != &_vm_info_queue) {
    puVar2 = (undefined4 *)puVar8[10];
    if ((*(byte *)(puVar8 + 0xe) & 2) != 0) {
      LOCK();
      uVar5 = _vm_info_lock_data;
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
      if ((*(byte *)(puVar8 + 0xe) & 1) != 0) {
        puVar3 = (undefined4 *)puVar8[10];
        puVar4 = (undefined4 *)puVar8[0xb];
        puVar7 = puVar4;
        if ((undefined4 **)puVar3 != &_vm_info_queue) {
          puVar3[0xb] = puVar4;
          puVar7 = DAT_001f64d4;
        }
        DAT_001f64d4 = puVar7;
        if ((undefined4 **)puVar4 != &_vm_info_queue) {
          puVar4[10] = puVar3;
          puVar3 = _vm_info_queue;
        }
        _vm_info_queue = puVar3;
        *(byte *)(puVar8 + 0xe) = *(byte *)(puVar8 + 0xe) & 0xfe;
        _mfs_files_mapped = _mfs_files_mapped + -1;
        _vm_info_version = _vm_info_version + 1;
      }
      *(short *)((int)puVar8 + 6) = *(short *)((int)puVar8 + 6) + 1;
      LOCK();
      uVar5 = _vm_info_lock_data;
      _vm_info_lock_data = 0;
      UNLOCK();
      _lock_write(puVar8 + 6);
      _vmp_push(puVar8);
      do {
        iVar6 = _vm_info_lock_data;
        do {
        } while (iVar6 != 0);
        LOCK();
        iVar6 = _vm_info_lock_data;
        _vm_info_lock_data = 1;
        UNLOCK();
      } while (iVar6 == 1);
      sVar1 = *(short *)((int)puVar8 + 6);
      *(short *)((int)puVar8 + 6) = sVar1 + -1;
      if (sVar1 == 1) {
        puVar3 = puVar8;
        if ((undefined4 **)DAT_001f64d4 != &_vm_info_queue) {
          DAT_001f64d4[10] = puVar8;
          puVar3 = _vm_info_queue;
        }
        _vm_info_queue = puVar3;
        puVar8[0xb] = DAT_001f64d4;
        puVar8[10] = &_vm_info_queue;
        DAT_001f64d4 = puVar8;
        *(byte *)(puVar8 + 0xe) = *(byte *)(puVar8 + 0xe) | 1;
        _mfs_files_mapped = _mfs_files_mapped + 1;
        _vm_info_version = _vm_info_version + 1;
      }
      LOCK();
      uVar5 = _vm_info_lock_data;
      _vm_info_lock_data = 0;
      UNLOCK();
      _lock_done(puVar8 + 6);
      if (_mfs_files_max < _mfs_files_mapped) {
        _mfs_cache_trim();
      }
      if ((*(byte *)(puVar8 + 0xe) & 8) != 0) {
        *(byte *)(puVar8 + 0xe) = *(byte *)(puVar8 + 0xe) & 0xf7;
        _vmp_invalidate(puVar8);
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
      iVar9 = iVar9 + 2;
    }
    puVar8 = _vm_info_queue;
    iVar6 = _vm_info_version;
    if (iVar9 == _vm_info_version) {
      puVar8 = puVar2;
      iVar6 = iVar9;
    }
  }
  LOCK();
  uVar5 = _vm_info_lock_data;
  _vm_info_lock_data = 0;
  UNLOCK();
  return uVar5;
}



undefined4 _mfs_fsync(undefined4 *param_1)

{
  short sVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  
  param_1 = (undefined4 *)*param_1;
  if ((param_1 == (undefined4 *)0x0) || ((*(byte *)(param_1 + 0xe) & 0x10) == 0)) {
    uVar6 = 0;
  }
  else {
    do {
      iVar4 = _vm_info_lock_data;
      do {
      } while (iVar4 != 0);
      LOCK();
      iVar4 = _vm_info_lock_data;
      _vm_info_lock_data = 1;
      UNLOCK();
    } while (iVar4 == 1);
    if ((*(byte *)(param_1 + 0xe) & 1) != 0) {
      puVar2 = (undefined4 *)param_1[10];
      puVar3 = (undefined4 *)param_1[0xb];
      puVar5 = puVar3;
      if ((undefined4 **)puVar2 != &_vm_info_queue) {
        puVar2[0xb] = puVar3;
        puVar5 = DAT_001f64d4;
      }
      DAT_001f64d4 = puVar5;
      if ((undefined4 **)puVar3 != &_vm_info_queue) {
        puVar3[10] = puVar2;
        puVar2 = _vm_info_queue;
      }
      _vm_info_queue = puVar2;
      *(byte *)(param_1 + 0xe) = *(byte *)(param_1 + 0xe) & 0xfe;
      _mfs_files_mapped = _mfs_files_mapped + -1;
      _vm_info_version = _vm_info_version + 1;
    }
    *(short *)((int)param_1 + 6) = *(short *)((int)param_1 + 6) + 1;
    LOCK();
    uVar6 = _vm_info_lock_data;
    _vm_info_lock_data = 0;
    UNLOCK();
    _lock_write(param_1 + 6);
    _vmp_push(param_1);
    do {
      iVar4 = _vm_info_lock_data;
      do {
      } while (iVar4 != 0);
      LOCK();
      iVar4 = _vm_info_lock_data;
      _vm_info_lock_data = 1;
      UNLOCK();
    } while (iVar4 == 1);
    sVar1 = *(short *)((int)param_1 + 6);
    *(short *)((int)param_1 + 6) = sVar1 + -1;
    if (sVar1 == 1) {
      puVar2 = param_1;
      if ((undefined4 **)DAT_001f64d4 != &_vm_info_queue) {
        DAT_001f64d4[10] = param_1;
        puVar2 = _vm_info_queue;
      }
      _vm_info_queue = puVar2;
      param_1[0xb] = DAT_001f64d4;
      param_1[10] = &_vm_info_queue;
      DAT_001f64d4 = param_1;
      *(byte *)(param_1 + 0xe) = *(byte *)(param_1 + 0xe) | 1;
      _mfs_files_mapped = _mfs_files_mapped + 1;
      _vm_info_version = _vm_info_version + 1;
    }
    LOCK();
    uVar6 = _vm_info_lock_data;
    _vm_info_lock_data = 0;
    UNLOCK();
    _lock_done(param_1 + 6);
    if (_mfs_files_max < _mfs_files_mapped) {
      _mfs_cache_trim();
    }
    if ((*(byte *)(param_1 + 0xe) & 8) != 0) {
      *(byte *)(param_1 + 0xe) = *(byte *)(param_1 + 0xe) & 0xf7;
      _vmp_invalidate(param_1);
    }
    uVar6 = param_1[0xd];
  }
  return uVar6;
}


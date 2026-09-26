
undefined4 _mfs_fsync_invalidate(int *param_1,uint param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  
  iVar2 = *param_1;
  if ((iVar2 == 0) || ((*(byte *)(iVar2 + 0x38) & 0x10) == 0)) {
    uVar6 = 0;
  }
  else {
    do {
      iVar5 = _vm_info_lock_data;
      do {
      } while (iVar5 != 0);
      LOCK();
      iVar5 = _vm_info_lock_data;
      _vm_info_lock_data = 1;
      UNLOCK();
    } while (iVar5 == 1);
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
      uVar6 = _mfs_files_mapped;
      iVar5 = _mfs_files_mapped;
      _mfs_files_mapped = iVar5 + -1;
      uVar6 = _mfs_files_mapped;
      uVar6 = _mfs_files_mapped;
      uVar6 = _mfs_files_mapped;
      uVar6 = _vm_info_version;
      iVar5 = _vm_info_version;
      _vm_info_version = iVar5 + 1;
      uVar6 = _vm_info_version;
      uVar6 = _vm_info_version;
      uVar6 = _vm_info_version;
    }
    *(short *)(iVar2 + 6) = *(short *)(iVar2 + 6) + 1;
    LOCK();
    uVar6 = _vm_info_lock_data;
    _vm_info_lock_data = 0;
    UNLOCK();
    if ((param_2 & 1) == 0) {
      _vmp_push_all(iVar2);
    }
    if ((param_2 & 2) == 0) {
      *(byte *)(iVar2 + 0x38) = *(byte *)(iVar2 + 0x38) & 0xf7;
      _vmp_invalidate(iVar2);
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
      uVar6 = _mfs_files_mapped;
      iVar5 = _mfs_files_mapped;
      _mfs_files_mapped = iVar5 + 1;
      uVar6 = _mfs_files_mapped;
      uVar6 = _mfs_files_mapped;
      uVar6 = _mfs_files_mapped;
      uVar6 = _vm_info_version;
      iVar5 = _vm_info_version;
      _vm_info_version = iVar5 + 1;
      uVar6 = _vm_info_version;
      uVar6 = _vm_info_version;
      uVar6 = _vm_info_version;
    }
    LOCK();
    uVar6 = _vm_info_lock_data;
    _vm_info_lock_data = 0;
    UNLOCK();
    uVar6 = *(undefined4 *)(iVar2 + 0x34);
  }
  return uVar6;
}


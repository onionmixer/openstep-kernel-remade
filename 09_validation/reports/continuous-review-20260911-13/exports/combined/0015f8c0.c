
undefined4 _mfs_invalidate(int *param_1)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  
  iVar2 = *param_1;
  if ((iVar2 != 0) && ((*(byte *)(iVar2 + 0x38) & 0x10) != 0)) {
    if (*(short *)(iVar2 + 6) < 1) {
      do {
        iVar6 = _vm_info_lock_data;
        do {
        } while (iVar6 != 0);
        LOCK();
        iVar6 = _vm_info_lock_data;
        _vm_info_lock_data = 1;
        UNLOCK();
      } while (iVar6 == 1);
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
        uVar5 = _mfs_files_mapped;
        iVar6 = _mfs_files_mapped;
        _mfs_files_mapped = iVar6 + -1;
        uVar5 = _mfs_files_mapped;
        uVar5 = _mfs_files_mapped;
        uVar5 = _mfs_files_mapped;
        uVar5 = _vm_info_version;
        iVar6 = _vm_info_version;
        _vm_info_version = iVar6 + 1;
        uVar5 = _vm_info_version;
        uVar5 = _vm_info_version;
        uVar5 = _vm_info_version;
      }
      *(short *)(iVar2 + 6) = *(short *)(iVar2 + 6) + 1;
      LOCK();
      uVar5 = _vm_info_lock_data;
      _vm_info_lock_data = 0;
      UNLOCK();
      _lock_write(iVar2 + 0x18);
      _vmp_invalidate(iVar2);
      do {
        iVar6 = _vm_info_lock_data;
        do {
        } while (iVar6 != 0);
        LOCK();
        iVar6 = _vm_info_lock_data;
        _vm_info_lock_data = 1;
        UNLOCK();
      } while (iVar6 == 1);
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
        uVar5 = _mfs_files_mapped;
        iVar6 = _mfs_files_mapped;
        _mfs_files_mapped = iVar6 + 1;
        uVar5 = _mfs_files_mapped;
        uVar5 = _mfs_files_mapped;
        uVar5 = _mfs_files_mapped;
        uVar5 = _vm_info_version;
        iVar6 = _vm_info_version;
        _vm_info_version = iVar6 + 1;
        uVar5 = _vm_info_version;
        uVar5 = _vm_info_version;
        uVar5 = _vm_info_version;
      }
      LOCK();
      uVar5 = _vm_info_lock_data;
      _vm_info_lock_data = 0;
      UNLOCK();
      _lock_done(iVar2 + 0x18);
      iVar6 = _mfs_files_max;
      iVar7 = _mfs_files_mapped;
      if (iVar6 < iVar7) {
        _mfs_cache_trim();
      }
      if ((*(byte *)(iVar2 + 0x38) & 8) != 0) {
        *(byte *)(iVar2 + 0x38) = *(byte *)(iVar2 + 0x38) & 0xf7;
        _vmp_invalidate(iVar2);
      }
    }
    else {
      *(byte *)(iVar2 + 0x38) = *(byte *)(iVar2 + 0x38) | 8;
    }
  }
  return *(undefined4 *)(iVar2 + 0x34);
}



void _mfs_memfree(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  
  do {
  } while (_vm_info_lock_data != 0);
  LOCK();
  UNLOCK();
  if ((*(byte *)(param_1 + 0x38) & 1) != 0) {
    puVar1 = *(undefined4 **)(param_1 + 0x28);
    puVar2 = *(undefined4 **)(param_1 + 0x2c);
    puVar3 = puVar2;
    if ((undefined4 **)puVar1 != &_vm_info_queue) {
      puVar1[0xb] = puVar2;
      puVar3 = DAT_001f64d4;
    }
    DAT_001f64d4 = puVar3;
    if ((undefined4 **)puVar2 != &_vm_info_queue) {
      puVar2[10] = puVar1;
      puVar1 = _vm_info_queue;
    }
    _vm_info_queue = puVar1;
    *(byte *)(param_1 + 0x38) = *(byte *)(param_1 + 0x38) & 0xfe;
    _mfs_files_mapped = _mfs_files_mapped + -1;
    _vm_info_version = _vm_info_version + 1;
  }
  LOCK();
  _vm_info_lock_data = 0;
  UNLOCK();
  _lock_write(param_1 + 0x18);
  if (*(short *)(param_1 + 4) == 0) {
    *(byte *)(param_1 + 0x38) = *(byte *)(param_1 + 0x38) & 0xef;
  }
  _mfs_map_remove(param_1,*(int *)(param_1 + 8),*(int *)(param_1 + 8) + *(int *)(param_1 + 0xc),
                  param_2);
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  iVar4 = 0;
  if (*(short *)(param_1 + 4) == 0) {
    iVar4 = *(int *)(param_1 + 0x24);
    *(undefined4 *)(param_1 + 0x24) = 0;
    if (*(int *)(param_1 + 0x30) != 0) {
      _crfree(*(int *)(param_1 + 0x30));
      *(undefined4 *)(param_1 + 0x30) = 0;
    }
  }
  _lock_done(param_1 + 0x18);
  if (iVar4 != 0) {
    _vm_object_deallocate(iVar4);
  }
  return;
}


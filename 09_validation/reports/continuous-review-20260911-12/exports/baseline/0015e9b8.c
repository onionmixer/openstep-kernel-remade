
void _vmp_get(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
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
  *(short *)(param_1 + 6) = *(short *)(param_1 + 6) + 1;
  LOCK();
  _vm_info_lock_data = 0;
  UNLOCK();
  _lock_write(param_1 + 0x18);
  return;
}


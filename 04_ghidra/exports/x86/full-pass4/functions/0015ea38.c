/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015ea38 */

void _vmp_put(undefined4 *param_1)

{
  short sVar1;
  
  do {
  } while (_vm_info_lock_data != 0);
  LOCK();
  UNLOCK();
  sVar1 = *(short *)((int)param_1 + 6);
  *(short *)((int)param_1 + 6) = sVar1 + -1;
  if (sVar1 == 1) {
    if ((undefined4 **)DAT_001f64d4 == &_vm_info_queue) {
      _vm_info_queue = param_1;
    }
    else {
      DAT_001f64d4[10] = param_1;
    }
    param_1[0xb] = DAT_001f64d4;
    param_1[10] = &_vm_info_queue;
    DAT_001f64d4 = param_1;
    *(byte *)(param_1 + 0xe) = *(byte *)(param_1 + 0xe) | 1;
    _mfs_files_mapped = _mfs_files_mapped + 1;
    _vm_info_version = _vm_info_version + 1;
  }
  LOCK();
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
  return;
}


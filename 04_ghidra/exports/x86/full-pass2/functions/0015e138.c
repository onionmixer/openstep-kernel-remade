/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015e138 */

void _vm_info_enqueue(int param_1)

{
  if (DAT_001f64d4 == &_vm_info_queue) {
    _vm_info_queue = param_1;
  }
  else {
    DAT_001f64d4[10] = param_1;
  }
  *(undefined4 **)(param_1 + 0x2c) = DAT_001f64d4;
  *(int **)(param_1 + 0x28) = &_vm_info_queue;
  DAT_001f64d4 = (undefined4 *)param_1;
  *(byte *)(param_1 + 0x38) = *(byte *)(param_1 + 0x38) | 1;
  _mfs_files_mapped = _mfs_files_mapped + 1;
  _vm_info_version = _vm_info_version + 1;
  return;
}


/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015e17c */

void _vm_info_dequeue(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
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
  return;
}


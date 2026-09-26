/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00180078 */

void FUN_00180078(int param_1)

{
  _KernLockAcquire(*(undefined4 *)(param_1 + 0x30));
  if ((*(byte *)(param_1 + 0x54) & 3) == 0) {
    _KernLockRelease(*(undefined4 *)(param_1 + 0x30));
    _ipc_object_release(*(undefined4 *)(param_1 + 0x2c));
    _ipc_object_release(*(undefined4 *)(param_1 + 0x2c));
    _objc_msgSend(*(undefined4 *)(param_1 + 0x30),PTR_s_free_001f921c);
    _kfree(param_1,0x58);
  }
  else {
    *(byte *)(param_1 + 0x54) = *(byte *)(param_1 + 0x54) | 4;
    _KernLockRelease(*(undefined4 *)(param_1 + 0x30));
  }
  return;
}


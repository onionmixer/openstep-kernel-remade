/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017fb8c */

void _KernBusInterruptResume(int param_1)

{
  if (param_1 != 0) {
    _KernLockAcquire(*(undefined4 *)(param_1 + 0x24));
    if (0 < *(int *)(param_1 + 0x20)) {
      *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + -1;
    }
    _KernLockRelease(*(undefined4 *)(param_1 + 0x24));
  }
  return;
}


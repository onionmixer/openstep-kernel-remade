/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010a06c */

void _stop(int param_1)

{
  _task_suspend_nowait(*(undefined4 *)(param_1 + 0x68));
  *(undefined1 *)(param_1 + 0x13) = 6;
  *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) & 0xffffffdf;
  _wakeup(*(undefined4 *)(param_1 + 0x44));
  return;
}


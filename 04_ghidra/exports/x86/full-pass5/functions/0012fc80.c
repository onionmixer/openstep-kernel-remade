/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012fc80 */

void _rlock(uint param_1)

{
  while (((*(ushort *)(param_1 + 0x60) & 1) != 0 && (*(int *)(param_1 + 0x68) != _active_threads)))
  {
    *(ushort *)(param_1 + 0x60) = *(ushort *)(param_1 + 0x60) | 2;
    _sleep(param_1);
  }
  *(int *)(param_1 + 0x68) = _active_threads;
  *(short *)(param_1 + 0x6c) = *(short *)(param_1 + 0x6c) + 1;
  *(byte *)(param_1 + 0x60) = *(byte *)(param_1 + 0x60) | 1;
  return;
}


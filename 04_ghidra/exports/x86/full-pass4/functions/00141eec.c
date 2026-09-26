/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00141eec */

void _ilock(uint param_1)

{
  while ((*(ushort *)(param_1 + 0x44) & 1) != 0) {
    *(ushort *)(param_1 + 0x44) = *(ushort *)(param_1 + 0x44) | 0x10;
    _sleep(param_1);
  }
  *(byte *)(param_1 + 0x44) = *(byte *)(param_1 + 0x44) | 1;
  return;
}


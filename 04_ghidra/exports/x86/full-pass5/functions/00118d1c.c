/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00118d1c */

void _unp_mark(int param_1)

{
  if ((*(byte *)(param_1 + 8) & 0x10) == 0) {
    _unp_defer = _unp_defer + 1;
    *(byte *)(param_1 + 8) = *(byte *)(param_1 + 8) | 0x30;
  }
  return;
}


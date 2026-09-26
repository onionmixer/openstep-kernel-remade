/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00116120 */

void _soisconnecting(int param_1)

{
  *(ushort *)(param_1 + 6) = *(ushort *)(param_1 + 6) & 0xfff5 | 4;
  _wakeup(param_1 + 0x54);
  return;
}


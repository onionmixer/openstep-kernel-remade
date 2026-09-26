/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00116418 */

void _sbwait(uint param_1)

{
  *(byte *)(param_1 + 0x14) = *(byte *)(param_1 + 0x14) | 4;
  _sleep(param_1);
  return;
}


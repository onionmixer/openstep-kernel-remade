/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00135c08 */

void _ckuwakeup(byte *param_1)

{
  *param_1 = *param_1 | 1;
  _sbwakeup(*(int *)(param_1 + 0x14) + 0x24);
  return;
}


/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001163e0 */

void _socantrcvmore(int param_1)

{
  *(byte *)(param_1 + 6) = *(byte *)(param_1 + 6) | 0x20;
  _sowakeup(param_1,param_1 + 0x24);
  return;
}


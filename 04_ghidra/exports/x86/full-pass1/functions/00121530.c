/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00121530 */

void _raw_connaddr(int param_1,int param_2)

{
  _bcopy((void *)(param_2 + *(int *)(param_2 + 4)),(void *)(param_1 + 0xc),0x10);
  *(byte *)(param_1 + 0x4c) = *(byte *)(param_1 + 0x4c) | 2;
  return;
}


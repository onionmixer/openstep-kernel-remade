/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a1abc */

bool _PCtimersPending(int param_1)

{
  return (*(byte *)(param_1 + 0x78) & 6) != 0;
}


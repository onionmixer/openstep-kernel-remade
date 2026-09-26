/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011b244 */

void FUN_0011b244(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0x40) != 0) {
    FUN_0011b26c(param_1);
  }
  *(short *)(param_2 + 6) = *(short *)(param_2 + 6) + 1;
  *(int *)(param_1 + 0x40) = param_2;
  return;
}


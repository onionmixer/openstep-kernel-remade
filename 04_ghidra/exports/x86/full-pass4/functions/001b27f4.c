/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b27f4 */

void FUN_001b27f4(int param_1,undefined4 param_2,int param_3)

{
  if (param_3 < 0) {
    param_3 = 0;
  }
  else if (0x40 < param_3) {
    param_3 = 0x40;
  }
  *(int *)(param_1 + 0x1c4) = param_3;
  return;
}


/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001812f8 */

int FUN_001812f8(int param_1,undefined4 param_2,int param_3)

{
  if ((*(int *)(param_1 + 8) == 0) || (param_3 == 0)) {
    *(int *)(param_1 + 8) = param_3;
  }
  if (*(int *)(param_1 + 8) != param_3) {
    param_3 = 0;
  }
  return param_3;
}


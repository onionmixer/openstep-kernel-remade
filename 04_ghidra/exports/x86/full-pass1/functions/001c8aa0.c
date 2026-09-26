/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c8aa0 */

int FUN_001c8aa0(int param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5)

{
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0x10) = param_5;
  *(int *)(param_1 + 8) = param_3;
  if (param_3 == 0) {
    *(char **)(param_1 + 8) = "@";
  }
  *(int *)(param_1 + 0xc) = param_4;
  if (param_4 == 0) {
    *(char **)(param_1 + 0xc) = "@";
  }
  *(undefined4 *)(param_1 + 0x14) = 0;
  return param_1;
}


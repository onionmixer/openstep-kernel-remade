/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012d3b4 */

void FUN_0012d3b4(undefined4 *param_1,int *param_2)

{
  for (; param_1 != (undefined4 *)0x0; param_1 = (undefined4 *)*param_1) {
    *param_2 = param_1[1] + (int)param_1;
    param_2[1] = (int)*(short *)(param_1 + 2);
    param_2 = param_2 + 2;
  }
  return;
}


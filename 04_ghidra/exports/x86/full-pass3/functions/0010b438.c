/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010b438 */

void _timevalfix(int *param_1)

{
  if (param_1[1] < 0) {
    *param_1 = *param_1 + -1;
    param_1[1] = param_1[1] + 1000000;
  }
  if (999999 < param_1[1]) {
    *param_1 = *param_1 + 1;
    param_1[1] = param_1[1] + -1000000;
  }
  return;
}


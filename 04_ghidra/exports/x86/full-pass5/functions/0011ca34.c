/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011ca34 */

void _pn_set(undefined4 *param_1,undefined4 param_2)

{
  param_1[1] = *param_1;
  _copystr(param_2,*param_1,0x400,param_1 + 2);
  param_1[2] = param_1[2] + -1;
  return;
}


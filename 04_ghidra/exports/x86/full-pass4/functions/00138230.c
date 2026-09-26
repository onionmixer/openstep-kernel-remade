/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00138230 */

void _xdrmbuf_init(undefined4 *param_1,int param_2,undefined4 param_3)

{
  *param_1 = param_3;
  param_1[1] = &_xdrmbuf_ops;
  param_1[4] = param_2;
  param_1[3] = *(int *)(param_2 + 4) + param_2;
  param_1[2] = 0;
  param_1[5] = (int)*(short *)(param_2 + 8);
  return;
}


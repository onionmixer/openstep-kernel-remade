/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00160098 */

void _vm_set_close_flush(int *param_1,int param_2)

{
  *(byte *)(*param_1 + 0x38) = *(byte *)(*param_1 + 0x38) & 0xfb | (param_2 != 0) << 2;
  return;
}


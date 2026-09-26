/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015b54c */

void _lock_init(undefined4 *param_1,byte param_2)

{
  _bzero(param_1,0xc);
  param_1[2] = 0;
  *(byte *)((int)param_1 + 6) = *(byte *)((int)param_1 + 6) & 0xfc;
  *(undefined2 *)(param_1 + 1) = 0;
  *(byte *)((int)param_1 + 6) = *(byte *)((int)param_1 + 6) & 0xf7 | (param_2 & 1) << 3;
  *param_1 = 0xffffffff;
  *(ushort *)((int)param_1 + 6) = *(ushort *)((int)param_1 + 6) & 0xf;
  return;
}


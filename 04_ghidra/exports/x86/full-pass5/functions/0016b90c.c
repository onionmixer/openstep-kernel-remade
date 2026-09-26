/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016b90c */

void _zchange(undefined4 *param_1,byte param_2,byte param_3,byte param_4,int param_5)

{
  *(byte *)(param_1 + 0xb) =
       *(byte *)(param_1 + 0xb) & 0xf8 | param_2 & 1 | (param_3 & 1) * '\x02' | (param_4 & 1) << 2;
  if (param_5 == 0) {
    param_1[0xf] = &__zone_default_space;
  }
  if ((*(byte *)(param_1 + 0xb) & 1) == 0) {
    *param_1 = 0;
  }
  else {
    _lock_init(param_1 + 0xc,1);
  }
  return;
}


/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016058c */

void _ns_time_to_timeval(uint param_1,uint param_2,undefined4 *param_3)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)param_2 % 1000000000 << 0x20 | (ulonglong)param_1;
  param_3[1] = (int)(uVar1 % 1000000000);
  *param_3 = (int)(uVar1 / 1000000000);
  param_3[1] = (int)param_3[1] / 1000;
  return;
}


/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00160674 */

void _ns_time_to_tsval(uint param_1,uint param_2,undefined4 *param_3)

{
  *param_3 = (int)(((ulonglong)param_2 % 1000 << 0x20 | (ulonglong)param_1) / 1000);
  param_3[1] = param_2 / 1000;
  return;
}


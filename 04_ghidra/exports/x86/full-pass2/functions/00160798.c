/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00160798 */

void _get_calendar_time_value(undefined4 *param_1)

{
  ulonglong uVar1;
  
  uVar1 = _clock_value(0);
  uVar1 = (uVar1 >> 0x20) % 1000000000 << 0x20 | uVar1 & 0xffffffff;
  param_1[1] = (int)(uVar1 % 1000000000);
  *param_1 = (int)(uVar1 / 1000000000);
  param_1[1] = (int)param_1[1] / 1000;
  return;
}


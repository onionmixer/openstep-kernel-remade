/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001607f0 */

void _set_calendar_time_value(int *param_1)

{
  _set_clock(0,(longlong)*param_1 * 1000000000 + (longlong)param_1[1] * 1000);
  return;
}


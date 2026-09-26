/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1607f0. */
int __cdecl set_calendar_time_value(int *a1)
{
  return set_clock(0, 1000 * a1[1] + 1000000000 * *a1, (unsigned __int64)(1000LL * a1[1] + 1000000000LL * *a1) >> 32); /*0x16083b*/
}

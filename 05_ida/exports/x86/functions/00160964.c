/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x160964. */
int __cdecl us_timeout(int a1, int a2, int *a3)
{
  __int64 v3; // kr00_8
  __int64 v5; // [esp+18h] [ebp-8h]

  v3 = 25 * (a3[1] + 1000000LL * *a3); /*0x1609c0*/
  v5 = clock_value(1); /*0x1609f0*/
  return calloutDispatchDelayed(a1, a2, v5 + 40 * v3, (unsigned __int64)(v5 + 40 * v3) >> 32); /*0x160a19*/
}

/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x160a20. */
int __cdecl us_abstimeout(int a1, int a2, int *a3)
{
  __int64 v3; // kr00_8

  v3 = 25 * (a3[1] + 1000000LL * *a3); /*0x160a78*/
  return calloutDispatchDelayed(a1, a2, 40 * v3, (unsigned __int64)(40 * v3) >> 32); /*0x160ab9*/
}

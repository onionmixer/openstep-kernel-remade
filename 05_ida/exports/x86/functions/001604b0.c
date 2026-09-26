/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1604b0. */
int __cdecl ns_timeout(int a1, int a2, __int64 a3)
{
  __int64 v3; // rax

  v3 = clock_value(1); /*0x1604c1*/
  return calloutDispatchDelayed(a1, a2, v3 + a3, (unsigned __int64)(v3 + a3) >> 32); /*0x1604d9*/
}

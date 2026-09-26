/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a1aa4. */
int __cdecl PCdeliverTimers(int a1)
{
  *(_DWORD *)(a1 + 116) |= *(_DWORD *)(a1 + 120) & 6; /*0x1a1ab0*/
  *(_DWORD *)(a1 + 120) &= 0xFFFFFFF9; /*0x1a1ab3*/
  return a1; /*0x1a1ab9*/
}

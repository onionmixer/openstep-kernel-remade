/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10f22c. */
int __cdecl nullmodem(int a1, int a2)
{
  int v2; // eax

  v2 = ttynty(a1); /*0x10f238*/
  if ( a2 ) /*0x10f23f*/
  {
    *(_BYTE *)(a1 + 64) |= 0x10u; /*0x10f250*/
  }
  else
  {
    *(_DWORD *)(a1 + 64) &= ~0x10u; /*0x10f241*/
    if ( *(__int16 *)(v2 + 16) >= 0 ) /*0x10f24a*/
      return 0; /*0x10f24e*/
  }
  return a2; /*0x10f259*/
}

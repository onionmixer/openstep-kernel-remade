/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15b098. */
int __cdecl canSwap(int a1)
{
  int v1; // edx
  int v2; // eax

  v1 = ~page_mask & a1; /*0x15b0a6*/
  v2 = 0; /*0x15b0a8*/
  if ( dword_1E5BA4 <= 0 ) /*0x15b0b2*/
    return 1; /*0x15b0cf*/
  while ( *(_DWORD *)(v1 + 8) != 2 ) /*0x15b0c0*/
  {
    v1 += dword_1E5BA0; /*0x15b0c8*/
    if ( ++v2 >= dword_1E5BA4 ) /*0x15b0cd*/
      return 1; /*0x15b0cd*/
  }
  return 0; /*0x15b0d4*/
}

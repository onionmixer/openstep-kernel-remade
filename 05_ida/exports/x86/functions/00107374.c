/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x107374. */
int __cdecl pfind(int a1)
{
  int v1; // edx

  v1 = pidhash[a1 & 0x3F]; /*0x10737f*/
  if ( !v1 ) /*0x107388*/
    return 0; /*0x1073a3*/
  while ( *(__int16 *)(v1 + 48) != a1 ) /*0x107392*/
  {
    v1 = *(_DWORD *)(v1 + 64); /*0x10739c*/
    if ( !v1 ) /*0x1073a1*/
      return 0; /*0x1073a1*/
  }
  return v1; /*0x107398*/
}

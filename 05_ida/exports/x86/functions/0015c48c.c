/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15c48c. */
_DWORD *__cdecl firstsegfromheader(int a1)
{
  _DWORD *v1; // edx
  int v2; // ecx
  unsigned int v3; // eax

  v1 = (_DWORD *)(a1 + 28); /*0x15c492*/
  v2 = 0; /*0x15c495*/
  v3 = *(_DWORD *)(a1 + 16); /*0x15c497*/
  if ( !v3 ) /*0x15c49c*/
    return nullptr; /*0x15c4b4*/
  while ( *v1 != 1 ) /*0x15c4a3*/
  {
    v1 = (_DWORD *)((char *)v1 + v1[1]); /*0x15c4ac*/
    if ( ++v2 >= v3 ) /*0x15c4b2*/
      return nullptr; /*0x15c4b2*/
  }
  return v1; /*0x15c4a9*/
}

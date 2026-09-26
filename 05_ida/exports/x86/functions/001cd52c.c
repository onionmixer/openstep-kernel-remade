/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cd52c. */
int __cdecl class_lookupMethodInMethodList(int a1, int a2)
{
  _DWORD *v2; // edx
  int v3; // eax

  v2 = (_DWORD *)(a1 + 8); /*0x1cd535*/
  v3 = *(_DWORD *)(a1 + 4) - 1; /*0x1cd53b*/
  if ( v3 < 0 ) /*0x1cd53c*/
    return 0; /*0x1cd552*/
  while ( *v2 != a2 ) /*0x1cd542*/
  {
    v2 += 3; /*0x1cd54c*/
    if ( --v3 < 0 ) /*0x1cd550*/
      return 0; /*0x1cd550*/
  }
  return v2[2]; /*0x1cd549*/
}

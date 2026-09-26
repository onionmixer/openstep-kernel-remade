/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1d02b0. */
void __cdecl _sel_unloadSelectors(unsigned int a1, unsigned int a2)
{
  unsigned int i; // ecx
  char *v3; // eax
  _DWORD *v4; // edx

  for ( i = 0; dword_1E5628 > i; ++i ) /*0x1d02c9*/
  {
    v3 = (char *)off_1E5638 + 4 * i; /*0x1d02d3*/
    while ( *(_DWORD *)v3 ) /*0x1d02d9*/
    {
      v4 = *(_DWORD **)v3; /*0x1d02db*/
      if ( *(_DWORD *)(*(_DWORD *)v3 + 4) < a1 || v4[1] >= a2 ) /*0x1d02e5*/
        v3 = *(char **)v3; /*0x1d02f0*/
      else
        *(_DWORD *)v3 = *v4; /*0x1d02e9*/
    }
  }
}

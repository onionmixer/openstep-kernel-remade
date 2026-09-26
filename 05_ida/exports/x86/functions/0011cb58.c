/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11cb58. */
void __cdecl pn_skipslash(int a1)
{
  _BYTE *v1; // eax
  int v2; // eax

  if ( *(_DWORD *)(a1 + 8) ) /*0x11cb5e*/
  {
    do /*0x11cb7c*/
    {
      v1 = *(_BYTE **)(a1 + 4); /*0x11cb64*/
      if ( *v1 != 47 ) /*0x11cb6a*/
        break; /*0x11cb6a*/
      *(_DWORD *)(a1 + 4) = v1 + 1; /*0x11cb6d*/
      v2 = *(_DWORD *)(a1 + 8); /*0x11cb70*/
      *(_DWORD *)(a1 + 8) = v2 - 1; /*0x11cb76*/
    }
    while ( v2 != 1 ); /*0x11cb7c*/
  }
}

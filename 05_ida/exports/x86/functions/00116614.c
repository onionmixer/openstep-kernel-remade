/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x116614. */
void __cdecl sbappend(int a1, int a2)
{
  _DWORD *v2; // eax

  if ( a2 ) /*0x11661f*/
  {
    v2 = *(_DWORD **)(a1 + 12); /*0x116621*/
    if ( v2 ) /*0x116626*/
    {
      for ( ; v2[31]; v2 = (_DWORD *)v2[31] ) /*0x116628*/
        ; /*0x116630*/
      while ( *v2 ) /*0x116641*/
        v2 = (_DWORD *)*v2; /*0x11663c*/
    }
    sbcompress(a1, a2, v2); /*0x116646*/
  }
}

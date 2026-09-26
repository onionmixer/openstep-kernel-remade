/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x113a68. */
void __cdecl pfctlinput(int a1, sockaddr *a2)
{
  _DWORD *v2; // esi
  unsigned int i; // ebx
  void (__cdecl *v4)(int, sockaddr *, _DWORD); // eax

  v2 = (_DWORD *)domains; /*0x113a71*/
  if ( domains ) /*0x113a79*/
  {
    do /*0x113aa4*/
    {
      for ( i = v2[5]; v2[6] > i; i += 48 ) /*0x113a82*/
      {
        v4 = *(void (__cdecl **)(int, sockaddr *, _DWORD))(i + 20); /*0x113a84*/
        if ( v4 ) /*0x113a89*/
          v4(a1, a2, 0); /*0x113a92*/
      }
      v2 = (_DWORD *)v2[7]; /*0x113a9f*/
    }
    while ( v2 ); /*0x113aa4*/
  }
}

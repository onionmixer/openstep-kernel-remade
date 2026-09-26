/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x113914. */
int domaininit()
{
  _DWORD *v0; // esi
  void (*v1)(void); // eax
  unsigned int i; // ebx
  void (*v3)(void); // eax

  dword_1DB2D4 = domains; /*0x11391f*/
  dword_1DBCD0 = (int)&unixdomain; /*0x11392f*/
  domains = (int)&inetdomain; /*0x113939*/
  v0 = &inetdomain; /*0x113943*/
  if ( &inetdomain ) /*0x11394a*/
  {
    do /*0x113976*/
    {
      v1 = (void (*)(void))v0[2]; /*0x11394c*/
      if ( v1 ) /*0x113951*/
        v1(); /*0x113953*/
      for ( i = v0[5]; v0[6] > i; i += 48 ) /*0x11395b*/
      {
        v3 = *(void (**)(void))(i + 32); /*0x113960*/
        if ( v3 ) /*0x113965*/
          v3(); /*0x113967*/
      }
      v0 = (_DWORD *)v0[7]; /*0x113971*/
    }
    while ( v0 ); /*0x113976*/
  }
  null_init(); /*0x113978*/
  pffasttimo(); /*0x11397d*/
  return pfslowtimo(); /*0x11398a*/
}

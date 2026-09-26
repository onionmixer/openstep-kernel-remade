/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x113ab0. */
void pfslowtimo()
{
  _DWORD *v0; // esi
  unsigned int i; // ebx
  void (*v2)(void); // eax

  v0 = (_DWORD *)domains; /*0x113ab5*/
  if ( domains ) /*0x113abd*/
  {
    do /*0x113ade*/
    {
      for ( i = v0[5]; v0[6] > i; i += 48 ) /*0x113ac6*/
      {
        v2 = *(void (**)(void))(i + 40); /*0x113ac8*/
        if ( v2 ) /*0x113acd*/
          v2(); /*0x113acf*/
      }
      v0 = (_DWORD *)v0[7]; /*0x113ad9*/
    }
    while ( v0 ); /*0x113ade*/
  }
  timeout((int)pfslowtimo); /*0x113af8*/
}

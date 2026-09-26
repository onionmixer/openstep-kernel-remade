/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x113b08. */
void pffasttimo()
{
  _DWORD *v0; // esi
  unsigned int i; // ebx
  void (*v2)(void); // eax

  v0 = (_DWORD *)domains; /*0x113b0d*/
  if ( domains ) /*0x113b15*/
  {
    do /*0x113b36*/
    {
      for ( i = v0[5]; v0[6] > i; i += 48 ) /*0x113b1e*/
      {
        v2 = *(void (**)(void))(i + 36); /*0x113b20*/
        if ( v2 ) /*0x113b25*/
          v2(); /*0x113b27*/
      }
      v0 = (_DWORD *)v0[7]; /*0x113b31*/
    }
    while ( v0 ); /*0x113b36*/
  }
  timeout((int)pffasttimo); /*0x113b4d*/
}

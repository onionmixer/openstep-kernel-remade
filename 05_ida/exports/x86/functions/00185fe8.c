/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x185fe8. */
int miniMonGetchar()
{
  int v0; // eax
  int v1; // ebx

  do /*0x185ff6*/
  {
    v0 = kmtrygetc(); /*0x185fec*/
    v1 = v0; /*0x185ff1*/
  }
  while ( v0 == -1 ); /*0x185ff6*/
  if ( v0 != 21 ) /*0x185ffb*/
  {
    if ( v0 > 21 ) /*0x185ffd*/
    {
      if ( v0 == 127 ) /*0x18600b*/
        v1 = 8; /*0x18600d*/
    }
    else if ( v0 == 13 ) /*0x186002*/
    {
      kmputc(0, 13); /*0x186018*/
      v1 = 10; /*0x18601d*/
    }
  }
  kmputc(0, v1); /*0x186028*/
  return v1; /*0x18602f*/
}

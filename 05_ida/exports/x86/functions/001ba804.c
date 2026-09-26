/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ba804. */
id __cdecl -[OutputStream clearForMix:size:format:](OutputStream *self, SEL a2, char *a3, unsigned int a4, int a5)
{
  char *v5; // edx
  unsigned int v6; // eax
  unsigned int v7; // eax

  v5 = a3; /*0x1ba807*/
  if ( a5 == 3 ) /*0x1ba813*/
  {
    v6 = a4 - 1; /*0x1ba815*/
    if ( a4 ) /*0x1ba819*/
    {
      do /*0x1ba824*/
      {
        *v5++ = 0x80; /*0x1ba81c*/
        --v6; /*0x1ba820*/
      }
      while ( v6 != -1 ); /*0x1ba824*/
    }
  }
  else if ( a5 == 1 ) /*0x1ba82b*/
  {
    v7 = a4 - 1; /*0x1ba82d*/
    if ( a4 ) /*0x1ba831*/
    {
      do /*0x1ba83c*/
      {
        *v5++ = 127; /*0x1ba834*/
        --v7; /*0x1ba838*/
      }
      while ( v7 != -1 ); /*0x1ba83c*/
    }
  }
  else
  {
    bzero(a3, a4); /*0x1ba842*/
  }
  return self; /*0x1ba84c*/
}

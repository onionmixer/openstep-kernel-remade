/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x158fc8. */
int __cdecl mig_strncpy(char *dest, const char *src, int len)
{
  int v5; // edx
  int result; // eax

  if ( len > 0 ) /*0x158fd8*/
  {
    v5 = 1; /*0x158fda*/
    if ( len <= 1 ) /*0x158fe1*/
    {
LABEL_5:
      *dest = 0; /*0x158ff3*/
    }
    else
    {
      while ( 1 ) /*0x158fe4*/
      {
        LOBYTE(result) = *src; /*0x158fe4*/
        *dest++ = *src++; /*0x158fe6*/
        if ( !(_BYTE)result ) /*0x158fec*/
          break; /*0x158fec*/
        if ( ++v5 >= len ) /*0x158ff1*/
          goto LABEL_5; /*0x158ff1*/
      }
    }
  }
  return result; /*0x158ff9*/
}

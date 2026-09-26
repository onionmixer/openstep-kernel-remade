/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1946e0. */
int eisa_present()
{
  if ( !dword_1E7744 ) /*0x1946ea*/
  {
    if ( !strncmp((const char *)0xFFFD9, aEisa_5, 4u) ) /*0x1946f8*/
      dword_1E2C50 = 1; /*0x194701*/
    dword_1E7744 = 1; /*0x19470b*/
  }
  return dword_1E2C50; /*0x19471c*/
}

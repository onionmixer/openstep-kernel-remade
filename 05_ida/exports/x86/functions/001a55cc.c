/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a55cc. */
int __cdecl IOSizeToAlignment(int a1)
{
  int i; // eax

  for ( i = 1; i <= 31; ++i ) /*0x1a55d2*/
  {
    if ( a1 < 0 ) /*0x1a55da*/
      return 32 - i; /*0x1a55e8*/
    a1 *= 2; /*0x1a55ec*/
  }
  return 0; /*0x1a55e7*/
}

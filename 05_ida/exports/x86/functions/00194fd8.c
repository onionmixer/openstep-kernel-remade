/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x194fd8. */
int __cdecl yeartoday(char a1)
{
  int result; // eax

  result = 366; /*0x194fdb*/
  if ( (a1 & 3) != 0 ) /*0x194fe4*/
    return 365; /*0x194fe6*/
  return result; /*0x194fed*/
}

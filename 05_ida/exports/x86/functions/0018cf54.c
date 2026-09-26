/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18cf54. */
int __cdecl sub_18CF54(char *a1)
{
  int result; // eax

  result = printf(a1); /*0x18cf5c*/
  if ( prettyShutdown ) /*0x18cf6c*/
    return kmGraphicPanelString(a1); /*0x18cf6f*/
  return result; /*0x18cf74*/
}

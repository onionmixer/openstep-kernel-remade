/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10c974. */
char __cdecl sub_10C974(char *a1, int a2, int a3)
{
  char result; // al

  while ( 1 ) /*0x10c996*/
  {
    result = *a1++; /*0x10c996*/
    if ( !result ) /*0x10c99b*/
      break; /*0x10c99b*/
    sub_10CBAC(result, a2, a3); /*0x10c98e*/
  }
  return result; /*0x10c9a0*/
}

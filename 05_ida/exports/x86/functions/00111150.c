/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x111150. */
char __cdecl ttyoutstr(char *a1, int a2)
{
  char result; // al

  while ( 1 ) /*0x11116d*/
  {
    result = *a1++; /*0x11116d*/
    if ( !result ) /*0x111172*/
      break; /*0x111172*/
    ttyoutput(result, a2); /*0x111165*/
  }
  return result; /*0x111177*/
}

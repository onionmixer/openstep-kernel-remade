/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10ef4c. */
int __cdecl ttylclose(FILE *a1)
{
  int result; // eax

  ttywait((int)a1); /*0x10ef54*/
  result = ttyflush(a1, 1); /*0x10ef5c*/
  HIBYTE(a1->_lb._base) = 0; /*0x10ef61*/
  return result; /*0x10ef65*/
}

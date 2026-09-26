/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10835c. */
_WORD *crget()
{
  _WORD *v0; // ebx

  v0 = (_WORD *)kalloc(0x2Au); /*0x108367*/
  bzero(v0, 0x2Au); /*0x10836c*/
  ++*v0; /*0x108371*/
  ++cractive; /*0x108374*/
  return v0; /*0x10837c*/
}

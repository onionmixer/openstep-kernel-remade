/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x108434. */
_WORD *__cdecl crdup(const void *a1)
{
  _WORD *v1; // ebx

  v1 = (_WORD *)kalloc(0x2Au); /*0x108444*/
  bzero(v1, 0x2Au); /*0x108449*/
  ++*v1; /*0x10844e*/
  ++cractive; /*0x108451*/
  qmemcpy(v1, a1, 0x2Au); /*0x10845f*/
  *v1 = 1; /*0x108463*/
  return v1; /*0x10846d*/
}

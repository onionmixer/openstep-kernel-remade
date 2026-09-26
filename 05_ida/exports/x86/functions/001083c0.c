/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1083c0. */
_WORD *__cdecl crcopy(_WORD *a1)
{
  _WORD *v1; // ebx
  int v2; // esi
  __int16 v3; // ax

  v1 = (_WORD *)kalloc(0x2Au); /*0x1083cd*/
  bzero(v1, 0x2Au); /*0x1083d2*/
  ++*v1; /*0x1083d7*/
  ++cractive; /*0x1083da*/
  qmemcpy(v1, a1, 0x2Au); /*0x1083ee*/
  v2 = splhigh(); /*0x1083f7*/
  v3 = (*a1)--; /*0x1083fc*/
  if ( v3 == 1 ) /*0x10840a*/
  {
    kfree((int)a1, 0x2Au); /*0x108412*/
    --cractive; /*0x108417*/
  }
  splx(v2); /*0x10841e*/
  *v1 = 1; /*0x108423*/
  return v1; /*0x10842d*/
}

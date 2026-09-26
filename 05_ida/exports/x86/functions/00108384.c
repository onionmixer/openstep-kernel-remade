/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x108384. */
int __cdecl crfree(_WORD *a1)
{
  int v1; // esi
  __int16 v2; // ax

  v1 = splhigh(); /*0x108391*/
  v2 = (*a1)--; /*0x108393*/
  if ( v2 == 1 ) /*0x1083a1*/
  {
    kfree((int)a1, 0x2Au); /*0x1083a6*/
    --cractive; /*0x1083ab*/
  }
  return splx(v1); /*0x1083ba*/
}

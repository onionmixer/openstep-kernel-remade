/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ab9b0. */
$199DFB5D1DF31DC82E78091AC4DEC886 *__cdecl -[IOTokenRing allocateNetbuf](IOTokenRing *self, SEL a2)
{
  int v2; // eax
  $199DFB5D1DF31DC82E78091AC4DEC886 *v3; // ebx

  v2 = nb_alloc(self->_maxInfoFieldSize + 32); /*0x1ab9c1*/
  v3 = ($199DFB5D1DF31DC82E78091AC4DEC886 *)v2; /*0x1ab9c6*/
  if ( v2 ) /*0x1ab9cd*/
    nb_shrink_top(v2, 32); /*0x1ab9d2*/
  return v3; /*0x1ab9d9*/
}

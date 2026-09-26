/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c97e4. */
id __cdecl -[List lastObject](List *self, SEL a2)
{
  if ( self->numElements ) /*0x1c97ea*/
    return self->dataPtr[self->numElements - 1]; /*0x1c97f6*/
  else
    return nullptr; /*0x1c9800*/
}

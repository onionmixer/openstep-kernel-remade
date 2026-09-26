/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c9a30. */
id __cdecl -[List removeLastObject](List *self, SEL a2)
{
  if ( self->numElements ) /*0x1c9a36*/
    return -[List removeObjectAt:](self, sel_removeObjectAt_, self->numElements - 1); /*0x1c9a49*/
  else
    return nullptr; /*0x1c9a54*/
}

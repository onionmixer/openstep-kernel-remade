/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c977c. */
id __cdecl -[List objectAt:](List *self, SEL a2, unsigned int a3)
{
  if ( self->numElements <= a3 ) /*0x1c9788*/
    return nullptr; /*0x1c9794*/
  else
    return self->dataPtr[a3]; /*0x1c978d*/
}

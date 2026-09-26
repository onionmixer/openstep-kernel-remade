/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c9abc. */
id __cdecl -[List replaceObjectAt:with:](List *self, SEL a2, unsigned int a3, id a4)
{
  void **v5; // eax
  void *v6; // edx

  if ( !a4 ) /*0x1c9aca*/
    return nullptr; /*0x1c9acc*/
  if ( self->numElements <= a3 ) /*0x1c9ad7*/
    return nullptr; /*0x1c9aec*/
  v5 = &self->dataPtr[a3]; /*0x1c9adc*/
  v6 = *v5; /*0x1c9adf*/
  *v5 = a4; /*0x1c9ae1*/
  return v6; /*0x1c9ad0*/
}

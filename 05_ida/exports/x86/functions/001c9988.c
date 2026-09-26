/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c9988. */
id __cdecl -[List removeObjectAt:](List *self, SEL a2, unsigned int a3)
{
  void **v4; // ecx
  id *v5; // eax
  id *v6; // edx
  void *i; // esi

  if ( self->numElements <= a3 ) /*0x1c9997*/
    return nullptr; /*0x1c9999*/
  v4 = &self->dataPtr[a3]; /*0x1c99a5*/
  v5 = &self->dataPtr[self->numElements]; /*0x1c99b2*/
  v6 = v4 + 1; /*0x1c99b5*/
  for ( i = *v4; v6 < v5; ++v4 ) /*0x1c99bc*/
    *v4 = *v6++; /*0x1c99c2*/
  --self->numElements; /*0x1c99ce*/
  return i; /*0x1c99d6*/
}

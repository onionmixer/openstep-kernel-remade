/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c9b0c. */
id __cdecl -[List makeObjectsPerform:](List *self, SEL a2, SEL a3)
{
  unsigned int i; // ebx

  for ( i = self->numElements; --i != -1; objc_msgSend(self->dataPtr[i], sel_perform_, a3) ) /*0x1c9b18*/
    ; /*0x1c9b2f*/
  return self; /*0x1c9b42*/
}

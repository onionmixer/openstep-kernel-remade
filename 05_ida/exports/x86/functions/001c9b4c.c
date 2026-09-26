/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c9b4c. */
id __cdecl -[List makeObjectsPerform:with:](List *self, SEL a2, SEL a3, id a4)
{
  unsigned int i; // ebx

  for ( i = self->numElements; --i != -1; objc_msgSend(self->dataPtr[i], sel_perform_with_, a3, a4) ) /*0x1c9b58*/
    ; /*0x1c9b73*/
  return self; /*0x1c9b86*/
}

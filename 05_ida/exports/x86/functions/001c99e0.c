/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c99e0. */
id __cdecl -[List removeObject:](List *self, SEL a2, id a3)
{
  id *dataPtr; // edx
  id *v4; // eax

  dataPtr = self->dataPtr; /*0x1c99eb*/
  v4 = &dataPtr[self->numElements]; /*0x1c99f8*/
  if ( dataPtr >= v4 ) /*0x1c99fc*/
    return nullptr; /*0x1c9a23*/
  while ( *dataPtr != a3 ) /*0x1c9a02*/
  {
    if ( ++dataPtr >= v4 ) /*0x1c9a21*/
      return nullptr; /*0x1c9a21*/
  }
  return -[List removeObjectAt:](self, sel_removeObjectAt_, dataPtr - self->dataPtr); /*0x1c9a28*/
}

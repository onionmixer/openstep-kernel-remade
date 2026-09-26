/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c979c. */
unsigned int __cdecl -[List indexOf:](List *self, SEL a2, id a3)
{
  id *dataPtr; // edx
  id *v4; // eax

  dataPtr = self->dataPtr; /*0x1c97a7*/
  v4 = &dataPtr[self->numElements]; /*0x1c97b4*/
  if ( dataPtr >= v4 ) /*0x1c97b8*/
    return -1; /*0x1c97d3*/
  while ( *dataPtr != a3 ) /*0x1c97be*/
  {
    if ( ++dataPtr >= v4 ) /*0x1c97d1*/
      return -1; /*0x1c97d1*/
  }
  return dataPtr - self->dataPtr; /*0x1c97db*/
}

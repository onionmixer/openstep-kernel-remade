/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c9a70. */
id __cdecl -[List replaceObject:with:](List *self, SEL a2, id a3, id a4)
{
  id *dataPtr; // edx
  id *v6; // eax

  if ( !a4 ) /*0x1c9a81*/
    return nullptr; /*0x1c9a81*/
  dataPtr = self->dataPtr; /*0x1c9a90*/
  v6 = &dataPtr[self->numElements]; /*0x1c9a9d*/
  if ( dataPtr >= v6 ) /*0x1c9aa1*/
    return nullptr; /*0x1c9aaf*/
  while ( *dataPtr != a3 ) /*0x1c9aa6*/
  {
    if ( ++dataPtr >= v6 ) /*0x1c9aad*/
      return nullptr; /*0x1c9aad*/
  }
  *dataPtr = a4; /*0x1c9a88*/
  return a3; /*0x1c9ab4*/
}

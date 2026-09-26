/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c9934. */
id __cdecl -[List addObjectIfAbsent:](List *self, SEL a2, id a3)
{
  id *dataPtr; // edx
  id *v5; // eax

  if ( !a3 ) /*0x1c9941*/
    return nullptr; /*0x1c9943*/
  dataPtr = self->dataPtr; /*0x1c994c*/
  v5 = &dataPtr[self->numElements]; /*0x1c9959*/
  if ( dataPtr >= v5 ) /*0x1c995d*/
    return -[List insertObject:at:](self, sel_insertObject_at_, a3, self->numElements); /*0x1c996b*/
  while ( *dataPtr != a3 ) /*0x1c9962*/
  {
    if ( ++dataPtr >= v5 ) /*0x1c9969*/
      return -[List insertObject:at:](self, sel_insertObject_at_, a3, self->numElements); /*0x1c9969*/
  }
  return self; /*0x1c9980*/
}

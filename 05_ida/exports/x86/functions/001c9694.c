/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c9694. */
id __cdecl -[List copyFromZone:](List *self, SEL a2, $3D27A55567FB06BC0E416B979767FD15 *a3)
{
  id v3; // eax
  id v4; // eax
  id v5; // esi

  v3 = -[Object class](self, sel_class); /*0x1c96ba*/
  v4 = objc_msgSend(v3, sel_allocFromZone_); /*0x1c96c3*/
  v5 = objc_msgSend(v4, sel_initCount_); /*0x1c96d1*/
  *((_DWORD *)v5 + 2) = self->numElements; /*0x1c96d6*/
  memmove(*((void **)v5 + 1), self->dataPtr, 4 * self->numElements); /*0x1c96ec*/
  return v5; /*0x1c96f6*/
}

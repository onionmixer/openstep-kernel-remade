/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c9808. */
id __cdecl -[List setAvailableCapacity:](List *self, SEL a2, unsigned int a3)
{
  $3D27A55567FB06BC0E416B979767FD15 *v3; // edi
  $3D27A55567FB06BC0E416B979767FD15 *v4; // eax
  id *dataPtr; // [esp-10h] [ebp-1Ch]
  int v7; // [esp-8h] [ebp-14h]
  int v8; // [esp-4h] [ebp-10h]

  if ( self->numElements > a3 ) /*0x1c9817*/
    return nullptr; /*0x1c9854*/
  v3 = -[Object zone](self, sel_zone); /*0x1c9826*/
  dataPtr = self->dataPtr; /*0x1c9833*/
  v4 = -[Object zone](self, sel_zone); /*0x1c983c*/
  self->dataPtr = (id *)((int (__stdcall *)($3D27A55567FB06BC0E416B979767FD15 *, id *, unsigned int, int, int))v3->var0)( /*0x1c9849*/
                          v4,
                          dataPtr,
                          4 * a3,
                          v7,
                          v8);
  self->maxElements = a3; /*0x1c984c*/
  return self; /*0x1c9859*/
}

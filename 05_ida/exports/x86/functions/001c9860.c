/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c9860. */
id __cdecl -[List insertObject:at:](List *self, SEL a2, id a3, unsigned int a4)
{
  $3D27A55567FB06BC0E416B979767FD15 *v5; // eax
  id *v6; // edx
  id *v7; // ecx
  id *i; // eax
  id *dataPtr; // [esp-10h] [ebp-20h]
  unsigned int v10; // [esp-Ch] [ebp-1Ch]
  int v11; // [esp-8h] [ebp-18h]
  int v12; // [esp-4h] [ebp-14h]
  $3D27A55567FB06BC0E416B979767FD15 *v13; // [esp+Ch] [ebp-4h]

  if ( !a3 || self->numElements < a4 ) /*0x1c9878*/
    return nullptr; /*0x1c987a*/
  if ( self->maxElements < self->numElements + 1 ) /*0x1c988b*/
  {
    self->maxElements += 1 + self->maxElements; /*0x1c9891*/
    v13 = -[Object zone](self, sel_zone); /*0x1c98a1*/
    v10 = 4 * self->maxElements; /*0x1c98ae*/
    dataPtr = self->dataPtr; /*0x1c98b2*/
    v5 = -[Object zone](self, sel_zone); /*0x1c98bb*/
    self->dataPtr = (id *)((int (__stdcall *)($3D27A55567FB06BC0E416B979767FD15 *, id *, unsigned int, int, int))v13->var0)( /*0x1c98cb*/
                            v5,
                            dataPtr,
                            v10,
                            v11,
                            v12);
  }
  v6 = &self->dataPtr[self->numElements]; /*0x1c98da*/
  v7 = v6 - 1; /*0x1c98dd*/
  for ( i = &self->dataPtr[a4]; v6 > i; --v6 ) /*0x1c98ec*/
    *v6 = *v7--; /*0x1c98f2*/
  *i = a3; /*0x1c9901*/
  ++self->numElements; /*0x1c9903*/
  return self; /*0x1c990b*/
}

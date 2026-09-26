/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c9560. */
id __cdecl -[List initCount:](List *self, SEL a2, unsigned int a3)
{
  $3D27A55567FB06BC0E416B979767FD15 *v3; // esi
  $3D27A55567FB06BC0E416B979767FD15 *v4; // eax
  unsigned int v6; // [esp-Ch] [ebp-14h]
  int v7; // [esp-8h] [ebp-10h]
  int v8; // [esp-4h] [ebp-Ch]

  self->maxElements = a3; /*0x1c956b*/
  if ( a3 ) /*0x1c9570*/
  {
    v3 = -[Object zone](self, sel_zone); /*0x1c957f*/
    v6 = 4 * self->maxElements; /*0x1c958b*/
    v4 = -[Object zone](self, sel_zone); /*0x1c9594*/
    self->dataPtr = (id *)((int (__stdcall *)($3D27A55567FB06BC0E416B979767FD15 *, unsigned int, int, int))v3->var1)( /*0x1c95a2*/
                            v4,
                            v6,
                            v7,
                            v8);
  }
  return self; /*0x1c95aa*/
}

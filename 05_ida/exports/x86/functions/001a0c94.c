/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a0c94. */
int __cdecl -[PCPointer setIntValues:forParameter:count:](
        PCPointer *self,
        SEL a2,
        unsigned int *a3,
        char *a4,
        unsigned int a5)
{
  id v5; // eax
  char v7; // cl

  if ( !strcmp(a4, aResolution_2) ) /*0x1a0cb7*/
  {
    self->resolution = *a3; /*0x1a0cc0*/
    v5 = -[PCPointer getResolution](self, sel_getResolution); /*0x1a0cce*/
    objc_msgSend(self->target, sel_setResolution_, v5); /*0x1a0ce2*/
    return 0; /*0x1a0ce7*/
  }
  else if ( !strcmp(a4, aInverted_1) ) /*0x1a0cfb*/
  {
    v7 = *(_BYTE *)a3; /*0x1a0d02*/
    self->inverted = *(_BYTE *)a3; /*0x1a0d04*/
    objc_msgSend(self->target, sel_setInverted_, v7); /*0x1a0d1c*/
    return 0; /*0x1a0d21*/
  }
  else
  {
    return -711; /*0x1a0d28*/
  }
}

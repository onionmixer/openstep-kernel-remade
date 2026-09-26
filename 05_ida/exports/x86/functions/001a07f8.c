/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a07f8. */
int __cdecl -[EventSrcPCPointer getIntValues:forParameter:count:](
        EventSrcPCPointer *self,
        SEL a2,
        unsigned int *a3,
        char *a4,
        unsigned int *a5)
{
  int result; // eax
  unsigned int v6; // eax
  objc_super v7; // [esp+14h] [ebp-8h] BYREF

  result = -706; /*0x1a0804*/
  if ( !strcmp(a4, aEvsCurrentmous) ) /*0x1a0826*/
  {
    *a3 = (*a5 - 1) >> 1; /*0x1a082f*/
    -[EventSrcPCPointer pointerScaling:data:](self, sel_pointerScaling_data_, a3, a3 + 1); /*0x1a0841*/
    v6 = 2 * *a3; /*0x1a084a*/
    LOBYTE(v6) = (2 * *a3) | 1; /*0x1a084c*/
    *a5 = v6; /*0x1a0851*/
    return 0; /*0x1a0853*/
  }
  else if ( !strcmp(a4, aEvsCurrentmous_0) ) /*0x1a086c*/
  {
    if ( *a5 ) /*0x1a080e*/
    {
      *a5 = 1; /*0x1a087d*/
      objc_msgSend(self->deviceLock, sel_lock); /*0x1a0894*/
      *a3 = self->buttonMode; /*0x1a08a2*/
      objc_msgSend(self->deviceLock, sel_unlock); /*0x1a08b5*/
      return 0; /*0x1a08ba*/
    }
  }
  else if ( !strcmp(a4, aEvsEventdevice_1) ) /*0x1a08d0*/
  {
    *a5 = 0; /*0x1a08d7*/
    *a3 = 4; /*0x1a08dd*/
    a3[2] = 2; /*0x1a08e3*/
    a3[1] = 0; /*0x1a08ea*/
    a3[3] = 0; /*0x1a08f1*/
    *a5 = 4; /*0x1a08f8*/
    return 0; /*0x1a08fe*/
  }
  else
  {
    v7.receiver = self; /*0x1a0917*/
    v7.super_class = (Class)stru_1FA064.super_class; /*0x1a0920*/
    result = -[IODevice getIntValues:forParameter:count:](&v7, sel_getIntValues_forParameter_count_, a3, a4, a5); /*0x1a0927*/
    if ( result == -711 ) /*0x1a0931*/
      return -706; /*0x1a0933*/
  }
  return result; /*0x1a093b*/
}

/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a0950. */
int __cdecl -[EventSrcPCPointer setIntValues:forParameter:count:](
        EventSrcPCPointer *self,
        SEL a2,
        unsigned int *a3,
        char *a4,
        unsigned int a5)
{
  int v6; // [esp+Ch] [ebp-Ch]
  objc_super v7; // [esp+10h] [ebp-8h] BYREF

  v6 = -706; /*0x1a095c*/
  if ( !strcmp(a4, aEvsSetmousesca) ) /*0x1a0972*/
  {
    if ( a5 <= 0x29 && a5 >= 2 * *a3 + 1 ) /*0x1a098c*/
    {
      -[EventSrcPCPointer setPointerScaling:data:](self, sel_setPointerScaling_data_, *a3, a3 + 1); /*0x1a09a4*/
      return 0; /*0x1a09a9*/
    }
  }
  else if ( !strcmp(a4, aEvsSetmousehan) ) /*0x1a09c7*/
  {
    if ( a5 == 1 ) /*0x1a09cf*/
    {
      objc_msgSend(self->deviceLock, sel_lock); /*0x1a09e6*/
      self->buttonMode = *a3; /*0x1a09f3*/
      objc_msgSend(self->deviceLock, sel_unlock); /*0x1a0a0a*/
      return 0; /*0x1a0a0f*/
    }
  }
  else if ( !strcmp(a4, aEvsResetmouse_0) ) /*0x1a0a27*/
  {
    return 0; /*0x1a0a2b*/
  }
  else
  {
    v7.receiver = self; /*0x1a0a47*/
    v7.super_class = (Class)stru_1FA064.super_class; /*0x1a0a50*/
    v6 = -[IODevice setIntValues:forParameter:count:](&v7, sel_setIntValues_forParameter_count_, a3, a4, a5); /*0x1a0a5c*/
    if ( v6 == -711 ) /*0x1a0a64*/
      return -706; /*0x1a0a66*/
  }
  return v6; /*0x1a0a73*/
}

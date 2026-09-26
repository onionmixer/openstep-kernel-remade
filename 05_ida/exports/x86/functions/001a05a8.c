/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a05a8. */
EventSrcPCPointer *__cdecl -[EventSrcPCPointer init](EventSrcPCPointer *self, SEL a2)
{
  EventSrcPCPointer *v2; // esi
  id v3; // eax
  objc_super v5; // [esp+8h] [ebp-8h] BYREF

  self->lastTimestamp = 0; /*0x1a05b3*/
  self->dyRemainder = 0; /*0x1a05c7*/
  self->dxRemainder = 0; /*0x1a05d1*/
  if ( !self->deviceLock ) /*0x1a05db*/
    self->deviceLock = +[Object new](aNxlock, sel_new); /*0x1a05f7*/
  objc_msgSend(self->deviceLock, sel_lock); /*0x1a060e*/
  v5.receiver = self; /*0x1a061a*/
  v5.super_class = (Class)stru_1FA064.super_class; /*0x1a0623*/
  -[IOEventSource init](&v5, sel_init); /*0x1a062a*/
  self->pointerDevice = nullptr; /*0x1a062f*/
  self->buttonMode = 0; /*0x1a0639*/
  v2 = -[EventSrcPCPointer initPointer](self, sel_initPointer); /*0x1a0650*/
  v3 = objc_msgSend(self->pointerDevice, sel_getResolution); /*0x1a0660*/
  self->resolution = (unsigned int)v3; /*0x1a0665*/
  if ( !v3 ) /*0x1a0670*/
    self->resolution = 72; /*0x1a0672*/
  self->resScaling = 0x4800 / self->resolution; /*0x1a0689*/
  self->inverted = (unsigned __int8)objc_msgSend(self->pointerDevice, sel_getInverted); /*0x1a06a2*/
  objc_msgSend(self->deviceLock, sel_unlock); /*0x1a06b6*/
  -[EventSrcPCPointer setPointerScaling:data:](self, sel_setPointerScaling_data_, 5, &unk_1D58BC); /*0x1a06ca*/
  return v2; /*0x1a06d4*/
}

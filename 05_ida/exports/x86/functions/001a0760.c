/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a0760. */
id __cdecl -[EventSrcPCPointer free](EventSrcPCPointer *self, SEL a2)
{
  id deviceLock; // esi
  id pointerDevice; // eax
  objc_super v5; // [esp+8h] [ebp-8h] BYREF

  objc_msgSend(self->deviceLock, sel_lock); /*0x1a0779*/
  dword_1E49BC = nullptr; /*0x1a077e*/
  deviceLock = self->deviceLock; /*0x1a0788*/
  self->deviceLock = nullptr; /*0x1a078e*/
  pointerDevice = self->pointerDevice; /*0x1a079b*/
  if ( pointerDevice ) /*0x1a07a3*/
    objc_msgSend(pointerDevice, sel_setEventTarget_, 0); /*0x1a07af*/
  objc_msgSend(deviceLock, sel_unlock); /*0x1a07bf*/
  objc_msgSend(deviceLock, sel_free); /*0x1a07cc*/
  v5.receiver = self; /*0x1a07d8*/
  v5.super_class = (Class)stru_1FA064.super_class; /*0x1a07e1*/
  return -[IOEventSource free](&v5, sel_free); /*0x1a07f0*/
}

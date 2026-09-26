/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19ff48. */
int __cdecl -[EventSrcPCKeyboard relinquishOwnership:](EventSrcPCKeyboard *self, SEL a2, id a3)
{
  id v3; // esi
  id v4; // eax
  id v5; // eax
  objc_super v7; // [esp+8h] [ebp-8h] BYREF

  v7.receiver = self; /*0x19ff5e*/
  v7.super_class = (Class)stru_1FA014.ext; /*0x19ff67*/
  v3 = -[IOEventSource relinquishOwnership:](&v7, sel_relinquishOwnership_, a3); /*0x19ff73*/
  v4 = -[IOEventSource ownerLock](self, sel_ownerLock); /*0x19ff84*/
  objc_msgSend(v4, sel_lock); /*0x19ff8d*/
  if ( !v3 && !-[IOEventSource owner](self, sel_owner) && !objc_msgSend(self->kbdDevice, sel_relinquishOwnership_, self) ) /*0x19ffbc*/
    self->ownDevice = 0; /*0x19ffc8*/
  v5 = -[IOEventSource ownerLock](self, sel_ownerLock); /*0x19ffde*/
  objc_msgSend(v5, sel_unlock); /*0x19ffe7*/
  return (int)v3; /*0x19fff1*/
}

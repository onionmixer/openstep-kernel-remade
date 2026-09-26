/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19fff8. */
int __cdecl -[EventSrcPCKeyboard becomeOwner:](EventSrcPCKeyboard *self, SEL a2, id a3)
{
  int v3; // esi
  id v4; // eax
  id v5; // eax
  objc_super v7; // [esp+Ch] [ebp-8h] BYREF

  v7.receiver = self; /*0x1a000f*/
  v7.super_class = (Class)stru_1FA014.ext; /*0x1a0018*/
  v3 = -[IOEventSource becomeOwner:](&v7, sel_becomeOwner_, a3); /*0x1a0024*/
  v4 = -[IOEventSource ownerLock](self, sel_ownerLock); /*0x1a0035*/
  objc_msgSend(v4, sel_lock); /*0x1a003e*/
  if ( !v3 && !self->ownDevice ) /*0x1a004a*/
  {
    if ( objc_msgSend(self->kbdDevice, sel_becomeOwner_, self) ) /*0x1a0062*/
    {
      if ( objc_msgSend(self->kbdDevice, sel_desireOwnership_, self) ) /*0x1a0087*/
      {
        v7.receiver = self; /*0x1a009e*/
        v7.super_class = (Class)stru_1FA014.ext; /*0x1a00a7*/
        -[IOEventSource relinquishOwnership:](&v7, sel_relinquishOwnership_, a3); /*0x1a00ab*/
        v3 = -725; /*0x1a00b0*/
      }
    }
    else
    {
      self->ownDevice = 1; /*0x1a006e*/
    }
  }
  v5 = -[IOEventSource ownerLock](self, sel_ownerLock); /*0x1a00c7*/
  objc_msgSend(v5, sel_unlock); /*0x1a00d0*/
  return v3; /*0x1a00da*/
}

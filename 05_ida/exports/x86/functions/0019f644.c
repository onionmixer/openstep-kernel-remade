/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19f644. */
int __cdecl -[EventSrcPCKeyboard relinquishOwnershipRequest:](EventSrcPCKeyboard *self, SEL a2, id a3)
{
  id v3; // eax
  int v4; // ebx
  id v5; // eax

  v3 = -[IOEventSource ownerLock](self, sel_ownerLock); /*0x19f65b*/
  objc_msgSend(v3, sel_lock); /*0x19f664*/
  if ( -[IOEventSource owner](self, sel_owner) ) /*0x19f671*/
  {
    v4 = -725; /*0x19f688*/
  }
  else
  {
    self->ownDevice = 0; /*0x19f67d*/
    v4 = 0; /*0x19f684*/
  }
  v5 = -[IOEventSource ownerLock](self, sel_ownerLock); /*0x19f69c*/
  objc_msgSend(v5, sel_unlock); /*0x19f6a5*/
  return v4; /*0x19f6af*/
}

/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b2b0c. */
id __cdecl -[EventDriver registerEventSource:](EventDriver *self, SEL a2, id a3)
{
  id *v4; // ebx
  queue_entry *prev; // edx

  if ( objc_msgSend(a3, sel_becomeOwner_, self) ) /*0x1b2b21*/
    return nullptr; /*0x1b2b2d*/
  v4 = (id *)IOMalloc(0xCu); /*0x1b2b3b*/
  bzero(v4, 0xCu); /*0x1b2b40*/
  *v4 = a3; /*0x1b2b45*/
  objc_msgSend(self->eventSrcListLock, sel_lock); /*0x1b2b55*/
  prev = self->eventSrcList.prev; /*0x1b2b5d*/
  if ( &self->eventSrcList == ($BAB6C68F9D34F0972F921D3DB17D7446 *)prev ) /*0x1b2b6b*/
    self->eventSrcList.next = (queue_entry *)v4; /*0x1b2b6d*/
  else
    *((_DWORD *)prev + 1) = v4; /*0x1b2b78*/
  v4[2] = prev; /*0x1b2b7b*/
  v4[1] = &self->eventSrcList; /*0x1b2b84*/
  self->eventSrcList.prev = (queue_entry *)v4; /*0x1b2b87*/
  objc_msgSend(self->eventSrcListLock, sel_unlock); /*0x1b2b9b*/
  return self; /*0x1b2ba5*/
}

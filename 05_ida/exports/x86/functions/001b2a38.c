/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b2a38. */
id __cdecl -[EventDriver detachEventSources](EventDriver *self, SEL a2)
{
  queue_entry *p_eventSrcList; // edi
  queue_entry *next; // ebx
  int v4; // edx
  int v5; // eax

  objc_msgSend(self->eventSrcListLock, sel_lock); /*0x1b2a4f*/
  if ( ($BAB6C68F9D34F0972F921D3DB17D7446 *)self->eventSrcList.next != &self->eventSrcList ) /*0x1b2a63*/
  {
    p_eventSrcList = (queue_entry *)&self->eventSrcList; /*0x1b2a69*/
    do /*0x1b2ae8*/
    {
      next = self->eventSrcList.next; /*0x1b2a6c*/
      v4 = *((_DWORD *)next + 1); /*0x1b2a72*/
      v5 = *((_DWORD *)next + 2); /*0x1b2a75*/
      if ( p_eventSrcList == (queue_entry *)v4 ) /*0x1b2a7a*/
        self->eventSrcList.prev = (queue_entry *)v5; /*0x1b2a7c*/
      else
        *(_DWORD *)(v4 + 8) = v5; /*0x1b2a84*/
      if ( p_eventSrcList == (queue_entry *)v5 ) /*0x1b2a89*/
        self->eventSrcList.next = (queue_entry *)v4; /*0x1b2a8b*/
      else
        *(_DWORD *)(v5 + 4) = v4; /*0x1b2a94*/
      objc_msgSend(self->eventSrcListLock, sel_unlock); /*0x1b2aa5*/
      if ( *(_DWORD *)next ) /*0x1b2aad*/
        objc_msgSend(*(id *)next, sel_relinquishOwnership_, self); /*0x1b2abc*/
      IOFree((int)next, 12); /*0x1b2ac7*/
      objc_msgSend(self->eventSrcListLock, sel_lock); /*0x1b2ada*/
    }
    while ( self->eventSrcList.next != p_eventSrcList ); /*0x1b2ae8*/
  }
  objc_msgSend(self->eventSrcListLock, sel_unlock); /*0x1b2af8*/
  return self; /*0x1b2b02*/
}

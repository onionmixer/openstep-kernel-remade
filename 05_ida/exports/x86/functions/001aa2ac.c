/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1aa2ac. */
id __cdecl -[IOEthernet free](IOEthernet *self, SEL a2)
{
  id driverCmd; // eax
  IONetwork *netif; // eax
  id multiLock; // eax
  queue_entry *p_multicastQueue; // ebx
  int v6; // ecx
  int v7; // edx
  $BAB6C68F9D34F0972F921D3DB17D7446 *v8; // eax
  $BAB6C68F9D34F0972F921D3DB17D7446 *v9; // eax
  queue_entry *next; // [esp+Ch] [ebp-Ch]
  objc_super v12; // [esp+10h] [ebp-8h] BYREF

  -[IOEthernet clearTimeout](self, sel_clearTimeout); /*0x1aa2c0*/
  driverCmd = self->_driverCmd; /*0x1aa2c8*/
  if ( driverCmd ) /*0x1aa2d0*/
  {
    objc_msgSend(driverCmd, sel_send_, 4); /*0x1aa2dc*/
    objc_msgSend(self->_driverCmd, sel_free); /*0x1aa2ef*/
  }
  netif = self->_netif; /*0x1aa2f7*/
  if ( netif ) /*0x1aa2ff*/
    -[IONetwork free](netif, sel_free); /*0x1aa309*/
  multiLock = self->_multiLock; /*0x1aa311*/
  if ( multiLock ) /*0x1aa319*/
  {
    objc_msgSend(multiLock, sel_lock); /*0x1aa327*/
    if ( ($BAB6C68F9D34F0972F921D3DB17D7446 *)self->_multicastQueue.next != &self->_multicastQueue ) /*0x1aa33b*/
    {
      p_multicastQueue = (queue_entry *)&self->_multicastQueue; /*0x1aa33d*/
      do /*0x1aa381*/
      {
        next = self->_multicastQueue.next; /*0x1aa346*/
        v6 = *((_DWORD *)next + 2); /*0x1aa349*/
        v7 = *((_DWORD *)next + 3); /*0x1aa34c*/
        if ( p_multicastQueue == (queue_entry *)v6 ) /*0x1aa351*/
          v8 = &self->_multicastQueue; /*0x1aa353*/
        else
          v8 = ($BAB6C68F9D34F0972F921D3DB17D7446 *)(v6 + 8); /*0x1aa358*/
        v8->prev = (queue_entry *)v7; /*0x1aa35b*/
        if ( p_multicastQueue == (queue_entry *)v7 ) /*0x1aa360*/
          v9 = &self->_multicastQueue; /*0x1aa362*/
        else
          v9 = ($BAB6C68F9D34F0972F921D3DB17D7446 *)(v7 + 8); /*0x1aa368*/
        v9->next = (queue_entry *)v6; /*0x1aa36b*/
        IOFree((int)next, 20); /*0x1aa373*/
      }
      while ( self->_multicastQueue.next != p_multicastQueue ); /*0x1aa381*/
    }
    objc_msgSend(self->_multiLock, sel_unlock); /*0x1aa391*/
    objc_msgSend(self->_multiLock, sel_free); /*0x1aa3a4*/
  }
  v12.receiver = self; /*0x1aa3b3*/
  v12.super_class = (Class)stru_1FA294.ext; /*0x1aa3bc*/
  return -[IODirectDevice free](&v12, sel_free); /*0x1aa3cb*/
}

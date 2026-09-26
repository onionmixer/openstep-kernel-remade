/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ae74c. */
void __cdecl -[SCSIDisk unlockIoQLock](SCSIDisk *self, SEL a2)
{
  char *v2; // edx
  int v3; // ebx

  v2 = -[IODisk lastReadyState](self, sel_lastReadyState); /*0x1ae761*/
  if ( ($BAB6C68F9D34F0972F921D3DB17D7446 *)self->_ioQueueNodisk.next == &self->_ioQueueNodisk /*0x1ae78a*/
    && (($BAB6C68F9D34F0972F921D3DB17D7446 *)self->_ioQueueDisk.next == &self->_ioQueueDisk
     || (unsigned int)(v2 - 2) <= 1
     || self->_ejectPending) )
  {
    v3 = 0; /*0x1ae79c*/
    objc_msgSend(self->_ioQLock, sel_unlockWith_, 0); /*0x1ae7ad*/
  }
  else
  {
    v3 = 1; /*0x1ae793*/
    objc_msgSend(self->_ioQLock, sel_unlockWith_, 1); /*0x1ae798*/
  }
  if ( v3 == 1 ) /*0x1ae7b8*/
    thread_block(); /*0x1ae7ba*/
}

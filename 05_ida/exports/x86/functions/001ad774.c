/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ad774. */
int __cdecl -[SCSIDisk enqueueSdBuf:](SCSIDisk *self, SEL a2, $BB0ECD142E749ABD0946980FC80D177E *a3)
{
  $BAB6C68F9D34F0972F921D3DB17D7446 *p_ioQueueDisk; // edx
  queue_entry *prev; // eax

  a3->var11 = -1; /*0x1ad77f*/
  objc_msgSend(self->_ioQLock, sel_lock); /*0x1ad794*/
  if ( (*((_BYTE *)a3 + 32) & 1) != 0 ) /*0x1ad7a0*/
    p_ioQueueDisk = &self->_ioQueueDisk; /*0x1ad7a2*/
  else
    p_ioQueueDisk = &self->_ioQueueNodisk; /*0x1ad7bc*/
  if ( ($BAB6C68F9D34F0972F921D3DB17D7446 *)p_ioQueueDisk->next == p_ioQueueDisk ) /*0x1ad7c4*/
  {
    p_ioQueueDisk->next = (queue_entry *)a3; /*0x1ad7ac*/
    p_ioQueueDisk->prev = (queue_entry *)a3; /*0x1ad7ae*/
    a3->var12.var0 = (queue_entry *)p_ioQueueDisk; /*0x1ad7b1*/
    a3->var12.var1 = (queue_entry *)p_ioQueueDisk; /*0x1ad7b4*/
  }
  else
  {
    prev = p_ioQueueDisk->prev; /*0x1ad7c6*/
    a3->var12.var1 = prev; /*0x1ad7c9*/
    a3->var12.var0 = (queue_entry *)p_ioQueueDisk; /*0x1ad7cc*/
    p_ioQueueDisk->prev = (queue_entry *)a3; /*0x1ad7cf*/
    *((_DWORD *)prev + 11) = a3; /*0x1ad7d2*/
  }
  objc_msgSend(self->_ioQLock, sel_unlockWith_, 1); /*0x1ad7e5*/
  if ( a3->var6 ) /*0x1ad7ed*/
    return 0; /*0x1ad81c*/
  objc_msgSend(a3->var7, sel_lockWhen_, 1); /*0x1ad800*/
  objc_msgSend(a3->var7, sel_unlockWith_, 0); /*0x1ad812*/
  return a3->var11; /*0x1ad821*/
}

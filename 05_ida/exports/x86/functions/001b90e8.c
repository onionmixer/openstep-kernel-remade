/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b90e8. */
char __cdecl -[AudioStream markAbortionsExclude:](AudioStream *self, SEL a2, char a3)
{
  queue_entry *next; // eax

  objc_msgSend(self->regionQueueLock, sel_lock); /*0x1b9104*/
  next = self->regionQueue.next; /*0x1b910c*/
  if ( &self->regionQueue == ($BAB6C68F9D34F0972F921D3DB17D7446 *)next ) /*0x1b9114*/
  {
    objc_msgSend(self->regionQueueLock, sel_unlock); /*0x1b9121*/
    return 0; /*0x1b9126*/
  }
  else
  {
    do /*0x1b913f*/
    {
      *((_DWORD *)next + 13) = 1; /*0x1b9130*/
      *((_DWORD *)next + 14) = a3; /*0x1b9137*/
      next = *((queue_entry **)next + 15); /*0x1b913a*/
    }
    while ( &self->regionQueue != ($BAB6C68F9D34F0972F921D3DB17D7446 *)next ); /*0x1b913f*/
    objc_msgSend(self->regionQueueLock, sel_unlock); /*0x1b914c*/
    return 1; /*0x1b9151*/
  }
}

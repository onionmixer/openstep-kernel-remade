/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b8d80. */
id __cdecl -[AudioStream dmaCompleteDescriptor:transfered:](
        AudioStream *self,
        SEL a2,
        $2D87D4CA0FCCD4E0D80DDC4A8D8F85EA *a3,
        unsigned int a4)
{
  queue_entry *next; // ebx
  $BAB6C68F9D34F0972F921D3DB17D7446 *p_regionQueue; // esi
  int v6; // edx
  $BAB6C68F9D34F0972F921D3DB17D7446 *v7; // eax
  $BAB6C68F9D34F0972F921D3DB17D7446 *v8; // eax
  int v10; // [esp+Ch] [ebp-10h]
  char v11; // [esp+14h] [ebp-8h]
  unsigned int v12; // [esp+18h] [ebp-4h] BYREF

  v12 = 0; /*0x1b8d89*/
  v11 = 0; /*0x1b8d90*/
  objc_msgSend(self->regionQueueLock, sel_lock); /*0x1b8da2*/
  if ( &self->regionQueue != ($BAB6C68F9D34F0972F921D3DB17D7446 *)self->regionQueue.next ) /*0x1b8db8*/
  {
    next = self->regionQueue.next; /*0x1b8dc8*/
    p_regionQueue = &self->regionQueue; /*0x1b8dca*/
    while ( 1 ) /*0x1b8dcc*/
    {
      if ( *(($2D87D4CA0FCCD4E0D80DDC4A8D8F85EA **)next + 8) == a3 ) /*0x1b8dd2*/
      {
        if ( (*((_BYTE *)next + 24) & 1) != 0 ) /*0x1b8dd8*/
          -[AudioStream sendStatusMessage:forRegion:](self, sel_sendStatusMessage_forRegion_, 0, next); /*0x1b8de8*/
        *((_DWORD *)next + 8) = 0; /*0x1b8df0*/
      }
      -[AudioStream completeRegion:descriptor:size:used:]( /*0x1b8e0f*/
        self,
        sel_completeRegion_descriptor_size_used_,
        next,
        a3,
        a4,
        &v12);
      if ( *(($2D87D4CA0FCCD4E0D80DDC4A8D8F85EA **)next + 9) != a3 ) /*0x1b8e1d*/
      {
        if ( *((_DWORD *)next + 13) ) /*0x1b8e1f*/
          goto LABEL_12; /*0x1b8e23*/
        if ( !*((_DWORD *)next + 12) ) /*0x1b8e29*/
        {
          if ( v12 >= a4 ) /*0x1b8ee2*/
            goto LABEL_30; /*0x1b8ee2*/
          next = *((queue_entry **)next + 15); /*0x1b8ee4*/
          goto LABEL_29; /*0x1b8ee4*/
        }
      }
      if ( *((_DWORD *)next + 13) ) /*0x1b8e2f*/
      {
LABEL_12:
        if ( (*((_BYTE *)next + 24) & 0x10) != 0 && (!v11 || self->type == 1) ) /*0x1b8e48*/
        {
          -[AudioStream sendStatusMessage:forRegion:](self, sel_sendStatusMessage_forRegion_, 4, next); /*0x1b8e58*/
          v11 = 1; /*0x1b8e5d*/
        }
        if ( *((_DWORD *)next + 13) ) /*0x1b8e64*/
          goto LABEL_20; /*0x1b8e68*/
      }
      if ( !*((_DWORD *)next + 12) && (*((_BYTE *)next + 24) & 2) != 0 ) /*0x1b8e74*/
        -[AudioStream sendStatusMessage:forRegion:](self, sel_sendStatusMessage_forRegion_, 1, next); /*0x1b8e84*/
LABEL_20:
      v10 = *((_DWORD *)next + 15); /*0x1b8e8c*/
      v6 = *((_DWORD *)next + 16); /*0x1b8e98*/
      if ( p_regionQueue == ($BAB6C68F9D34F0972F921D3DB17D7446 *)v10 ) /*0x1b8e9d*/
        v7 = &self->regionQueue; /*0x1b8e9f*/
      else
        v7 = ($BAB6C68F9D34F0972F921D3DB17D7446 *)(v10 + 60); /*0x1b8ea7*/
      v7->prev = (queue_entry *)v6; /*0x1b8eaa*/
      if ( p_regionQueue == ($BAB6C68F9D34F0972F921D3DB17D7446 *)v6 ) /*0x1b8eaf*/
        v8 = &self->regionQueue; /*0x1b8eb1*/
      else
        v8 = ($BAB6C68F9D34F0972F921D3DB17D7446 *)(v6 + 60); /*0x1b8eb8*/
      v8->next = (queue_entry *)v10; /*0x1b8ebe*/
      -[AudioStream freeRegion:](self, sel_freeRegion_, next); /*0x1b8ecc*/
      next = *((queue_entry **)next + 15); /*0x1b8ed4*/
LABEL_29:
      if ( p_regionQueue == ($BAB6C68F9D34F0972F921D3DB17D7446 *)next ) /*0x1b8ee9*/
      {
LABEL_30:
        objc_msgSend(self->regionQueueLock, sel_unlock); /*0x1b8eef*/
        return self; /*0x1b8efd*/
      }
    }
  }
  objc_msgSend(self->regionQueueLock, sel_unlock); /*0x1b8dc1*/
  return self; /*0x1b8f08*/
}

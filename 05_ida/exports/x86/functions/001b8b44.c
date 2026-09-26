/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b8b44. */
id __cdecl -[AudioStream sendControlMessage:mask:](AudioStream *self, SEL a2, int a3, unsigned int a4)
{
  int v4; // eax
  int v5; // ebx
  int v6; // esi
  int v7; // eax
  void *p_regionQueue; // eax
  queue_entry *i; // ebx
  int v11; // eax

  if ( self->type ) /*0x1b8b4d*/
  {
    objc_msgSend(self->regionQueueLock, sel_lock); /*0x1b8b9b*/
    if ( ($BAB6C68F9D34F0972F921D3DB17D7446 *)self->regionQueue.next != &self->regionQueue ) /*0x1b8ba9*/
    {
      p_regionQueue = -[AudioStream createSndReplyMsg](self, sel_createSndReplyMsg); /*0x1b8bcc*/
      for ( i = self->regionQueue.next; /*0x1b8bd9*/
            &self->regionQueue != ($BAB6C68F9D34F0972F921D3DB17D7446 *)i;
            p_regionQueue = &self->regionQueue )
      {
        if ( (a4 & *((_DWORD *)i + 6)) != 0 ) /*0x1b8be2*/
        {
          v11 = IOConvertPort((int)p_regionQueue, (int)i, *((_DWORD *)i + 7), 0, 1); /*0x1b8bec*/
          switch ( a3 ) /*0x1b8bfa*/
          {
            case 2: /*0x1b8bfa*/
              audio_snd_reply_paused(self->sndReplyMsg, v11, *((_DWORD *)i + 5)); /*0x1b8c05*/
              break;
            case 3: /*0x1b8bfa*/
              audio_snd_reply_resumed(self->sndReplyMsg, v11, *((_DWORD *)i + 5)); /*0x1b8c1b*/
              break;
            case 4: /*0x1b8bfa*/
              audio_snd_reply_aborted(self->sndReplyMsg, v11, *((_DWORD *)i + 5)); /*0x1b8c33*/
              break;
          }
          msg_send(self->sndReplyMsg, 33, 1000); /*0x1b8c46*/
        }
        i = *((queue_entry **)i + 15); /*0x1b8c4e*/
      }
    }
    objc_msgSend(self->regionQueueLock, sel_unlock); /*0x1b8c63*/
    return self; /*0x1b8c68*/
  }
  else
  {
    if ( (a4 & self->userReplyMessages) != 0 ) /*0x1b8b59*/
    {
      v6 = IOConvertPort(v4, v5, self->userReplyPort, 0, 1); /*0x1b8b68*/
      v7 = IOConvertPort(v6, v5, self->kernUserPort, 0, 1); /*0x1b8b72*/
      _NXAudioReplyStreamStatus(v6, v7, v6, self->tag, 0, a3); /*0x1b8b84*/
    }
    return self; /*0x1b8b89*/
  }
}

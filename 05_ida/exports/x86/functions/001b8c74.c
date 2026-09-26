/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b8c74. */
id __cdecl -[AudioStream sendStatusMessage:forRegion:](
        AudioStream *self,
        SEL a2,
        int a3,
        $4BA88FAFA6E9A53AC825FB6F75E82BF2 *a4)
{
  int v4; // ebx
  int v5; // esi
  int v6; // eax

  v4 = a3; /*0x1b8c7d*/
  v5 = IOConvertPort(a4->var7, 0, 1); /*0x1b8c90*/
  v6 = IOConvertPort(self->kernUserPort, 0, 1); /*0x1b8c9a*/
  if ( self->type )
  {
    -[AudioStream createSndReplyMsg](self, sel_createSndReplyMsg); /*0x1b8cec*/
    if ( a3 ) /*0x1b8cf6*/
    {
      if ( a3 == 1 ) /*0x1b8d0f*/
      {
        audio_snd_reply_completed(self->sndReplyMsg, v5, a4->var5); /*0x1b8d1d*/
      }
      else if ( a3 == 5 ) /*0x1b8d27*/
      {
        audio_snd_reply_overflow(self->sndReplyMsg, v5, a4->var5); /*0x1b8d35*/
      }
    }
    else
    {
      audio_snd_reply_started(self->sndReplyMsg, v5, a4->var5); /*0x1b8d04*/
    }
    msg_send(self->sndReplyMsg, 33, 1000); /*0x1b8d48*/
  }
  else
  {
    if ( a3 == 4 && a4->var10.var4 ) /*0x1b8cb0*/
      v4 = 6; /*0x1b8cb6*/
    if ( _NXAudioReplyStreamStatus(v5, v6, v5, self->tag, a4->var5, v4) )
      IOLog("AS: replyStreamStatus returns %d\n");
  }
  return self; /*0x1b8d52*/
}

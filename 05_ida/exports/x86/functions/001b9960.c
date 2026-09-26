/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b9960. */
id __cdecl -[InputStream sendRecordedDataForRegion:](InputStream *self, SEL a2, $4BA88FAFA6E9A53AC825FB6F75E82BF2 *a3)
{
  unsigned int v3; // edi
  unsigned int v4; // ebx
  int v5; // eax
  int v6; // ebx
  int v7; // eax
  int v8; // eax
  int v10; // [esp+10h] [ebp-14h]
  unsigned int v11; // [esp+14h] [ebp-10h]
  int v12; // [esp+18h] [ebp-Ch]
  _BYTE v13[4]; // [esp+1Ch] [ebp-8h] BYREF
  int v14; // [esp+20h] [ebp-4h] BYREF

  v3 = a3->var3 - a3->var0; /*0x1b9974*/
  v4 = a3->var0 & ~page_mask; /*0x1b9981*/
  v11 = a3->var0 - v4; /*0x1b9985*/
  v10 = kern_serv_kernel_task_port(); /*0x1b998d*/
  v5 = vm_read_EXTERNAL(v10, v4, ~page_mask & (page_mask + v3 + v11), &v14, v13); /*0x1b99ae*/
  if ( v5 )
    v5 = IOLog((int)"Audio: vm_read returned %d\n", v5);
  v12 = v14 + v11; /*0x1b99ce*/
  if ( v3 ) /*0x1b99d5*/
  {
    v6 = IOConvertPort(v5, v4, a3->var7, 0, 1); /*0x1b99eb*/
    v7 = IOConvertPort(v6, v6, self->super.kernUserPort, 0, 1); /*0x1b99f5*/
    if ( self->super.type ) /*0x1b99fd*/
    {
      if ( !self->super.sndReplyMsg ) /*0x1b9a20*/
      {
        v8 = IOMalloc(0x2000u); /*0x1b9a2b*/
        self->super.sndReplyMsg = ($8EF4127CF77ECA3DDB612FCF233DC3A8 *)v8; /*0x1b9a30*/
        *(_BYTE *)(v8 + 3) = 1; /*0x1b9a33*/
        *((_DWORD *)self->super.sndReplyMsg + 1) = 24; /*0x1b9a3a*/
        *((_DWORD *)self->super.sndReplyMsg + 2) = 0; /*0x1b9a44*/
        *((_DWORD *)self->super.sndReplyMsg + 3) = 0; /*0x1b9a4e*/
        *((_DWORD *)self->super.sndReplyMsg + 4) = 0; /*0x1b9a58*/
        *((_DWORD *)self->super.sndReplyMsg + 5) = 0; /*0x1b9a62*/
      }
      audio_snd_reply_recorded_data(self->super.sndReplyMsg, v6, a3->var5, v12, v3); /*0x1b9a80*/
      msg_send(self->super.sndReplyMsg, 33, 1000); /*0x1b9a90*/
    }
    else
    {
      _NXAudioReplyRecordedData(v6, v7, v6, self->super.tag, a3->var5, v12, v3); /*0x1b9a19*/
    }
  }
  return self; /*0x1b9a9a*/
}

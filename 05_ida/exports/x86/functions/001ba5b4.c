/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ba5b4. */
char __cdecl -[OutputStream playBuffer:size:tag:replyTo:replyMsgs:](
        OutputStream *self,
        SEL a2,
        void *a3,
        unsigned int a4,
        int a5,
        int a6,
        unsigned int a7)
{
  unsigned int v7; // edi
  unsigned int v8; // ebx
  int v9; // eax
  char v10; // al
  int v11; // eax
  $4BA88FAFA6E9A53AC825FB6F75E82BF2 *v13; // ebx
  unsigned int v14; // eax
  $BAB6C68F9D34F0972F921D3DB17D7446 *p_regionQueue; // edx
  queue_entry *prev; // eax
  id v17; // eax
  int v18; // [esp+10h] [ebp-18h]
  unsigned int v19; // [esp+18h] [ebp-10h]
  int v20; // [esp+20h] [ebp-8h]
  unsigned int v21; // [esp+24h] [ebp-4h] BYREF

  v7 = a4; /*0x1ba5c3*/
  v20 = IOConvertPort(a6, 2, 0); /*0x1ba5d3*/
  if ( !self->super.dataFormat ) /*0x1ba5d9*/
  {
    if ( self->super.channelCount == 1 ) /*0x1ba5e3*/
      v7 = a4 & 0xFFFFFFFE; /*0x1ba5e5*/
    else
      v7 = a4 & 0xFFFFFFFC; /*0x1ba5ec*/
  }
  v19 = (unsigned int)a3 & ~page_mask; /*0x1ba603*/
  v8 = ((unsigned int)a3 + v7 - v19 + page_mask) & ~page_mask; /*0x1ba614*/
  v18 = kern_serv_kernel_task_port(); /*0x1ba61b*/
  v9 = task_self(); /*0x1ba627*/
  if ( vm_protect_EXTERNAL(v9, v19, v8, 0, 1) )
    IOLog("Audio: vm_protect returned %d\n");
  if ( vm_allocate_EXTERNAL(v18, &v21, v8, 1) )
  {
    v10 = 0; /*0x1ba65e*/
  }
  else
  {
    if ( vm_write_EXTERNAL(v18, v21, v19, v8) )
      IOLog("Audio: vm_write returned %d\n");
    v11 = task_self(); /*0x1ba690*/
    if ( vm_deallocate_EXTERNAL(v11, v19, v8) )
      IOLog("Audio: vm_deallocate returned %d\n");
    v21 += (unsigned int)a3 - v19; /*0x1ba6b3*/
    v10 = 1; /*0x1ba6b6*/
  }
  if ( v10 )
  {
    v13 = -[AudioStream newRegion](self, sel_newRegion); /*0x1ba6f1*/
    v14 = v21; /*0x1ba6f3*/
    v13->var2 = v21; /*0x1ba6f6*/
    v13->var0 = v14; /*0x1ba6f9*/
    v13->var1 = v7 + v14; /*0x1ba6fd*/
    v13->var4 = v7; /*0x1ba700*/
    v13->var5 = a5; /*0x1ba706*/
    v13->var7 = v20; /*0x1ba70c*/
    v13->var6 = a7; /*0x1ba712*/
    self->super.userReplyMessages = a7; /*0x1ba715*/
    self->super.userReplyPort = v20; /*0x1ba71b*/
    objc_msgSend(self->super.regionQueueLock, sel_lock); /*0x1ba729*/
    p_regionQueue = &self->super.regionQueue; /*0x1ba731*/
    if ( ($BAB6C68F9D34F0972F921D3DB17D7446 *)self->super.regionQueue.next == &self->super.regionQueue ) /*0x1ba737*/
    {
      self->super.regionQueue.next = (queue_entry *)v13; /*0x1ba6d4*/
      self->super.regionQueue.prev = (queue_entry *)v13; /*0x1ba6d7*/
      v13->var11.var0 = (queue_entry *)p_regionQueue; /*0x1ba6da*/
      v13->var11.var1 = (queue_entry *)p_regionQueue; /*0x1ba6dd*/
    }
    else
    {
      prev = self->super.regionQueue.prev; /*0x1ba739*/
      v13->var11.var1 = prev; /*0x1ba73c*/
      v13->var11.var0 = (queue_entry *)p_regionQueue; /*0x1ba73f*/
      self->super.regionQueue.prev = (queue_entry *)v13; /*0x1ba742*/
      *((_DWORD *)prev + 15) = v13; /*0x1ba745*/
    }
    objc_msgSend(self->super.regionQueueLock, sel_unlock); /*0x1ba753*/
    v17 = -[AudioStream channel](self, sel_channel); /*0x1ba760*/
    objc_msgSend(self->super.device, sel__dataPendingForChannel_, v17); /*0x1ba771*/
    return 1; /*0x1ba776*/
  }
  else
  {
    IOLog("Audio: playback request (%d bytes) too large\n");
    return 0; /*0x1ba6ca*/
  }
}

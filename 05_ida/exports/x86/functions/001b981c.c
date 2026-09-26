/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b981c. */
char __cdecl -[InputStream recordSize:tag:replyTo:replyMsgs:](
        InputStream *self,
        SEL a2,
        unsigned int a3,
        int a4,
        int a5,
        unsigned int a6)
{
  unsigned int v6; // esi
  $4BA88FAFA6E9A53AC825FB6F75E82BF2 *v8; // ebx
  unsigned int v9; // eax
  $BAB6C68F9D34F0972F921D3DB17D7446 *p_regionQueue; // edx
  queue_entry *prev; // eax
  id v12; // eax
  int v13; // [esp+Ch] [ebp-Ch]
  int v14; // [esp+10h] [ebp-8h]
  unsigned int v15; // [esp+14h] [ebp-4h] BYREF

  v6 = a3; /*0x1b9828*/
  v13 = kern_serv_kernel_task_port(); /*0x1b9833*/
  v14 = IOConvertPort(v13, a5, a5, 2, 0); /*0x1b9840*/
  if ( !self->super.dataFormat ) /*0x1b9846*/
  {
    if ( self->super.channelCount == 1 ) /*0x1b9850*/
      v6 = a3 & 0xFFFFFFFE; /*0x1b9852*/
    else
      v6 = a3 & 0xFFFFFFFC; /*0x1b9858*/
  }
  if ( vm_allocate_EXTERNAL(v13, &v15, v6, 1) )
  {
    IOLog((int)"Audio: record request (%d bytes) too large\n", v6);
    return 0; /*0x1b987d*/
  }
  else
  {
    v8 = -[AudioStream newRegion](self, sel_newRegion); /*0x1b98a1*/
    v9 = v15; /*0x1b98a3*/
    v8->var0 = v15; /*0x1b98a6*/
    v8->var3 = v9; /*0x1b98a8*/
    v8->var2 = v9; /*0x1b98ab*/
    v8->var1 = v6 + v8->var0; /*0x1b98b2*/
    v8->var4 = v6; /*0x1b98b5*/
    v8->var5 = a4; /*0x1b98bb*/
    v8->var7 = v14; /*0x1b98c1*/
    v8->var6 = a6; /*0x1b98c7*/
    self->super.userReplyMessages = a6; /*0x1b98ca*/
    self->super.userReplyPort = v14; /*0x1b98d0*/
    objc_msgSend(self->super.regionQueueLock, sel_lock); /*0x1b98de*/
    p_regionQueue = &self->super.regionQueue; /*0x1b98e6*/
    if ( ($BAB6C68F9D34F0972F921D3DB17D7446 *)self->super.regionQueue.next == &self->super.regionQueue ) /*0x1b98ec*/
    {
      self->super.regionQueue.next = (queue_entry *)v8; /*0x1b9884*/
      self->super.regionQueue.prev = (queue_entry *)v8; /*0x1b9887*/
      v8->var11.var0 = (queue_entry *)p_regionQueue; /*0x1b988a*/
      v8->var11.var1 = (queue_entry *)p_regionQueue; /*0x1b988d*/
    }
    else
    {
      prev = self->super.regionQueue.prev; /*0x1b98ee*/
      v8->var11.var1 = prev; /*0x1b98f1*/
      v8->var11.var0 = (queue_entry *)p_regionQueue; /*0x1b98f4*/
      self->super.regionQueue.prev = (queue_entry *)v8; /*0x1b98f7*/
      *((_DWORD *)prev + 15) = v8; /*0x1b98fa*/
    }
    objc_msgSend(self->super.regionQueueLock, sel_unlock); /*0x1b9908*/
    v12 = -[AudioStream channel](self, sel_channel); /*0x1b9915*/
    objc_msgSend(self->super.device, sel__dataPendingForChannel_, v12); /*0x1b9926*/
    return 1; /*0x1b992b*/
  }
}

/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b89b8. */
id __cdecl -[AudioStream initChannel:tag:user:owner:type:](
        AudioStream *self,
        SEL a2,
        id a3,
        int a4,
        int *a5,
        int a6,
        unsigned int a7)
{
  NXLock *v7; // eax
  int v8; // eax
  int v10; // edx
  objc_super v11; // [esp+Ch] [ebp-8h] BYREF

  v11.receiver = self; /*0x1b89d1*/
  v11.super_class = (Class)stru_1FA4C4.super_class; /*0x1b89da*/
  -[Object init](&v11, sel_init); /*0x1b89e1*/
  self->channel = a3; /*0x1b89e6*/
  self->device = objc_msgSend(a3, sel_audioDevice); /*0x1b89f6*/
  self->tag = a4; /*0x1b89f9*/
  self->samplingRate = 22050; /*0x1b89fc*/
  self->dataFormat = 0; /*0x1b8a03*/
  self->channelCount = 2; /*0x1b8a0a*/
  self->regionQueue.prev = (queue_entry *)&self->regionQueue; /*0x1b8a14*/
  self->regionQueue.next = (queue_entry *)&self->regionQueue; /*0x1b8a17*/
  v7 = +[Object alloc](aNxlock, sel_alloc); /*0x1b8a2f*/
  self->regionQueueLock = -[NXLock init](v7, sel_init); /*0x1b8a3d*/
  v8 = task_self(); /*0x1b8a44*/
  if ( port_allocate_EXTERNAL(v8) )
  {
    IOLog((int)"Audio: initChannel: stream port_allocate: %s\n", "MACH ERR");
    -[AudioStream free](self, sel_free); /*0x1b8a6d*/
    return nullptr; /*0x1b8a72*/
  }
  else
  {
    v10 = *a5; /*0x1b8a7b*/
    self->userPort = *a5; /*0x1b8a7d*/
    self->kernUserPort = IOConvertPort(0, (int)a3, v10, 2, 0); /*0x1b8a8a*/
    self->ownerPort = a6; /*0x1b8a90*/
    self->type = a7; /*0x1b8a96*/
    return self; /*0x1b8a99*/
  }
}

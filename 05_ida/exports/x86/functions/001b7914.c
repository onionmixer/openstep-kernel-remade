/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b7914. */
id __cdecl -[AudioChannel initOnDevice:read:](AudioChannel *self, SEL a2, id a3, char a4)
{
  id v4; // eax
  List *v5; // eax
  NXLock *v6; // eax
  objc_super v8; // [esp+Ch] [ebp-8h] BYREF

  v8.receiver = self; /*0x1b792d*/
  v8.super_class = (Class)stru_1FA474.ext; /*0x1b7936*/
  -[Object init](&v8, sel_init); /*0x1b793d*/
  self->audioDevice = a3; /*0x1b7942*/
  self->_isRead = a4; /*0x1b7945*/
  if ( a4 ) /*0x1b794d*/
    v4 = +[Object class](aInputstream, sel_class); /*0x1b795c*/
  else
    v4 = +[Object class](aOutputstream, sel_class); /*0x1b796e*/
  self->streamClass = v4; /*0x1b7973*/
  self->exclusiveUser = 0; /*0x1b7979*/
  v5 = +[Object alloc](aList, sel_alloc); /*0x1b7995*/
  self->streamList = -[List init](v5, sel_init); /*0x1b79a3*/
  v6 = +[Object alloc](aNxlock, sel_alloc); /*0x1b79bb*/
  self->streamListLock = -[NXLock init](v6, sel_init); /*0x1b79c9*/
  self->dmaQueue.prev = (queue_entry *)&self->dmaQueue; /*0x1b79cf*/
  self->dmaQueue.next = (queue_entry *)&self->dmaQueue; /*0x1b79d2*/
  self->freeQueue.prev = (queue_entry *)&self->freeQueue; /*0x1b79d8*/
  self->freeQueue.next = (queue_entry *)&self->freeQueue; /*0x1b79db*/
  self->peakHistory = 1; /*0x1b79de*/
  self->channelBufferPtr = 0; /*0x1b79e5*/
  if ( (unsigned __int8)objc_msgSend(self->audioDevice, sel_isEISAPresent) ) /*0x1b79f7*/
    -[AudioChannel setDMASize:](self, sel_setDMASize_, 16 * page_size); /*0x1b7a0b*/
  else
    -[AudioChannel setDMASize:](self, sel_setDMASize_, 8 * page_size); /*0x1b7a26*/
  -[AudioChannel setDescriptorSize:](self, sel_setDescriptorSize_, page_size); /*0x1b7a3a*/
  return self; /*0x1b7a44*/
}

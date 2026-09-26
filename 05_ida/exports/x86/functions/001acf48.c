/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1acf48. */
id __cdecl -[SCSIDisk initResources](SCSIDisk *self, SEL a2)
{
  NXConditionLock *v2; // eax
  NXConditionLock *v3; // eax
  int i; // ebx

  self->_ioQueueDisk.prev = (queue_entry *)&self->_ioQueueDisk; /*0x1acf56*/
  self->_ioQueueDisk.next = (queue_entry *)&self->_ioQueueDisk; /*0x1acf5c*/
  self->_ioQueueNodisk.prev = (queue_entry *)&self->_ioQueueNodisk; /*0x1acf68*/
  self->_ioQueueNodisk.next = (queue_entry *)&self->_ioQueueNodisk; /*0x1acf6e*/
  v2 = +[Object alloc](aNxconditionloc, sel_alloc); /*0x1acf82*/
  self->_ioQLock = v2; /*0x1acf87*/
  -[NXConditionLock initWith:](v2, sel_initWith_, 0); /*0x1acf97*/
  -[SCSIDisk setLastReadyState:](self, sel_setLastReadyState_, 1); /*0x1acfa6*/
  v3 = +[Object alloc](aNxconditionloc, sel_alloc); /*0x1acfbc*/
  self->_ejectLock = v3; /*0x1acfc1*/
  -[NXConditionLock initWith:](v3, sel_initWith_, 0); /*0x1acfd1*/
  self->_numDiskIos = 0; /*0x1acfd6*/
  self->_ejectPending = 0; /*0x1acfe0*/
  *((_BYTE *)self + 394) &= 0xFCu; /*0x1acfe7*/
  self->_numThreads = 0; /*0x1acfee*/
  for ( i = 0; i <= 5; ++i ) /*0x1acff8*/
  {
    self->_thread[i] = (void *)IOForkThread((int)sdIoThread, (int)self); /*0x1ad00b*/
    ++self->_numThreads; /*0x1ad012*/
  }
  return self; /*0x1ad026*/
}

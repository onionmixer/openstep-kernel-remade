/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b1548. */
int __cdecl -[EventDriver mapEventShmem:task:size:at:](
        EventDriver *self,
        SEL a2,
        int a3,
        int a4,
        unsigned int a5,
        unsigned int *a6)
{
  int v7; // eax
  int v8; // ebx
  const char *v9; // eax
  int v10; // [esp-4h] [ebp-18h]
  unsigned int v11; // [esp+Ch] [ebp-8h] BYREF
  void *v12; // [esp+10h] [ebp-4h] BYREF

  if ( a3 != self->eventPort || !self->evOpenCalled ) /*0x1b1562*/
    return -705; /*0x1b156b*/
  if ( !a4 || !a5 || self->owner_task || self->owner ) /*0x1b158b*/
    return -706; /*0x1b1594*/
  v7 = createEventShmem(a4, a5, (int *)&v12, &v11, (int *)&self->shmem_addr); /*0x1b15b4*/
  v8 = v7; /*0x1b15b9*/
  if ( v7 )
  {
    v10 = v7; /*0x1b15c2*/
    v9 = -[IODevice name](self, sel_name); /*0x1b15cb*/
    IOLog((int)"%s: createEventShmem fails (%d).\n", v9, v10);
    return v8; /*0x1b15de*/
  }
  else
  {
    objc_msgSend(self->driverLock, sel_lock); /*0x1b15f6*/
    self->shmem_size = a5; /*0x1b15fb*/
    self->owner_task = a4; /*0x1b1604*/
    self->owner_addr = v11; /*0x1b160d*/
    *a6 = v11; /*0x1b1619*/
    self->owner = v12; /*0x1b161e*/
    -[EventDriver initShmem](self, sel_initShmem); /*0x1b162c*/
    objc_msgSend(self->driverLock, sel_unlock); /*0x1b163f*/
    -[EventDriver _resetMouseParameters](self, sel__resetMouseParameters); /*0x1b164c*/
    -[EventDriver _resetKeyboardParameters](self, sel__resetKeyboardParameters); /*0x1b165c*/
    objc_msgSend(self->driverLock, sel_lock); /*0x1b166f*/
    -[EventDriver scheduleNextPeriodicEvent](self, sel_scheduleNextPeriodicEvent); /*0x1b167c*/
    objc_msgSend(self->driverLock, sel_unlock); /*0x1b168f*/
    return 0; /*0x1b1694*/
  }
}

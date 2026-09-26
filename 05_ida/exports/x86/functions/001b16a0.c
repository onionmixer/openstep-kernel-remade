/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b16a0. */
int __cdecl -[EventDriver unmapEventShmem:](EventDriver *self, SEL a2, int a3)
{
  int v4; // eax
  int v5; // ebx
  const char *v6; // eax
  int v7; // [esp-4h] [ebp-Ch]

  objc_msgSend(self->driverLock, sel_lock); /*0x1b16b9*/
  if ( self->eventPort == a3 && self->evOpenCalled && self->eventsOpen )
  {
    self->eventsOpen = 0; /*0x1b16f8*/
    v4 = destroyEventShmem(self->owner_task, (int)self->owner, self->shmem_size, self->owner_addr, self->shmem_addr); /*0x1b1722*/
    v5 = v4; /*0x1b1727*/
    if ( v4 )
    {
      v7 = v4; /*0x1b1730*/
      v6 = -[IODevice name](self, sel_name); /*0x1b1739*/
      IOLog((int)"%s: destroyEventShmem fails (%d).\n", v6, v7);
    }
    self->owner_addr = 0; /*0x1b174f*/
    self->shmem_addr = 0; /*0x1b1759*/
    self->shmem_size = 0; /*0x1b1763*/
    self->owner = nullptr; /*0x1b176d*/
    self->owner_task = 0; /*0x1b1777*/
    objc_msgSend(self->driverLock, sel_unlock); /*0x1b178f*/
    return v5; /*0x1b1794*/
  }
  else
  {
    objc_msgSend(self->driverLock, sel_unlock); /*0x1b16e9*/
    return -705; /*0x1b16ee*/
  }
}

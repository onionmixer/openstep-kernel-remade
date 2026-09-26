/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b3298. */
id __cdecl -[EventDriver updateEventFlags:](EventDriver *self, SEL a2, unsigned int a3)
{
  objc_msgSend(self->driverLock, sel_lock); /*0x1b32ae*/
  if ( self->eventsOpen ) /*0x1b32b6*/
    *((_DWORD *)self->evg + 3) = a3 & 0x7F007F | *((_DWORD *)self->evg + 3) & 0xFF80FF80; /*0x1b32d9*/
  objc_msgSend(self->driverLock, sel_unlock); /*0x1b32ea*/
  return self; /*0x1b32f4*/
}

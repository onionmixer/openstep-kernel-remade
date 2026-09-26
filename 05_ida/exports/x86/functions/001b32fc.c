/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b32fc. */
int __cdecl -[EventDriver eventFlags](EventDriver *self, SEL a2)
{
  int v2; // esi

  v2 = 0; /*0x1b3304*/
  objc_msgSend(self->driverLock, sel_lock); /*0x1b3314*/
  if ( self->eventsOpen ) /*0x1b331c*/
    v2 = *((_DWORD *)self->evg + 3); /*0x1b332b*/
  objc_msgSend(self->driverLock, sel_unlock); /*0x1b333c*/
  return v2; /*0x1b3346*/
}

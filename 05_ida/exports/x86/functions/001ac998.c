/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ac998. */
void __cdecl -[SCSIDisk diskBecameReady](SCSIDisk *self, SEL a2)
{
  objc_msgSend(self->_ioQLock, sel_lock); /*0x1ac9ad*/
  objc_msgSend(self->_ioQLock, sel_unlockWith_, 1); /*0x1ac9c2*/
}

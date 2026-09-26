/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bac0c. */
void __cdecl -[AudioCommand done:](AudioCommand *self, SEL a2, int a3)
{
  if ( objc_msgSend(self->interLock, sel_condition) == (id)2 ) /*0x1bac29*/
  {
    objc_msgSend(self->interLock, sel_lock); /*0x1bac36*/
    self->ret = a3; /*0x1bac3e*/
    objc_msgSend(self->interLock, sel_unlockWith_, 1); /*0x1bac4e*/
  }
}

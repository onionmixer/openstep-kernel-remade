/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1aafdc. */
void __cdecl -[DriverCmdtr done:](DriverCmdtr *self, SEL a2, int a3)
{
  if ( objc_msgSend(self->_interLock, sel_condition) == (id)2 ) /*0x1aaff9*/
  {
    objc_msgSend(self->_interLock, sel_lock); /*0x1ab006*/
    self->_ret = a3; /*0x1ab00e*/
    objc_msgSend(self->_interLock, sel_unlockWith_, 1); /*0x1ab01e*/
  }
}

/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1aa058. */
void __cdecl -[DriverCmd done:](DriverCmd *self, SEL a2, int a3)
{
  if ( objc_msgSend(self->_interLock, sel_condition) == (id)2 ) /*0x1aa075*/
  {
    objc_msgSend(self->_interLock, sel_lock); /*0x1aa082*/
    self->_ret = a3; /*0x1aa08a*/
    objc_msgSend(self->_interLock, sel_unlockWith_, 1); /*0x1aa09a*/
  }
}

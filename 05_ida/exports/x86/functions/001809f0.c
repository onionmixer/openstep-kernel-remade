/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1809f0. */
id __cdecl -[KernDeviceInterrupt resume](KernDeviceInterrupt *self, SEL a2)
{
  id busInterrupt; // edi
  char isSuspended; // bl

  objc_msgSend(self->_lock, sel_acquire); /*0x180a04*/
  busInterrupt = self->_busInterrupt; /*0x180a0c*/
  if ( busInterrupt ) /*0x180a11*/
  {
    isSuspended = self->_isSuspended; /*0x180a28*/
    self->_isSuspended = 0; /*0x180a2b*/
    objc_msgSend(self->_lock, sel_release); /*0x180a3a*/
    if ( isSuspended ) /*0x180a44*/
      objc_msgSend(busInterrupt, sel_resume); /*0x180a4e*/
    return self; /*0x180a53*/
  }
  else
  {
    objc_msgSend(self->_lock, sel_release); /*0x180a1e*/
    return nullptr; /*0x180a23*/
  }
}

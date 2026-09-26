/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1808ec. */
id __cdecl -[KernDeviceInterrupt detach](KernDeviceInterrupt *self, SEL a2)
{
  id busInterrupt; // edi
  char isSuspended; // bl

  objc_msgSend(self->_lock, sel_acquire); /*0x180900*/
  busInterrupt = self->_busInterrupt; /*0x180908*/
  if ( busInterrupt ) /*0x18090d*/
  {
    self->_busInterrupt = nullptr; /*0x180924*/
    isSuspended = self->_isSuspended; /*0x18092b*/
    self->_isSuspended = 0; /*0x18092e*/
    objc_msgSend(self->_lock, sel_release); /*0x18093d*/
    if ( !isSuspended ) /*0x180947*/
      objc_msgSend(busInterrupt, sel_suspend); /*0x180951*/
    objc_msgSend(busInterrupt, sel_detachDeviceInterrupt_, self); /*0x180962*/
    objc_msgSend(busInterrupt, sel_resume); /*0x18096f*/
    return self; /*0x180974*/
  }
  else
  {
    objc_msgSend(self->_lock, sel_release); /*0x18091a*/
    return nullptr; /*0x18091f*/
  }
}

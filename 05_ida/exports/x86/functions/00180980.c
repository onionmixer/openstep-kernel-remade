/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x180980. */
id __cdecl -[KernDeviceInterrupt suspend](KernDeviceInterrupt *self, SEL a2)
{
  id busInterrupt; // edi
  char isSuspended; // bl

  objc_msgSend(self->_lock, sel_acquire); /*0x180994*/
  busInterrupt = self->_busInterrupt; /*0x18099c*/
  if ( busInterrupt ) /*0x1809a1*/
  {
    isSuspended = self->_isSuspended; /*0x1809b8*/
    self->_isSuspended = 1; /*0x1809bb*/
    objc_msgSend(self->_lock, sel_release); /*0x1809ca*/
    if ( !isSuspended ) /*0x1809d4*/
      objc_msgSend(busInterrupt, sel_suspend); /*0x1809de*/
    return self; /*0x1809e3*/
  }
  else
  {
    objc_msgSend(self->_lock, sel_release); /*0x1809ae*/
    return nullptr; /*0x1809b3*/
  }
}

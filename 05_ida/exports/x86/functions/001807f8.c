/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1807f8. */
id __cdecl -[KernDeviceInterrupt attachToBusInterrupt:withSpecialHandler:argument:atLevel:](
        KernDeviceInterrupt *self,
        SEL a2,
        id a3,
        void *a4,
        void *a5,
        int a6)
{
  objc_msgSend(self->_lock, sel_acquire); /*0x18080e*/
  if ( self->_busInterrupt ) /*0x180816*/
  {
    objc_msgSend(self->_lock, sel_release); /*0x180827*/
    return nullptr; /*0x18082c*/
  }
  else
  {
    self->_busInterrupt = a3; /*0x180834*/
    objc_msgSend(self->_lock, sel_release); /*0x180842*/
    objc_msgSend(a3, sel_suspend); /*0x18084f*/
    if ( objc_msgSend(self->_busInterrupt, sel_attachDeviceInterrupt_atLevel_, self, a6) ) /*0x180864*/
    {
      objc_msgSend(self->_lock, sel_acquire); /*0x1808b3*/
      self->_handler = a4; /*0x1808bb*/
      self->_handlerArgument = a5; /*0x1808c1*/
      objc_msgSend(self->_lock, sel_release); /*0x1808cf*/
      objc_msgSend(a3, sel_resume); /*0x1808dc*/
      return self; /*0x1808e1*/
    }
    else
    {
      objc_msgSend(a3, sel_resume); /*0x180878*/
      objc_msgSend(self->_lock, sel_acquire); /*0x180888*/
      self->_busInterrupt = nullptr; /*0x18088d*/
      objc_msgSend(self->_lock, sel_release); /*0x18089f*/
      return nullptr; /*0x1808a4*/
    }
  }
}

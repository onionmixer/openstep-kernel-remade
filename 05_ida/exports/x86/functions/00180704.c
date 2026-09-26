/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x180704. */
id __cdecl -[KernDeviceInterrupt attachToBusInterrupt:withArgument:](
        KernDeviceInterrupt *self,
        SEL a2,
        id a3,
        void *a4)
{
  objc_msgSend(self->_lock, sel_acquire); /*0x18071a*/
  if ( self->_busInterrupt ) /*0x180722*/
  {
    objc_msgSend(self->_lock, sel_release); /*0x180733*/
    return nullptr; /*0x180738*/
  }
  else
  {
    self->_busInterrupt = a3; /*0x180740*/
    objc_msgSend(self->_lock, sel_release); /*0x18074e*/
    objc_msgSend(a3, sel_suspend); /*0x18075b*/
    if ( objc_msgSend(a3, sel_attachDeviceInterrupt_, self) ) /*0x180769*/
    {
      objc_msgSend(self->_lock, sel_acquire); /*0x1807bb*/
      self->_handler = IOSendInterrupt; /*0x1807c0*/
      self->_handlerArgument = a4; /*0x1807ca*/
      objc_msgSend(self->_lock, sel_release); /*0x1807d8*/
      objc_msgSend(a3, sel_resume); /*0x1807e5*/
      return self; /*0x1807ea*/
    }
    else
    {
      objc_msgSend(a3, sel_resume); /*0x18077d*/
      objc_msgSend(self->_lock, sel_acquire); /*0x18078d*/
      self->_busInterrupt = nullptr; /*0x180792*/
      objc_msgSend(self->_lock, sel_release); /*0x1807a4*/
      return nullptr; /*0x1807a9*/
    }
  }
}

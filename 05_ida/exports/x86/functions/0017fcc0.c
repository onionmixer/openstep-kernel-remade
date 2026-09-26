/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17fcc0. */
id __cdecl -[KernBusInterrupt free](KernBusInterrupt *self, SEL a2)
{
  objc_super v3; // [esp+4h] [ebp-8h] BYREF

  objc_msgSend(self->_interruptLock, sel_acquire); /*0x17fcd5*/
  if ( self->_attachedInterruptCount <= 0 ) /*0x17fce1*/
  {
    objc_msgSend(self->_interruptLock, sel_release); /*0x17fd03*/
    v3.receiver = self; /*0x17fd0f*/
    v3.super_class = (Class)stru_1F9F24.ext; /*0x17fd18*/
    return -[KernBusItem free](&v3, sel_free); /*0x17fd1f*/
  }
  else
  {
    objc_msgSend(self->_interruptLock, sel_release); /*0x17fcee*/
    return self; /*0x17fcf3*/
  }
}

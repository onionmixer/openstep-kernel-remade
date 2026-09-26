/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17fd2c. */
id __cdecl -[KernBusInterrupt dealloc](KernBusInterrupt *self, SEL a2)
{
  int suspendCount; // edx
  objc_super v4; // [esp+4h] [ebp-8h] BYREF

  objc_msgSend(self->_interruptLock, sel_acquire); /*0x17fd41*/
  if ( self->_attachedInterruptCount <= 0 ) /*0x17fd4d*/
  {
    objc_msgSend(self->_suspendLock, sel_acquire); /*0x17fd73*/
    suspendCount = self->_suspendCount; /*0x17fd78*/
    self->_suspendCount = suspendCount + 1; /*0x17fd7e*/
    if ( suspendCount + 1 < 0 ) /*0x17fd89*/
      self->_suspendCount = suspendCount; /*0x17fd8b*/
    objc_msgSend(self->_suspendLock, sel_release); /*0x17fd99*/
    objc_msgSend(self->_interruptLock, sel_release); /*0x17fda9*/
    objc_msgSend(self->_attachedInterrupts, sel_free); /*0x17fdb9*/
    objc_msgSend(self->_suspendLock, sel_free); /*0x17fdc9*/
    objc_msgSend(self->_interruptLock, sel_free); /*0x17fddc*/
    v4.receiver = self; /*0x17fde8*/
    v4.super_class = (Class)stru_1F9F24.ext; /*0x17fdf1*/
    return -[KernBusItem dealloc](&v4, sel_dealloc); /*0x17fdf8*/
  }
  else
  {
    objc_msgSend(self->_interruptLock, sel_release); /*0x17fd5a*/
    return self; /*0x17fd5f*/
  }
}

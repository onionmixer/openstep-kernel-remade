/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17fec0. */
id __cdecl -[KernBusInterrupt detachDeviceInterrupt:](KernBusInterrupt *self, SEL a2, id a3)
{
  KernBusInterrupt *v3; // ebx

  objc_msgSend(self->_interruptLock, sel_acquire); /*0x17fed6*/
  if ( objc_msgSend(self->_attachedInterrupts, sel_removeObject_, a3) ) /*0x17fee7*/
    --self->_attachedInterruptCount; /*0x17fef3*/
  objc_msgSend(self->_suspendLock, sel_acquire); /*0x17ff01*/
  v3 = nullptr; /*0x17ff09*/
  if ( self->_attachedInterruptCount > 0 && !self->_suspendCount ) /*0x17ff11*/
    v3 = self; /*0x17ff17*/
  objc_msgSend(self->_suspendLock, sel_release); /*0x17ff24*/
  objc_msgSend(self->_interruptLock, sel_release); /*0x17ff34*/
  return v3; /*0x17ff3e*/
}

/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17fe04. */
id __cdecl -[KernBusInterrupt attachDeviceInterrupt:](KernBusInterrupt *self, SEL a2, id a3)
{
  KernBusInterrupt *v3; // esi

  objc_msgSend(self->_interruptLock, sel_acquire); /*0x17fe1a*/
  if ( objc_msgSend(self->_attachedInterrupts, sel_indexOf_, a3) == (id)-1 /*0x17fe44*/
    && objc_msgSend(self->_attachedInterrupts, sel_addObject_, a3) )
  {
    ++self->_attachedInterruptCount; /*0x17fe50*/
  }
  objc_msgSend(self->_suspendLock, sel_acquire); /*0x17fe5e*/
  v3 = nullptr; /*0x17fe66*/
  if ( self->_attachedInterruptCount > 0 && !self->_suspendCount ) /*0x17fe6e*/
    v3 = self; /*0x17fe74*/
  objc_msgSend(self->_suspendLock, sel_release); /*0x17fe81*/
  objc_msgSend(self->_interruptLock, sel_release); /*0x17fe91*/
  return v3; /*0x17fe9b*/
}

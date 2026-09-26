/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17ff8c. */
id __cdecl -[KernBusInterrupt resume](KernBusInterrupt *self, SEL a2)
{
  int suspendCount; // eax
  KernBusInterrupt *v3; // esi

  objc_msgSend(self->_suspendLock, sel_acquire); /*0x17ff9f*/
  suspendCount = self->_suspendCount; /*0x17ffa4*/
  if ( suspendCount > 0 ) /*0x17ffac*/
    self->_suspendCount = suspendCount - 1; /*0x17ffaf*/
  v3 = nullptr; /*0x17ffb2*/
  if ( !self->_suspendCount ) /*0x17ffb4*/
    v3 = self; /*0x17ffba*/
  objc_msgSend(self->_suspendLock, sel_release); /*0x17ffc7*/
  return v3; /*0x17ffd1*/
}

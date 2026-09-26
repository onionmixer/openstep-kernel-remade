/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17ff44. */
id __cdecl -[KernBusInterrupt suspend](KernBusInterrupt *self, SEL a2)
{
  int suspendCount; // edx

  objc_msgSend(self->_suspendLock, sel_acquire); /*0x17ff56*/
  suspendCount = self->_suspendCount; /*0x17ff5b*/
  self->_suspendCount = suspendCount + 1; /*0x17ff61*/
  if ( suspendCount + 1 < 0 ) /*0x17ff6c*/
    self->_suspendCount = suspendCount; /*0x17ff6e*/
  objc_msgSend(self->_suspendLock, sel_release); /*0x17ff7c*/
  return self; /*0x17ff83*/
}

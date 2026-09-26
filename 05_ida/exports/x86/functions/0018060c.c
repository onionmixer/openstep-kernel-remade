/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18060c. */
void __cdecl -[KernDevice _detachInterruptSources](KernDevice *self, SEL a2)
{
  id interrupts; // eax
  id v3; // eax

  interrupts = self->_interrupts; /*0x180613*/
  if ( interrupts ) /*0x180618*/
  {
    v3 = objc_msgSend(interrupts, sel_freeObjects); /*0x180629*/
    objc_msgSend(v3, sel_free); /*0x180632*/
    self->_interrupts = nullptr; /*0x180637*/
  }
}

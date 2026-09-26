/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1805a8. */
id __cdecl -[KernDevice detachInterruptPort](KernDevice *self, SEL a2)
{
  if ( self->_interruptPort ) /*0x1805af*/
  {
    -[KernDevice _detachInterruptSources](self, sel__detachInterruptSources); /*0x1805bd*/
    ipc_port_release_send((int)self->_interruptPort); /*0x1805c6*/
    self->_interruptPort = nullptr; /*0x1805cb*/
  }
  return self; /*0x1805d4*/
}

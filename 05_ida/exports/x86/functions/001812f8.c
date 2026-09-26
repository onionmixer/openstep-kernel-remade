/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1812f8. */
id __cdecl -[KernDeviceDescription setDevice:](KernDeviceDescription *self, SEL a2, id a3)
{
  id result; // eax

  result = a3; /*0x1812fe*/
  if ( !self->_device || !a3 ) /*0x181309*/
    self->_device = a3; /*0x18130b*/
  if ( self->_device != a3 ) /*0x181311*/
    return nullptr; /*0x181313*/
  return result; /*0x181317*/
}

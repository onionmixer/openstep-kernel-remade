/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a85d8. */
void __cdecl -[IODirectDevice setDeviceDescription:](IODirectDevice *self, SEL a2, id a3)
{
  self->_deviceDescription = (IODeviceDescription *)a3; /*0x1a85e2*/
  self->_deviceDescriptionDelegate = objc_msgSend(a3, sel__delegate); /*0x1a85f5*/
}

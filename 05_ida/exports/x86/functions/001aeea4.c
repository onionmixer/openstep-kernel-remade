/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1aeea4. */
int __cdecl -[SCSIGeneric resetSCSIBus](SCSIGeneric *self, SEL a2)
{
  return (int)objc_msgSend(self->_controller, sel_resetSCSIBus); /*0x1aeebf*/
}

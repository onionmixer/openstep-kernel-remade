/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c1c38. */
id __cdecl -[IOPCIDeviceDescription free](IOPCIDeviceDescription *self, SEL a2)
{
  objc_super v3; // [esp+4h] [ebp-8h] BYREF

  IOFree((int)self->_pci_private, 4); /*0x1c1c48*/
  v3.receiver = self; /*0x1c1c54*/
  v3.super_class = (Class)stru_1FA564.ext; /*0x1c1c5d*/
  return -[IOEISADeviceDescription free](&v3, sel_free); /*0x1c1c69*/
}

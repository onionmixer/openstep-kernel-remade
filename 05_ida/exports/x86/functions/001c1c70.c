/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c1c70. */
int __cdecl -[IOPCIDeviceDescription getPCIdevice:function:bus:](
        IOPCIDeviceDescription *self,
        SEL a2,
        char *a3,
        char *a4,
        char *a5)
{
  _BYTE *pci_private; // eax

  pci_private = self->_pci_private; /*0x1c1c81*/
  if ( !*pci_private ) /*0x1c1c84*/
    return -704; /*0x1c1ca8*/
  if ( a3 ) /*0x1c1c8b*/
    *a3 = pci_private[1]; /*0x1c1c90*/
  if ( a4 ) /*0x1c1c94*/
    *a4 = pci_private[2]; /*0x1c1c99*/
  if ( a5 ) /*0x1c1c9d*/
    *a5 = pci_private[3]; /*0x1c1ca2*/
  return 0; /*0x1c1cb0*/
}

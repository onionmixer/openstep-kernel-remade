/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c2154. */
unsigned int __cdecl -[IOPCMCIADeviceDescription numTuples](IOPCMCIADeviceDescription *self, SEL a2)
{
  unsigned int *pcmcia_private; // ebx

  pcmcia_private = (unsigned int *)self->_pcmcia_private; /*0x1c215b*/
  if ( !*pcmcia_private ) /*0x1c215e*/
    -[IOPCMCIADeviceDescription tupleList](self, sel_tupleList); /*0x1c216b*/
  return *pcmcia_private; /*0x1c2172*/
}

/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c0b40. */
int __cdecl -[IODirectDevice enableChannel:](IODirectDevice *self, SEL a2, unsigned int a3)
{
  id v3; // eax

  if ( a3 >= (unsigned int)-[IODeviceDescription numChannels](self->_deviceDescription, sel_numChannels) ) /*0x1c0b63*/
    return -706; /*0x1c0b80*/
  v3 = -[IODirectDevice _localToChannel:](self, sel__localToChannel_, a3); /*0x1c0b6e*/
  dma_unmask_chan((signed int)v3); /*0x1c0b74*/
  return 0; /*0x1c0b88*/
}

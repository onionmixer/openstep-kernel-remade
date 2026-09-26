/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c0e60. */
unsigned int __cdecl -[IODirectDevice currentAddressForChannel:](IODirectDevice *self, SEL a2, unsigned int a3)
{
  id v3; // eax

  if ( a3 >= (unsigned int)-[IODeviceDescription numChannels](self->_deviceDescription, sel_numChannels) ) /*0x1c0e83*/
    return 0; /*0x1c0e9c*/
  v3 = -[IODirectDevice _localToChannel:](self, sel__localToChannel_, a3); /*0x1c0e8e*/
  return get_dma_addr((int)v3); /*0x1c0ea1*/
}

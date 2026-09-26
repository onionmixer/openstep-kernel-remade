/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c0b90. */
void __cdecl -[IODirectDevice disableChannel:](IODirectDevice *self, SEL a2, unsigned int a3)
{
  id v3; // eax

  if ( a3 < (unsigned int)-[IODeviceDescription numChannels](self->_deviceDescription, sel_numChannels) ) /*0x1c0bb3*/
  {
    v3 = -[IODirectDevice _localToChannel:](self, sel__localToChannel_, a3); /*0x1c0bbe*/
    dma_mask_chan((signed int)v3); /*0x1c0bc4*/
  }
}

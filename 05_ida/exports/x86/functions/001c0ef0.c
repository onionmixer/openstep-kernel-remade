/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c0ef0. */
char __cdecl -[IODirectDevice isDMADone:](IODirectDevice *self, SEL a2, unsigned int a3)
{
  id v3; // eax

  if ( a3 >= (unsigned int)-[IODeviceDescription numChannels](self->_deviceDescription, sel_numChannels) ) /*0x1c0f13*/
    return 0; /*0x1c0f38*/
  v3 = -[IODirectDevice _localToChannel:](self, sel__localToChannel_, a3); /*0x1c0f1e*/
  return is_dma_done((int)v3) != 0; /*0x1c0f3d*/
}

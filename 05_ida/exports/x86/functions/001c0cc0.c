/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c0cc0. */
int __cdecl -[IODirectDevice setIncrementMode:forChannel:](IODirectDevice *self, SEL a2, int a3, unsigned int a4)
{
  id v5; // eax

  if ( a3 == 1 ) /*0x1c0ccf*/
    return -711; /*0x1c0cd1*/
  if ( a4 >= (unsigned int)-[IODeviceDescription numChannels](self->_deviceDescription, sel_numChannels) ) /*0x1c0cf0*/
    return -706; /*0x1c0d10*/
  v5 = -[IODirectDevice _localToChannel:](self, sel__localToChannel_, a4); /*0x1c0cfb*/
  dma_chan_adrs_dir((signed int)v5, 0); /*0x1c0d06*/
  return 0; /*0x1c0d18*/
}

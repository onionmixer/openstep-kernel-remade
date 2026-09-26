/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c0c58. */
int __cdecl -[IODirectDevice setAutoinitialize:forChannel:](IODirectDevice *self, SEL a2, char a3, unsigned int a4)
{
  id v4; // eax

  if ( a4 >= (unsigned int)-[IODeviceDescription numChannels](self->_deviceDescription, sel_numChannels) ) /*0x1c0c84*/
    return -706; /*0x1c0cb0*/
  v4 = -[IODirectDevice _localToChannel:](self, sel__localToChannel_, a4); /*0x1c0c8f*/
  dma_chan_autoinit((signed int)v4, a3 != 0); /*0x1c0ca7*/
  return 0; /*0x1c0cb8*/
}

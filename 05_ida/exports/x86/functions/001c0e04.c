/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c0e04. */
int __cdecl -[IODirectDevice startDMAForBuffer:channel:](IODirectDevice *self, SEL a2, void *a3, unsigned int a4)
{
  id v5; // eax

  if ( a4 >= (unsigned int)-[IODeviceDescription numChannels](self->_deviceDescription, sel_numChannels) ) /*0x1c0e27*/
    return -706; /*0x1c0e29*/
  v5 = -[IODirectDevice _localToChannel:](self, sel__localToChannel_, a4); /*0x1c0e39*/
  if ( dma_xfer_chan((int)v5, (int)a3) ) /*0x1c0e43*/
    return 0; /*0x1c0e54*/
  else
    return -736; /*0x1c0e4c*/
}

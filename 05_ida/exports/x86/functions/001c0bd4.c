/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c0bd4. */
int __cdecl -[IODirectDevice setTransferMode:forChannel:](IODirectDevice *self, SEL a2, int a3, unsigned int a4)
{
  char v4; // bl
  id v6; // eax

  if ( a4 >= (unsigned int)-[IODeviceDescription numChannels](self->_deviceDescription, sel_numChannels) ) /*0x1c0bfb*/
    return -706; /*0x1c0bfd*/
  v6 = -[IODirectDevice _localToChannel:](self, sel__localToChannel_, a4); /*0x1c0c10*/
  if ( a3 == 1 ) /*0x1c0c1b*/
  {
    v4 = 1; /*0x1c0c30*/
  }
  else if ( a3 ) /*0x1c0c1d*/
  {
    if ( a3 == 2 ) /*0x1c0c22*/
    {
      v4 = 2; /*0x1c0c38*/
    }
    else if ( a3 == 3 ) /*0x1c0c27*/
    {
      v4 = 3; /*0x1c0c40*/
    }
  }
  else
  {
    v4 = 0; /*0x1c0c2c*/
  }
  dma_chan_xfer_mode((signed int)v6, v4); /*0x1c0c47*/
  return 0; /*0x1c0c51*/
}

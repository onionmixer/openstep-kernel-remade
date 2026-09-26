/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c105c. */
int __cdecl -[IODirectDevice setDMATransferWidth:forChannel:](IODirectDevice *self, SEL a2, int a3, unsigned int a4)
{
  id v5; // eax
  id v6; // eax
  char v7; // dl

  if ( a3 == 1 || is_ISA ) /*0x1c1077*/
    return -711; /*0x1c107e*/
  v5 = -[IODirectDevice deviceDescription](self, sel_deviceDescription); /*0x1c108f*/
  if ( a4 >= (unsigned int)objc_msgSend(v5, sel_numChannels) ) /*0x1c10a2*/
    return -706; /*0x1c10a2*/
  v6 = -[IODirectDevice _localToChannel:](self, sel__localToChannel_, a4); /*0x1c10b5*/
  if ( a3 ) /*0x1c10c0*/
  {
    if ( a3 == 2 ) /*0x1c10c5*/
    {
      v7 = 3; /*0x1c10d4*/
    }
    else
    {
      if ( a3 != 3 ) /*0x1c10ca*/
        return -706; /*0x1c10a9*/
      v7 = 2; /*0x1c10dc*/
    }
  }
  else
  {
    v7 = 0; /*0x1c10d0*/
  }
  dma_xfer_width((signed int)v6, v7); /*0x1c10e3*/
  return 0; /*0x1c10ed*/
}

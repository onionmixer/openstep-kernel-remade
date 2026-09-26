/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c10f4. */
int __cdecl -[IODirectDevice getDMATransferWidth:forChannel:](IODirectDevice *self, SEL a2, int *a3, unsigned int a4)
{
  id v4; // eax
  id v6; // eax
  int dma_xfer_width; // eax

  v4 = -[IODirectDevice deviceDescription](self, sel_deviceDescription); /*0x1c1112*/
  if ( a4 >= (unsigned int)objc_msgSend(v4, sel_numChannels) ) /*0x1c1125*/
    return -706; /*0x1c112c*/
  v6 = -[IODirectDevice _localToChannel:](self, sel__localToChannel_, a4); /*0x1c1139*/
  dma_xfer_width = get_dma_xfer_width((unsigned int)v6); /*0x1c113f*/
  if ( dma_xfer_width == 1 ) /*0x1c1147*/
  {
    *a3 = 1; /*0x1c1168*/
  }
  else if ( dma_xfer_width > 1 ) /*0x1c1149*/
  {
    if ( dma_xfer_width == 2 ) /*0x1c1157*/
    {
      *a3 = 3; /*0x1c1178*/
    }
    else
    {
      if ( dma_xfer_width != 3 ) /*0x1c115c*/
        return -729; /*0x1c115c*/
      *a3 = 2; /*0x1c1170*/
    }
  }
  else
  {
    if ( dma_xfer_width ) /*0x1c114d*/
      return -729; /*0x1c1185*/
    *a3 = 0; /*0x1c1160*/
  }
  return 0; /*0x1c118d*/
}

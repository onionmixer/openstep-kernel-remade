/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c1234. */
int __cdecl -[IODirectDevice setEOPAsOutput:forChannel:](IODirectDevice *self, SEL a2, char a3, unsigned int a4)
{
  id v5; // eax
  id v6; // eax

  if ( is_ISA ) /*0x1c124a*/
    return -711; /*0x1c124c*/
  v5 = -[IODirectDevice deviceDescription](self, sel_deviceDescription); /*0x1c1263*/
  if ( a4 >= (unsigned int)objc_msgSend(v5, sel_numChannels) ) /*0x1c1276*/
    return -706; /*0x1c12a0*/
  v6 = -[IODirectDevice _localToChannel:](self, sel__localToChannel_, a4); /*0x1c1281*/
  dma_eop_in((signed int)v6, a3 == 0); /*0x1c1297*/
  return 0; /*0x1c12a8*/
}

/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c12b0. */
int __cdecl -[IODirectDevice setStopRegisterMode:forChannel:](IODirectDevice *self, SEL a2, int a3, unsigned int a4)
{
  id v5; // eax
  id v6; // eax

  if ( !a3 || is_ISA ) /*0x1c12c8*/
    return -711; /*0x1c12ca*/
  v5 = -[IODirectDevice deviceDescription](self, sel_deviceDescription); /*0x1c12e3*/
  if ( a4 >= (unsigned int)objc_msgSend(v5, sel_numChannels) ) /*0x1c12f6*/
    return -706; /*0x1c1318*/
  v6 = -[IODirectDevice _localToChannel:](self, sel__localToChannel_, a4); /*0x1c1301*/
  dma_stop_enable((signed int)v6, 0); /*0x1c130c*/
  return 0; /*0x1c1320*/
}

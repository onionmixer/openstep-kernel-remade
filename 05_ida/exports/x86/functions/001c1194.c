/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c1194. */
int __cdecl -[IODirectDevice setDMATiming:forChannel:](IODirectDevice *self, SEL a2, int a3, unsigned int a4)
{
  char v4; // bl
  id v6; // eax
  id v7; // eax

  if ( is_ISA ) /*0x1c11a7*/
    return -711; /*0x1c11a9*/
  v6 = -[IODirectDevice deviceDescription](self, sel_deviceDescription); /*0x1c11c2*/
  if ( a4 >= (unsigned int)objc_msgSend(v6, sel_numChannels) ) /*0x1c11d5*/
    return -706; /*0x1c11d7*/
  v7 = -[IODirectDevice _localToChannel:](self, sel__localToChannel_, a4); /*0x1c11ec*/
  if ( a3 == 1 ) /*0x1c11f7*/
  {
    v4 = 1; /*0x1c120c*/
  }
  else if ( a3 ) /*0x1c11f9*/
  {
    if ( a3 == 2 ) /*0x1c11fe*/
    {
      v4 = 2; /*0x1c1214*/
    }
    else if ( a3 == 3 ) /*0x1c1203*/
    {
      v4 = 3; /*0x1c121c*/
    }
  }
  else
  {
    v4 = 0; /*0x1c1208*/
  }
  dma_timing((signed int)v7, v4); /*0x1c1223*/
  return 0; /*0x1c122d*/
}

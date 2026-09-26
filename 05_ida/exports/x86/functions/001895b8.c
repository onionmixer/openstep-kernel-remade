/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1895b8. */
int __cdecl get_dma_count(int a1)
{
  _BOOL4 v1; // ebx
  unsigned __int16 v2; // dx
  unsigned __int16 v3; // dx
  _BOOL4 v4; // ebx
  unsigned __int16 v5; // dx
  unsigned __int8 v6; // al
  _BOOL4 v7; // ebx
  char v9; // [esp+14h] [ebp-Ch]
  char v10; // [esp+18h] [ebp-8h]
  unsigned __int8 v11; // [esp+1Ch] [ebp-4h]

  v1 = a1 > 3; /*0x1895c8*/
  v11 = dma_cmd_regs[v1] | 4; /*0x1895d4*/
  dma_cmd_regs[v1] = v11; /*0x1895d7*/
  us_spin(1); /*0x1895df*/
  if ( a1 <= 3 ) /*0x1895e9*/
    v2 = _dma_chip_port; /*0x1895f4*/
  else
    v2 = word_1E18A0; /*0x1895eb*/
  __outbyte(v2, v11); /*0x1895fe*/
  _InterlockedIncrement(dword_1E75EC); /*0x1895ff*/
  us_spin(1); /*0x18960a*/
  if ( a1 > 3 ) /*0x189616*/
    v3 = word_1E18A8; /*0x189624*/
  else
    v3 = word_1E189A; /*0x189618*/
  __outbyte(v3, 0xFFu); /*0x18962d*/
  _InterlockedIncrement(dword_1E75EC); /*0x18962e*/
  us_spin(1); /*0x189637*/
  __inbyte(_dma_chan_port[5 * a1 + 3]); /*0x189654*/
  us_spin(1); /*0x18965f*/
  __inbyte(_dma_chan_port[5 * a1 + 3]); /*0x18966c*/
  if ( eisa_present() ) /*0x189682*/
  {
    __inbyte(_dma_chan_port[5 * a1 + 4]); /*0x189692*/
    v4 = a1 > 3; /*0x1896af*/
    v10 = dma_cmd_regs[v4] & 0xFB; /*0x1896bb*/
    dma_cmd_regs[v4] = v10; /*0x1896be*/
    us_spin(1); /*0x1896c6*/
    if ( a1 <= 3 ) /*0x1896cd*/
      v5 = _dma_chip_port; /*0x1896d8*/
    else
      v5 = word_1E18A0; /*0x1896cf*/
    v6 = v10; /*0x1896df*/
  }
  else
  {
    v7 = a1 > 3; /*0x1896eb*/
    v9 = dma_cmd_regs[v7] & 0xFB; /*0x1896f6*/
    dma_cmd_regs[v7] = v9; /*0x1896f9*/
    us_spin(1); /*0x189701*/
    if ( a1 <= 3 ) /*0x189708*/
      v5 = _dma_chip_port; /*0x189714*/
    else
      v5 = word_1E18A0; /*0x18970a*/
    v6 = v9; /*0x18971b*/
  }
  __outbyte(v5, v6); /*0x18971e*/
  _InterlockedIncrement(dword_1E75EC); /*0x18971f*/
  return ((unsigned __int8)byte_1F74F1[2 * a1] >> 2) & 3; /*0x18973e*/
}

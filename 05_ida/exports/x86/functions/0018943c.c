/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18943c. */
unsigned int __cdecl get_dma_addr(int a1)
{
  _BOOL4 v1; // ebx
  unsigned __int16 v2; // dx
  unsigned __int16 v3; // dx
  unsigned __int8 v4; // al
  int v5; // esi
  unsigned __int8 v6; // al
  unsigned int v7; // esi
  unsigned __int8 v8; // al
  unsigned int v9; // esi
  int v10; // eax
  _BOOL4 v11; // ebx
  unsigned __int16 v12; // dx
  unsigned __int8 v14; // [esp+14h] [ebp-8h]
  unsigned __int8 v15; // [esp+18h] [ebp-4h]

  v1 = a1 > 3; /*0x189450*/
  v15 = dma_cmd_regs[v1] | 4; /*0x18945b*/
  dma_cmd_regs[v1] = v15; /*0x18945e*/
  us_spin(1); /*0x189466*/
  if ( a1 <= 3 ) /*0x189470*/
    v2 = _dma_chip_port; /*0x18947c*/
  else
    v2 = word_1E18A0; /*0x189472*/
  __outbyte(v2, v15); /*0x189486*/
  _InterlockedIncrement(dword_1E75EC); /*0x189487*/
  us_spin(1); /*0x189490*/
  if ( a1 > 3 ) /*0x18949b*/
    v3 = word_1E18A8; /*0x1894a8*/
  else
    v3 = word_1E189A; /*0x18949d*/
  __outbyte(v3, 0xFFu); /*0x1894b1*/
  _InterlockedIncrement(dword_1E75EC); /*0x1894b2*/
  us_spin(1); /*0x1894bb*/
  v4 = __inbyte(_dma_chan_port[5 * a1]); /*0x1894d1*/
  v5 = v4; /*0x1894d8*/
  us_spin(1); /*0x1894dc*/
  v6 = __inbyte(_dma_chan_port[5 * a1]); /*0x1894eb*/
  v7 = (v6 << 8) | v5 & 0xFFFF00FF; /*0x1894ff*/
  us_spin(1); /*0x189503*/
  v8 = __inbyte(word_1E1844[5 * a1]); /*0x189512*/
  v9 = (v8 << 16) | v7 & 0xFF00FFFF; /*0x189526*/
  if ( eisa_present() ) /*0x189528*/
  {
    v10 = us_spin(1); /*0x189535*/
    LOBYTE(v10) = __inbyte(word_1E1846[5 * a1]); /*0x189544*/
    v9 = (v10 << 24) | v9 & 0xFFFFFF; /*0x18954e*/
  }
  v11 = a1 > 3; /*0x189556*/
  v14 = dma_cmd_regs[v11] & 0xFB; /*0x189561*/
  dma_cmd_regs[v11] = v14; /*0x189564*/
  us_spin(1); /*0x18956c*/
  if ( a1 <= 3 ) /*0x189573*/
    v12 = _dma_chip_port; /*0x189580*/
  else
    v12 = word_1E18A0; /*0x189575*/
  __outbyte(v12, v14); /*0x18958a*/
  _InterlockedIncrement(dword_1E75EC); /*0x18958b*/
  if ( (((unsigned __int8)byte_1F74F1[2 * a1] >> 2) & 3) == 1 ) /*0x1895a2*/
    LOWORD(v9) = 2 * v9; /*0x1895a9*/
  return v9; /*0x1895b1*/
}

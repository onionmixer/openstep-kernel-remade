/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1891e4. */
char __cdecl dma_eop_in(signed int a1, char a2)
{
  int v2; // eax
  char v3; // al
  _BOOL4 v4; // ebx
  unsigned __int16 v5; // dx
  unsigned __int16 v6; // dx
  _BOOL4 v7; // ebx
  unsigned __int16 v8; // dx
  unsigned __int8 v10; // [esp+Ch] [ebp-Ch]
  unsigned __int8 v11; // [esp+10h] [ebp-8h]
  unsigned __int8 v12; // [esp+14h] [ebp-4h]

  v2 = (unsigned __int8)dma_assigned_bits; /*0x1891ef*/
  if ( _bittest(&v2, a1) ) /*0x1891f6*/
  {
    v3 = ((a2 & 1) << 6) | dma_write_regs[2 * a1 + 1] & 0xBF; /*0x189216*/
    dma_write_regs[2 * a1 + 1] = v3; /*0x189218*/
    v12 = v3 & 0xFC | a1 & 3; /*0x189225*/
    v4 = a1 > 3; /*0x18922e*/
    v11 = dma_cmd_regs[v4] | 4; /*0x189239*/
    dma_cmd_regs[v4] = v11; /*0x18923c*/
    us_spin(1); /*0x189244*/
    if ( a1 <= 3 ) /*0x18924e*/
      v5 = _dma_chip_port; /*0x18925c*/
    else
      v5 = word_1E18A0; /*0x189250*/
    __outbyte(v5, v11); /*0x189266*/
    _InterlockedIncrement(dword_1E75EC); /*0x189267*/
    us_spin(1); /*0x189270*/
    if ( a1 > 3 ) /*0x18927b*/
      v6 = word_1E18AC; /*0x189288*/
    else
      v6 = word_1E189E; /*0x18927d*/
    __outbyte(v6, v12); /*0x189292*/
    _InterlockedIncrement(dword_1E75EC); /*0x189293*/
    v7 = a1 > 3; /*0x1892a0*/
    v10 = dma_cmd_regs[v7] & 0xFB; /*0x1892ab*/
    dma_cmd_regs[v7] = v10; /*0x1892ae*/
    us_spin(1); /*0x1892b6*/
    if ( a1 <= 3 ) /*0x1892bd*/
      v8 = _dma_chip_port; /*0x1892c8*/
    else
      v8 = word_1E18A0; /*0x1892bf*/
    LOBYTE(v2) = v10; /*0x1892cf*/
    __outbyte(v8, v10); /*0x1892d2*/
    _InterlockedIncrement(dword_1E75EC); /*0x1892d3*/
  }
  return v2; /*0x1892dd*/
}

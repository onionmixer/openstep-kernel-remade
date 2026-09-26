/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18836c. */
char __cdecl dma_unmask_chan(signed int a1)
{
  int v1; // eax
  _BOOL4 v2; // ebx
  unsigned __int16 v3; // dx
  unsigned __int16 v4; // dx
  _BOOL4 v5; // ebx
  unsigned __int16 v6; // dx
  unsigned __int8 v8; // [esp+Ch] [ebp-Ch]
  unsigned __int8 v9; // [esp+10h] [ebp-8h]

  v1 = (unsigned __int8)dma_assigned_bits; /*0x188377*/
  if ( _bittest(&v1, a1) ) /*0x18837e*/
  {
    v2 = a1 > 3; /*0x188394*/
    v9 = dma_cmd_regs[v2] | 4; /*0x18839f*/
    dma_cmd_regs[v2] = v9; /*0x1883a2*/
    us_spin(1); /*0x1883aa*/
    if ( a1 <= 3 ) /*0x1883b4*/
      v3 = _dma_chip_port; /*0x1883c0*/
    else
      v3 = word_1E18A0; /*0x1883b6*/
    __outbyte(v3, v9); /*0x1883ca*/
    _InterlockedIncrement(dword_1E75EC); /*0x1883cb*/
    us_spin(1); /*0x1883d4*/
    if ( a1 > 3 ) /*0x1883df*/
      v4 = word_1E18A4; /*0x1883ec*/
    else
      v4 = word_1E1896; /*0x1883e1*/
    __outbyte(v4, a1 & 3); /*0x1883f6*/
    _InterlockedIncrement(dword_1E75EC); /*0x1883f7*/
    v5 = a1 > 3; /*0x188404*/
    v8 = dma_cmd_regs[v5] & 0xFB; /*0x18840f*/
    dma_cmd_regs[v5] = v8; /*0x188412*/
    us_spin(1); /*0x18841a*/
    if ( a1 <= 3 ) /*0x188421*/
      v6 = _dma_chip_port; /*0x18842c*/
    else
      v6 = word_1E18A0; /*0x188423*/
    LOBYTE(v1) = v8; /*0x188433*/
    __outbyte(v6, v8); /*0x188436*/
    _InterlockedIncrement(dword_1E75EC); /*0x188437*/
  }
  return v1; /*0x188441*/
}

/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x188740. */
char __cdecl dma_chan_xfer_dir(signed int a1, char a2)
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

  v2 = (unsigned __int8)dma_assigned_bits; /*0x18874b*/
  if ( _bittest(&v2, a1) ) /*0x188752*/
  {
    v3 = (4 * (a2 & 3)) | dma_write_regs[2 * a1] & 0xF3; /*0x18876f*/
    dma_write_regs[2 * a1] = v3; /*0x188771*/
    v12 = v3 & 0xFC | a1 & 3; /*0x188780*/
    v4 = a1 > 3; /*0x188789*/
    v11 = dma_cmd_regs[v4] | 4; /*0x188794*/
    dma_cmd_regs[v4] = v11; /*0x188797*/
    us_spin(1); /*0x18879f*/
    if ( a1 <= 3 ) /*0x1887a9*/
      v5 = _dma_chip_port; /*0x1887b4*/
    else
      v5 = word_1E18A0; /*0x1887ab*/
    __outbyte(v5, v11); /*0x1887be*/
    _InterlockedIncrement(dword_1E75EC); /*0x1887bf*/
    us_spin(1); /*0x1887c8*/
    if ( a1 > 3 ) /*0x1887d3*/
      v6 = word_1E18A6; /*0x1887e0*/
    else
      v6 = word_1E1898; /*0x1887d5*/
    __outbyte(v6, v12); /*0x1887ea*/
    _InterlockedIncrement(dword_1E75EC); /*0x1887eb*/
    v7 = a1 > 3; /*0x1887f8*/
    v10 = dma_cmd_regs[v7] & 0xFB; /*0x188803*/
    dma_cmd_regs[v7] = v10; /*0x188806*/
    us_spin(1); /*0x18880e*/
    if ( a1 <= 3 ) /*0x188815*/
      v8 = _dma_chip_port; /*0x188820*/
    else
      v8 = word_1E18A0; /*0x188817*/
    LOBYTE(v2) = v10; /*0x188827*/
    __outbyte(v8, v10); /*0x18882a*/
    _InterlockedIncrement(dword_1E75EC); /*0x18882b*/
  }
  return v2; /*0x188835*/
}

/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x188448. */
char __cdecl dma_chan_xfer_mode(signed int a1, char a2)
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

  v2 = (unsigned __int8)dma_assigned_bits; /*0x188453*/
  if ( _bittest(&v2, a1) ) /*0x18845a*/
  {
    v3 = (a2 << 6) | dma_write_regs[2 * a1] & 0x3F; /*0x188474*/
    dma_write_regs[2 * a1] = v3; /*0x188476*/
    v12 = v3 & 0xFC | a1 & 3; /*0x188485*/
    v4 = a1 > 3; /*0x18848e*/
    v11 = dma_cmd_regs[v4] | 4; /*0x188499*/
    dma_cmd_regs[v4] = v11; /*0x18849c*/
    us_spin(1); /*0x1884a4*/
    if ( a1 <= 3 ) /*0x1884ae*/
      v5 = _dma_chip_port; /*0x1884bc*/
    else
      v5 = word_1E18A0; /*0x1884b0*/
    __outbyte(v5, v11); /*0x1884c6*/
    _InterlockedIncrement(dword_1E75EC); /*0x1884c7*/
    us_spin(1); /*0x1884d0*/
    if ( a1 > 3 ) /*0x1884db*/
      v6 = word_1E18A6; /*0x1884e8*/
    else
      v6 = word_1E1898; /*0x1884dd*/
    __outbyte(v6, v12); /*0x1884f2*/
    _InterlockedIncrement(dword_1E75EC); /*0x1884f3*/
    v7 = a1 > 3; /*0x188500*/
    v10 = dma_cmd_regs[v7] & 0xFB; /*0x18850b*/
    dma_cmd_regs[v7] = v10; /*0x18850e*/
    us_spin(1); /*0x188516*/
    if ( a1 <= 3 ) /*0x18851d*/
      v8 = _dma_chip_port; /*0x188528*/
    else
      v8 = word_1E18A0; /*0x18851f*/
    LOBYTE(v2) = v10; /*0x18852f*/
    __outbyte(v8, v10); /*0x188532*/
    _InterlockedIncrement(dword_1E75EC); /*0x188533*/
  }
  return v2; /*0x18853d*/
}

/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x188544. */
char __cdecl dma_chan_autoinit(signed int a1, char a2)
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

  v2 = (unsigned __int8)dma_assigned_bits; /*0x18854f*/
  if ( _bittest(&v2, a1) ) /*0x188556*/
  {
    v3 = (16 * (a2 & 1)) | dma_write_regs[2 * a1] & 0xEF; /*0x188573*/
    dma_write_regs[2 * a1] = v3; /*0x188575*/
    v12 = v3 & 0xFC | a1 & 3; /*0x188584*/
    v4 = a1 > 3; /*0x18858d*/
    v11 = dma_cmd_regs[v4] | 4; /*0x188598*/
    dma_cmd_regs[v4] = v11; /*0x18859b*/
    us_spin(1); /*0x1885a3*/
    if ( a1 <= 3 ) /*0x1885ad*/
      v5 = _dma_chip_port; /*0x1885b8*/
    else
      v5 = word_1E18A0; /*0x1885af*/
    __outbyte(v5, v11); /*0x1885c2*/
    _InterlockedIncrement(dword_1E75EC); /*0x1885c3*/
    us_spin(1); /*0x1885cc*/
    if ( a1 > 3 ) /*0x1885d7*/
      v6 = word_1E18A6; /*0x1885e4*/
    else
      v6 = word_1E1898; /*0x1885d9*/
    __outbyte(v6, v12); /*0x1885ee*/
    _InterlockedIncrement(dword_1E75EC); /*0x1885ef*/
    v7 = a1 > 3; /*0x1885fc*/
    v10 = dma_cmd_regs[v7] & 0xFB; /*0x188607*/
    dma_cmd_regs[v7] = v10; /*0x18860a*/
    us_spin(1); /*0x188612*/
    if ( a1 <= 3 ) /*0x188619*/
      v8 = _dma_chip_port; /*0x188624*/
    else
      v8 = word_1E18A0; /*0x18861b*/
    LOBYTE(v2) = v10; /*0x18862b*/
    __outbyte(v8, v10); /*0x18862e*/
    _InterlockedIncrement(dword_1E75EC); /*0x18862f*/
  }
  return v2; /*0x188639*/
}

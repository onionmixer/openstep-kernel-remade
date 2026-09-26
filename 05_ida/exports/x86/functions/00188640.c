/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x188640. */
char __cdecl dma_chan_adrs_dir(signed int a1, int a2)
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

  v2 = (unsigned __int8)dma_assigned_bits; /*0x18864b*/
  if ( _bittest(&v2, a1) ) /*0x188652*/
  {
    v3 = (32 * (a2 != 0)) | dma_write_regs[2 * a1] & 0xDF; /*0x188670*/
    dma_write_regs[2 * a1] = v3; /*0x188672*/
    v12 = v3 & 0xFC | a1 & 3; /*0x188681*/
    v4 = a1 > 3; /*0x18868a*/
    v11 = dma_cmd_regs[v4] | 4; /*0x188695*/
    dma_cmd_regs[v4] = v11; /*0x188698*/
    us_spin(1); /*0x1886a0*/
    if ( a1 <= 3 ) /*0x1886aa*/
      v5 = _dma_chip_port; /*0x1886b8*/
    else
      v5 = word_1E18A0; /*0x1886ac*/
    __outbyte(v5, v11); /*0x1886c2*/
    _InterlockedIncrement(dword_1E75EC); /*0x1886c3*/
    us_spin(1); /*0x1886cc*/
    if ( a1 > 3 ) /*0x1886d7*/
      v6 = word_1E18A6; /*0x1886e4*/
    else
      v6 = word_1E1898; /*0x1886d9*/
    __outbyte(v6, v12); /*0x1886ee*/
    _InterlockedIncrement(dword_1E75EC); /*0x1886ef*/
    v7 = a1 > 3; /*0x1886fc*/
    v10 = dma_cmd_regs[v7] & 0xFB; /*0x188707*/
    dma_cmd_regs[v7] = v10; /*0x18870a*/
    us_spin(1); /*0x188712*/
    if ( a1 <= 3 ) /*0x188719*/
      v8 = _dma_chip_port; /*0x188724*/
    else
      v8 = word_1E18A0; /*0x18871b*/
    LOBYTE(v2) = v10; /*0x18872b*/
    __outbyte(v8, v10); /*0x18872e*/
    _InterlockedIncrement(dword_1E75EC); /*0x18872f*/
  }
  return v2; /*0x188739*/
}

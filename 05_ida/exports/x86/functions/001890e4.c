/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1890e4. */
char __cdecl dma_timing(signed int a1, char a2)
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

  v2 = (unsigned __int8)dma_assigned_bits; /*0x1890ef*/
  if ( _bittest(&v2, a1) ) /*0x1890f6*/
  {
    v3 = (16 * (a2 & 3)) | dma_write_regs[2 * a1 + 1] & 0xCF; /*0x189116*/
    dma_write_regs[2 * a1 + 1] = v3; /*0x189118*/
    v12 = v3 & 0xFC | a1 & 3; /*0x189125*/
    v4 = a1 > 3; /*0x18912e*/
    v11 = dma_cmd_regs[v4] | 4; /*0x189139*/
    dma_cmd_regs[v4] = v11; /*0x18913c*/
    us_spin(1); /*0x189144*/
    if ( a1 <= 3 ) /*0x18914e*/
      v5 = _dma_chip_port; /*0x18915c*/
    else
      v5 = word_1E18A0; /*0x189150*/
    __outbyte(v5, v11); /*0x189166*/
    _InterlockedIncrement(dword_1E75EC); /*0x189167*/
    us_spin(1); /*0x189170*/
    if ( a1 > 3 ) /*0x18917b*/
      v6 = word_1E18AC; /*0x189188*/
    else
      v6 = word_1E189E; /*0x18917d*/
    __outbyte(v6, v12); /*0x189192*/
    _InterlockedIncrement(dword_1E75EC); /*0x189193*/
    v7 = a1 > 3; /*0x1891a0*/
    v10 = dma_cmd_regs[v7] & 0xFB; /*0x1891ab*/
    dma_cmd_regs[v7] = v10; /*0x1891ae*/
    us_spin(1); /*0x1891b6*/
    if ( a1 <= 3 ) /*0x1891bd*/
      v8 = _dma_chip_port; /*0x1891c8*/
    else
      v8 = word_1E18A0; /*0x1891bf*/
    LOBYTE(v2) = v10; /*0x1891cf*/
    __outbyte(v8, v10); /*0x1891d2*/
    _InterlockedIncrement(dword_1E75EC); /*0x1891d3*/
  }
  return v2; /*0x1891dd*/
}

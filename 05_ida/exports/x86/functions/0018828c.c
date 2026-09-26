/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18828c. */
char __cdecl dma_mask_chan(signed int a1)
{
  int v1; // eax
  _BOOL4 v2; // ebx
  unsigned __int16 v3; // dx
  unsigned __int16 v4; // dx
  _BOOL4 v5; // ebx
  unsigned __int16 v6; // dx
  unsigned __int8 v8; // [esp+Ch] [ebp-Ch]
  unsigned __int8 v9; // [esp+10h] [ebp-8h]

  v1 = (unsigned __int8)dma_assigned_bits; /*0x188297*/
  if ( _bittest(&v1, a1) ) /*0x18829e*/
  {
    v2 = a1 > 3; /*0x1882b6*/
    v9 = dma_cmd_regs[v2] | 4; /*0x1882c1*/
    dma_cmd_regs[v2] = v9; /*0x1882c4*/
    us_spin(1); /*0x1882cc*/
    if ( a1 <= 3 ) /*0x1882d6*/
      v3 = _dma_chip_port; /*0x1882e4*/
    else
      v3 = word_1E18A0; /*0x1882d8*/
    __outbyte(v3, v9); /*0x1882ee*/
    _InterlockedIncrement(dword_1E75EC); /*0x1882ef*/
    us_spin(1); /*0x1882f8*/
    if ( a1 > 3 ) /*0x188303*/
      v4 = word_1E18A4; /*0x188310*/
    else
      v4 = word_1E1896; /*0x188305*/
    __outbyte(v4, a1 & 3 | 4); /*0x18831a*/
    _InterlockedIncrement(dword_1E75EC); /*0x18831b*/
    v5 = a1 > 3; /*0x188328*/
    v8 = dma_cmd_regs[v5] & 0xFB; /*0x188333*/
    dma_cmd_regs[v5] = v8; /*0x188336*/
    us_spin(1); /*0x18833e*/
    if ( a1 <= 3 ) /*0x188345*/
      v6 = _dma_chip_port; /*0x188350*/
    else
      v6 = word_1E18A0; /*0x188347*/
    LOBYTE(v1) = v8; /*0x188357*/
    __outbyte(v6, v8); /*0x18835a*/
    _InterlockedIncrement(dword_1E75EC); /*0x18835b*/
  }
  return v1; /*0x188365*/
}

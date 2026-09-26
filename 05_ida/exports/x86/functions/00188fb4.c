/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x188fb4. */
char __cdecl dma_xfer_width(signed int a1, char a2)
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

  v2 = (unsigned __int8)dma_assigned_bits; /*0x188fbf*/
  if ( _bittest(&v2, a1) ) /*0x188fc6*/
  {
    v3 = (4 * (a2 & 3)) | dma_write_regs[2 * a1 + 1] & 0xF3; /*0x188fe6*/
    dma_write_regs[2 * a1 + 1] = v3; /*0x188fe8*/
    v12 = v3 & 0xFC | a1 & 3; /*0x188ff5*/
    v4 = a1 > 3; /*0x188ffe*/
    v11 = dma_cmd_regs[v4] | 4; /*0x189009*/
    dma_cmd_regs[v4] = v11; /*0x18900c*/
    us_spin(1); /*0x189014*/
    if ( a1 <= 3 ) /*0x18901e*/
      v5 = _dma_chip_port; /*0x18902c*/
    else
      v5 = word_1E18A0; /*0x189020*/
    __outbyte(v5, v11); /*0x189036*/
    _InterlockedIncrement(dword_1E75EC); /*0x189037*/
    us_spin(1); /*0x189040*/
    if ( a1 > 3 ) /*0x18904b*/
      v6 = word_1E18AC; /*0x189058*/
    else
      v6 = word_1E189E; /*0x18904d*/
    __outbyte(v6, v12); /*0x189062*/
    _InterlockedIncrement(dword_1E75EC); /*0x189063*/
    v7 = a1 > 3; /*0x189070*/
    v10 = dma_cmd_regs[v7] & 0xFB; /*0x18907b*/
    dma_cmd_regs[v7] = v10; /*0x18907e*/
    us_spin(1); /*0x189086*/
    if ( a1 <= 3 ) /*0x18908d*/
      v8 = _dma_chip_port; /*0x189098*/
    else
      v8 = word_1E18A0; /*0x18908f*/
    LOBYTE(v2) = v10; /*0x18909f*/
    __outbyte(v8, v10); /*0x1890a2*/
    _InterlockedIncrement(dword_1E75EC); /*0x1890a3*/
  }
  return v2; /*0x1890ad*/
}

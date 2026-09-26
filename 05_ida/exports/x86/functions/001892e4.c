/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1892e4. */
char __cdecl dma_stop_enable(signed int a1, char a2)
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

  v2 = (unsigned __int8)dma_assigned_bits; /*0x1892ef*/
  if ( _bittest(&v2, a1) ) /*0x1892f6*/
  {
    v3 = (a2 << 7) | dma_write_regs[2 * a1 + 1] & 0x7F; /*0x189313*/
    dma_write_regs[2 * a1 + 1] = v3; /*0x189315*/
    v12 = v3 & 0xFC | a1 & 3; /*0x189322*/
    v4 = a1 > 3; /*0x18932b*/
    v11 = dma_cmd_regs[v4] | 4; /*0x189336*/
    dma_cmd_regs[v4] = v11; /*0x189339*/
    us_spin(1); /*0x189341*/
    if ( a1 <= 3 ) /*0x18934b*/
      v5 = _dma_chip_port; /*0x189358*/
    else
      v5 = word_1E18A0; /*0x18934d*/
    __outbyte(v5, v11); /*0x189362*/
    _InterlockedIncrement(dword_1E75EC); /*0x189363*/
    us_spin(1); /*0x18936c*/
    if ( a1 > 3 ) /*0x189377*/
      v6 = word_1E18AC; /*0x189384*/
    else
      v6 = word_1E189E; /*0x189379*/
    __outbyte(v6, v12); /*0x18938e*/
    _InterlockedIncrement(dword_1E75EC); /*0x18938f*/
    v7 = a1 > 3; /*0x18939c*/
    v10 = dma_cmd_regs[v7] & 0xFB; /*0x1893a7*/
    dma_cmd_regs[v7] = v10; /*0x1893aa*/
    us_spin(1); /*0x1893b2*/
    if ( a1 <= 3 ) /*0x1893b9*/
      v8 = _dma_chip_port; /*0x1893c4*/
    else
      v8 = word_1E18A0; /*0x1893bb*/
    LOBYTE(v2) = v10; /*0x1893cb*/
    __outbyte(v8, v10); /*0x1893ce*/
    _InterlockedIncrement(dword_1E75EC); /*0x1893cf*/
  }
  return v2; /*0x1893d9*/
}

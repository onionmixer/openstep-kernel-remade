/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x188124. */
char __cdecl sub_188124(int a1)
{
  int v1; // ebx
  int v2; // eax
  char v3; // dl
  _BOOL4 v4; // ebx
  unsigned __int16 v5; // dx
  unsigned __int16 v6; // dx
  _BOOL4 v7; // ebx
  unsigned __int16 v8; // dx
  unsigned __int8 v10; // [esp+10h] [ebp-Ch]
  unsigned __int8 v11; // [esp+14h] [ebp-8h]
  unsigned __int8 v12; // [esp+18h] [ebp-4h]

  v1 = 2 * a1; /*0x188130*/
  dma_write_regs[2 * a1 + 1] &= 0xFu; /*0x188138*/
  v2 = eisa_present(); /*0x18813d*/
  if ( v2 ) /*0x188144*/
  {
    v3 = dma_write_regs[v1 + 1] & 0xF3; /*0x188170*/
    dma_write_regs[v1 + 1] = v3; /*0x188173*/
    v12 = v3; /*0x188177*/
    v4 = a1 > 3; /*0x188180*/
    v11 = dma_cmd_regs[v4] | 4; /*0x18818b*/
    dma_cmd_regs[v4] = v11; /*0x18818e*/
    us_spin(1); /*0x188196*/
    if ( a1 <= 3 ) /*0x1881a0*/
      v5 = _dma_chip_port; /*0x1881ac*/
    else
      v5 = word_1E18A0; /*0x1881a2*/
    __outbyte(v5, v11); /*0x1881b6*/
    _InterlockedIncrement(dword_1E75EC); /*0x1881b7*/
    us_spin(1); /*0x1881c0*/
    if ( a1 > 3 ) /*0x1881cb*/
      v6 = word_1E18AC; /*0x1881d8*/
    else
      v6 = word_1E189E; /*0x1881cd*/
    __outbyte(v6, v12); /*0x1881e2*/
    _InterlockedIncrement(dword_1E75EC); /*0x1881e3*/
    v7 = a1 > 3; /*0x1881f0*/
    v10 = dma_cmd_regs[v7] & 0xFB; /*0x1881fb*/
    dma_cmd_regs[v7] = v10; /*0x1881fe*/
    us_spin(1); /*0x188206*/
    if ( a1 <= 3 ) /*0x18820d*/
      v8 = _dma_chip_port; /*0x188218*/
    else
      v8 = word_1E18A0; /*0x18820f*/
    LOBYTE(v2) = v10; /*0x18821f*/
    __outbyte(v8, v10); /*0x188222*/
    _InterlockedIncrement(dword_1E75EC); /*0x188223*/
  }
  else if ( a1 > 3 ) /*0x188149*/
  {
    LOBYTE(v2) = dma_write_regs[v1 + 1] & 0xF3 | 4; /*0x18815e*/
    dma_write_regs[v1 + 1] = v2; /*0x188160*/
  }
  else
  {
    dma_write_regs[v1 + 1] &= 0xF3u; /*0x18814b*/
  }
  return v2; /*0x18822d*/
}

/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18883c. */
int __cdecl dma_xfer_chan(int a1, int a2)
{
  int v2; // eax
  int v4; // ecx
  _BOOL4 v5; // ebx
  unsigned __int16 v6; // dx
  unsigned __int16 v7; // dx
  _BOOL4 v8; // ebx
  unsigned __int16 v9; // dx
  int v10; // eax
  char v11; // al
  _BOOL4 v12; // ebx
  unsigned __int16 v13; // dx
  unsigned __int16 v14; // dx
  _BOOL4 v15; // ebx
  unsigned __int16 v16; // dx
  unsigned __int8 v17; // al
  int v18; // eax
  char v19; // cl
  _BOOL4 v20; // ebx
  unsigned __int16 v21; // dx
  unsigned __int16 v22; // dx
  _BOOL4 v23; // ebx
  int v24; // esi
  _BOOL4 v25; // ebx
  unsigned __int16 v26; // dx
  unsigned __int16 v27; // dx
  _BOOL4 v28; // ebx
  unsigned __int16 v29; // dx
  unsigned int v30; // edx
  int v31; // esi
  _BOOL4 v32; // ebx
  unsigned __int16 v33; // dx
  unsigned __int16 v34; // dx
  _BOOL4 v35; // ebx
  unsigned __int16 v36; // dx
  int v37; // eax
  _BOOL4 v38; // ebx
  unsigned __int16 v39; // dx
  unsigned __int16 v40; // dx
  _BOOL4 v41; // ebx
  unsigned __int16 v42; // dx
  unsigned __int8 v43; // [esp+18h] [ebp-44h]
  unsigned __int8 v44; // [esp+1Ch] [ebp-40h]
  unsigned __int8 v45; // [esp+24h] [ebp-38h]
  unsigned __int8 v46; // [esp+28h] [ebp-34h]
  unsigned __int8 v47; // [esp+2Ch] [ebp-30h]
  unsigned __int8 v48; // [esp+30h] [ebp-2Ch]
  char v49; // [esp+34h] [ebp-28h]
  unsigned __int8 v50; // [esp+38h] [ebp-24h]
  unsigned __int8 v51; // [esp+3Ch] [ebp-20h]
  char v52; // [esp+40h] [ebp-1Ch]
  unsigned __int8 v53; // [esp+44h] [ebp-18h]
  unsigned __int8 v54; // [esp+48h] [ebp-14h]
  unsigned __int8 v55; // [esp+4Ch] [ebp-10h]
  unsigned __int8 v56; // [esp+50h] [ebp-Ch]
  int v57; // [esp+58h] [ebp-4h] BYREF

  v2 = (unsigned __int8)dma_assigned_bits; /*0x188848*/
  if ( !_bittest(&v2, a1) ) /*0x18884f*/
    return 0; /*0x18884f*/
  if ( !eisa_present() ) /*0x188854*/
    *(_BYTE *)(a2 + 20) |= 0x30u; /*0x188860*/
  if ( !dma_xfer(a2, &v57) ) /*0x18886c*/
    return 0; /*0x18887c*/
  *(_DWORD *)(a2 + 8) = a1; /*0x188887*/
  *(_BYTE *)(a2 + 20) |= 4u; /*0x18888a*/
  v4 = (unsigned __int8)dma_assigned_bits; /*0x18888e*/
  if ( _bittest(&v4, a1) ) /*0x188895*/
  {
    v5 = a1 > 3; /*0x1888ad*/
    v56 = dma_cmd_regs[v5] | 4; /*0x1888b8*/
    dma_cmd_regs[v5] = v56; /*0x1888bb*/
    us_spin(1); /*0x1888c3*/
    if ( a1 <= 3 ) /*0x1888cd*/
      v6 = _dma_chip_port; /*0x1888d8*/
    else
      v6 = word_1E18A0; /*0x1888cf*/
    __outbyte(v6, v56); /*0x1888e2*/
    _InterlockedIncrement(dword_1E75EC); /*0x1888e3*/
    us_spin(1); /*0x1888ec*/
    if ( a1 > 3 ) /*0x1888f7*/
      v7 = word_1E18A4; /*0x188904*/
    else
      v7 = word_1E1896; /*0x1888f9*/
    __outbyte(v7, a1 & 3 | 4); /*0x18890e*/
    _InterlockedIncrement(dword_1E75EC); /*0x18890f*/
    v8 = a1 > 3; /*0x18891c*/
    v55 = dma_cmd_regs[v8] & 0xFB; /*0x188927*/
    dma_cmd_regs[v8] = v55; /*0x18892a*/
    us_spin(1); /*0x188932*/
    if ( a1 <= 3 ) /*0x18893c*/
      v9 = _dma_chip_port; /*0x188948*/
    else
      v9 = word_1E18A0; /*0x18893e*/
    __outbyte(v9, v55); /*0x188952*/
    _InterlockedIncrement(dword_1E75EC); /*0x188953*/
  }
  if ( (*(_BYTE *)(a2 + 20) & 8) != 0 ) /*0x188961*/
  {
    v10 = (unsigned __int8)dma_assigned_bits; /*0x188967*/
    if ( _bittest(&v10, a1) ) /*0x18896e*/
    {
      v11 = dma_write_regs[2 * a1] & 0xF3 | 4; /*0x188982*/
      dma_write_regs[2 * a1] = v11; /*0x188984*/
      v54 = v11 & 0xFC | a1 & 3; /*0x188993*/
      v12 = a1 > 3; /*0x18899c*/
      v53 = dma_cmd_regs[v12] | 4; /*0x1889a7*/
      dma_cmd_regs[v12] = v53; /*0x1889aa*/
      us_spin(1); /*0x1889b2*/
      if ( a1 <= 3 ) /*0x1889bc*/
        v13 = _dma_chip_port; /*0x1889c8*/
      else
        v13 = word_1E18A0; /*0x1889be*/
      __outbyte(v13, v53); /*0x1889d2*/
      _InterlockedIncrement(dword_1E75EC); /*0x1889d3*/
      us_spin(1); /*0x1889dc*/
      if ( a1 > 3 ) /*0x1889e7*/
        v14 = word_1E18A6; /*0x1889f4*/
      else
        v14 = word_1E1898; /*0x1889e9*/
      __outbyte(v14, v54); /*0x1889fe*/
      _InterlockedIncrement(dword_1E75EC); /*0x1889ff*/
      v15 = a1 > 3; /*0x188a0c*/
      v52 = dma_cmd_regs[v15] & 0xFB; /*0x188a17*/
      dma_cmd_regs[v15] = v52; /*0x188a1a*/
      us_spin(1); /*0x188a22*/
      if ( a1 <= 3 ) /*0x188a2c*/
        v16 = _dma_chip_port; /*0x188a40*/
      else
        v16 = word_1E18A0; /*0x188a2e*/
      v17 = v52; /*0x188a35*/
LABEL_40:
      __outbyte(v16, v17); /*0x188b2e*/
      _InterlockedIncrement(dword_1E75EC); /*0x188b2f*/
    }
  }
  else
  {
    v18 = (unsigned __int8)dma_assigned_bits; /*0x188a50*/
    if ( _bittest(&v18, a1) ) /*0x188a57*/
    {
      v19 = dma_write_regs[2 * a1] & 0xF3 | 8; /*0x188a6c*/
      dma_write_regs[2 * a1] = v19; /*0x188a6f*/
      v51 = v19 & 0xFC | a1 & 3; /*0x188a7f*/
      v20 = a1 > 3; /*0x188a88*/
      v50 = dma_cmd_regs[v20] | 4; /*0x188a94*/
      dma_cmd_regs[v20] = v50; /*0x188a97*/
      us_spin(1); /*0x188a9f*/
      if ( a1 <= 3 ) /*0x188aa9*/
        v21 = _dma_chip_port; /*0x188ab4*/
      else
        v21 = word_1E18A0; /*0x188aab*/
      __outbyte(v21, v50); /*0x188abe*/
      _InterlockedIncrement(dword_1E75EC); /*0x188abf*/
      us_spin(1); /*0x188ac8*/
      if ( a1 > 3 ) /*0x188ad3*/
        v22 = word_1E18A6; /*0x188ae0*/
      else
        v22 = word_1E1898; /*0x188ad5*/
      __outbyte(v22, v51); /*0x188aea*/
      _InterlockedIncrement(dword_1E75EC); /*0x188aeb*/
      v23 = a1 > 3; /*0x188af8*/
      v49 = dma_cmd_regs[v23] & 0xFB; /*0x188b03*/
      dma_cmd_regs[v23] = v49; /*0x188b06*/
      us_spin(1); /*0x188b0e*/
      if ( a1 <= 3 ) /*0x188b18*/
        v16 = _dma_chip_port; /*0x188b24*/
      else
        v16 = word_1E18A0; /*0x188b1a*/
      v17 = v49; /*0x188b2b*/
      goto LABEL_40; /*0x188b2b*/
    }
  }
  v24 = v57; /*0x188b36*/
  if ( (((unsigned __int8)byte_1F74F1[2 * a1] >> 2) & 3) == 1 ) /*0x188b49*/
    LOWORD(v24) = (unsigned __int16)v57 >> 1; /*0x188b50*/
  v25 = a1 > 3; /*0x188b59*/
  v48 = dma_cmd_regs[v25] | 4; /*0x188b64*/
  dma_cmd_regs[v25] = v48; /*0x188b67*/
  us_spin(1); /*0x188b6f*/
  if ( a1 <= 3 ) /*0x188b79*/
    v26 = _dma_chip_port; /*0x188b84*/
  else
    v26 = word_1E18A0; /*0x188b7b*/
  __outbyte(v26, v48); /*0x188b8e*/
  _InterlockedIncrement(dword_1E75EC); /*0x188b8f*/
  us_spin(1); /*0x188b98*/
  if ( a1 > 3 ) /*0x188ba3*/
    v27 = word_1E18A8; /*0x188bb0*/
  else
    v27 = word_1E189A; /*0x188ba5*/
  __outbyte(v27, 0xFFu); /*0x188bb9*/
  _InterlockedIncrement(dword_1E75EC); /*0x188bba*/
  us_spin(1); /*0x188bc3*/
  __outbyte(_dma_chan_port[5 * a1], v24); /*0x188bde*/
  _InterlockedIncrement(dword_1E75EC); /*0x188bdf*/
  us_spin(1); /*0x188be8*/
  __outbyte(_dma_chan_port[5 * a1], BYTE1(v24)); /*0x188bfe*/
  _InterlockedIncrement(dword_1E75EC); /*0x188bff*/
  us_spin(1); /*0x188c08*/
  __outbyte(word_1E1844[5 * a1], BYTE2(v24)); /*0x188c1e*/
  _InterlockedIncrement(dword_1E75EC); /*0x188c1f*/
  if ( eisa_present() ) /*0x188c26*/
  {
    us_spin(1); /*0x188c33*/
    __outbyte(word_1E1846[5 * a1], HIBYTE(v24)); /*0x188c47*/
    _InterlockedIncrement(dword_1E75EC); /*0x188c48*/
  }
  v28 = a1 > 3; /*0x188c55*/
  v47 = dma_cmd_regs[v28] & 0xFB; /*0x188c60*/
  dma_cmd_regs[v28] = v47; /*0x188c63*/
  us_spin(1); /*0x188c6b*/
  if ( a1 <= 3 ) /*0x188c75*/
    v29 = _dma_chip_port; /*0x188c80*/
  else
    v29 = word_1E18A0; /*0x188c77*/
  __outbyte(v29, v47); /*0x188c8a*/
  _InterlockedIncrement(dword_1E75EC); /*0x188c8b*/
  v30 = *(_DWORD *)(a2 + 4); /*0x188c95*/
  if ( (((unsigned __int8)byte_1F74F1[2 * a1] >> 2) & 3) == 1 ) /*0x188cad*/
    v31 = (v30 >> 1) - 1; /*0x188cb3*/
  else
    v31 = v30 - 1; /*0x188cb8*/
  v32 = a1 > 3; /*0x188cc1*/
  v46 = dma_cmd_regs[v32] | 4; /*0x188ccd*/
  dma_cmd_regs[v32] = v46; /*0x188cd0*/
  us_spin(1); /*0x188cd8*/
  if ( a1 <= 3 ) /*0x188ce2*/
    v33 = _dma_chip_port; /*0x188cf0*/
  else
    v33 = word_1E18A0; /*0x188ce4*/
  __outbyte(v33, v46); /*0x188cfa*/
  _InterlockedIncrement(dword_1E75EC); /*0x188cfb*/
  us_spin(1); /*0x188d04*/
  if ( a1 > 3 ) /*0x188d0f*/
    v34 = word_1E18A8; /*0x188d1c*/
  else
    v34 = word_1E189A; /*0x188d11*/
  __outbyte(v34, 0xFFu); /*0x188d25*/
  _InterlockedIncrement(dword_1E75EC); /*0x188d26*/
  us_spin(1); /*0x188d2f*/
  __outbyte(word_1E1848[5 * a1], v31); /*0x188d4a*/
  _InterlockedIncrement(dword_1E75EC); /*0x188d4b*/
  us_spin(1); /*0x188d54*/
  __outbyte(word_1E1848[5 * a1], BYTE1(v31)); /*0x188d6a*/
  _InterlockedIncrement(dword_1E75EC); /*0x188d6b*/
  if ( eisa_present() ) /*0x188d72*/
  {
    us_spin(1); /*0x188d7f*/
    __outbyte(word_1E184A[5 * a1], BYTE2(v31)); /*0x188d93*/
    _InterlockedIncrement(dword_1E75EC); /*0x188d94*/
  }
  v35 = a1 > 3; /*0x188da1*/
  v45 = dma_cmd_regs[v35] & 0xFB; /*0x188dac*/
  dma_cmd_regs[v35] = v45; /*0x188daf*/
  us_spin(1); /*0x188db7*/
  if ( a1 <= 3 ) /*0x188dc1*/
    v36 = _dma_chip_port; /*0x188dcc*/
  else
    v36 = word_1E18A0; /*0x188dc3*/
  __outbyte(v36, v45); /*0x188dd6*/
  _InterlockedIncrement(dword_1E75EC); /*0x188dd7*/
  if ( a1 > 3 ) /*0x188de1*/
    prev_tcstatus1 &= __ROL4__(-2, a1 - 4); /*0x188dfe*/
  else
    prev_tcstatus0 &= __ROL4__(-2, a1); /*0x188dec*/
  v37 = (unsigned __int8)dma_assigned_bits; /*0x188e04*/
  if ( _bittest(&v37, a1) ) /*0x188e0b*/
  {
    v38 = a1 > 3; /*0x188e21*/
    v44 = dma_cmd_regs[v38] | 4; /*0x188e2c*/
    dma_cmd_regs[v38] = v44; /*0x188e2f*/
    us_spin(1); /*0x188e37*/
    if ( a1 <= 3 ) /*0x188e41*/
      v39 = _dma_chip_port; /*0x188e4c*/
    else
      v39 = word_1E18A0; /*0x188e43*/
    __outbyte(v39, v44); /*0x188e56*/
    _InterlockedIncrement(dword_1E75EC); /*0x188e57*/
    us_spin(1); /*0x188e60*/
    if ( a1 > 3 ) /*0x188e6b*/
      v40 = word_1E18A4; /*0x188e78*/
    else
      v40 = word_1E1896; /*0x188e6d*/
    __outbyte(v40, a1 & 3); /*0x188e82*/
    _InterlockedIncrement(dword_1E75EC); /*0x188e83*/
    v41 = a1 > 3; /*0x188e90*/
    v43 = dma_cmd_regs[v41] & 0xFB; /*0x188e9b*/
    dma_cmd_regs[v41] = v43; /*0x188e9e*/
    us_spin(1); /*0x188ea6*/
    if ( a1 <= 3 ) /*0x188ead*/
      v42 = _dma_chip_port; /*0x188eb8*/
    else
      v42 = word_1E18A0; /*0x188eaf*/
    __outbyte(v42, v43); /*0x188ec2*/
    _InterlockedIncrement(dword_1E75EC); /*0x188ec3*/
  }
  return 1; /*0x188ed2*/
}

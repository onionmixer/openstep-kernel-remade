/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x122764. */
void __cdecl in_arpinput(int a1, void *a2, unsigned int a3, int *a4)
{
  char *v4; // esi
  int v5; // ebx
  int i; // eax
  char *v7; // esi
  int j; // eax
  long double v9; // [esp-14h] [ebp-70h]
  long double v10; // [esp-Ch] [ebp-68h]
  int v11; // [esp+Ch] [ebp-50h]
  int v12; // [esp+10h] [ebp-4Ch]
  int v13; // [esp+14h] [ebp-48h]
  unsigned int v14; // [esp+18h] [ebp-44h] BYREF
  unsigned int v15; // [esp+1Ch] [ebp-40h] BYREF
  __int16 v16; // [esp+20h] [ebp-3Ch] BYREF
  _BYTE v17[14]; // [esp+22h] [ebp-3Ah] BYREF
  __int16 v18; // [esp+30h] [ebp-2Ch] BYREF
  unsigned int v19; // [esp+34h] [ebp-28h]
  _BYTE v20[2]; // [esp+40h] [ebp-1Ch] BYREF
  __int16 v21; // [esp+42h] [ebp-1Ah]
  __int16 v22; // [esp+44h] [ebp-18h]
  __int16 v23; // [esp+46h] [ebp-16h]
  _BYTE v24[20]; // [esp+48h] [ebp-14h] BYREF

  v13 = 0; /*0x12276d*/
  bcopy((char *)a4 + a4[1], v20, 0x1Cu); /*0x122781*/
  v16 = 2054; /*0x122788*/
  v12 = (unsigned __int16)__ROR2__(v21, 8); /*0x12279e*/
  v11 = (unsigned __int16)__ROR2__(v23, 8); /*0x1227ae*/
  if ( v22 != word_1DB968 ) /*0x1227bb*/
    goto LABEL_52; /*0x1227bb*/
  bcopy(&v24[(unsigned __int8)word_1DB968], &v15, 4u); /*0x1227d3*/
  bcopy(&v20[2 * (unsigned __int8)word_1DB968 + 8 + HIBYTE(word_1DB968)], &v14, 4u); /*0x1227f3*/
  if ( !bcmp(v24, a2, (unsigned __int8)word_1DB968) ) /*0x122808*/
    goto LABEL_52; /*0x122812*/
  if ( !bcmp(v24, &etherbroadcastaddr, 6u) ) /*0x122820*/
  {
    DWORD2(v10) = _byteswap_ulong(v15); /*0x122831*/
    DWORD1(v10) = aArpEtherAddres; /*0x122832*/
    LODWORD(v10) = 3; /*0x122837*/
    log(v10); /*0x122839*/
LABEL_52:
    m_freem((int)a4); /*0x122bd4*/
    return; /*0x122bd8*/
  }
  if ( v15 == a3 ) /*0x12284e*/
  {
    HIDWORD(v9) = ether_sprintf(v24); /*0x122856*/
    DWORD2(v9) = aDuplicateIpAdd; /*0x122857*/
    DWORD1(v9) = aSS_0; /*0x12285c*/
    LODWORD(v9) = 3; /*0x122861*/
    log(v9); /*0x122863*/
    v14 = a3; /*0x12286b*/
    if ( v11 != 1 ) /*0x122875*/
      goto LABEL_52; /*0x122875*/
    v4 = nullptr; /*0x12287b*/
  }
  else
  {
    v5 = splimp(); /*0x122889*/
    v4 = (char *)&arptab + 180 * (v15 % 0x13); /*0x1228a0*/
    for ( i = 0; i <= 8; ++i ) /*0x1228a7*/
    {
      if ( *(_DWORD *)v4 == v15 && (!a1 || *((_DWORD *)v4 + 4) == a1) ) /*0x1228bc*/
        break; /*0x1228bc*/
      v4 += 20; /*0x1228bf*/
    }
    if ( i > 8 ) /*0x1228ca*/
      v4 = nullptr; /*0x1228cc*/
    if ( v4 ) /*0x1228d0*/
    {
      bcopy(v24, v4 + 4, (unsigned __int8)word_1DB968); /*0x1228e2*/
      if ( (unsigned __int8)word_1DB968 <= 5u ) /*0x1228f2*/
        bzero(&v4[(unsigned __int8)word_1DB968 + 4], 6 - (unsigned __int8)word_1DB968); /*0x122906*/
      v4[11] |= 2u; /*0x12290e*/
      if ( *((_DWORD *)v4 + 3) ) /*0x122912*/
      {
        v18 = 2; /*0x12291c*/
        v19 = v15; /*0x122925*/
        if_output_mbuf(a1, *((_DWORD *)v4 + 3), (int)&v18); /*0x122934*/
        *((_DWORD *)v4 + 3) = 0; /*0x122939*/
      }
    }
    else if ( v14 == a3 ) /*0x12294e*/
    {
      v4 = (char *)arptnew(a1, &v15); /*0x12295d*/
      bcopy(v24, v4 + 4, (unsigned __int8)word_1DB968); /*0x12296f*/
      if ( (unsigned __int8)word_1DB968 <= 5u ) /*0x12297f*/
        bzero(&v4[(unsigned __int8)word_1DB968 + 4], 6 - (unsigned __int8)word_1DB968); /*0x122993*/
      v4[11] |= 2u; /*0x12299b*/
    }
    splx(v5); /*0x1229a0*/
  }
  if ( v12 == 2048 ) /*0x1229af*/
  {
    if ( v11 == 1 ) /*0x1229d4*/
      goto LABEL_33; /*0x1229d4*/
  }
  else
  {
    if ( v12 != 4096 ) /*0x1229b8*/
      goto LABEL_33; /*0x1229b8*/
    if ( v4 ) /*0x1229bc*/
      v4[11] |= 0x10u; /*0x1229be*/
    if ( v11 != 1 ) /*0x1229c6*/
      goto LABEL_52; /*0x1229c6*/
  }
  if ( (*(_BYTE *)(a1 + 12) & 0x20) != 0 ) /*0x1229dd*/
    goto LABEL_52; /*0x1229dd*/
LABEL_33:
  if ( a3 == v14 ) /*0x1229e9*/
  {
    bcopy(v24, &v20[HIBYTE(word_1DB968) + 8 + (unsigned __int8)word_1DB968], (unsigned __int8)word_1DB968); /*0x122a05*/
    bcopy(a2, v24, (unsigned __int8)word_1DB968); /*0x122a17*/
  }
  else
  {
    v7 = (char *)&arptab + 180 * (v14 % 0x13); /*0x122a30*/
    for ( j = 0; j <= 8; ++j ) /*0x122a37*/
    {
      if ( *(_DWORD *)v7 == v14 && (!a1 || *((_DWORD *)v7 + 4) == a1) ) /*0x122a4c*/
        break; /*0x122a4c*/
      v7 += 20; /*0x122a4f*/
    }
    if ( j > 8 ) /*0x122a5a*/
      v7 = nullptr; /*0x122a5c*/
    if ( !v7 || (v7[11] & 8) == 0 ) /*0x122a6a*/
      goto LABEL_52; /*0x122a6a*/
    bcopy(v24, &v20[HIBYTE(word_1DB968) + 8 + (unsigned __int8)word_1DB968], (unsigned __int8)word_1DB968); /*0x122a8a*/
    bcopy(v7 + 4, v24, (unsigned __int8)word_1DB968); /*0x122a9c*/
  }
  bcopy( /*0x122abf*/
    &v24[(unsigned __int8)word_1DB968],
    &v20[2 * (unsigned __int8)word_1DB968 + 8 + HIBYTE(word_1DB968)],
    HIBYTE(word_1DB968));
  bcopy(&v14, &v24[(unsigned __int8)word_1DB968], HIBYTE(word_1DB968)); /*0x122adc*/
  v23 = 2; /*0x122ae1*/
  bcopy(&v20[HIBYTE(word_1DB968) + 8 + (unsigned __int8)word_1DB968], v17, (unsigned __int8)word_1DB968); /*0x122b04*/
  bcopy(&v16, &v17[2 * (unsigned __int8)word_1DB968], 2u); /*0x122b1b*/
  if ( v11 == 2 ) /*0x122b27*/
  {
    v21 = __ROR2__(4096, 8); /*0x122b32*/
  }
  else if ( v12 == 2048 && (*(_BYTE *)(a1 + 12) & 0x20) == 0 ) /*0x122b48*/
  {
    v13 = m_copy(a4, 0, 1000000000); /*0x122b5a*/
  }
  v23 = __ROR2__(v23, 8); /*0x122b75*/
  bcopy(v20, (char *)a4 + a4[1], 0x1Cu); /*0x122b83*/
  v16 = 0; /*0x122b88*/
  if_output_mbuf(a1, (int)a4, (int)&v16); /*0x122b9a*/
  if ( v13 ) /*0x122ba6*/
  {
    v21 = __ROR2__(4096, 8); /*0x122bb1*/
    bcopy(v20, (void *)(*(_DWORD *)(v13 + 4) + v13), 0x1Cu); /*0x122bbf*/
    if_output_mbuf(a1, v13, (int)&v16); /*0x122bcd*/
  }
}

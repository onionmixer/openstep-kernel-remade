/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12b2c0. */
void __cdecl udp_input(int a1, int a2)
{
  _BYTE *v2; // ecx
  int v3; // ebx
  int v4; // eax
  __int16 v5; // ax
  int v6; // edx
  int i; // edi
  int v8; // eax
  int v9; // eax
  int **v10; // eax
  int v11; // ebx
  int v12; // ebx
  _DWORD *v13; // eax
  _DWORD *v14; // edi
  unsigned __int32 v15; // ebx
  _DWORD *v16; // edi
  int v17; // edx
  int v18; // edx
  int v19; // eax
  int v20; // [esp+10h] [ebp-20h]
  int v21; // [esp+10h] [ebp-20h]
  int *v22; // [esp+14h] [ebp-1Ch]
  _DWORD *v23; // [esp+18h] [ebp-18h]
  _BYTE v24[20]; // [esp+1Ch] [ebp-14h] BYREF

  v22 = (int *)a1; /*0x12b2cc*/
  if ( *(_DWORD *)(a1 + 4) > 0x7Cu || *(_WORD *)(a1 + 8) <= 0x1Bu ) /*0x12b2da*/
  {
    v22 = m_pullup(a1, 28); /*0x12b2e7*/
    if ( !v22 ) /*0x12b2ef*/
    {
      ++udpstat; /*0x12b2f1*/
      return; /*0x12b2f7*/
    }
  }
  v2 = (char *)v22 + v22[1]; /*0x12b2ff*/
  v23 = v2; /*0x12b302*/
  if ( (*v2 & 0xFu) > 5 ) /*0x12b30d*/
    ip_stripoptions((unsigned int)v2, 0); /*0x12b312*/
  v3 = (unsigned __int16)__ROR2__(*((_WORD *)v23 + 12), 8); /*0x12b325*/
  v4 = *((__int16 *)v23 + 1); /*0x12b328*/
  if ( v4 != v3 ) /*0x12b32e*/
  {
    if ( v3 > v4 ) /*0x12b332*/
    {
      ++dword_1EAB28; /*0x12b334*/
      goto LABEL_49; /*0x12b33a*/
    }
    m_adj(v22, v3 - v4); /*0x12b34b*/
  }
  qmemcpy(v24, v23, sizeof(v24)); /*0x12b35f*/
  if ( udpcksum ) /*0x12b368*/
  {
    if ( *((_WORD *)v23 + 13) ) /*0x12b36d*/
    {
      v23[1] = 0; /*0x12b374*/
      *v23 = 0; /*0x12b37b*/
      *((_BYTE *)v23 + 8) = 0; /*0x12b381*/
      *((_WORD *)v23 + 5) = *((_WORD *)v23 + 12); /*0x12b38c*/
      v5 = in_cksum(v22, v3 + 20); /*0x12b398*/
      *((_WORD *)v23 + 13) = v5; /*0x12b3a0*/
      if ( v5 ) /*0x12b3aa*/
      {
        ++dword_1EAB24; /*0x12b3ac*/
        m_freem((int)v22); /*0x12b3b6*/
        return; /*0x12b3b6*/
      }
    }
  }
  if ( (_byteswap_ulong(v23[4]) & 0xF0000000) == 0xE0000000 || in_broadcast(v23[4]) ) /*0x12b3d3*/
  {
    word_1DBEF6 = *((_WORD *)v23 + 10); /*0x12b3ea*/
    dword_1DBEF8 = v23[3]; /*0x12b3f7*/
    *((_WORD *)v22 + 4) -= 28; /*0x12b400*/
    v22[1] += 28; /*0x12b405*/
    v6 = 0; /*0x12b409*/
    for ( i = udb; (int *)i != &udb; i = *(_DWORD *)i ) /*0x12b417*/
    {
      if ( *(_WORD *)(i + 24) == *((_WORD *)v23 + 11) ) /*0x12b42b*/
      {
        v8 = *(_DWORD *)(i + 20); /*0x12b431*/
        if ( !v8 || v23[4] == v8 ) /*0x12b43b*/
        {
          v9 = *(_DWORD *)(i + 12); /*0x12b441*/
          if ( !v9 || v23[3] == v9 && *(_WORD *)(i + 16) == *((_WORD *)v23 + 10) ) /*0x12b458*/
          {
            if ( v6 ) /*0x12b45c*/
            {
              v20 = v6; /*0x12b469*/
              v10 = (int **)m_copy(v22, 0, 1000000000); /*0x12b46c*/
              v11 = (int)v10; /*0x12b471*/
              if ( v10 ) /*0x12b47b*/
              {
                if ( sbappendaddr((unsigned __int16 *)(v20 + 36), (int *)&udp_in, v10, 0) ) /*0x12b48f*/
                  sowakeup(v20, v20 + 36); /*0x12b4b1*/
                else
                  m_freem(v11); /*0x12b49f*/
              }
            }
            v6 = *(_DWORD *)(i + 28); /*0x12b4b9*/
            if ( (*(_BYTE *)(v6 + 2) & 4) == 0 ) /*0x12b4c0*/
              break; /*0x12b4c0*/
          }
        }
      }
    }
    if ( v6 ) /*0x12b4d2*/
    {
      v12 = v6 + 36; /*0x12b4e3*/
      v21 = v6; /*0x12b4e7*/
      if ( sbappendaddr((unsigned __int16 *)(v6 + 36), (int *)&udp_in, (int **)v22, 0) ) /*0x12b4ea*/
      {
        sowakeup(v21, v12); /*0x12b4fe*/
        return; /*0x12b4fe*/
      }
    }
    goto LABEL_49; /*0x12b4f7*/
  }
  v13 = in_pcblookup(&udb, v23[3], *((_WORD *)v23 + 10), v23[4], *((_WORD *)v23 + 11), 1); /*0x12b520*/
  v14 = v13; /*0x12b525*/
  if ( !v13 ) /*0x12b52c*/
  {
    v15 = _byteswap_ulong(v23[4]); /*0x12b53a*/
    v16 = (_DWORD *)in_ifaddr; /*0x12b53c*/
    if ( in_ifaddr ) /*0x12b544*/
    {
      while ( 1 ) /*0x12b548*/
      {
        if ( (*(_BYTE *)(v16[8] + 12) & 2) != 0 ) /*0x12b54f*/
        {
          v17 = v15 ^ v16[10]; /*0x12b554*/
          if ( v17 == ~v16[11] ) /*0x12b55d*/
            break; /*0x12b55d*/
          if ( !v17 ) /*0x12b565*/
            break; /*0x12b565*/
          v18 = v15 ^ v16[12]; /*0x12b56e*/
          if ( v18 == ~v16[13] || !v18 ) /*0x12b57f*/
            break; /*0x12b57f*/
        }
        v16 = (_DWORD *)v16[16]; /*0x12b585*/
        if ( !v16 ) /*0x12b58a*/
          goto LABEL_42; /*0x12b58a*/
      }
    }
    else
    {
LABEL_42:
      v19 = v23[4]; /*0x12b58c*/
      if ( v19 != -1 && v19 && !in_broadcast(v23[4]) ) /*0x12b5a4*/
      {
        qmemcpy(v23, v24, 0x14u); /*0x12b5be*/
        icmp_error(v23, 3u, 3, a2, nullptr); /*0x12b5ce*/
        return; /*0x12b5d3*/
      }
    }
    goto LABEL_49; /*0x12b57f*/
  }
  word_1DBEF6 = *((_WORD *)v23 + 10); /*0x12b5df*/
  dword_1DBEF8 = v23[3]; /*0x12b5ec*/
  *((_WORD *)v22 + 4) -= 28; /*0x12b5f5*/
  v22[1] += 28; /*0x12b5fa*/
  if ( !sbappendaddr((unsigned __int16 *)(v13[7] + 36), (int *)&udp_in, (int **)v22, 0) ) /*0x12b617*/
  {
LABEL_49:
    m_freem((int)v22); /*0x12b628*/
    return; /*0x12b62c*/
  }
  sowakeup(v14[7], v14[7] + 36); /*0x12b621*/
}

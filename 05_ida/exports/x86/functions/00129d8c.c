/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x129d8c. */
int __cdecl tcp_output(int a1)
{
  unsigned __int16 v1; // ax
  int v2; // eax
  int v3; // edi
  int v4; // edx
  int v5; // edx
  int result; // eax
  int v7; // eax
  int v8; // eax
  int v9; // edx
  int v10; // edx
  int v11; // [esp+Ch] [ebp-30h]
  void *v12; // [esp+Ch] [ebp-30h]
  char *v13; // [esp+Ch] [ebp-30h]
  char v14; // [esp+10h] [ebp-2Ch]
  int v15; // [esp+10h] [ebp-2Ch]
  int v16; // [esp+10h] [ebp-2Ch]
  int v17; // [esp+14h] [ebp-28h]
  int v18; // [esp+18h] [ebp-24h]
  _BOOL4 v19; // [esp+1Ch] [ebp-20h]
  int v20; // [esp+20h] [ebp-1Ch]
  size_t v21; // [esp+24h] [ebp-18h]
  int *v22; // [esp+28h] [ebp-14h]
  char v23; // [esp+2Ch] [ebp-10h]
  int v24; // [esp+30h] [ebp-Ch]
  int v25; // [esp+34h] [ebp-8h]
  int v26; // [esp+34h] [ebp-8h]
  int v27; // [esp+38h] [ebp-4h]

  v27 = *(_DWORD *)(*(_DWORD *)(a1 + 32) + 28); /*0x129d9e*/
  v19 = *(_DWORD *)(a1 + 80) == *(_DWORD *)(a1 + 36); /*0x129daf*/
  if ( *(_DWORD *)(a1 + 80) == *(_DWORD *)(a1 + 36) && *(_WORD *)(a1 + 88) >= *(_WORD *)(a1 + 20) ) /*0x129dbe*/
    *(_WORD *)(a1 + 84) = *(_WORD *)(a1 + 24); /*0x129dc4*/
  while ( 1 ) /*0x129dc8*/
  {
    v18 = 0; /*0x129dc8*/
    v24 = *(_DWORD *)(a1 + 40) - *(_DWORD *)(a1 + 36); /*0x129dd5*/
    v1 = *(_WORD *)(a1 + 60); /*0x129dd8*/
    if ( v1 > *(_WORD *)(a1 + 84) ) /*0x129de3*/
      v1 = *(_WORD *)(a1 + 84); /*0x129de5*/
    v25 = v1; /*0x129dec*/
    if ( *(_BYTE *)(a1 + 26) ) /*0x129def*/
    {
      if ( v1 ) /*0x129df7*/
      {
        *(_WORD *)(a1 + 12) = 0; /*0x129e04*/
        *(_WORD *)(a1 + 18) = 0; /*0x129e0a*/
      }
      else
      {
        v25 = 1; /*0x129df9*/
      }
    }
    v23 = tcp_outflags[*(__int16 *)(a1 + 8)]; /*0x129e1b*/
    v2 = *(unsigned __int16 *)(v27 + 60); /*0x129e21*/
    if ( v25 < v2 ) /*0x129e28*/
      v2 = v25; /*0x129e2a*/
    v3 = v2 - v24; /*0x129e2f*/
    if ( v2 - v24 < 0 ) /*0x129e32*/
    {
      v3 = 0; /*0x129e34*/
      if ( !v25 ) /*0x129e3a*/
      {
        *(_WORD *)(a1 + 10) = 0; /*0x129e3c*/
        *(_DWORD *)(a1 + 40) = *(_DWORD *)(a1 + 36); /*0x129e45*/
      }
    }
    v11 = *(unsigned __int16 *)(a1 + 24); /*0x129e4c*/
    if ( v3 > v11 ) /*0x129e51*/
    {
      v3 = *(unsigned __int16 *)(a1 + 24); /*0x129e53*/
      v18 = 1; /*0x129e56*/
    }
    v17 = *(unsigned __int16 *)(v27 + 60); /*0x129e69*/
    if ( v3 + *(_DWORD *)(a1 + 40) - (*(_DWORD *)(a1 + 36) + v17) < 0 ) /*0x129e73*/
      v23 &= ~1u; /*0x129e75*/
    v26 = *(unsigned __int16 *)(v27 + 38) - *(unsigned __int16 *)(v27 + 36); /*0x129e93*/
    if ( v26 > *(unsigned __int16 *)(v27 + 42) - *(unsigned __int16 *)(v27 + 40) ) /*0x129e9b*/
      v26 = *(unsigned __int16 *)(v27 + 42) - *(unsigned __int16 *)(v27 + 40); /*0x129e9d*/
    if ( !v3 /*0x129eeb*/
      || v11 != v3
      && (!v19 && (*(_BYTE *)(a1 + 27) & 4) == 0 || v17 > v3 + v24)
      && !*(_BYTE *)(a1 + 26)
      && v3 < *(_WORD *)(a1 + 102) >> 1
      && *(_DWORD *)(a1 + 40) - *(_DWORD *)(a1 + 80) >= 0 )
    {
      if ( v26 <= 0 /*0x129f17*/
        || (v4 = v26 - (*(_DWORD *)(a1 + 76) - *(_DWORD *)(a1 + 64)), v4 < 2 * *(unsigned __int16 *)(a1 + 24))
        && 2 * v4 < *(unsigned __int16 *)(v27 + 38) )
      {
        v14 = *(_BYTE *)(a1 + 27); /*0x129f1c*/
        if ( (v14 & 1) == 0 && (v23 & 6) == 0 ) /*0x129f28*/
        {
          v5 = *(_DWORD *)(a1 + 36); /*0x129f2a*/
          if ( *(_DWORD *)(a1 + 44) - v5 <= 0 && ((v23 & 1) == 0 || (v14 & 0x10) != 0 && *(_DWORD *)(a1 + 40) != v5) ) /*0x129f49*/
          {
            if ( *(_WORD *)(v27 + 60) && !*(_WORD *)(a1 + 10) && !*(_WORD *)(a1 + 12) ) /*0x129f64*/
            {
              *(_WORD *)(a1 + 18) = 0; /*0x129f6f*/
              tcp_setpersist(a1); /*0x129f76*/
            }
            return 0; /*0x129f7b*/
          }
        }
      }
    }
    v21 = 0; /*0x129f80*/
    v20 = 40; /*0x129f87*/
    if ( (v23 & 2) != 0 && (*(_BYTE *)(a1 + 27) & 8) == 0 ) /*0x129f9a*/
    {
      v21 = 4; /*0x129f9c*/
      v20 = 44; /*0x129fa3*/
      word_1DBE67 = __ROR2__(tcp_mss(a1, 0), 8); /*0x129fb9*/
    }
    v12 = (void *)splimp(); /*0x129fc4*/
    v22 = (int *)mfree; /*0x129fcd*/
    if ( mfree ) /*0x129fd2*/
    {
      if ( *(_WORD *)(mfree + 10) ) /*0x129fd4*/
        panic(aMget_11); /*0x129fe0*/
      *(_WORD *)(mfree + 10) = 2; /*0x129feb*/
      --word_1E917C[0]; /*0x129ff1*/
      ++word_1E9180; /*0x129ff8*/
      mfree = *v22; /*0x12a001*/
      *v22 = 0; /*0x12a007*/
      v22[1] = 12; /*0x12a00d*/
    }
    else
    {
      v22 = m_more(0, 2); /*0x12a021*/
    }
    splx(v12); /*0x12a02b*/
    if ( !v22 ) /*0x12a037*/
      return 55; /*0x12a03e*/
    v22[1] = 84 - v21; /*0x12a04f*/
    *((_WORD *)v22 + 4) = v20; /*0x12a056*/
    if ( v3 ) /*0x12a05c*/
    {
      if ( *(_BYTE *)(a1 + 26) && v3 == 1 ) /*0x12a067*/
      {
        ++dword_1EEDC4; /*0x12a069*/
      }
      else if ( *(_DWORD *)(a1 + 40) - *(_DWORD *)(a1 + 80) >= 0 ) /*0x12a07a*/
      {
        ++dword_1EEDB0; /*0x12a08c*/
        dword_1EEDB4 += v3; /*0x12a092*/
      }
      else
      {
        ++dword_1EEDB8; /*0x12a07c*/
        dword_1EEDBC += v3; /*0x12a082*/
      }
      v7 = m_copy(*(int **)(v27 + 72), v24, v3); /*0x12a0a4*/
      *v22 = v7; /*0x12a0ac*/
      if ( v7 ) /*0x12a0b3*/
      {
        if ( v3 + v24 == *(unsigned __int16 *)(v27 + 60) ) /*0x12a0ca*/
          v23 |= 8u; /*0x12a0cc*/
      }
      else
      {
        v3 = 0; /*0x12a0b5*/
      }
    }
    else if ( (*(_BYTE *)(a1 + 27) & 1) != 0 ) /*0x12a0d8*/
    {
      ++dword_1EEDC0; /*0x12a0da*/
    }
    else if ( (v23 & 7) != 0 ) /*0x12a0ea*/
    {
      ++dword_1EEDD0; /*0x12a0ec*/
    }
    else if ( *(_DWORD *)(a1 + 44) - *(_DWORD *)(a1 + 36) <= 0 ) /*0x12a0fc*/
    {
      ++dword_1EEDCC; /*0x12a108*/
    }
    else
    {
      ++dword_1EEDC8; /*0x12a0fe*/
    }
    v13 = (char *)v22 + v22[1]; /*0x12a114*/
    if ( !*(_DWORD *)(a1 + 28) ) /*0x12a117*/
      panic(aTcpOutput); /*0x12a122*/
    bcopy(*(const void **)(a1 + 28), v13, 0x28u); /*0x12a134*/
    if ( (v23 & 1) != 0 && (*(_BYTE *)(a1 + 27) & 0x10) != 0 ) /*0x12a148*/
    {
      v8 = *(_DWORD *)(a1 + 40); /*0x12a14a*/
      if ( *(_DWORD *)(a1 + 80) == v8 ) /*0x12a150*/
        *(_DWORD *)(a1 + 40) = v8 - 1; /*0x12a153*/
    }
    *((_DWORD *)v13 + 6) = _byteswap_ulong(*(_DWORD *)(a1 + 40)); /*0x12a15e*/
    *((_DWORD *)v13 + 7) = _byteswap_ulong(*(_DWORD *)(a1 + 64)); /*0x12a166*/
    if ( v21 ) /*0x12a16d*/
    {
      bcopy(&tcp_initopt, v13 + 40, v21); /*0x12a17f*/
      v13[32] = (16 * ((v21 + 20) >> 2)) | v13[32] & 0xF; /*0x12a199*/
    }
    v13[33] = v23; /*0x12a1a5*/
    if ( v26 < *(_WORD *)(v27 + 38) >> 2 && v26 < *(unsigned __int16 *)(a1 + 24) ) /*0x12a1c4*/
      v26 = 0; /*0x12a1c6*/
    if ( v26 > 0xFFFF ) /*0x12a1d4*/
      v26 = 0xFFFF; /*0x12a1d6*/
    if ( v26 < *(_DWORD *)(a1 + 76) - *(_DWORD *)(a1 + 64) ) /*0x12a1e6*/
      v26 = *(_DWORD *)(a1 + 76) - *(_DWORD *)(a1 + 64); /*0x12a1e8*/
    *((_WORD *)v13 + 17) = __ROR2__(v26, 8); /*0x12a1f6*/
    v15 = *(_DWORD *)(a1 + 44); /*0x12a1fd*/
    v9 = *(_DWORD *)(a1 + 40); /*0x12a200*/
    if ( v15 - v9 <= 0 ) /*0x12a209*/
    {
      *(_DWORD *)(a1 + 44) = *(_DWORD *)(a1 + 36); /*0x12a223*/
    }
    else
    {
      *((_WORD *)v13 + 19) = __ROR2__(v15 - v9, 8); /*0x12a216*/
      v13[33] |= 0x20u; /*0x12a21a*/
    }
    if ( v3 + v21 ) /*0x12a229*/
      *((_WORD *)v13 + 5) = __ROR2__(v3 + v21 + 20, 8); /*0x12a23f*/
    *((_WORD *)v13 + 18) = in_cksum(v22, v3 + v20); /*0x12a255*/
    if ( *(_BYTE *)(a1 + 26) && *(_WORD *)(a1 + 12) ) /*0x12a262*/
    {
      if ( v3 + *(_DWORD *)(a1 + 40) - *(_DWORD *)(a1 + 80) > 0 ) /*0x12a2f4*/
        *(_DWORD *)(a1 + 80) = v3 + *(_DWORD *)(a1 + 40); /*0x12a2f6*/
    }
    else
    {
      v16 = *(_DWORD *)(a1 + 40); /*0x12a26c*/
      if ( (v23 & 3) != 0 ) /*0x12a275*/
      {
        if ( (v23 & 2) != 0 ) /*0x12a27a*/
          ++*(_DWORD *)(a1 + 40); /*0x12a27d*/
        if ( (v23 & 1) != 0 ) /*0x12a286*/
        {
          ++*(_DWORD *)(a1 + 40); /*0x12a288*/
          *(_BYTE *)(a1 + 27) |= 0x10u; /*0x12a28b*/
        }
      }
      v10 = v3 + *(_DWORD *)(a1 + 40); /*0x12a292*/
      *(_DWORD *)(a1 + 40) = v10; /*0x12a294*/
      if ( v10 - *(_DWORD *)(a1 + 80) > 0 ) /*0x12a29e*/
      {
        *(_DWORD *)(a1 + 80) = v10; /*0x12a2a0*/
        if ( !*(_WORD *)(a1 + 90) ) /*0x12a2a3*/
        {
          *(_WORD *)(a1 + 90) = 1; /*0x12a2aa*/
          *(_DWORD *)(a1 + 92) = v16; /*0x12a2b3*/
          ++dword_1EED88; /*0x12a2b6*/
        }
      }
      if ( !*(_WORD *)(a1 + 10) && *(_DWORD *)(a1 + 40) != *(_DWORD *)(a1 + 36) ) /*0x12a2c9*/
      {
        *(_WORD *)(a1 + 10) = *(_WORD *)(a1 + 20); /*0x12a2cf*/
        if ( *(_WORD *)(a1 + 12) ) /*0x12a2d3*/
        {
          *(_WORD *)(a1 + 12) = 0; /*0x12a2da*/
          *(_WORD *)(a1 + 18) = 0; /*0x12a2e0*/
        }
      }
    }
    if ( (*(_BYTE *)(v27 + 2) & 1) != 0 ) /*0x12a300*/
      tcp_trace(1, *(_WORD *)(a1 + 8), (const void *)a1, v13, 0); /*0x12a310*/
    *((_WORD *)v13 + 1) = v3 + v21 + 40; /*0x12a326*/
    v13[8] = 60; /*0x12a32a*/
    result = ip_output( /*0x12a349*/
               (int)v22,
               *(_DWORD *)(*(_DWORD *)(a1 + 32) + 56),
               (int *)(*(_DWORD *)(a1 + 32) + 36),
               *(_BYTE *)(v27 + 2) & 0x10,
               0);
    if ( result ) /*0x12a353*/
      break; /*0x12a353*/
    ++dword_1EEDAC; /*0x12a384*/
    if ( v26 > 0 && *(_DWORD *)(a1 + 64) + v26 - *(_DWORD *)(a1 + 76) > 0 ) /*0x12a39d*/
      *(_DWORD *)(a1 + 76) = *(_DWORD *)(a1 + 64) + v26; /*0x12a39f*/
    *(_BYTE *)(a1 + 27) &= 0xFCu; /*0x12a3a2*/
    if ( !v18 ) /*0x12a3aa*/
      return 0; /*0x12a3aa*/
  }
  if ( result != 55 ) /*0x12a358*/
  {
    if ( result != 65 && result != 50 || *(__int16 *)(a1 + 8) <= 2 ) /*0x12a377*/
      return result; /*0x12a377*/
    *(_WORD *)(a1 + 106) = result; /*0x12a379*/
    return 0; /*0x12a37f*/
  }
  tcp_quench(*(_DWORD *)(a1 + 32)); /*0x12a35e*/
  return 0; /*0x12a3b5*/
}

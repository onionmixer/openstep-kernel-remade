/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1108e8. */
int __cdecl ttwrite(unsigned int a1, _DWORD *a2)
{
  int v2; // eax
  int v4; // ebx
  int v5; // edi
  _DWORD *v6; // esi
  __int16 v7; // ax
  int v8; // esi
  char *v9; // edi
  int v10; // eax
  int v11; // eax
  int v12; // ebx
  void (__cdecl *v13)(unsigned int); // eax
  _BYTE *v14; // eax
  int i; // ebx
  size_t v16; // ebx
  int v17; // eax
  int v18; // ebx
  void (__cdecl *v19)(unsigned int); // eax
  int v20; // eax
  size_t v21; // ebx
  int v22; // ebx
  void (__cdecl *v23)(unsigned int); // eax
  int v24; // ebx
  void (__cdecl *v25)(unsigned int); // eax
  int v26; // ebx
  int v27; // esi
  void (__cdecl *v28)(unsigned int); // eax
  int v29; // eax
  int v30; // [esp+Ch] [ebp-74h]
  int v31; // [esp+10h] [ebp-70h]
  int v32; // [esp+14h] [ebp-6Ch]
  int v33; // [esp+18h] [ebp-68h]
  _BYTE v34[100]; // [esp+1Ch] [ebp-64h] BYREF

  v33 = ttynty(a1); /*0x1108fa*/
  v32 = tthiwat[*(_BYTE *)(a1 + 74) & 0x1F]; /*0x11090e*/
  v31 = a2[5]; /*0x110917*/
  v30 = 0; /*0x11091a*/
  while ( 1 ) /*0x110927*/
  {
LABEL_2:
    v2 = *(_DWORD *)(a1 + 64); /*0x110924*/
    if ( (v2 & 0x10) == 0 && *(__int16 *)(v33 + 16) >= 0 ) /*0x110936*/
    {
      while ( (v2 & 0x8000u) != 0 ) /*0x11093b*/
      {
        if ( (v2 & 0x2000) != 0 ) /*0x110944*/
          goto LABEL_6; /*0x110944*/
        sleep(a1); /*0x11096a*/
        v2 = *(_DWORD *)(a1 + 64); /*0x110975*/
        if ( (v2 & 0x10) != 0 || *(__int16 *)(v33 + 16) < 0 ) /*0x110984*/
          goto LABEL_10; /*0x110984*/
      }
      return 5; /*0x1109e0*/
    }
LABEL_10:
    v4 = *(_DWORD *)active_u; /*0x11098c*/
    if ( (*(_BYTE *)(*(_DWORD *)active_u + 22) & 2) == 0 ) /*0x110992*/
      break; /*0x110992*/
    v5 = get_posix_proc(*(__int16 *)(v4 + 48))[4]; /*0x11099e*/
    v6 = *(_DWORD **)(v5 + 12); /*0x1109a8*/
    if ( v6 == (_DWORD *)*(__int16 *)(a1 + 68) /*0x1109d3*/
      || *(_DWORD *)(active_u + 360) != a1
      || (*(_BYTE *)(a1 + 62) & 0x40) == 0
      || (*(_BYTE *)(v4 + 34) & 0x20) != 0
      || (*(_BYTE *)(v4 + 30) & 0x20) != 0 )
    {
      goto LABEL_27; /*0x1109d3*/
    }
    if ( !*(_DWORD *)(v5 + 16) ) /*0x1109d5*/
      return 5; /*0x1109d9*/
    gsignal(v6, (char *)0x16); /*0x1109eb*/
LABEL_26:
    sleep((unsigned int)&lbolt); /*0x110a26*/
  }
  v7 = *(_WORD *)(v4 + 46); /*0x1109f0*/
  if ( *(_WORD *)(a1 + 68) != v7 /*0x110a1b*/
    && *(_DWORD *)(active_u + 360) == a1
    && (*(_BYTE *)(a1 + 62) & 0x40) != 0
    && (*(_BYTE *)(v4 + 41) & 0x10) == 0
    && (*(_BYTE *)(v4 + 34) & 0x20) == 0
    && (*(_BYTE *)(v4 + 30) & 0x20) == 0 )
  {
    gsignal((_DWORD *)v7, (char *)0x16); /*0x110a21*/
    goto LABEL_26; /*0x110a21*/
  }
LABEL_27:
  if ( (int)a2[5] <= 0 ) /*0x110a43*/
  {
LABEL_74:
    v24 = spltty(); /*0x110d1a*/
    if ( (*(_DWORD *)(a1 + 64) & 0x4000121) == 0 ) /*0x110d2b*/
    {
      v25 = *(void (__cdecl **)(unsigned int))(a1 + 36); /*0x110d2d*/
      if ( v25 ) /*0x110d32*/
        v25(a1); /*0x110d35*/
    }
    splx(v24); /*0x110d3b*/
    return v30; /*0x110d43*/
  }
  while ( 1 ) /*0x110a51*/
  {
    v8 = *(_DWORD *)(*a2 + 4); /*0x110a51*/
    if ( !v8 ) /*0x110a56*/
    {
      --a2[1]; /*0x110a58*/
      *a2 += 8; /*0x110a5b*/
      if ( (int)a2[1] <= 0 ) /*0x110a62*/
        panic(aTtwrite); /*0x110a6d*/
      goto LABEL_73; /*0x110a62*/
    }
    if ( v8 > 100 ) /*0x110a7f*/
      v8 = 100; /*0x110a81*/
    v9 = v34; /*0x110a86*/
    v30 = uiomove((int)v34, v8, 1, a2); /*0x110a96*/
    if ( v30 ) /*0x110a9e*/
      goto LABEL_74; /*0x110a9e*/
    if ( *(_DWORD *)(a1 + 24) > v32 ) /*0x110aad*/
      break; /*0x110aad*/
    v10 = *(_DWORD *)(a1 + 60); /*0x110ab3*/
    if ( (v10 & 0x800000) == 0 ) /*0x110abb*/
    {
      if ( (v10 & 0x200024) != 4 || (*(_BYTE *)(v33 + 19) & 0x10) == 0 ) /*0x110ad6*/
      {
        if ( (*(_DWORD *)(a1 + 60) & 0x2200020) == 0 /*0x110ba7*/
          && (*(_DWORD *)(v33 + 16) & 0x10000000) != 0
          && (*(_DWORD *)(v33 + 16) & 0x300) != 0x300 )
        {
          v14 = v34; /*0x110bad*/
          for ( i = v8 - 1; i >= 0; --i ) /*0x110bb4*/
            *v14++ &= ~0x80u; /*0x110bbc*/
        }
        while ( 1 ) /*0x110d05*/
        {
          if ( v8 <= 0 ) /*0x110d07*/
            goto LABEL_73; /*0x110d07*/
          if ( (*(_DWORD *)(a1 + 60) & 0x200020) != 0 || (*(_BYTE *)(v33 + 19) & 0x10) == 0 ) /*0x110bdb*/
            break; /*0x110bdb*/
          v17 = scanc(v8, v9, partab, 63); /*0x110bed*/
          v16 = v8 - v17; /*0x110bf4*/
          if ( v8 != v17 ) /*0x110bfb*/
            goto LABEL_65; /*0x110bfb*/
          *(_BYTE *)(a1 + 75) = 0; /*0x110c00*/
          if ( (int)ttyoutput(*v9, a1) >= 0 ) /*0x110c13*/
          {
            v18 = spltty(); /*0x110c1a*/
            if ( (*(_DWORD *)(a1 + 64) & 0x4000121) == 0 ) /*0x110c26*/
            {
              v19 = *(void (__cdecl **)(unsigned int))(a1 + 36); /*0x110c28*/
              if ( v19 ) /*0x110c2d*/
                v19(a1); /*0x110c30*/
            }
            splx(v18); /*0x110c36*/
            sleep((unsigned int)&lbolt); /*0x110c45*/
            *(_DWORD *)*a2 -= v8; /*0x110c5a*/
            *(_DWORD *)(*a2 + 4) += v8; /*0x110c5e*/
            a2[5] += v8; /*0x110c61*/
            a2[2] -= v8; /*0x110c64*/
            goto LABEL_2; /*0x110c67*/
          }
          ++v9; /*0x110c6c*/
          --v8; /*0x110c6d*/
LABEL_70:
          if ( *(char *)(a1 + 62) < 0 || *(_DWORD *)(a1 + 24) > v32 ) /*0x110d03*/
            goto LABEL_78; /*0x110d03*/
        }
        v16 = v8; /*0x110bdd*/
LABEL_65:
        *(_BYTE *)(a1 + 75) = 0; /*0x110c74*/
        v20 = b_to_q(v9, v16, a1 + 24); /*0x110c84*/
        v21 = v16 - v20; /*0x110c89*/
        *(_BYTE *)(a1 + 72) += v21; /*0x110c8e*/
        v9 += v21; /*0x110c91*/
        v8 -= v21; /*0x110c93*/
        tk_nout += v21; /*0x110c95*/
        if ( v20 > 0 ) /*0x110ca0*/
        {
          v22 = spltty(); /*0x110ca7*/
          if ( (*(_DWORD *)(a1 + 64) & 0x4000121) == 0 ) /*0x110cb3*/
          {
            v23 = *(void (__cdecl **)(unsigned int))(a1 + 36); /*0x110cb5*/
            if ( v23 ) /*0x110cba*/
              v23(a1); /*0x110cbd*/
          }
          splx(v22); /*0x110cc3*/
          sleep((unsigned int)&lbolt); /*0x110cd2*/
          *(_DWORD *)*a2 -= v8; /*0x110cdc*/
          *(_DWORD *)(*a2 + 4) += v8; /*0x110ce0*/
          a2[5] += v8; /*0x110ce3*/
          a2[2] -= v8; /*0x110ce6*/
          goto LABEL_2; /*0x110cec*/
        }
        goto LABEL_70; /*0x110ca0*/
      }
      if ( v8 <= 0 ) /*0x110ade*/
        goto LABEL_73; /*0x110ade*/
      while ( 1 ) /*0x110ae4*/
      {
        v11 = *v9++; /*0x110ae4*/
        *(_BYTE *)(a1 + 75) = 0; /*0x110aeb*/
        if ( (int)ttyoutput(v11, a1) >= 0 ) /*0x110afb*/
          break; /*0x110afb*/
        --v8; /*0x110b5c*/
        if ( *(_DWORD *)(a1 + 24) > v32 ) /*0x110b66*/
          goto LABEL_78; /*0x110b66*/
        if ( v8 <= 0 ) /*0x110b6e*/
          goto LABEL_73; /*0x110b6e*/
      }
      v12 = spltty(); /*0x110b02*/
      if ( (*(_DWORD *)(a1 + 64) & 0x4000121) == 0 ) /*0x110b0e*/
      {
        v13 = *(void (__cdecl **)(unsigned int))(a1 + 36); /*0x110b10*/
        if ( v13 ) /*0x110b15*/
          v13(a1); /*0x110b18*/
      }
      splx(v12); /*0x110b1e*/
      sleep((unsigned int)&lbolt); /*0x110b2d*/
      *(_BYTE *)(a1 + 75) = 0; /*0x110b35*/
      *(_DWORD *)*a2 -= v8; /*0x110b49*/
      *(_DWORD *)(*a2 + 4) += v8; /*0x110b4d*/
      a2[5] += v8; /*0x110b50*/
      a2[2] -= v8; /*0x110b53*/
      goto LABEL_2; /*0x110b56*/
    }
LABEL_73:
    if ( (int)a2[5] <= 0 ) /*0x110d14*/
      goto LABEL_74; /*0x110d14*/
  }
LABEL_78:
  v26 = spltty(); /*0x110d48*/
  if ( v8 ) /*0x110d51*/
  {
    *(_DWORD *)*a2 -= v8; /*0x110d58*/
    *(_DWORD *)(*a2 + 4) += v8; /*0x110d5c*/
    a2[5] += v8; /*0x110d5f*/
    a2[2] -= v8; /*0x110d62*/
  }
  v27 = spltty(); /*0x110d6a*/
  if ( (*(_DWORD *)(a1 + 64) & 0x4000121) == 0 ) /*0x110d76*/
  {
    v28 = *(void (__cdecl **)(unsigned int))(a1 + 36); /*0x110d78*/
    if ( v28 ) /*0x110d7d*/
      v28(a1); /*0x110d80*/
  }
  splx(v27); /*0x110d86*/
  if ( *(_DWORD *)(a1 + 24) <= v32 ) /*0x110d97*/
  {
    splx(v26); /*0x110d9a*/
    goto LABEL_2; /*0x110d9f*/
  }
  v29 = *(_DWORD *)(a1 + 64); /*0x110da7*/
  if ( (v29 & 0x2000) == 0 ) /*0x110dad*/
  {
    LOBYTE(v29) = v29 | 0x40; /*0x110dc8*/
    *(_DWORD *)(a1 + 64) = v29; /*0x110dcd*/
    sleep(a1 + 24); /*0x110dd9*/
    splx(v26); /*0x110ddf*/
    goto LABEL_2; /*0x110de7*/
  }
  splx(v26); /*0x110db0*/
  if ( a2[5] != v31 ) /*0x110dbe*/
    return 0; /*0x110dc6*/
LABEL_6:
  if ( (*(_BYTE *)(*(_DWORD *)active_u + 22) & 2) != 0 ) /*0x110951*/
    return 11; /*0x110dec*/
  else
    return 35; /*0x110957*/
}

/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10c290. */
int __cdecl prf(char *a1, int a2, int a3, int a4)
{
  int v4; // ebx
  int v5; // ebx
  int v6; // esi
  int m; // edi
  char *v8; // esi
  char *v9; // esi
  int v10; // eax
  int k; // ebx
  int v12; // ecx
  int v13; // eax
  int j; // ebx
  int v15; // edi
  char *v16; // esi
  int v17; // ebx
  char *n; // esi
  int i; // edi
  _DWORD *v20; // esi
  _DWORD *v21; // esi
  unsigned int v22; // edi
  int v23; // eax
  unsigned int v24; // edi
  int v25; // eax
  _DWORD *v26; // ebx
  _DWORD *v27; // esi
  int v29; // [esp-14h] [ebp-3Ch]
  int v30; // [esp-8h] [ebp-30h]
  int v31; // [esp-4h] [ebp-2Ch]
  int v32; // [esp+10h] [ebp-18h]
  _DWORD *v33; // [esp+14h] [ebp-14h]
  int v34; // [esp+18h] [ebp-10h]
  int v35; // [esp+1Ch] [ebp-Ch]
  int v36; // [esp+20h] [ebp-8h]
  int v37; // [esp+20h] [ebp-8h]
  int v38; // [esp+24h] [ebp-4h]
  int v39; // [esp+24h] [ebp-4h]
  int v40; // [esp+24h] [ebp-4h]
  int v41; // [esp+24h] [ebp-4h]
  int v42; // [esp+24h] [ebp-4h]
  int v43; // [esp+24h] [ebp-4h]
  int v44; // [esp+34h] [ebp+Ch]
  int v45; // [esp+34h] [ebp+Ch]
  int v46; // [esp+34h] [ebp+Ch]

  v35 = 0; /*0x10c299*/
  v34 = 1; /*0x10c2a0*/
  while ( 1 ) /*0x10c2aa*/
  {
    v4 = *a1++; /*0x10c2aa*/
    if ( v4 != 37 ) /*0x10c2b4*/
      break; /*0x10c2b4*/
LABEL_5:
    v5 = *a1++; /*0x10c2e0*/
    if ( v5 == 48 ) /*0x10c2ed*/
      v35 = 48; /*0x10c2ef*/
    v6 = 0; /*0x10c2f6*/
    while ( (unsigned int)(v5 - 48) <= 9 ) /*0x10c315*/
    {
      v6 = v5 + 10 * v6 - 48; /*0x10c301*/
      v5 = *a1++; /*0x10c308*/
    }
    switch ( v5 ) /*0x10c31f*/
    {
      case '%': /*0x10c31f*/
        sub_10CBAC(37, a3, a4); /*0x10c692*/
        continue; /*0x10c692*/
      case 'C': /*0x10c31f*/
        a2 += 4; /*0x10c698*/
        v41 = *(_DWORD *)(a2 - 4); /*0x10c6a2*/
        for ( i = 24; i >= 0; i -= 8 ) /*0x10c6a5*/
        {
          if ( (unsigned __int8)(v41 >> i) ) /*0x10c6b1*/
            sub_10CBAC((unsigned __int8)(v41 >> i), a3, a4); /*0x10c6c3*/
        }
        continue; /*0x10c6ce*/
      case 'D': /*0x10c31f*/
      case 'd': /*0x10c31f*/
      case 'u': /*0x10c31f*/
        v38 = 10; /*0x10c484*/
        goto LABEL_14; /*0x10c48b*/
      case 'L': /*0x10c31f*/
        v34 = 0; /*0x10c958*/
        continue; /*0x10c95f*/
      case 'N': /*0x10c31f*/
      case 'n': /*0x10c31f*/
        v46 = a2 + 4; /*0x10c8d0*/
        v43 = *(_DWORD *)(v46 - 4); /*0x10c8da*/
        a2 = v46 + 4; /*0x10c8dd*/
        v27 = *(_DWORD **)(a2 - 4); /*0x10c8e4*/
        if ( !v27[1] ) /*0x10c8eb*/
          goto LABEL_88; /*0x10c8eb*/
        while ( *v27 != v43 ) /*0x10c8f5*/
        {
          v27 += 2; /*0x10c8f7*/
          if ( !v27[1] ) /*0x10c8fa*/
            goto LABEL_87; /*0x10c8fe*/
        }
        sub_10C974(v27[1], a3, a4); /*0x10c8c4*/
LABEL_87:
        if ( !v27[1] ) /*0x10c900*/
LABEL_88:
          sub_10C974(&unk_1DAC1F, a3, a4); /*0x10c906*/
        if ( v5 == 78 || !v27[1] ) /*0x10c920*/
        {
          sub_10CBAC(58, a3, a4); /*0x10c934*/
          sub_10C9A8(v43, 10, a3, a4, 0, 0); /*0x10c94b*/
        }
        continue; /*0x10c953*/
      case 'O': /*0x10c31f*/
      case 'o': /*0x10c31f*/
        v38 = 8; /*0x10c490*/
        goto LABEL_14; /*0x10c490*/
      case 'R': /*0x10c31f*/
      case 'r': /*0x10c31f*/
        v45 = a2 + 4; /*0x10c6d8*/
        v42 = *(_DWORD *)(v45 - 4); /*0x10c6e2*/
        a2 = v45 + 4; /*0x10c6e5*/
        v20 = *(_DWORD **)(a2 - 4); /*0x10c6ec*/
        if ( v5 == 82 ) /*0x10c6f2*/
        {
          sub_10C974(&unk_1DAC18, a3, a4); /*0x10c701*/
          sub_10C9A8(v42, 16, a3, a4, 0, 0); /*0x10c718*/
        }
        v37 = 0; /*0x10c720*/
        if ( v5 != 114 && !v42 ) /*0x10c730*/
          continue; /*0x10c730*/
        sub_10CBAC(60, a3, a4); /*0x10c740*/
        v33 = v20; /*0x10c745*/
        if ( !*v20 ) /*0x10c74e*/
          goto LABEL_80; /*0x10c74e*/
        v21 = v20 + 4; /*0x10c754*/
        break; /*0x10c754*/
      case 'X': /*0x10c31f*/
      case 'x': /*0x10c31f*/
        v38 = 16; /*0x10c478*/
LABEL_14:
        a2 += 4; /*0x10c497*/
        sub_10C9A8(*(_DWORD *)(a2 - 4), v38, a3, a4, v35, v6); /*0x10c4b3*/
        continue; /*0x10c4bb*/
      case 'b': /*0x10c31f*/
        v44 = a2 + 4; /*0x10c500*/
        v40 = *(_DWORD *)(v44 - 4); /*0x10c50a*/
        a2 = v44 + 4; /*0x10c50d*/
        v8 = *(char **)(a2 - 4); /*0x10c514*/
        v29 = *v8; /*0x10c526*/
        v9 = v8 + 1; /*0x10c527*/
        sub_10C9A8(v40, v29, a3, a4, 0, 0); /*0x10c52c*/
        v36 = 0; /*0x10c531*/
        if ( !v40 ) /*0x10c53f*/
          continue; /*0x10c53f*/
        while ( 1 ) /*0x10c636*/
        {
          v15 = *v9++; /*0x10c636*/
          if ( !v15 ) /*0x10c63c*/
            break; /*0x10c63c*/
          if ( *v9 > 32 ) /*0x10c54f*/
          {
            v12 = v40; /*0x10c5db*/
            if ( _bittest(&v12, v15 - 1) ) /*0x10c5de*/
            {
              v13 = 60; /*0x10c5eb*/
              if ( v36 ) /*0x10c5f4*/
                v13 = 44; /*0x10c5f6*/
              sub_10CBAC(v13, a3, a4); /*0x10c5fc*/
              v36 = 1; /*0x10c601*/
              for ( j = *v9; j > 32; j = *v9 ) /*0x10c611*/
              {
                sub_10CBAC(j, a3, a4); /*0x10c61d*/
                ++v9; /*0x10c625*/
              }
            }
            else
            {
              do /*0x10c634*/
                ++v9; /*0x10c630*/
              while ( *v9 > 32 ); /*0x10c634*/
            }
          }
          else
          {
            if ( ++v36 != 1 ) /*0x10c55c*/
              sub_10CBAC(44, a3, a4); /*0x10c568*/
            v10 = *v9++; /*0x10c570*/
            for ( k = *v9; k > 32; v10 = v32 ) /*0x10c57a*/
            {
              v32 = v10; /*0x10c585*/
              sub_10CBAC(k, a3, a4); /*0x10c588*/
              k = *++v9; /*0x10c591*/
            }
            sub_10C9A8((v40 >> (v10 - 1)) & ((2 << (v15 - v10)) - 1), 8, a3, a4, 0, 0); /*0x10c5ce*/
          }
        }
        v31 = a4; /*0x10c645*/
        v30 = a3; /*0x10c649*/
        goto LABEL_81; /*0x10c64a*/
      case 'c': /*0x10c31f*/
        a2 += 4; /*0x10c4c0*/
        v39 = *(_DWORD *)(a2 - 4); /*0x10c4ca*/
        for ( m = 24; m >= 0; m -= 8 ) /*0x10c4cd*/
        {
          if ( ((v39 >> m) & 0x7F) != 0 ) /*0x10c4e0*/
            sub_10CBAC((v39 >> m) & 0x7F, a3, a4); /*0x10c4eb*/
        }
        continue; /*0x10c4f6*/
      case 'l': /*0x10c31f*/
        goto LABEL_5;
      case 's': /*0x10c31f*/
        a2 += 4; /*0x10c650*/
        v16 = *(char **)(a2 - 4); /*0x10c657*/
        v17 = *v16; /*0x10c65a*/
        for ( n = v16 + 1; v17; ++n ) /*0x10c660*/
        {
          sub_10CBAC(v17, a3, a4); /*0x10c671*/
          v17 = *n; /*0x10c679*/
        }
        continue; /*0x10c67f*/
      default:
        continue;
    }
    do /*0x10c896*/
    {
      v22 = *v33 & v42; /*0x10c75e*/
      v23 = *(v21 - 3); /*0x10c760*/
      if ( v23 <= 0 ) /*0x10c765*/
        v24 = v22 >> -(char)v23; /*0x10c790*/
      else
        v24 = v22 << v23; /*0x10c769*/
      if ( v37 ) /*0x10c796*/
      {
        if ( *(v21 - 1) || *v21 ) /*0x10c79e*/
          goto LABEL_61; /*0x10c79e*/
        if ( !*(v21 - 2) ) /*0x10c7a7*/
          goto LABEL_70; /*0x10c7a7*/
        if ( v24 ) /*0x10c7ab*/
LABEL_61:
          sub_10CBAC(44, a3, a4); /*0x10c7b7*/
      }
      if ( *(v21 - 2) ) /*0x10c7bf*/
      {
        if ( *(v21 - 1) || *v21 || v24 ) /*0x10c7d2*/
        {
          sub_10C974(*(v21 - 2), a3, a4); /*0x10c7e0*/
          v37 = 1; /*0x10c7e5*/
        }
        if ( *(v21 - 1) || *v21 ) /*0x10c7f5*/
        {
          sub_10CBAC(61, a3, a4); /*0x10c804*/
          v37 = 1; /*0x10c809*/
        }
      }
LABEL_70:
      v25 = *(v21 - 1); /*0x10c813*/
      if ( v25 ) /*0x10c818*/
      {
        _printf(a3, a4, v25, v24); /*0x10c824*/
        v37 = 1; /*0x10c829*/
        if ( !*v21 ) /*0x10c836*/
          goto LABEL_79; /*0x10c836*/
        sub_10CBAC(58, a3, a4); /*0x10c842*/
      }
      if ( *v21 ) /*0x10c84a*/
      {
        v37 = 1; /*0x10c850*/
        v26 = (_DWORD *)*v21; /*0x10c857*/
        if ( !*(_DWORD *)(*v21 + 4) ) /*0x10c859*/
          goto LABEL_78; /*0x10c859*/
        while ( *v26 != v24 ) /*0x10c862*/
        {
          v26 += 2; /*0x10c868*/
          if ( !v26[1] ) /*0x10c86b*/
            goto LABEL_77; /*0x10c86f*/
        }
        sub_10C974(v26[1], a3, a4); /*0x10c77c*/
LABEL_77:
        if ( !v26[1] ) /*0x10c871*/
LABEL_78:
          sub_10C974(&unk_1DAC1B, a3, a4); /*0x10c884*/
      }
LABEL_79:
      v21 += 5; /*0x10c88c*/
      v33 += 5; /*0x10c88f*/
    }
    while ( *v33 ); /*0x10c896*/
LABEL_80:
    v31 = a4; /*0x10c89f*/
    v30 = a3; /*0x10c8a6*/
LABEL_81:
    sub_10CBAC(62, v30, v31); /*0x10c8a7*/
  }
  while ( v4 ) /*0x10c2ba*/
  {
    sub_10CBAC(v4, a3, a4); /*0x10c2c9*/
    v4 = *a1++; /*0x10c2d4*/
    if ( v4 == 37 ) /*0x10c2de*/
      goto LABEL_5; /*0x10c2de*/
  }
  return v34; /*0x10c96a*/
}

/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c2388. */
__int16 __cdecl sub_1C2388(id a1)
{
  int v1; // ebx
  int v2; // edx
  int v3; // edx
  __int16 v4; // cx
  unsigned int v5; // eax
  __int16 v6; // di
  __int16 v7; // dx
  _WORD *v8; // esi
  unsigned int v9; // edx
  __int16 v10; // di
  unsigned int v11; // edx
  __int16 v12; // cx
  __int16 v13; // cx
  __int16 v14; // dx
  __int16 v15; // ax
  int v17; // [esp+Ch] [ebp-40h]
  int v18; // [esp+10h] [ebp-3Ch]
  __int16 v19; // [esp+18h] [ebp-34h]
  unsigned __int16 v20; // [esp+18h] [ebp-34h]
  unsigned int v21; // [esp+1Ch] [ebp-30h]
  int v22; // [esp+24h] [ebp-28h]
  int v23; // [esp+28h] [ebp-24h]
  unsigned __int16 *v24; // [esp+2Ch] [ebp-20h]
  _WORD *v25; // [esp+30h] [ebp-1Ch]
  _WORD *v26; // [esp+34h] [ebp-18h]
  __int16 v27; // [esp+3Ch] [ebp-10h]
  __int16 v28; // [esp+3Ch] [ebp-10h]
  int v29; // [esp+40h] [ebp-Ch]
  int v30; // [esp+40h] [ebp-Ch]
  _DWORD *v31; // [esp+48h] [ebp-4h]

  v31 = objc_msgSend(a1, sel_displayInfo); /*0x1c23a1*/
  v1 = *((_DWORD *)a1 + 127); /*0x1c23a4*/
  v17 = *(_DWORD *)(v1 + 32); /*0x1c23b0*/
  v18 = *(_DWORD *)(v1 + 36); /*0x1c23b6*/
  if ( (__int16)v18 < *(__int16 *)(v1 + 52) ) /*0x1c23c1*/
    LOWORD(v18) = *(_WORD *)(v1 + 52); /*0x1c23c7*/
  v2 = v18 >> 16; /*0x1c23ce*/
  if ( SHIWORD(v18) > *(__int16 *)(v1 + 54) ) /*0x1c23db*/
  {
    LOWORD(v2) = *(_WORD *)(v1 + 54); /*0x1c23dd*/
    v18 = (v2 << 16) | (unsigned __int16)v18; /*0x1c23ec*/
  }
  if ( (__int16)v17 < *(__int16 *)(v1 + 48) ) /*0x1c23fa*/
    LOWORD(v17) = *(_WORD *)(v1 + 48); /*0x1c2400*/
  v3 = v17 >> 16; /*0x1c2407*/
  if ( SHIWORD(v17) > *(__int16 *)(v1 + 50) ) /*0x1c2414*/
  {
    LOWORD(v3) = *(_WORD *)(v1 + 50); /*0x1c2416*/
    v17 = (v3 << 16) | (unsigned __int16)v17; /*0x1c2425*/
  }
  *(_DWORD *)(v1 + 12) = v17; /*0x1c242e*/
  *(_DWORD *)(v1 + 16) = v18; /*0x1c2434*/
  v29 = v31[2]; /*0x1c243d*/
  v26 = (_WORD *)(v31[5] + 2 * v29 * ((__int16)v18 - *(__int16 *)(v1 + 52)) + 2 * ((__int16)v17 - *(__int16 *)(v1 + 48))); /*0x1c2476*/
  v30 = v29 - (__int16)(HIWORD(v17) - v17); /*0x1c248a*/
  v4 = 16 - (HIWORD(v17) - v17); /*0x1c2492*/
  v25 = (_WORD *)(v1 + 2120); /*0x1c249c*/
  v5 = (__int16)v17 - *(__int16 *)(v1 + 32) + 16 * ((__int16)v18 - *(__int16 *)(v1 + 36)); /*0x1c24c6*/
  v24 = (unsigned __int16 *)(v1 + (*(_DWORD *)v1 << 9) + 72 + 2 * v5); /*0x1c24ce*/
  if ( v31[6] == 2 ) /*0x1c24d8*/
  {
    v27 = HIWORD(v18) - v18 - 1; /*0x1c24ec*/
    if ( HIWORD(v18) != (_WORD)v18 ) /*0x1c24f5*/
    {
      do /*0x1c25d1*/
      {
        v6 = HIWORD(v17) - v17; /*0x1c2504*/
        while ( --v6 != -1 ) /*0x1c25aa*/
        {
          v7 = *v26; /*0x1c2513*/
          *v25 = *v26; /*0x1c2519*/
          LOWORD(v5) = v7; /*0x1c251c*/
          ++v25; /*0x1c2521*/
          v19 = *v24++; /*0x1c252a*/
          if ( v19 ) /*0x1c2535*/
          {
            if ( (~(_BYTE)v19 & 0xF) != 0 ) /*0x1c254f*/
            {
              LOWORD(v5) = ~(_BYTE)v19 & 0xF; /*0x1c2582*/
              v8 = v26; /*0x1c259e*/
              *v26 = v19 /*0x1c25a1*/
                   + ((((~(_BYTE)v19 & 0xF) * (v7 & 0xF0F) + 3855) >> 4) & 0xF0F
                    | (v5 * ((unsigned __int16)(v7 & 0xF0F0) >> 4) + 3855) & 0xF0F0);
            }
            else
            {
              v8 = v26; /*0x1c2555*/
              *v26 = v19; /*0x1c2558*/
            }
            v26 = v8 + 1; /*0x1c25a7*/
          }
          else
          {
            ++v26; /*0x1c2537*/
          }
        }
        v24 += v4; /*0x1c25b9*/
        v26 += v30; /*0x1c25c5*/
        --v27; /*0x1c25c8*/
      }
      while ( v27 != -1 ); /*0x1c25d1*/
    }
  }
  else
  {
    v23 = *((_DWORD *)a1 + 128); /*0x1c25e5*/
    if ( v23 ) /*0x1c25ea*/
    {
      v22 = *((_DWORD *)a1 + 129); /*0x1c25f9*/
      if ( v22 ) /*0x1c25fe*/
      {
        v28 = HIWORD(v18) - v18 - 1; /*0x1c2612*/
        if ( v28 >= 0 ) /*0x1c2616*/
        {
          v9 = 2 * v4; /*0x1c261f*/
          v21 = v9; /*0x1c2621*/
          do /*0x1c27a3*/
          {
            v10 = HIWORD(v17) - v17; /*0x1c2624*/
            while ( --v10 >= 0 ) /*0x1c2785*/
            {
              LOWORD(v9) = *v26; /*0x1c2633*/
              *v25 = *v26; /*0x1c2639*/
              v5 = v9; /*0x1c263c*/
              ++v25; /*0x1c2641*/
              v20 = *v24++; /*0x1c264a*/
              if ( v20 ) /*0x1c2655*/
              {
                if ( (~(_BYTE)v20 & 0xF) != 0 ) /*0x1c266f*/
                {
                  v14 = *(unsigned __int8 *)(((v9 >> 5) & 0x1F) + v22) << 8; /*0x1c26e0*/
                  LOBYTE(v14) = 15; /*0x1c26e4*/
                  v15 = (*(unsigned __int8 *)(((v5 >> 10) & 0x1F) + v22) << 12) /*0x1c26fb*/
                      | v14
                      | (16 * *(unsigned __int8 *)((v5 & 0x1F) + v22));
                  v5 = (unsigned __int16)(((((~(_BYTE)v20 & 0xF) * (v15 & 0xF0F) + 3855) >> 4) & 0xF0F /*0x1c273c*/
                                         | ((~(_BYTE)v20 & 0xF) * ((unsigned __int16)(v15 & 0xF0F0) >> 4) + 3855)
                                         & 0xF0F0)
                                        + v20);
                  v9 = *(unsigned __int8 *)(((unsigned __int16)v5 >> 12) + v23); /*0x1c276f*/
                  *v26 = ((_WORD)v9 << 10) /*0x1c277c*/
                       | (32 * *(unsigned __int8 *)(((v5 >> 8) & 0xF) + v23))
                       | *(unsigned __int8 *)(((unsigned __int8)v5 >> 4) + v23);
                }
                else
                {
                  v11 = (unsigned __int8)v20 >> 4; /*0x1c2678*/
                  v12 = *(unsigned __int8 *)(v11 + v23); /*0x1c267e*/
                  LOWORD(v11) = v20; /*0x1c2683*/
                  v13 = (32 * *(unsigned __int8 *)(((v11 >> 8) & 0xF) + v23)) | v12; /*0x1c2696*/
                  v9 = *(unsigned __int8 *)((v20 >> 12) + v23); /*0x1c26a7*/
                  *v26 = ((_WORD)v9 << 10) | v13; /*0x1c26b4*/
                }
                ++v26; /*0x1c26ba*/
              }
              else
              {
                ++v26; /*0x1c2657*/
              }
            }
            v24 = (unsigned __int16 *)((char *)v24 + v21); /*0x1c2790*/
            v26 += v30; /*0x1c279c*/
            --v28; /*0x1c279f*/
          }
          while ( v28 >= 0 ); /*0x1c27a3*/
        }
      }
    }
  }
  return v5; /*0x1c27ac*/
}

/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c27b4. */
char __cdecl sub_1C27B4(_DWORD *a1)
{
  int v1; // ebx
  int v2; // edx
  int v3; // edx
  int v4; // eax
  int v5; // edx
  __int16 v6; // si
  unsigned __int8 v7; // dl
  char v8; // al
  int v9; // edx
  __int16 v10; // si
  unsigned __int8 v11; // cl
  int v12; // edx
  int v14; // [esp+Ch] [ebp-40h]
  int v15; // [esp+Ch] [ebp-40h]
  unsigned int v16; // [esp+Ch] [ebp-40h]
  int v17; // [esp+10h] [ebp-3Ch]
  int v18; // [esp+18h] [ebp-34h]
  int v19; // [esp+1Ch] [ebp-30h]
  _BYTE *v20; // [esp+20h] [ebp-2Ch]
  char *v21; // [esp+24h] [ebp-28h]
  unsigned __int8 v22; // [esp+28h] [ebp-24h]
  _BYTE *v23; // [esp+2Ch] [ebp-20h]
  unsigned __int8 *v24; // [esp+30h] [ebp-1Ch]
  __int16 v25; // [esp+34h] [ebp-18h]
  __int16 v26; // [esp+38h] [ebp-14h]
  __int16 i; // [esp+3Ch] [ebp-10h]
  __int16 v28; // [esp+3Ch] [ebp-10h]
  int v29; // [esp+40h] [ebp-Ch]
  int v30; // [esp+40h] [ebp-Ch]
  _DWORD *v31; // [esp+48h] [ebp-4h]

  v19 = a1[130]; /*0x1c27c6*/
  v18 = a1[131]; /*0x1c27d2*/
  v31 = objc_msgSend(a1, sel_displayInfo); /*0x1c27e5*/
  v1 = a1[127]; /*0x1c27e8*/
  v14 = *(_DWORD *)(v1 + 32); /*0x1c27f4*/
  v17 = *(_DWORD *)(v1 + 36); /*0x1c27fa*/
  if ( (__int16)v17 < *(__int16 *)(v1 + 52) ) /*0x1c2805*/
    LOWORD(v17) = *(_WORD *)(v1 + 52); /*0x1c280b*/
  v2 = v17 >> 16; /*0x1c2812*/
  if ( SHIWORD(v17) > *(__int16 *)(v1 + 54) ) /*0x1c281f*/
  {
    LOWORD(v2) = *(_WORD *)(v1 + 54); /*0x1c2821*/
    v17 = (v2 << 16) | (unsigned __int16)v17; /*0x1c2830*/
  }
  if ( (__int16)v14 < *(__int16 *)(v1 + 48) ) /*0x1c283e*/
    LOWORD(v14) = *(_WORD *)(v1 + 48); /*0x1c2844*/
  v3 = v14 >> 16; /*0x1c284b*/
  if ( SHIWORD(v14) > *(__int16 *)(v1 + 50) ) /*0x1c2858*/
  {
    LOWORD(v3) = *(_WORD *)(v1 + 50); /*0x1c285a*/
    v14 = (v3 << 16) | (unsigned __int16)v14; /*0x1c2869*/
  }
  *(_DWORD *)(v1 + 12) = v14; /*0x1c2872*/
  *(_DWORD *)(v1 + 16) = v17; /*0x1c2878*/
  v29 = v31[2]; /*0x1c2881*/
  v4 = (__int16)v14 - *(__int16 *)(v1 + 48) + v31[5] + v29 * ((__int16)v17 - *(__int16 *)(v1 + 52)); /*0x1c28b0*/
  v24 = (unsigned __int8 *)v4; /*0x1c28b2*/
  v26 = HIWORD(v14) - v14; /*0x1c28bf*/
  v30 = v29 - (__int16)(HIWORD(v14) - v14); /*0x1c28c6*/
  v25 = 16 - (HIWORD(v14) - v14); /*0x1c28d2*/
  v23 = (_BYTE *)(v1 + 2120); /*0x1c28df*/
  v5 = (__int16)(16 * (v17 - *(_WORD *)(v1 + 36)) + v14 - *(_WORD *)(v1 + 32)); /*0x1c2927*/
  v21 = (char *)(v5 + v1 + (*(_DWORD *)v1 << 8) + 72); /*0x1c292a*/
  v20 = (_BYTE *)(v5 + v1 + (*(_DWORD *)v1 << 8) + 1096); /*0x1c292d*/
  if ( v31[7] == 1 ) /*0x1c2937*/
  {
    for ( i = HIWORD(v17) - v17 - 1; i >= 0; --i ) /*0x1c294f*/
    {
      v6 = HIWORD(v14) - v14; /*0x1c295c*/
      while ( --v6 >= 0 ) /*0x1c29b3*/
      {
        v7 = *v24; /*0x1c2967*/
        *v23++ = *v24; /*0x1c296c*/
        v8 = *v21++; /*0x1c2975*/
        v9 = (255 - (unsigned __int8)*v20++) * v7; /*0x1c2995*/
        LOBYTE(v4) = ((unsigned __int16)((v9 >> 8) + v9 + 1) >> 8) + v8; /*0x1c29a8*/
        *v24++ = v4; /*0x1c29ad*/
      }
      v21 += v25; /*0x1c29ba*/
      v20 += v25; /*0x1c29bd*/
      v24 += v30; /*0x1c29c3*/
    }
  }
  else
  {
    v28 = HIWORD(v17) - v17; /*0x1c29de*/
    while ( --v28 >= 0 ) /*0x1c2b0b*/
    {
      v10 = v26; /*0x1c29e8*/
      while ( --v10 >= 0 ) /*0x1c2af3*/
      {
        *v23 = *v24; /*0x1c29fc*/
        if ( *v20 ) /*0x1c2a01*/
        {
          v22 = *v21; /*0x1c2a10*/
          if ( *v20 != 0xFF ) /*0x1c2a17*/
          {
            v15 = *(_DWORD *)(v19 + 4 * *v24); /*0x1c2a29*/
            v12 = *(_DWORD *)(v19 + 4 * v22); /*0x1c2a83*/
            LOBYTE(v12) = 0; /*0x1c2a86*/
            v11 = ~*v20; /*0x1c2a13*/
            v16 = ((((((v11 * (v15 & 0xFF00FF)) & 0xFF00FF00) >> 8) + v11 * (v15 & 0xFF00FF) + 65537) >> 8) & 0xFF00FF /*0x1c2a8a*/
                 | ((((v11 * ((v15 & 0xFF00FF00) >> 8)) & 0xFF00FF00) >> 8) + v11 * ((v15 & 0xFF00FF00) >> 8) + 65537)
                 & 0xFF00FF00)
                + v12;
            v4 = v16 >> 8; /*0x1c2a8f*/
            if ( (((v16 >> 8) ^ v16) & 0xFFFF00) != 0 ) /*0x1c2a9a*/
              v22 = *(_BYTE *)(v18 + BYTE1(v16) + 512) /*0x1c2ac5*/
                  + *(_BYTE *)(v18 + BYTE2(v16) + 256)
                  + *(_BYTE *)(HIBYTE(v16) + v18);
            else
              v22 = *(_BYTE *)(v18 + HIBYTE(v16) + 768); /*0x1c2adc*/
          }
          *v24 = v22; /*0x1c2ae5*/
        }
        ++v23; /*0x1c2ae7*/
        ++v20; /*0x1c2aea*/
        ++v21; /*0x1c2aed*/
        ++v24; /*0x1c2af0*/
      }
      v21 += v25; /*0x1c2aff*/
      v20 += v25; /*0x1c2b02*/
      v24 += v30; /*0x1c2b08*/
    }
  }
  return v4; /*0x1c2b18*/
}

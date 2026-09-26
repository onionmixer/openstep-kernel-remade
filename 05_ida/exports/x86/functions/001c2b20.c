/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c2b20. */
char __cdecl sub_1C2B20(id a1)
{
  int v1; // ebx
  int v2; // edx
  int v3; // edx
  unsigned int *v4; // edi
  int v5; // eax
  char v6; // dl
  unsigned int v7; // edx
  unsigned int v8; // ebx
  unsigned int v9; // edx
  unsigned int v10; // ebx
  int v12; // [esp+10h] [ebp-30h]
  int v13; // [esp+14h] [ebp-2Ch]
  unsigned int *v14; // [esp+1Ch] [ebp-24h]
  unsigned int *v15; // [esp+20h] [ebp-20h]
  int v16; // [esp+24h] [ebp-1Ch]
  int v17; // [esp+28h] [ebp-18h]
  int v18; // [esp+2Ch] [ebp-14h]
  int v19; // [esp+2Ch] [ebp-14h]
  int v20; // [esp+30h] [ebp-10h]
  int v21; // [esp+30h] [ebp-10h]
  int v22; // [esp+34h] [ebp-Ch]
  int v23; // [esp+34h] [ebp-Ch]
  _DWORD *v24; // [esp+3Ch] [ebp-4h]

  v24 = objc_msgSend(a1, sel_displayInfo); /*0x1c2b39*/
  v1 = *((_DWORD *)a1 + 127); /*0x1c2b3c*/
  v12 = *(_DWORD *)(v1 + 32); /*0x1c2b48*/
  v13 = *(_DWORD *)(v1 + 36); /*0x1c2b4e*/
  if ( (__int16)v13 < *(__int16 *)(v1 + 52) ) /*0x1c2b59*/
    LOWORD(v13) = *(_WORD *)(v1 + 52); /*0x1c2b5f*/
  v2 = v13 >> 16; /*0x1c2b66*/
  if ( SHIWORD(v13) > *(__int16 *)(v1 + 54) ) /*0x1c2b73*/
  {
    LOWORD(v2) = *(_WORD *)(v1 + 54); /*0x1c2b75*/
    v13 = (v2 << 16) | (unsigned __int16)v13; /*0x1c2b84*/
  }
  if ( (__int16)v12 < *(__int16 *)(v1 + 48) ) /*0x1c2b92*/
    LOWORD(v12) = *(_WORD *)(v1 + 48); /*0x1c2b98*/
  v3 = v12 >> 16; /*0x1c2b9f*/
  if ( SHIWORD(v12) > *(__int16 *)(v1 + 50) ) /*0x1c2bac*/
  {
    LOWORD(v3) = *(_WORD *)(v1 + 50); /*0x1c2bae*/
    v12 = (v3 << 16) | (unsigned __int16)v12; /*0x1c2bbd*/
  }
  *(_DWORD *)(v1 + 12) = v12; /*0x1c2bc6*/
  *(_DWORD *)(v1 + 16) = v13; /*0x1c2bcc*/
  v22 = v24[2]; /*0x1c2bd5*/
  v4 = (unsigned int *)(v24[5] /*0x1c2c0b*/
                      + 4 * v22 * ((__int16)v13 - *(__int16 *)(v1 + 52))
                      + 4 * ((__int16)v12 - *(__int16 *)(v1 + 48)));
  v17 = (v12 >> 16) - (__int16)v12; /*0x1c2c16*/
  v23 = v22 - v17; /*0x1c2c19*/
  v16 = 16 - v17; /*0x1c2c23*/
  v15 = (unsigned int *)(v1 + 4168); /*0x1c2c2f*/
  v5 = (__int16)v12 - *(__int16 *)(v1 + 32); /*0x1c2c59*/
  v14 = (unsigned int *)(v1 + (*(_DWORD *)v1 << 10) + 72 + 4 * (v5 + 16 * ((__int16)v13 - *(__int16 *)(v1 + 36)))); /*0x1c2c63*/
  v6 = *((_BYTE *)v24 + 32); /*0x1c2c69*/
  if ( v6 == 65 || v6 == 45 ) /*0x1c2c74*/
  {
    v20 = (v13 >> 16) - (__int16)v13 - 1; /*0x1c2c86*/
    if ( v13 >> 16 != (__int16)v13 ) /*0x1c2c83*/
    {
      do /*0x1c2d4d*/
      {
        v18 = v17 - 1; /*0x1c2c98*/
        if ( v17 ) /*0x1c2c9e*/
        {
          do /*0x1c2d2e*/
          {
            v7 = *v4; /*0x1c2ca4*/
            *v15++ = *v4; /*0x1c2ca9*/
            v8 = *v14++; /*0x1c2cb7*/
            v5 = HIBYTE(v8); /*0x1c2cc2*/
            if ( HIBYTE(v8) ) /*0x1c2cc2*/
            {
              if ( v5 == 255 ) /*0x1c2ccc*/
              {
                *v4 = v8; /*0x1c2cce*/
              }
              else
              {
                LOBYTE(v5) = ~HIBYTE(v8); /*0x1c2cdc*/
                *v4 = (((v8 << 8) /*0x1c2d22*/
                      + (((v5 * ((v7 << 8) & 0xFF00FF) + 16711935) >> 8) & 0xFF00FF
                       | (v5 * (((v7 << 8) & 0xFF00FF00) >> 8) + 16711935) & 0xFF00FF00)) >> 8)
                    | 0xFF000000;
              }
            }
            ++v4; /*0x1c2d24*/
            --v18; /*0x1c2d27*/
          }
          while ( v18 != -1 ); /*0x1c2d2e*/
        }
        v14 += v16; /*0x1c2d3d*/
        v4 += v23; /*0x1c2d43*/
        --v20; /*0x1c2d46*/
      }
      while ( v20 != -1 ); /*0x1c2d4d*/
    }
  }
  else
  {
    v21 = (v13 >> 16) - (__int16)v13; /*0x1c2d61*/
    while ( --v21 != -1 ) /*0x1c2e05*/
    {
      v19 = v17 - 1; /*0x1c2d70*/
      if ( v17 ) /*0x1c2d76*/
      {
        do /*0x1c2df1*/
        {
          v9 = *v4; /*0x1c2d78*/
          *v15++ = *v4; /*0x1c2d7d*/
          v10 = *v14++; /*0x1c2d8b*/
          v5 = (unsigned __int8)v10; /*0x1c2d94*/
          if ( (_BYTE)v10 ) /*0x1c2d99*/
          {
            if ( (unsigned __int8)v10 == 255 ) /*0x1c2da0*/
            {
              *v4 = v10; /*0x1c2da2*/
            }
            else
            {
              LOBYTE(v5) = ~(_BYTE)v10; /*0x1c2da8*/
              *v4 = v10 /*0x1c2de5*/
                  + (((v5 * (v9 & 0xFF00FF) + 16711935) >> 8) & 0xFF00FF
                   | (v5 * ((v9 & 0xFF00FF00) >> 8) + 16711935) & 0xFF00FF00);
            }
          }
          ++v4; /*0x1c2de7*/
          --v19; /*0x1c2dea*/
        }
        while ( v19 != -1 ); /*0x1c2df1*/
      }
      v14 += v16; /*0x1c2dfc*/
      v4 += v23; /*0x1c2e02*/
    }
  }
  return v5; /*0x1c2e15*/
}

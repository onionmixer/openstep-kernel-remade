/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19e7cc. */
int __cdecl sub_19E7CC(int a1, unsigned __int16 *a2)
{
  unsigned __int16 v2; // dx
  int result; // eax
  int *v4; // ebx
  int i; // esi
  char v6; // bl
  int j; // esi
  int v8; // esi
  int v9; // ebx
  int v10; // esi
  int v11; // ebx
  int v12; // esi
  int v13; // ebx
  int v14; // esi
  int v15; // ebx
  char v16; // [esp+14h] [ebp-54h]
  int v17; // [esp+14h] [ebp-54h]
  int v18; // [esp+14h] [ebp-54h]
  int v19; // [esp+14h] [ebp-54h]
  int v20; // [esp+14h] [ebp-54h]
  int v21; // [esp+18h] [ebp-50h]
  _BYTE *v22; // [esp+18h] [ebp-50h]
  _BYTE *v23; // [esp+18h] [ebp-50h]
  _WORD *v24; // [esp+18h] [ebp-50h]
  int *v25; // [esp+18h] [ebp-50h]
  int v26; // [esp+1Ch] [ebp-4Ch]
  int v27; // [esp+40h] [ebp-28h]
  int v28; // [esp+44h] [ebp-24h]
  char v29; // [esp+48h] [ebp-20h]
  char v30; // [esp+4Ch] [ebp-1Ch]
  int v31; // [esp+50h] [ebp-18h]
  int v32; // [esp+58h] [ebp-10h]
  char v33; // [esp+58h] [ebp-10h]
  int v34; // [esp+5Ch] [ebp-Ch]
  signed int v35; // [esp+60h] [ebp-8h]
  _DWORD *v36; // [esp+64h] [ebp-4h]

  v36 = *(_DWORD **)(a1 + 28); /*0x19e7db*/
  v34 = (v36[2] - 480) / 2 + a2[1]; /*0x19e81e*/
  v35 = ((v36[1] - 640) / 2 + *a2) & 0xFFFFFFFC; /*0x19e821*/
  v2 = a2[2]; /*0x19e825*/
  LOBYTE(v2) = v2 & 0xFC; /*0x19e829*/
  a2[2] = v2; /*0x19e82c*/
  if ( v36[1] < v35 + v2 || v36[2] < v34 + a2[3] ) /*0x19e848*/
    return -1; /*0x19e84a*/
  v26 = *(_DWORD *)(a1 + 28); /*0x19e857*/
  v4 = nullptr; /*0x19e862*/
  switch ( *(_DWORD *)(v26 + 28) ) /*0x19e86f*/
  {
    case 0: /*0x19e86f*/
      v4 = (int *)&unk_1E4838; /*0x19e88c*/
      break; /*0x19e891*/
    case 1: /*0x19e86f*/
      v4 = (int *)&unk_1E4848; /*0x19e894*/
      break; /*0x19e899*/
    case 2: /*0x19e86f*/
    case 3: /*0x19e86f*/
      v31 = 16; /*0x19e89c*/
      break; /*0x19e8a3*/
    case 4: /*0x19e86f*/
      v31 = 32; /*0x19e8a8*/
      break; /*0x19e8af*/
    default:
      panic(aFbconsoleFillB_0); /*0x19e8b9*/
      return result; /*0x19e8b9*/
  }
  if ( !v4 ) /*0x19e8c0*/
  {
    v16 = 0; /*0x19e8c6*/
    v30 = 0; /*0x19e8cd*/
    v29 = 0; /*0x19e8d4*/
    v21 = -1; /*0x19e8db*/
    v28 = -1; /*0x19e8e2*/
    v27 = -1; /*0x19e8e9*/
    for ( i = 0; v31 > i; ++i ) /*0x19e8f5*/
    {
      v6 = *(_BYTE *)(i + v26 + 4 + 32); /*0x19e8fb*/
      if ( v6 == 71 ) /*0x19e902*/
      {
        if ( v28 == -1 ) /*0x19e928*/
          v28 = i; /*0x19e92a*/
        ++v30; /*0x19e92d*/
      }
      else if ( v6 > 71 ) /*0x19e904*/
      {
        if ( v6 == 82 ) /*0x19e913*/
        {
          if ( v21 == -1 ) /*0x19e919*/
            v21 = i; /*0x19e91b*/
          ++v16; /*0x19e91e*/
        }
      }
      else if ( v6 == 66 ) /*0x19e909*/
      {
        if ( v27 == -1 ) /*0x19e938*/
          v27 = i; /*0x19e93a*/
        ++v29; /*0x19e93d*/
      }
    }
    for ( j = 0; j <= 3; ++j ) /*0x19e946*/
      dword_1E4858[j] = (((3 - j) * ((1 << v29) - 1) / 3) << (v31 - v27 - v29)) /*0x19e9f5*/
                      | (((3 - j) * ((1 << v30) - 1) / 3) << (v31 - v28 - v30))
                      | (((3 - j) * ((1 << v16) - 1) / 3) << (v31 - v21 - v16));
    v4 = dword_1E4858; /*0x19ea02*/
  }
  v32 = v4[*((_DWORD *)a2 + 2) & 3]; /*0x19ea10*/
  switch ( v36[7] ) /*0x19ea22*/
  {
    case 0: /*0x19ea22*/
      v8 = v36[4] * v34 + v36[6] + v35 / 4; /*0x19ea5e*/
      v33 = ((_BYTE)v32 << 6) | (16 * v32) | v32 | (4 * v32); /*0x19ea7c*/
      v9 = 0; /*0x19ea7f*/
      if ( a2[3] ) /*0x19ea81*/
      {
        do /*0x19eace*/
        {
          v22 = (_BYTE *)v8; /*0x19ea94*/
          v17 = 0; /*0x19ea97*/
          if ( a2[2] ) /*0x19ea9e*/
          {
            do /*0x19eabf*/
            {
              *v22++ = v33; /*0x19eaae*/
              v17 += 4; /*0x19eab4*/
            }
            while ( v17 < a2[2] ); /*0x19eabf*/
          }
          v8 += v36[4]; /*0x19eac4*/
          ++v9; /*0x19eac7*/
        }
        while ( v9 < a2[3] ); /*0x19eace*/
      }
      break; /*0x19eace*/
    case 1: /*0x19ea22*/
      v10 = v36[4] * v34 + v36[6] + v35; /*0x19eaea*/
      v11 = 0; /*0x19eaec*/
      if ( a2[3] ) /*0x19eaee*/
      {
        do /*0x19eb39*/
        {
          v23 = (_BYTE *)v10; /*0x19eb00*/
          v18 = 0; /*0x19eb03*/
          if ( a2[2] ) /*0x19eb0a*/
          {
            do /*0x19eb2a*/
            {
              *v23++ = v32; /*0x19eb1a*/
              ++v18; /*0x19eb20*/
            }
            while ( v18 < a2[2] ); /*0x19eb2a*/
          }
          v10 += v36[4]; /*0x19eb2f*/
          ++v11; /*0x19eb32*/
        }
        while ( v11 < a2[3] ); /*0x19eb39*/
      }
      break; /*0x19eb39*/
    case 2: /*0x19ea22*/
    case 3: /*0x19ea22*/
      v12 = v36[4] * v34 + v36[6] + 2 * v35; /*0x19eb58*/
      v13 = 0; /*0x19eb5a*/
      if ( a2[3] ) /*0x19eb5c*/
      {
        do /*0x19ebad*/
        {
          v24 = (_WORD *)v12; /*0x19eb70*/
          v19 = 0; /*0x19eb73*/
          if ( a2[2] ) /*0x19eb7a*/
          {
            do /*0x19eb9e*/
            {
              *v24++ = v32; /*0x19eb8b*/
              ++v19; /*0x19eb94*/
            }
            while ( v19 < a2[2] ); /*0x19eb9e*/
          }
          v12 += v36[4]; /*0x19eba3*/
          ++v13; /*0x19eba6*/
        }
        while ( v13 < a2[3] ); /*0x19ebad*/
      }
      break; /*0x19ebad*/
    case 4: /*0x19ea22*/
      v14 = v36[4] * v34 + v36[6] + 4 * v35; /*0x19ebcc*/
      v15 = 0; /*0x19ebce*/
      if ( a2[3] ) /*0x19ebd0*/
      {
        do /*0x19ec13*/
        {
          v25 = (int *)v14; /*0x19ebd8*/
          v20 = 0; /*0x19ebdb*/
          if ( a2[2] ) /*0x19ebe2*/
          {
            do /*0x19ec04*/
            {
              *v25++ = v32; /*0x19ebf2*/
              ++v20; /*0x19ebfa*/
            }
            while ( v20 < a2[2] ); /*0x19ec04*/
          }
          v14 += v36[4]; /*0x19ec09*/
          ++v15; /*0x19ec0c*/
        }
        while ( v15 < a2[3] ); /*0x19ec13*/
      }
      break; /*0x19ec13*/
    default:
      return 0;
  }
  return 0; /*0x19ec1a*/
}

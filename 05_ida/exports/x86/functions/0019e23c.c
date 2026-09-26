/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19e23c. */
int __cdecl sub_19E23C(int a1, unsigned __int16 *a2)
{
  int *v2; // ebx
  char v3; // di
  int i; // esi
  char v5; // bl
  int j; // esi
  int v7; // edi
  int v8; // ebx
  unsigned __int16 v9; // cx
  int result; // eax
  _BYTE *v11; // edi
  int v12; // esi
  char v13; // bl
  int v14; // ebx
  _BYTE *v15; // edi
  int v16; // esi
  _BYTE *v17; // edi
  int v18; // ebx
  _WORD *v19; // edi
  int v20; // esi
  _WORD *v21; // edi
  int v22; // ebx
  _DWORD *v23; // edi
  int v24; // esi
  _DWORD *v25; // edi
  char v26; // [esp+14h] [ebp-50h]
  int k; // [esp+14h] [ebp-50h]
  int v28; // [esp+18h] [ebp-4Ch]
  unsigned __int8 v29; // [esp+1Ch] [ebp-48h]
  unsigned __int8 v30; // [esp+1Ch] [ebp-48h]
  unsigned __int8 v31; // [esp+1Ch] [ebp-48h]
  unsigned __int8 v32; // [esp+1Ch] [ebp-48h]
  int v33; // [esp+24h] [ebp-40h]
  int v34; // [esp+3Ch] [ebp-28h]
  int v35; // [esp+40h] [ebp-24h]
  char v36; // [esp+44h] [ebp-20h]
  int v37; // [esp+48h] [ebp-1Ch]
  int *v38; // [esp+54h] [ebp-10h]
  unsigned __int8 *v39; // [esp+58h] [ebp-Ch]
  int v40; // [esp+5Ch] [ebp-8h]
  int v41; // [esp+5Ch] [ebp-8h]
  int v42; // [esp+5Ch] [ebp-8h]
  int v43; // [esp+5Ch] [ebp-8h]
  _DWORD *v44; // [esp+60h] [ebp-4h]

  v44 = *(_DWORD **)(a1 + 28); /*0x19e24b*/
  v2 = nullptr; /*0x19e25a*/
  switch ( v44[7] ) /*0x19e267*/
  {
    case 0: /*0x19e267*/
      v2 = (int *)&unk_1E4838; /*0x19e284*/
      break; /*0x19e289*/
    case 1: /*0x19e267*/
      v2 = (int *)&unk_1E4848; /*0x19e28c*/
      break; /*0x19e291*/
    case 2: /*0x19e267*/
    case 3: /*0x19e267*/
      v37 = 16; /*0x19e294*/
      break; /*0x19e29b*/
    case 4: /*0x19e267*/
      v37 = 32; /*0x19e2a0*/
      break; /*0x19e2a7*/
    default:
      panic(aFbconsoleFillB_0); /*0x19e2b1*/
      return result; /*0x19e2b1*/
  }
  if ( !v2 ) /*0x19e2b8*/
  {
    v26 = 0; /*0x19e2be*/
    v36 = 0; /*0x19e2c5*/
    v3 = 0; /*0x19e2cc*/
    v28 = -1; /*0x19e2ce*/
    v35 = -1; /*0x19e2d5*/
    v34 = -1; /*0x19e2dc*/
    for ( i = 0; v37 > i; ++i ) /*0x19e2e8*/
    {
      v5 = *((_BYTE *)v44 + i + 36); /*0x19e2ef*/
      if ( v5 == 71 ) /*0x19e2f6*/
      {
        if ( v35 == -1 ) /*0x19e31c*/
          v35 = i; /*0x19e31e*/
        ++v36; /*0x19e321*/
      }
      else if ( v5 > 71 ) /*0x19e2f8*/
      {
        if ( v5 == 82 ) /*0x19e307*/
        {
          if ( v28 == -1 ) /*0x19e30d*/
            v28 = i; /*0x19e30f*/
          ++v26; /*0x19e312*/
        }
      }
      else if ( v5 == 66 ) /*0x19e2fd*/
      {
        if ( v34 == -1 ) /*0x19e32c*/
          v34 = i; /*0x19e32e*/
        ++v3; /*0x19e331*/
      }
    }
    for ( j = 0; j <= 3; ++j ) /*0x19e338*/
      dword_1E4858[j] = (((3 - j) * ((1 << v3) - 1) / 3) << (v37 - v34 - v3)) /*0x19e3e8*/
                      | (((3 - j) * ((1 << v36) - 1) / 3) << (v37 - v35 - v36))
                      | (((3 - j) * ((1 << v26) - 1) / 3) << (v37 - v28 - v26));
    v2 = dword_1E4858; /*0x19e3f5*/
  }
  v38 = v2; /*0x19e3fa*/
  v8 = (v44[1] - 640) / 2 + *a2; /*0x19e41d*/
  v7 = (v44[2] - 480) / 2 + a2[1]; /*0x19e440*/
  LOBYTE(v8) = v8 & 0xFC; /*0x19e442*/
  v9 = a2[2]; /*0x19e448*/
  LOBYTE(v9) = v9 & 0xFC; /*0x19e44c*/
  a2[2] = v9; /*0x19e452*/
  if ( v44[1] < v8 + v9 || v44[2] < v7 + a2[3] ) /*0x19e46c*/
    return -1; /*0x19e46e*/
  v39 = *((unsigned __int8 **)a2 + 2); /*0x19e47e*/
  switch ( v44[7] ) /*0x19e490*/
  {
    case 0: /*0x19e490*/
      v33 = v44[4] * v7 + v44[6] + v8 / 4; /*0x19e4c9*/
      v40 = 0; /*0x19e4cc*/
      if ( a2[3] ) /*0x19e4d6*/
      {
        do /*0x19e55e*/
        {
          v11 = (_BYTE *)v33; /*0x19e4e4*/
          v12 = 0; /*0x19e4e7*/
          if ( a2[2] ) /*0x19e4ec*/
          {
            do /*0x19e546*/
            {
              v29 = *v39++; /*0x19e4f9*/
              v13 = 0; /*0x19e4ff*/
              for ( k = 0; k <= 7; k += 2 ) /*0x19e501*/
                v13 |= (v38[((int)v29 >> k) & 3] & 3) << k; /*0x19e529*/
              *v11++ = v13; /*0x19e537*/
              v12 += 4; /*0x19e53a*/
            }
            while ( v12 < a2[2] ); /*0x19e546*/
          }
          v33 += v44[4]; /*0x19e54e*/
          ++v40; /*0x19e551*/
        }
        while ( v40 < a2[3] ); /*0x19e55e*/
      }
      break; /*0x19e55e*/
    case 1: /*0x19e490*/
      v14 = v44[4] * v7 + v44[6] + v8; /*0x19e578*/
      v41 = 0; /*0x19e57a*/
      if ( a2[3] ) /*0x19e584*/
      {
        do /*0x19e618*/
        {
          v15 = (_BYTE *)v14; /*0x19e590*/
          v16 = 0; /*0x19e592*/
          if ( a2[2] ) /*0x19e597*/
          {
            do /*0x19e603*/
            {
              v30 = *v39++; /*0x19e5a5*/
              *v15 = v38[v30 >> 6]; /*0x19e5b7*/
              v17 = v15 + 1; /*0x19e5b9*/
              *v17++ = v38[(v30 >> 4) & 3]; /*0x19e5ce*/
              *v17++ = v38[(v30 >> 2) & 3]; /*0x19e5e5*/
              *v17 = v38[v30 & 3]; /*0x19e5f4*/
              v15 = v17 + 1; /*0x19e5f6*/
              v16 += 4; /*0x19e5f7*/
            }
            while ( v16 < a2[2] ); /*0x19e603*/
          }
          v14 += v44[4]; /*0x19e608*/
          ++v41; /*0x19e60b*/
        }
        while ( v41 < a2[3] ); /*0x19e618*/
      }
      break; /*0x19e618*/
    case 2: /*0x19e490*/
    case 3: /*0x19e490*/
      v18 = v44[4] * v7 + v44[6] + 2 * v8; /*0x19e63a*/
      v42 = 0; /*0x19e63c*/
      if ( a2[3] ) /*0x19e646*/
      {
        do /*0x19e6ec*/
        {
          v19 = (_WORD *)v18; /*0x19e654*/
          v20 = 0; /*0x19e656*/
          if ( a2[2] ) /*0x19e65b*/
          {
            do /*0x19e6d7*/
            {
              v31 = *v39++; /*0x19e669*/
              *v19 = v38[v31 >> 6]; /*0x19e67c*/
              v21 = v19 + 1; /*0x19e67f*/
              *v21++ = v38[(v31 >> 4) & 3]; /*0x19e697*/
              *v21++ = v38[(v31 >> 2) & 3]; /*0x19e6b2*/
              *v21 = v38[v31 & 3]; /*0x19e6c5*/
              v19 = v21 + 1; /*0x19e6c8*/
              v20 += 4; /*0x19e6cb*/
            }
            while ( v20 < a2[2] ); /*0x19e6d7*/
          }
          v18 += v44[4]; /*0x19e6dc*/
          ++v42; /*0x19e6df*/
        }
        while ( v42 < a2[3] ); /*0x19e6ec*/
      }
      break; /*0x19e6ec*/
    case 4: /*0x19e490*/
      v22 = v44[4] * v7 + v44[6] + 4 * v8; /*0x19e70e*/
      v43 = 0; /*0x19e710*/
      if ( a2[3] ) /*0x19e71a*/
      {
        do /*0x19e7b8*/
        {
          v23 = (_DWORD *)v22; /*0x19e728*/
          v24 = 0; /*0x19e72a*/
          if ( a2[2] ) /*0x19e72f*/
          {
            do /*0x19e7a3*/
            {
              v32 = *v39++; /*0x19e73d*/
              *v23 = v38[v32 >> 6]; /*0x19e74f*/
              v25 = v23 + 1; /*0x19e751*/
              *v25++ = v38[(v32 >> 4) & 3]; /*0x19e768*/
              *v25++ = v38[(v32 >> 2) & 3]; /*0x19e781*/
              *v25 = v38[v32 & 3]; /*0x19e792*/
              v23 = v25 + 1; /*0x19e794*/
              v24 += 4; /*0x19e797*/
            }
            while ( v24 < a2[2] ); /*0x19e7a3*/
          }
          v22 += v44[4]; /*0x19e7a8*/
          ++v43; /*0x19e7ab*/
        }
        while ( v43 < a2[3] ); /*0x19e7b8*/
      }
      break; /*0x19e7b8*/
    default:
      return 0;
  }
  return 0; /*0x19e7c3*/
}

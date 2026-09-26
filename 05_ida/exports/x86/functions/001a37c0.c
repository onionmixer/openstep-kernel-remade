/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a37c0. */
int __cdecl sub_1A37C0(int a1, int a2)
{
  unsigned __int16 v2; // ax
  int v3; // ecx
  int *v4; // eax
  int v5; // edx
  unsigned int v6; // eax
  int v7; // esi
  int *v8; // eax
  unsigned int v9; // edx
  _DWORD *v10; // esi
  int v11; // eax
  int *v12; // eax
  int v13; // ecx
  unsigned int v14; // edx
  int v15; // eax
  int v16; // edx
  int *v18; // eax
  int v19; // ecx
  unsigned int v20; // edx
  int v21; // eax
  _DWORD *v22; // edx
  int v23; // [esp+Ch] [ebp-28h]
  __int16 v24; // [esp+28h] [ebp-Ch]
  unsigned __int16 v25; // [esp+2Eh] [ebp-6h]
  unsigned int v26; // [esp+30h] [ebp-4h]

  v2 = *(_WORD *)(a2 + 60); /*0x1a37cc*/
  if ( (v2 & 4) == 0 ) /*0x1a37d2*/
    return 0; /*0x1a37d2*/
  v3 = v2 >> 3; /*0x1a37dc*/
  v4 = *(int **)(*(_DWORD *)(a1 + 40) + 236); /*0x1a37e5*/
  v5 = 0; /*0x1a37eb*/
  if ( v4 ) /*0x1a37ef*/
    v5 = *v4; /*0x1a37f1*/
  if ( *(_DWORD *)(v5 + 60) <= (unsigned int)(8 * v3) ) /*0x1a37fd*/
    return 0; /*0x1a37fd*/
  v6 = *(_DWORD *)(v5 + 56) + 8 * v3; /*0x1a3808*/
  *(_DWORD *)(a1 + 116) = &loc_1A3834; /*0x1a380e*/
  v25 = __readfsdword(v6) >> 16; /*0x1a3818*/
  v26 = __readfsdword(v6 + 4); /*0x1a381f*/
  *(_DWORD *)(a1 + 116) = 0; /*0x1a3825*/
  v7 = *(_DWORD *)(a2 + 56); /*0x1a3848*/
  LOBYTE(v5) = HIBYTE(v26); /*0x1a3856*/
  if ( (v26 & 0x400000) == 0 ) /*0x1a3866*/
    v7 = (unsigned __int16)*(_DWORD *)(a2 + 56); /*0x1a3868*/
  *(_DWORD *)(a1 + 116) = &loc_1A388C; /*0x1a3873*/
  v24 = __readfsdword(v7 + ((v5 << 24) | ((unsigned __int8)v26 << 16) | v25)); /*0x1a387d*/
  *(_DWORD *)(a1 + 116) = 0; /*0x1a3883*/
  switch ( (_BYTE)v24 ) /*0x1a38a1*/
  {
    case 0xCD: /*0x1a38a1*/
      v8 = *(int **)(*(_DWORD *)(a1 + 40) + 236); /*0x1a38ba*/
      v23 = 0; /*0x1a38c0*/
      if ( v8 ) /*0x1a38c9*/
        v23 = *v8; /*0x1a38cd*/
      v9 = *(_DWORD *)(v23 + 132); /*0x1a38d3*/
      if ( v9 > 7 ) /*0x1a38dc*/
        v10 = nullptr; /*0x1a38f0*/
      else
        v10 = (_DWORD *)(v23 + 132 * v9 + 136); /*0x1a38e5*/
      if ( HIBYTE(v24) > 0x1Fu ) /*0x1a3904*/
        v11 = ((int)*(unsigned __int8 *)(HIBYTE(v24) / 8 + v23 + 8) >> (HIBYTE(v24) % 8)) & 1; /*0x1a3939*/
      else
        v11 = ((1 << SHIBYTE(v24)) & *(_DWORD *)(v23 + 8)) != 0; /*0x1a3916*/
      if ( v11 ) /*0x1a393e*/
      {
        v10[19] = HIBYTE(v24); /*0x1a3944*/
        v10[20] = 0; /*0x1a3947*/
        if ( HIBYTE(v24) > 7u ) /*0x1a3952*/
          v10[22] = 2; /*0x1a3960*/
        else
          v10[22] = 1; /*0x1a3954*/
        PCcallMonitor(a1, (__int16 *)a2); /*0x1a396c*/
      }
      if ( (v26 & 0x400000) != 0 ) /*0x1a3978*/
        *(_DWORD *)(a2 + 56) += 2; /*0x1a397a*/
      else
        *(_DWORD *)(a2 + 56) = (unsigned __int16)(*(_WORD *)(a2 + 56) + 2); /*0x1a398d*/
      if ( !sub_1A3160(a1, a2, HIBYTE(v24), 0, 1) ) /*0x1a39a0*/
      {
        if ( (v26 & 0x400000) != 0 ) /*0x1a39b1*/
          *(_DWORD *)(a2 + 56) -= 2; /*0x1a39b3*/
        else
          *(_DWORD *)(a2 + 56) = (unsigned __int16)(*(_WORD *)(a2 + 56) - 2); /*0x1a39c9*/
        return 0; /*0x1a39b7*/
      }
      return 1; /*0x1a3a3e*/
    case 0xFA: /*0x1a38a1*/
      v12 = *(int **)(*(_DWORD *)(a1 + 40) + 236); /*0x1a39de*/
      v13 = 0; /*0x1a39e4*/
      if ( v12 ) /*0x1a39e8*/
        v13 = *v12; /*0x1a39ea*/
      if ( v13 ) /*0x1a39ee*/
      {
        v14 = *(_DWORD *)(v13 + 132); /*0x1a39f0*/
        if ( v14 > 7 ) /*0x1a39f9*/
          v15 = 0; /*0x1a3a0c*/
        else
          v15 = v13 + 132 * v14 + 136; /*0x1a3a02*/
        v16 = v15; /*0x1a3a0e*/
      }
      else
      {
        v16 = 0; /*0x1a3a14*/
      }
      if ( (v26 & 0x400000) != 0 ) /*0x1a3a1a*/
        ++*(_DWORD *)(a2 + 56); /*0x1a3a1c*/
      else
        *(_DWORD *)(a2 + 56) = (unsigned __int16)(*(_WORD *)(a2 + 56) + 1); /*0x1a3a2f*/
      *(_DWORD *)(v16 + 104) = 0; /*0x1a3a32*/
      return 1; /*0x1a3a32*/
    case 0xFB: /*0x1a38a1*/
      v18 = *(int **)(*(_DWORD *)(a1 + 40) + 236); /*0x1a3a4a*/
      v19 = 0; /*0x1a3a50*/
      if ( v18 ) /*0x1a3a54*/
        v19 = *v18; /*0x1a3a56*/
      if ( v19 ) /*0x1a3a5a*/
      {
        v20 = *(_DWORD *)(v19 + 132); /*0x1a3a5c*/
        if ( v20 > 7 ) /*0x1a3a65*/
          v21 = 0; /*0x1a3a78*/
        else
          v21 = v19 + 132 * v20 + 136; /*0x1a3a6e*/
        v22 = (_DWORD *)v21; /*0x1a3a7a*/
      }
      else
      {
        v22 = nullptr; /*0x1a3a80*/
      }
      if ( (v26 & 0x400000) != 0 ) /*0x1a3a86*/
        ++*(_DWORD *)(a2 + 56); /*0x1a3a88*/
      else
        *(_DWORD *)(a2 + 56) = (unsigned __int16)(*(_WORD *)(a2 + 56) + 1); /*0x1a3a9b*/
      if ( !v22[26] ) /*0x1a3a9e*/
      {
        v22[26] = 1; /*0x1a3aa4*/
        v22[29] |= v22[23] & 1; /*0x1a3ab1*/
      }
      return 1; /*0x1a3ab4*/
  }
  return 0; /*0x1a3abd*/
}

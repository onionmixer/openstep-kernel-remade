/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cd5b4. */
_DWORD *__cdecl sub_1CD5B4(int a1)
{
  int v1; // esi
  unsigned int v3; // ebx
  int v4; // edi
  int v5; // eax
  unsigned int v6; // edi
  int v7; // eax
  unsigned int i; // ebx
  unsigned int v9; // ebx
  _DWORD *v10; // edi
  int v11; // eax
  unsigned int v12; // ebx
  int v13; // edi
  int v14; // eax
  int v15; // ebx
  int v16; // eax
  int v17; // [esp-4h] [ebp-1Ch]
  int v18; // [esp+0h] [ebp-18h]
  int v19; // [esp+0h] [ebp-18h]
  int v20; // [esp+0h] [ebp-18h]
  int v21; // [esp+0h] [ebp-18h]
  int v22; // [esp+0h] [ebp-18h]
  int v23; // [esp+0h] [ebp-18h]
  int v24; // [esp+0h] [ebp-18h]
  int v25; // [esp+4h] [ebp-14h]
  int v26; // [esp+4h] [ebp-14h]
  int v27; // [esp+4h] [ebp-14h]
  int v28; // [esp+8h] [ebp-10h]
  int v29; // [esp+Ch] [ebp-Ch]
  int v30; // [esp+10h] [ebp-8h]
  int *v31; // [esp+14h] [ebp-4h]
  int v32; // [esp+14h] [ebp-4h]
  int savedregs; // [esp+18h] [ebp+0h]

  v1 = *(_DWORD *)(a1 + 32); /*0x1cd5c0*/
  if ( (_UNKNOWN *)v1 == &emptyCache ) /*0x1cd5c9*/
    return _cache_create(a1); /*0x1cd5d1*/
  if ( dword_1E55A8 ) /*0x1cd5df*/
  {
    if ( (*(_BYTE *)(a1 + 16) & 0x40) == 0 ) /*0x1cd5e8*/
    {
      *(_DWORD *)(v1 + 4) = 0; /*0x1cd5ea*/
      v3 = 0; /*0x1cd5f1*/
      if ( *(_DWORD *)v1 != -1 ) /*0x1cd5f6*/
      {
        do /*0x1cd634*/
        {
          if ( *(_DWORD *)(v1 + 4 * v3 + 8) ) /*0x1cd5f8*/
          {
            if ( *(id (**)(id, SEL, ...))(*(_DWORD *)(v1 + 4 * v3 + 8) + 8) == _objc_msgForward ) /*0x1cd60a*/
            {
              v4 = NXDefaultMallocZone(v18, v25); /*0x1cd611*/
              v5 = NXDefaultMallocZone(*(_DWORD *)(v1 + 4 * v3 + 8), v19); /*0x1cd618*/
              (*(void (__cdecl **)(int))(v4 + 8))(v5); /*0x1cd621*/
            }
            *(_DWORD *)(v1 + 4 * v3 + 8) = 0; /*0x1cd626*/
          }
          ++v3; /*0x1cd62e*/
        }
        while ( v3 < *(_DWORD *)v1 + 1 ); /*0x1cd634*/
      }
      *(_BYTE *)(a1 + 16) |= 0x40u; /*0x1cd639*/
      return (_DWORD *)v1; /*0x1cd63f*/
    }
    *(_DWORD *)(a1 + 16) &= ~0x40u; /*0x1cd647*/
  }
  v6 = 2 * (*(_DWORD *)v1 + 1); /*0x1cd64e*/
  v30 = NXDefaultMallocZone(v18, v25); /*0x1cd655*/
  v7 = NXDefaultMallocZone(4 * (v6 - 1) + 12, v20); /*0x1cd663*/
  v31 = (int *)(*(int (__cdecl **)(int))(v30 + 4))(v7); /*0x1cd671*/
  *v31 = v6 - 1; /*0x1cd674*/
  v31[1] = 0; /*0x1cd679*/
  for ( i = 0; i < v6; ++i ) /*0x1cd687*/
    v31[i + 2] = 0; /*0x1cd68f*/
  if ( dword_1E55A4 ) /*0x1cd6a3*/
  {
    v12 = 0; /*0x1cd704*/
    if ( *(_DWORD *)v1 != -1 ) /*0x1cd709*/
    {
      do /*0x1cd740*/
      {
        if ( *(_DWORD *)(v1 + 4 * v12 + 8) /*0x1cd71e*/
          && *(id (**)(id, SEL, ...))(*(_DWORD *)(v1 + 4 * v12 + 8) + 8) == _objc_msgForward )
        {
          v13 = NXDefaultMallocZone(v21, v26); /*0x1cd725*/
          v14 = NXDefaultMallocZone(*(_DWORD *)(v1 + 4 * v12 + 8), v22); /*0x1cd72c*/
          (*(void (__cdecl **)(int))(v13 + 8))(v14); /*0x1cd735*/
        }
        ++v12; /*0x1cd73a*/
      }
      while ( v12 < *(_DWORD *)v1 + 1 ); /*0x1cd740*/
    }
  }
  else
  {
    v9 = 0; /*0x1cd6a5*/
    if ( *(_DWORD *)v1 != -1 ) /*0x1cd6aa*/
    {
      do /*0x1cd6f6*/
      {
        if ( *(_DWORD *)(v1 + 4 * v9 + 8) ) /*0x1cd6ac*/
        {
          v29 = *v31; /*0x1cd6b8*/
          v10 = *(_DWORD **)(v1 + 4 * v9 + 8); /*0x1cd6bb*/
          v11 = *v10 & *v31; /*0x1cd6c1*/
          if ( v31[v11 + 2] ) /*0x1cd6c6*/
          {
            do /*0x1cd6db*/
              v11 = v29 & (v11 + 1); /*0x1cd6d5*/
            while ( v31[v11 + 2] ); /*0x1cd6db*/
            v31[v11 + 2] = *(_DWORD *)(v1 + 4 * v9 + 8); /*0x1cd6e6*/
          }
          else
          {
            v31[v11 + 2] = (int)v10; /*0x1cd6cd*/
          }
          ++v31[1]; /*0x1cd6ed*/
        }
        ++v9; /*0x1cd6f0*/
      }
      while ( v9 < *(_DWORD *)v1 + 1 ); /*0x1cd6f6*/
    }
    *(_BYTE *)(a1 + 16) |= 0x20u; /*0x1cd6fb*/
  }
  *(_DWORD *)(a1 + 32) = v31; /*0x1cd748*/
  v15 = NXDefaultMallocZone(v21, v26); /*0x1cd750*/
  v16 = NXDefaultMallocZone(v1, v23); /*0x1cd753*/
  (*(void (__stdcall **)(int, int, int, int, int, int, int, int *, int))(v15 + 8))( /*0x1cd75c*/
    v16,
    v17,
    v24,
    v27,
    v28,
    v29,
    v30,
    v31,
    savedregs);
  return (_DWORD *)v32; /*0x1cd764*/
}

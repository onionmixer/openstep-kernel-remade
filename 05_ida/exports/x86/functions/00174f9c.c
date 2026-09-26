/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x174f9c. */
int __cdecl vm_map_submap(int a1, unsigned int a2, unsigned int a3, int a4)
{
  volatile __int32 *v4; // edx
  _DWORD *v5; // ecx
  _DWORD *v6; // eax
  volatile __int32 *v7; // edx
  volatile __int32 *v8; // edx
  int v9; // eax
  int v10; // edx
  int v11; // edx
  volatile __int32 *v12; // ecx
  int v13; // eax
  int v14; // edx
  int v15; // edx
  volatile __int32 *v16; // ecx
  char v17; // cl
  int v18; // edx
  volatile __int32 *v19; // edx
  int *v21; // [esp+10h] [ebp-18h]
  int *v22; // [esp+18h] [ebp-10h]
  int v23; // [esp+20h] [ebp-8h]
  _DWORD *v24; // [esp+24h] [ebp-4h]
  int v25; // [esp+24h] [ebp-4h]

  v23 = 4; /*0x174fa5*/
  lock_write(a1); /*0x174fb0*/
  ++*(_DWORD *)(a1 + 76); /*0x174fb5*/
  if ( a2 < *(_DWORD *)(a1 + 20) ) /*0x174fc1*/
    a2 = *(_DWORD *)(a1 + 20); /*0x174fc3*/
  if ( a3 > *(_DWORD *)(a1 + 24) ) /*0x174fcf*/
    a3 = *(_DWORD *)(a1 + 24); /*0x174fd1*/
  if ( a2 > a3 ) /*0x174fda*/
    a2 = a3; /*0x174fdc*/
  v4 = (volatile __int32 *)(a1 + 60); /*0x174fe2*/
  do /*0x174ffa*/
  {
    while ( *v4 ) /*0x174fe8*/
      ; /*0x174fea*/
  }
  while ( _InterlockedExchange(v4, 1) == 1 ); /*0x174ffa*/
  v5 = *(_DWORD **)(a1 + 56); /*0x174fff*/
  _InterlockedExchange((volatile __int32 *)(a1 + 60), 0); /*0x175004*/
  v6 = (_DWORD *)(a1 + 12); /*0x175009*/
  if ( v5 == (_DWORD *)(a1 + 12) ) /*0x17500e*/
    v5 = *(_DWORD **)(a1 + 16); /*0x175010*/
  if ( v5[2] > a2 ) /*0x175019*/
  {
    v6 = (_DWORD *)v5[1]; /*0x17502c*/
    v5 = *(_DWORD **)(a1 + 16); /*0x175032*/
LABEL_24:
    while ( v5 != v6 ) /*0x175079*/
    {
      if ( v5[3] > a2 ) /*0x17503e*/
      {
        if ( v5[2] > a2 ) /*0x175043*/
          goto LABEL_25; /*0x175043*/
        v24 = v5; /*0x175045*/
        v7 = (volatile __int32 *)(a1 + 60); /*0x17504b*/
        do /*0x175062*/
        {
          while ( *v7 ) /*0x175050*/
            ; /*0x175052*/
        }
        while ( _InterlockedExchange(v7, 1) == 1 ); /*0x175062*/
        *(_DWORD *)(a1 + 56) = v5; /*0x175067*/
        _InterlockedExchange((volatile __int32 *)(a1 + 60), 0); /*0x17506c*/
        goto LABEL_29; /*0x17506f*/
      }
      v5 = (_DWORD *)v5[1]; /*0x175074*/
    }
    goto LABEL_25; /*0x175079*/
  }
  if ( v5 == v6 ) /*0x17501d*/
  {
LABEL_25:
    v25 = *v5; /*0x17507b*/
    v8 = (volatile __int32 *)(a1 + 60); /*0x175083*/
    do /*0x17509a*/
    {
      while ( *v8 ) /*0x175088*/
        ; /*0x17508a*/
    }
    while ( _InterlockedExchange(v8, 1) == 1 ); /*0x17509a*/
    *(_DWORD *)(a1 + 56) = v25; /*0x1750a2*/
    _InterlockedExchange((volatile __int32 *)(a1 + 60), 0); /*0x1750a7*/
    v24 = *(_DWORD **)(v25 + 4); /*0x175192*/
    goto LABEL_42; /*0x17509c*/
  }
  if ( v5[3] <= a2 ) /*0x175022*/
    goto LABEL_24; /*0x175022*/
  v24 = v5; /*0x175024*/
LABEL_29:
  if ( v24[2] < a2 ) /*0x1750b9*/
  {
    if ( *(_DWORD *)(a1 + 32) ) /*0x1750cd*/
      v9 = vm_map_entry_zone; /*0x1750d3*/
    else
      v9 = vm_map_kentry_zone; /*0x1750dc*/
    v22 = (int *)zalloc(v9); /*0x1750e7*/
    if ( !v22 ) /*0x1750ef*/
      panic(aVmMapEntryCrea); /*0x1750f6*/
    qmemcpy(v22, v24, 0x2Cu); /*0x175113*/
    v22[3] = a2; /*0x175118*/
    v24[5] += a2 - v24[2]; /*0x175121*/
    v24[2] = a2; /*0x175124*/
    ++*(_DWORD *)(a1 + 28); /*0x17512a*/
    *v22 = *v24; /*0x175132*/
    v22[1] = *(_DWORD *)(*v24 + 4); /*0x175139*/
    v10 = *v22; /*0x17513c*/
    *(_DWORD *)v22[1] = v22; /*0x175141*/
    *(_DWORD *)(v10 + 4) = v22; /*0x175143*/
    if ( (v24[6] & 5) != 0 ) /*0x17514a*/
    {
      v11 = v22[4]; /*0x17514c*/
      if ( v11 ) /*0x175151*/
      {
        v12 = (volatile __int32 *)(v11 + 52); /*0x175153*/
        do /*0x17516a*/
        {
          while ( *v12 ) /*0x175158*/
            ; /*0x17515a*/
        }
        while ( _InterlockedExchange(v12, 1) == 1 ); /*0x17516a*/
        ++*(_DWORD *)(v11 + 48); /*0x17516c*/
        _InterlockedExchange((volatile __int32 *)(v11 + 52), 0); /*0x175171*/
      }
    }
    else
    {
      vm_object_reference(v22[4]); /*0x17517f*/
    }
  }
LABEL_42:
  if ( v24[3] > a3 ) /*0x17519e*/
  {
    if ( *(_DWORD *)(a1 + 32) ) /*0x1751b2*/
      v13 = vm_map_entry_zone; /*0x1751b8*/
    else
      v13 = vm_map_kentry_zone; /*0x1751c0*/
    v21 = (int *)zalloc(v13); /*0x1751cb*/
    if ( !v21 ) /*0x1751d3*/
      panic(aVmMapEntryCrea); /*0x1751da*/
    qmemcpy(v21, v24, 0x2Cu); /*0x1751f7*/
    v24[3] = a3; /*0x1751fc*/
    v21[2] = a3; /*0x175202*/
    v21[5] += a3 - v24[2]; /*0x17520b*/
    ++*(_DWORD *)(a1 + 28); /*0x175211*/
    *v21 = (int)v24; /*0x175214*/
    v21[1] = v24[1]; /*0x175219*/
    v14 = *v21; /*0x17521c*/
    *(_DWORD *)v21[1] = v21; /*0x175221*/
    *(_DWORD *)(v14 + 4) = v21; /*0x175223*/
    if ( (v24[6] & 5) != 0 ) /*0x17522a*/
    {
      v15 = v21[4]; /*0x17522c*/
      if ( v15 ) /*0x175231*/
      {
        v16 = (volatile __int32 *)(v15 + 52); /*0x175233*/
        do /*0x17524a*/
        {
          while ( *v16 ) /*0x175238*/
            ; /*0x17523a*/
        }
        while ( _InterlockedExchange(v16, 1) == 1 ); /*0x17524a*/
        ++*(_DWORD *)(v15 + 48); /*0x17524c*/
        _InterlockedExchange((volatile __int32 *)(v15 + 52), 0); /*0x175251*/
      }
    }
    else
    {
      vm_object_reference(v21[4]); /*0x17525f*/
    }
  }
  if ( v24[2] == a2 && v24[3] == a3 ) /*0x175278*/
  {
    v17 = *((_BYTE *)v24 + 24); /*0x17527a*/
    if ( (v17 & 1) == 0 ) /*0x175280*/
    {
      v18 = v24[4]; /*0x175282*/
      if ( vm_submap_object == v18 && (v17 & 8) == 0 ) /*0x175290*/
      {
        v24[4] = 0; /*0x175292*/
        vm_object_deallocate(v18); /*0x17529a*/
        *((_BYTE *)v24 + 24) |= 4u; /*0x1752a2*/
        v24[4] = a4; /*0x1752ac*/
        if ( a4 ) /*0x1752b7*/
        {
          v19 = (volatile __int32 *)(a4 + 52); /*0x1752b9*/
          do /*0x1752ce*/
          {
            while ( *v19 ) /*0x1752bc*/
              ; /*0x1752be*/
          }
          while ( _InterlockedExchange(v19, 1) == 1 ); /*0x1752ce*/
          ++*(_DWORD *)(a4 + 48); /*0x1752d0*/
          _InterlockedExchange((volatile __int32 *)(a4 + 52), 0); /*0x1752d5*/
        }
        v23 = 0; /*0x1752d8*/
      }
    }
  }
  lock_done(a1); /*0x1752e3*/
  return v23; /*0x1752ee*/
}

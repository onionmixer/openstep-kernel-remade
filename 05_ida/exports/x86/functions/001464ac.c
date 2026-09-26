/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1464ac. */
int __cdecl ipc_entry_grow_table(int a1)
{
  volatile __int32 *v1; // edx
  int *v3; // ebx
  unsigned int v4; // edx
  volatile __int32 *v5; // edx
  volatile __int32 *v6; // edx
  unsigned int v7; // ebx
  int v8; // eax
  unsigned int v9; // ebx
  _DWORD *v10; // edx
  _DWORD *i; // ecx
  int *v12; // ebx
  int v13; // eax
  int v14; // eax
  int v15; // edx
  int v16; // ebx
  int j; // eax
  unsigned int v18; // edx
  unsigned int v19; // ebx
  _DWORD *v20; // eax
  volatile __int32 *v21; // edx
  int v22; // edx
  _DWORD *v23; // [esp+Ch] [ebp-7Ch]
  int v24; // [esp+Ch] [ebp-7Ch]
  unsigned int v25; // [esp+14h] [ebp-74h]
  int v26; // [esp+20h] [ebp-68h]
  _DWORD *v27; // [esp+24h] [ebp-64h]
  int *v28; // [esp+28h] [ebp-60h]
  _DWORD *v29; // [esp+2Ch] [ebp-5Ch]
  void *v30; // [esp+30h] [ebp-58h]
  int v31; // [esp+34h] [ebp-54h]
  int v32; // [esp+38h] [ebp-50h]
  unsigned int v33; // [esp+3Ch] [ebp-4Ch]
  _BYTE v34[24]; // [esp+40h] [ebp-48h] BYREF
  _BYTE v35[24]; // [esp+58h] [ebp-30h] BYREF
  _BYTE v36[24]; // [esp+70h] [ebp-18h] BYREF

  do /*0x1468f1*/
  {
    if ( *(_DWORD *)(a1 + 16) ) /*0x1464c7*/
    {
      assert_wait(a1, 0); /*0x1464d0*/
      _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x1464da*/
      thread_block_with_continuation(0); /*0x1464df*/
      v1 = (volatile __int32 *)(a1 + 8); /*0x1464e7*/
      do /*0x1464fe*/
      {
        while ( *v1 ) /*0x1464ec*/
          ; /*0x1464ee*/
      }
      while ( _InterlockedExchange(v1, 1) == 1 ); /*0x1464fe*/
      return 0; /*0x146502*/
    }
    v30 = *(void **)(a1 + 20); /*0x14650e*/
    v3 = *(int **)(a1 + 28); /*0x146514*/
    v32 = *v3; /*0x146519*/
    v28 = v3 - 1; /*0x14651f*/
    v33 = *(v3 - 1); /*0x146525*/
    v27 = v3 + 1; /*0x14652b*/
    v31 = v3[1]; /*0x146531*/
    if ( v33 == *v3 ) /*0x14653a*/
    {
      _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x146541*/
      return 3; /*0x146549*/
    }
    *(_DWORD *)(a1 + 16) = 1; /*0x146553*/
    _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14655c*/
    v4 = 16 * *(v3 - 1); /*0x146562*/
    if ( page_size > v4 ) /*0x14656b*/
      v29 = (_DWORD *)ipc_table_alloc(16 * *v3); /*0x146593*/
    else
      v29 = (_DWORD *)ipc_table_realloc(v4, v30, 16 * *v3); /*0x14657d*/
    v5 = (volatile __int32 *)(a1 + 8); /*0x14659c*/
    do /*0x1465b2*/
    {
      while ( *v5 ) /*0x1465a0*/
        ; /*0x1465a2*/
    }
    while ( _InterlockedExchange(v5, 1) == 1 ); /*0x1465b2*/
    *(_DWORD *)(a1 + 16) = 0; /*0x1465b7*/
    if ( !v29 ) /*0x1465c2*/
    {
      _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x1465c6*/
      thread_wakeup_prim(a1, 0, 0); /*0x1465ce*/
      return 6; /*0x1465d8*/
    }
    if ( !*(_DWORD *)(a1 + 12) ) /*0x1465e3*/
    {
      _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x1465eb*/
      thread_wakeup_prim(a1, 0, 0); /*0x1465f3*/
      ipc_table_free(16 * *v3, v29); /*0x146602*/
      v6 = (volatile __int32 *)(a1 + 8); /*0x14660a*/
      do /*0x146622*/
      {
        while ( *v6 ) /*0x146610*/
          ; /*0x146612*/
      }
      while ( _InterlockedExchange(v6, 1) == 1 ); /*0x146622*/
      return 0; /*0x146622*/
    }
    *(_DWORD *)(a1 + 20) = v29; /*0x146632*/
    *(_DWORD *)(a1 + 24) = v32; /*0x146638*/
    *(_DWORD *)(a1 + 28) = v27; /*0x14663e*/
    if ( page_size > 16 * *v28 ) /*0x14664f*/
      bcopy(v30, v29, 16 * v33); /*0x146660*/
    v7 = 0; /*0x146668*/
    if ( v33 ) /*0x14666d*/
    {
      v8 = 0; /*0x14666f*/
      do /*0x146686*/
      {
        v29[v8 + 3] = 0; /*0x146677*/
        v8 += 4; /*0x14667f*/
        ++v7; /*0x146682*/
      }
      while ( v33 > v7 ); /*0x146686*/
    }
    bzero(&v29[4 * v33], 16 * (v32 - v33)); /*0x14669c*/
    v9 = 0; /*0x1466a1*/
    if ( v33 ) /*0x1466a9*/
    {
      v10 = v29; /*0x1466ab*/
      do /*0x1466dd*/
      {
        if ( (*v10 & 0x1F0000) == 0x10000 ) /*0x1466bc*/
        {
          v23 = v10; /*0x1466c8*/
          ipc_hash_local_insert(a1, v10[1], v9); /*0x1466cb*/
          v10 = v23; /*0x1466d3*/
        }
        v10 += 4; /*0x1466d6*/
        ++v9; /*0x1466d9*/
      }
      while ( v33 > v9 ); /*0x1466dd*/
    }
    if ( *(_DWORD *)(a1 + 56) ) /*0x1466e2*/
    {
      ipc_splay_tree_split(a1 + 32, v31 << 8, v34); /*0x1466fe*/
      ipc_splay_tree_split(v34, v32 << 8, v35); /*0x14670f*/
      ipc_splay_tree_split(v35, v33 << 8, v36); /*0x146720*/
      for ( i = (_DWORD *)ipc_splay_traverse_start(v35); i; i = (_DWORD *)ipc_splay_traverse_next(v35, v13) ) /*0x146735*/
      {
        v25 = i[4]; /*0x14673f*/
        v12 = &v29[4 * (v25 >> 8)]; /*0x146759*/
        if ( *v12 ) /*0x14675b*/
        {
          *v12 |= 0x800000u; /*0x146767*/
          v13 = 0; /*0x146769*/
        }
        else
        {
          v14 = *i & 0x1F0000; /*0x146774*/
          *v12 = (v25 << 24) | *i; /*0x14677c*/
          v15 = i[1]; /*0x14677e*/
          v12[1] = v15; /*0x146781*/
          v12[2] = i[2]; /*0x146787*/
          if ( v14 == 0x10000 ) /*0x14678f*/
          {
            v24 = v15; /*0x14679b*/
            ipc_hash_global_delete(a1, v15, v25, i); /*0x14679e*/
            ipc_hash_local_insert(a1, v24, v25 >> 8); /*0x1467ad*/
          }
          --*(_DWORD *)(a1 + 56); /*0x1467b8*/
          v13 = 1; /*0x1467bb*/
        }
      }
      ipc_splay_traverse_finish(v35); /*0x1467db*/
      v16 = 0; /*0x1467e0*/
      v26 = 0; /*0x1467e2*/
      for ( j = ipc_splay_traverse_start(v34); j; j = ipc_splay_traverse_next(v34, 0) ) /*0x1467ed*/
      {
        if ( v26 != *(_DWORD *)(j + 16) >> 8 ) /*0x1467fd*/
        {
          ++v16; /*0x1467ff*/
          v26 = *(_DWORD *)(j + 16) >> 8; /*0x146800*/
        }
      }
      ipc_splay_traverse_finish(v34); /*0x14681b*/
      *(_DWORD *)(a1 + 60) = v16; /*0x146823*/
      ipc_splay_tree_join(a1 + 32, v34); /*0x14682e*/
      ipc_splay_tree_join(a1 + 32, v35); /*0x146838*/
      ipc_splay_tree_join(a1 + 32, v36); /*0x146842*/
    }
    v18 = v29[2]; /*0x14684d*/
    v19 = v32 - 1; /*0x146853*/
    if ( v33 <= v32 - 1 ) /*0x146857*/
    {
      v20 = &v29[4 * v19]; /*0x14685e*/
      do /*0x146877*/
      {
        if ( !*v20 ) /*0x146860*/
        {
          *v20 = -16777216; /*0x146865*/
          v20[2] = v18; /*0x14686b*/
          v18 = v19; /*0x14686e*/
        }
        v20 -= 4; /*0x146870*/
        --v19; /*0x146873*/
      }
      while ( v33 <= v19 ); /*0x146877*/
    }
    v29[2] = v18; /*0x14687c*/
    _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x146884*/
    thread_wakeup_prim(a1, 0, 0); /*0x14688c*/
    ipc_table_free(16 * *v28, v30); /*0x14689e*/
    v21 = (volatile __int32 *)(a1 + 8); /*0x1468a6*/
    do /*0x1468be*/
    {
      while ( *v21 ) /*0x1468ac*/
        ; /*0x1468ae*/
    }
    while ( _InterlockedExchange(v21, 1) == 1 ); /*0x1468be*/
    if ( !*(_DWORD *)(a1 + 12) || *(_DWORD **)(a1 + 28) != v27 ) /*0x1468d3*/
      return 0; /*0x1468d3*/
    v22 = *(_DWORD *)(a1 + 60); /*0x1468dc*/
  }
  while ( v22 && 16 * (v31 - v32) < (unsigned int)(32 * v22) ); /*0x1468f1*/
  return 0; /*0x1468ff*/
}

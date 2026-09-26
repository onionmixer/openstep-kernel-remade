/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x145fe8. */
int __cdecl ipc_entry_alloc_name(unsigned int a1, unsigned int a2, unsigned int **a3)
{
  unsigned __int64 v3; // kr00_8
  unsigned int *v4; // esi
  volatile __int32 *v5; // edx
  int result; // eax
  int v7; // ecx
  int v8; // edx
  int i; // eax
  unsigned int *v10; // eax
  _DWORD *v11; // ecx
  unsigned int v12; // edx
  unsigned int v13; // edx
  int v14; // ecx
  unsigned int *v15; // [esp+10h] [ebp-14h]
  volatile __int32 *v16; // [esp+10h] [ebp-14h]
  int v17; // [esp+14h] [ebp-10h]
  unsigned int v18; // [esp+18h] [ebp-Ch]
  unsigned int v19; // [esp+1Ch] [ebp-8h] BYREF
  unsigned int v20; // [esp+20h] [ebp-4h] BYREF

  v3 = (unsigned __int64)a2 << 24; /*0x145ffd*/
  v18 = a2 << 24; /*0x146000*/
  v4 = nullptr; /*0x146003*/
  v5 = (volatile __int32 *)(a1 + 8); /*0x146008*/
  do /*0x14601e*/
  {
    while ( *v5 ) /*0x14600c*/
      ; /*0x14600e*/
  }
  while ( _InterlockedExchange(v5, 1) == 1 ); /*0x14601e*/
  while ( 1 ) /*0x146141*/
  {
    while ( 1 ) /*0x146020*/
    {
      if ( !*(_DWORD *)(a1 + 12) ) /*0x146023*/
      {
        _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x14602b*/
        if ( v4 ) /*0x146030*/
          zfree(ipc_tree_entry_zone, v4); /*0x14603a*/
        return 16; /*0x146044*/
      }
      if ( !is_mul_ok(0x1000000u, a2) && *(_DWORD *)(a1 + 24) > HIDWORD(v3) ) /*0x14605f*/
      {
        v7 = *(_DWORD *)(a1 + 20); /*0x146061*/
        v15 = (unsigned int *)(v7 + 16 * HIDWORD(v3)); /*0x14606b*/
        if ( (*v15 & 0x1F0000) == 0 ) /*0x146075*/
        {
          v8 = 0; /*0x14609c*/
          for ( i = *(_DWORD *)(v7 + 8); HIDWORD(v3) != i; i = *(_DWORD *)(v7 + 16 * i + 8) ) /*0x1460a4*/
            v8 = i; /*0x1460a8*/
          *(_DWORD *)(v7 + 16 * v8 + 8) = *(_DWORD *)(v7 + 16 * i + 8); /*0x1460c0*/
          *v15 = v18; /*0x1460ca*/
          v15[2] = 0; /*0x1460cc*/
          *a3 = v15; /*0x1460d6*/
LABEL_20:
          if ( v4 ) /*0x146103*/
            goto LABEL_21; /*0x146103*/
          return 0; /*0x146103*/
        }
        if ( v18 == (*v15 & 0xFF000000) ) /*0x14607f*/
        {
          *a3 = v15; /*0x146087*/
          if ( v4 ) /*0x14608b*/
LABEL_21:
            zfree(ipc_tree_entry_zone, v4); /*0x146105*/
          return 0; /*0x146114*/
        }
      }
      if ( *(_DWORD *)(a1 + 56) ) /*0x1460df*/
      {
        v10 = (unsigned int *)ipc_splay_tree_lookup(a1 + 32, a2); /*0x1460f0*/
        if ( v10 ) /*0x1460fa*/
        {
          *a3 = v10; /*0x1460ff*/
          goto LABEL_20; /*0x1460ff*/
        }
      }
      v11 = *(_DWORD **)(a1 + 28); /*0x14611f*/
      v12 = *(_DWORD *)(a1 + 24); /*0x146122*/
      if ( HIDWORD(v3) < v12 || HIDWORD(v3) >= *v11 || 16 * (*v11 - v12) >= 32 * (*(_DWORD *)(a1 + 60) + 1) ) /*0x146141*/
        break; /*0x146141*/
      result = ipc_entry_grow_table(a1); /*0x146144*/
      if ( result ) /*0x14614e*/
      {
        if ( v4 ) /*0x146156*/
        {
          v17 = result; /*0x146164*/
          zfree(ipc_tree_entry_zone, v4); /*0x146167*/
          return v17; /*0x14616c*/
        }
        return result; /*0x14616f*/
      }
    }
    if ( v4 ) /*0x146176*/
      break; /*0x146176*/
    v16 = (volatile __int32 *)(a1 + 8); /*0x14622e*/
    _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x146236*/
    v4 = (unsigned int *)zalloc(ipc_tree_entry_zone); /*0x146245*/
    if ( !v4 ) /*0x14624c*/
      return 6; /*0x146253*/
    do /*0x14626e*/
    {
      while ( *v16 ) /*0x14625c*/
        ; /*0x14625e*/
    }
    while ( _InterlockedExchange(v16, 1) == 1 ); /*0x14626e*/
  }
  ++*(_DWORD *)(a1 + 56); /*0x14617f*/
  if ( *(_DWORD *)(a1 + 24) <= HIDWORD(v3) ) /*0x146188*/
  {
    if ( *v11 > HIDWORD(v3) ) /*0x1461a1*/
    {
      ipc_splay_tree_bounds(a1 + 32, a2, &v20, &v19); /*0x1461b6*/
      v13 = a2 >> 8; /*0x1461be*/
      v14 = 0; /*0x1461c1*/
      if ( v20 != -1 && v20 >> 8 == v13 || v19 && v19 >> 8 == v13 ) /*0x1461e1*/
        v14 = 1; /*0x1461e3*/
      if ( !v14 ) /*0x1461ea*/
        ++*(_DWORD *)(a1 + 60); /*0x1461ef*/
    }
  }
  else
  {
    *(_DWORD *)(*(_DWORD *)(a1 + 20) + 16 * HIDWORD(v3)) |= 0x800000u; /*0x146192*/
  }
  ipc_splay_tree_insert(a1 + 32, a2, v4); /*0x1461fe*/
  *v4 = 0; /*0x146203*/
  v4[1] = 0; /*0x146209*/
  v4[2] = 0; /*0x146210*/
  v4[5] = a1; /*0x14621a*/
  *a3 = v4; /*0x146220*/
  return 0; /*0x14627b*/
}

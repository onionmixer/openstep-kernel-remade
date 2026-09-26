/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17d2d0. */
int __cdecl vnode_pagein(int a1, _DWORD *a2)
{
  int v2; // edx
  int v3; // ebx
  _DWORD *v4; // edi
  int v5; // esi
  int v6; // eax
  unsigned int v8; // [esp+10h] [ebp-4h] BYREF

  v2 = 0; /*0x17d2d9*/
  v3 = *(_DWORD *)(*(_DWORD *)(a1 + 20) + 40); /*0x17d2e1*/
  do /*0x17d2fd*/
  {
    while ( vstruct_lock ) /*0x17d2eb*/
      ; /*0x17d2e9*/
  }
  while ( _InterlockedExchange(&vstruct_lock, 1) == 1 ); /*0x17d2fd*/
  ++*(_WORD *)(v3 + 14); /*0x17d2ff*/
  _InterlockedExchange(&vstruct_lock, 0); /*0x17d305*/
  v4 = *(_DWORD **)(v3 + 20); /*0x17d30b*/
  v5 = *(_DWORD *)(*(_DWORD *)(a1 + 20) + 44) + *(_DWORD *)(a1 + 24); /*0x17d317*/
  if ( (*(_BYTE *)(v3 + 12) & 1) != 0 ) /*0x17d31e*/
  {
    v6 = sub_17CD58(v3, v5, 1, &v8); /*0x17d32b*/
    v2 = 0; /*0x17d333*/
    if ( v6 == 5 ) /*0x17d339*/
    {
      v2 = 1; /*0x17d33b*/
    }
    else
    {
      v5 = v8 >> 8 << page_shift; /*0x17d352*/
      v4 = *(_DWORD **)(dword_1E7294[(unsigned __int8)v8] + 8); /*0x17d35f*/
    }
  }
  if ( v2 != 1 ) /*0x17d365*/
  {
    v2 = (*(int (__stdcall **)(_DWORD *, int, int))(v4[7] + 116))(v4, a1, v5); /*0x17d375*/
    if ( a2 ) /*0x17d37b*/
      *a2 = *(_DWORD *)(*v4 + 52); /*0x17d385*/
  }
  do /*0x17d3a1*/
  {
    while ( vstruct_lock ) /*0x17d38f*/
      ; /*0x17d38d*/
  }
  while ( _InterlockedExchange(&vstruct_lock, 1) == 1 ); /*0x17d3a1*/
  --*(_WORD *)(v3 + 14); /*0x17d3a3*/
  _InterlockedExchange(&vstruct_lock, 0); /*0x17d3a9*/
  return v2; /*0x17d3b4*/
}

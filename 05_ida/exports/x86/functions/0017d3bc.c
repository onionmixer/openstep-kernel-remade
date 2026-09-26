/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17d3bc. */
int __cdecl vnode_pageout(int a1)
{
  int v1; // esi
  _DWORD *v2; // ebx
  unsigned int v3; // ecx
  unsigned int v4; // eax
  int v6; // ebx
  vm_size_t v7; // [esp+Ch] [ebp-Ch]
  unsigned int v8; // [esp+14h] [ebp-4h] BYREF

  v1 = *(_DWORD *)(*(_DWORD *)(a1 + 20) + 40); /*0x17d3cb*/
  do /*0x17d3e9*/
  {
    while ( vstruct_lock ) /*0x17d3d7*/
      ; /*0x17d3d5*/
  }
  while ( _InterlockedExchange(&vstruct_lock, 1) == 1 ); /*0x17d3e9*/
  ++*(_WORD *)(v1 + 14); /*0x17d3eb*/
  _InterlockedExchange(&vstruct_lock, 0); /*0x17d3f1*/
  v2 = *(_DWORD **)(v1 + 20); /*0x17d3f7*/
  v3 = *(_DWORD *)(*(_DWORD *)(a1 + 20) + 44) + *(_DWORD *)(a1 + 24); /*0x17d403*/
  v7 = page_size; /*0x17d40c*/
  if ( (*(_BYTE *)(v1 + 12) & 1) == 0 ) /*0x17d413*/
  {
    v4 = *(_DWORD *)(*v2 + 20); /*0x17d41c*/
    if ( v3 + page_size > v4 ) /*0x17d421*/
    {
      if ( v3 <= v4 ) /*0x17d425*/
        v7 = v4 - v3; /*0x17d432*/
      else
        v7 = 0; /*0x17d427*/
    }
    if ( (*(_BYTE *)(v1 + 12) & 1) == 0 ) /*0x17d439*/
      goto LABEL_16; /*0x17d439*/
  }
  if ( sub_17CD58(v1, v3, 0, &v8) != 5 )
  {
    v3 = v8 >> 8 << page_shift; /*0x17d492*/
    v2 = *(_DWORD **)(dword_1E7294[(unsigned __int8)v8] + 8); /*0x17d49f*/
    if ( *(_DWORD *)(*v2 + 20) < v3 + v7 ) /*0x17d4af*/
      *(_DWORD *)(*v2 + 20) = v3 + v7; /*0x17d4b1*/
LABEL_16:
    if ( v7 ) /*0x17d4b8*/
      v6 = (*(int (__cdecl **)(_DWORD *, _DWORD, vm_size_t, unsigned int))(v2[7] + 120))( /*0x17d4cf*/
             v2,
             *(_DWORD *)(a1 + 36),
             v7,
             v3);
    else
      v6 = 0; /*0x17d4d8*/
    if ( v6 )
    {
      printf("vnode_pageout: failed!\n");
    }
    else
    {
      *(_BYTE *)(a1 + 30) |= 0x20u; /*0x17d4e1*/
      pmap_clear_modify(*(_DWORD *)(a1 + 36)); /*0x17d4e9*/
    }
    do /*0x17d515*/
    {
      while ( vstruct_lock ) /*0x17d503*/
        ; /*0x17d501*/
    }
    while ( _InterlockedExchange(&vstruct_lock, 1) == 1 ); /*0x17d515*/
    --*(_WORD *)(v1 + 14); /*0x17d517*/
    _InterlockedExchange(&vstruct_lock, 0); /*0x17d51d*/
    return v6; /*0x17d523*/
  }
  do /*0x17d469*/
  {
    while ( vstruct_lock ) /*0x17d457*/
      ; /*0x17d455*/
  }
  while ( _InterlockedExchange(&vstruct_lock, 1) == 1 ); /*0x17d469*/
  --*(_WORD *)(v1 + 14); /*0x17d46b*/
  _InterlockedExchange(&vstruct_lock, 0); /*0x17d471*/
  return 2; /*0x17d528*/
}

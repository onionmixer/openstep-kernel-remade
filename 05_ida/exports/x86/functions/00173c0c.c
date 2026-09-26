/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x173c0c. */
_BOOL4 __cdecl kmem_realloc(int a1, int a2, int a3, _DWORD *a4, int a5)
{
  int v5; // ebx
  int v6; // esi
  _BOOL4 result; // eax
  int v8; // ebx
  volatile __int32 *v9; // edx
  int v10; // eax
  int v11; // [esp+Ch] [ebp-14h]
  int v12; // [esp+14h] [ebp-Ch] BYREF
  int v13; // [esp+18h] [ebp-8h] BYREF
  unsigned int v14; // [esp+1Ch] [ebp-4h] BYREF

  v5 = a2 & ~page_mask; /*0x173c24*/
  v11 = (~page_mask & (page_mask + a3 + a2)) - v5; /*0x173c2f*/
  v6 = (a5 + page_mask) & ~page_mask; /*0x173c37*/
  result = vm_map_find(a1, 0, 0, &v14, v6, 1) != 0; /*0x173c55*/
  if ( !result ) /*0x173c5c*/
  {
    vm_map_lookup_entry(a1, v14, &v13); /*0x173c6e*/
    if ( !vm_map_lookup_entry(a1, v5, &v12) ) /*0x173c79*/
      panic(aKmemRealloc); /*0x173c8a*/
    v8 = *(_DWORD *)(v12 + 16); /*0x173c95*/
    vm_object_reference(v8); /*0x173c99*/
    v9 = (volatile __int32 *)(v8 + 16); /*0x173c9e*/
    do /*0x173cb6*/
    {
      while ( *v9 ) /*0x173ca4*/
        ; /*0x173ca6*/
    }
    while ( _InterlockedExchange(v9, 1) == 1 ); /*0x173cb6*/
    if ( *(_DWORD *)(v8 + 20) != v11 ) /*0x173cbe*/
      panic(aKmemRealloc_0); /*0x173cc5*/
    *(_DWORD *)(v8 + 20) = v6; /*0x173ccd*/
    _InterlockedExchange((volatile __int32 *)(v8 + 16), 0); /*0x173cd2*/
    v10 = v13; /*0x173cd5*/
    *(_DWORD *)(v13 + 16) = v8; /*0x173cd8*/
    *(_DWORD *)(v10 + 20) = 0; /*0x173cdb*/
    lock_done(a1); /*0x173ce6*/
    sub_173EBC(v8, v11, v6, 1); /*0x173cf3*/
    vm_map_pageable(a1, v14, v6 + v14, 0); /*0x173d03*/
    *a4 = v14; /*0x173d0e*/
    return 0; /*0x173d10*/
  }
  return result; /*0x173d15*/
}

/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x173e48. */
int __cdecl kmem_alloc_pageable(int a1, _DWORD *a2, int a3)
{
  int result; // eax
  unsigned int v4; // [esp+8h] [ebp-4h] BYREF

  v4 = *(_DWORD *)(a1 + 20); /*0x173e5c*/
  result = vm_map_find(a1, 0, 0, &v4, ~page_mask & (page_mask + a3), 1); /*0x173e76*/
  if ( !result ) /*0x173e7d*/
  {
    *a2 = v4; /*0x173e82*/
    return 0; /*0x173e84*/
  }
  return result; /*0x173e89*/
}

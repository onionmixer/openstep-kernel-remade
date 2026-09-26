/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x173d1c. */
int __cdecl kmem_alloc_wired(int a1, _DWORD *a2, int a3)
{
  int v3; // esi
  int v4; // eax
  _BOOL4 v6; // [esp+Ch] [ebp-10h]
  int v7; // [esp+10h] [ebp-Ch]
  int v8; // [esp+14h] [ebp-8h]
  int v9; // [esp+18h] [ebp-4h] BYREF

  v8 = kernel_object; /*0x173d31*/
  v7 = 0; /*0x173d34*/
  v9 = *(_DWORD *)(a1 + 20); /*0x173d3e*/
  v3 = ~page_mask & (page_mask + a3); /*0x173d4d*/
  v4 = vm_map_find(a1, 0, 0, &v9, v3, 1); /*0x173d5b*/
  v6 = v4 != 0; /*0x173d6d*/
  if ( v4 ) /*0x173d72*/
  {
    if ( kernel_object != v8 ) /*0x173d7d*/
      vm_object_deallocate(v8); /*0x173d80*/
    return v6; /*0x173d85*/
  }
  else
  {
    if ( kernel_object == v8 ) /*0x173d99*/
    {
      v7 = v9; /*0x173d9e*/
      vm_object_reference(v8); /*0x173da2*/
      lock_write(a1); /*0x173dab*/
      ++*(_DWORD *)(a1 + 76); /*0x173db0*/
      vm_map_delete(a1, v9, v3 + v9); /*0x173dbf*/
      vm_map_insert(a1, v8, v7, v9, v3 + v9); /*0x173dd5*/
      lock_done(a1); /*0x173dde*/
    }
    if ( sub_173EBC(v8, v7, v3, 1) ) /*0x173df1*/
    {
      vm_map_pageable(a1, v9, v3 + v9, 0); /*0x173e2f*/
      *a2 = v9; /*0x173e3a*/
      return 0; /*0x173e3c*/
    }
    else
    {
      lock_write(a1); /*0x173dfe*/
      ++*(_DWORD *)(a1 + 76); /*0x173e03*/
      vm_map_delete(a1, v9, v3 + v9); /*0x173e12*/
      lock_done(a1); /*0x173e18*/
      return 6; /*0x173e1d*/
    }
  }
}

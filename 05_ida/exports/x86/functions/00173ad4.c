/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x173ad4. */
int __cdecl kmem_alloc(int a1, _DWORD *a2, int a3)
{
  int v3; // ebx
  int v4; // eax
  int v5; // eax
  int v7; // [esp+Ch] [ebp-10h]
  _BOOL4 v8; // [esp+10h] [ebp-Ch]
  int v9; // [esp+14h] [ebp-8h]
  int v10; // [esp+18h] [ebp-4h] BYREF

  v7 = vm_object_allocate(a3); /*0x173ae9*/
  v9 = 0; /*0x173aef*/
  v10 = *(_DWORD *)(a1 + 20); /*0x173af9*/
  v3 = ~page_mask & (page_mask + a3); /*0x173b05*/
  v4 = 0; /*0x173b10*/
  if ( kernel_object != v7 ) /*0x173b1b*/
    v4 = v7; /*0x173b1d*/
  v5 = vm_map_find(a1, v4, 0, &v10, ~page_mask & (page_mask + a3), 1); /*0x173b22*/
  v8 = v5 != 0; /*0x173b34*/
  if ( v5 ) /*0x173b39*/
  {
    if ( kernel_object != v7 ) /*0x173b44*/
      vm_object_deallocate(v7); /*0x173b47*/
    return v8; /*0x173b4c*/
  }
  else
  {
    if ( kernel_object == v7 ) /*0x173b5d*/
    {
      v9 = v10; /*0x173b62*/
      vm_object_reference(v7); /*0x173b66*/
      lock_write(a1); /*0x173b6f*/
      ++*(_DWORD *)(a1 + 76); /*0x173b74*/
      vm_map_delete(a1, v10, v3 + v10); /*0x173b83*/
      vm_map_insert(a1, v7, v9, v10, v3 + v10); /*0x173b99*/
      lock_done(a1); /*0x173ba2*/
    }
    if ( sub_173EBC(v7, v9, v3, 1) ) /*0x173bb5*/
    {
      vm_map_pageable(a1, v10, v3 + v10, 0); /*0x173bf3*/
      *a2 = v10; /*0x173bfe*/
      return 0; /*0x173c00*/
    }
    else
    {
      lock_write(a1); /*0x173bc2*/
      ++*(_DWORD *)(a1 + 76); /*0x173bc7*/
      vm_map_delete(a1, v10, v3 + v10); /*0x173bd6*/
      lock_done(a1); /*0x173bdc*/
      return 6; /*0x173be1*/
    }
  }
}

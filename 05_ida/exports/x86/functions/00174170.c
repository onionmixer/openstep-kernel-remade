/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x174170. */
int __cdecl kmem_alloc_zone(int a1, int *a2, int a3, int a4)
{
  int v4; // esi
  int v5; // eax
  _BOOL4 v7; // [esp+Ch] [ebp-10h]
  int v8; // [esp+10h] [ebp-Ch]
  int v9; // [esp+14h] [ebp-8h]
  int v10; // [esp+18h] [ebp-4h] BYREF

  v9 = kernel_object; /*0x174185*/
  v8 = 0; /*0x174188*/
  v10 = *(_DWORD *)(a1 + 20); /*0x174192*/
  v4 = ~page_mask & (page_mask + a3); /*0x1741a1*/
  v5 = vm_map_find(a1, 0, 0, (unsigned int *)&v10, v4, 1); /*0x1741af*/
  v7 = v5 != 0; /*0x1741c1*/
  if ( v5 ) /*0x1741c6*/
  {
    if ( kernel_object != v9 ) /*0x1741d1*/
      vm_object_deallocate(v9); /*0x1741d4*/
    return v7; /*0x1741d9*/
  }
  else
  {
    if ( kernel_object == v9 ) /*0x1741ed*/
    {
      v8 = v10; /*0x1741f2*/
      vm_object_reference(v9); /*0x1741f6*/
      lock_write(a1); /*0x1741ff*/
      ++*(_DWORD *)(a1 + 76); /*0x174204*/
      vm_map_delete(a1, v10, v4 + v10); /*0x174213*/
      vm_map_insert(a1, v9, v8, v10, v4 + v10); /*0x174229*/
      lock_done(a1); /*0x174232*/
    }
    if ( sub_173EBC(v9, v8, v4, a4) ) /*0x174247*/
    {
      vm_map_pageable(a1, v10, v4 + v10, 0); /*0x174287*/
      *a2 = v10; /*0x174292*/
      return 0; /*0x174294*/
    }
    else
    {
      lock_write(a1); /*0x174254*/
      ++*(_DWORD *)(a1 + 76); /*0x174259*/
      vm_map_delete(a1, v10, v4 + v10); /*0x174268*/
      lock_done(a1); /*0x17426e*/
      return 6; /*0x174273*/
    }
  }
}

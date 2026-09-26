/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x151d04. */
int __cdecl host_ipc_hash_info(int a1, int *a2, unsigned int *a3)
{
  unsigned int v3; // edi
  int v5; // esi
  unsigned int i; // ebx
  int v7; // ebx
  unsigned int v8; // [esp+10h] [ebp-Ch]
  int v9; // [esp+14h] [ebp-8h] BYREF
  int v10; // [esp+18h] [ebp-4h] BYREF

  v3 = 0; /*0x151d0d*/
  if ( !a1 ) /*0x151d13*/
    return 22; /*0x151d1a*/
  v5 = *a2; /*0x151d23*/
  for ( i = *a3; ; i = v3 >> 2 ) /*0x151d28*/
  {
    v8 = ipc_hash_info(v5, i); /*0x151d33*/
    if ( v8 <= i ) /*0x151d3b*/
      break; /*0x151d3b*/
    if ( *a2 != v5 ) /*0x151d42*/
      kmem_free(ipc_kernel_map, v10, v3); /*0x151d50*/
    v3 = ~page_mask & (page_mask + 4 * v8); /*0x151d67*/
    if ( kmem_alloc_pageable(ipc_kernel_map, &v10, v3) ) /*0x151d75*/
      return 6; /*0x151dc1*/
    v5 = v10; /*0x151d81*/
  }
  if ( *a2 == v5 ) /*0x151d91*/
    goto LABEL_16; /*0x151d91*/
  if ( v8 ) /*0x151d9b*/
  {
    v7 = ~page_mask & (page_mask + 4 * v8); /*0x151dd3*/
    if ( v7 != v3 ) /*0x151dd7*/
      kmem_free(ipc_kernel_map, v7 + v10, v3 - v7); /*0x151deb*/
    vm_move(ipc_kernel_map, v10, ipc_soft_map, v7, 1, (int)&v9); /*0x151e0c*/
    *a2 = v9; /*0x151e17*/
LABEL_16:
    *a3 = v8; /*0x151e19*/
    return 0; /*0x151e1f*/
  }
  kmem_free(ipc_kernel_map, v10, v3); /*0x151da9*/
  *a3 = 0; /*0x151db1*/
  return 0; /*0x151e26*/
}

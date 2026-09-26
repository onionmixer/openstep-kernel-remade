/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x151e30. */
int __cdecl host_ipc_marequest_info(int a1, _DWORD *a2, int *a3, unsigned int *a4)
{
  unsigned int v4; // edi
  int v6; // ebx
  unsigned int i; // esi
  int v8; // ebx
  unsigned int v9; // [esp+10h] [ebp-Ch]
  int v10; // [esp+14h] [ebp-8h] BYREF
  int v11; // [esp+18h] [ebp-4h] BYREF

  v4 = 0; /*0x151e39*/
  if ( !a1 ) /*0x151e3f*/
    return 22; /*0x151e46*/
  v6 = *a3; /*0x151e4f*/
  for ( i = *a4; ; i = v4 >> 2 ) /*0x151e54*/
  {
    v9 = ipc_marequest_info(a2, v6, i); /*0x151e63*/
    if ( v9 <= i ) /*0x151e6b*/
      break; /*0x151e6b*/
    if ( *a3 != v6 ) /*0x151e72*/
      kmem_free(ipc_kernel_map, v11, v4); /*0x151e80*/
    v4 = ~page_mask & (page_mask + 4 * v9); /*0x151e97*/
    if ( kmem_alloc_pageable(ipc_kernel_map, &v11, v4) ) /*0x151ea5*/
      return 6; /*0x151ef1*/
    v6 = v11; /*0x151eb1*/
  }
  if ( *a3 == v6 ) /*0x151ec1*/
    goto LABEL_16; /*0x151ec1*/
  if ( v9 ) /*0x151ecb*/
  {
    v8 = ~page_mask & (page_mask + 4 * v9); /*0x151f03*/
    if ( v8 != v4 ) /*0x151f07*/
      kmem_free(ipc_kernel_map, v8 + v11, v4 - v8); /*0x151f1b*/
    vm_move(ipc_kernel_map, v11, ipc_soft_map, v8, 1, (int)&v10); /*0x151f3c*/
    *a3 = v10; /*0x151f47*/
LABEL_16:
    *a4 = v9; /*0x151f49*/
    return 0; /*0x151f4f*/
  }
  kmem_free(ipc_kernel_map, v11, v4); /*0x151ed9*/
  *a4 = 0; /*0x151ee1*/
  return 0; /*0x151f56*/
}

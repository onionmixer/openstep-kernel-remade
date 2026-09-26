/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15ce08. */
int __cdecl sub_15CE08(_DWORD *a1, int a2, int a3, unsigned int a4, int a5, int a6, int *a7)
{
  int v8; // esi
  int v9; // eax
  int v10; // edx
  int v11; // ebx
  int v12; // ebx
  int v13; // eax
  int v14; // eax
  int v15; // [esp+Ch] [ebp-1Ch]
  int v16; // [esp+10h] [ebp-18h]
  int v17; // [esp+14h] [ebp-14h]
  int v18; // [esp+18h] [ebp-10h]
  vm_address_t address; // [esp+1Ch] [ebp-Ch] BYREF
  int v20; // [esp+20h] [ebp-8h] BYREF
  int v21; // [esp+24h] [ebp-4h] BYREF

  if ( a4 < a1[9] + a1[8] ) /*0x15ce1d*/
    return 2; /*0x15ce1d*/
  v18 = ~page_mask & (page_mask + a1[7]); /*0x15ce30*/
  if ( v18 < 0 ) /*0x15ce33*/
    return 2; /*0x15ce33*/
  if ( !v18 ) /*0x15ce39*/
    return 0; /*0x15ce3d*/
  v21 = a1[6] & ~page_mask; /*0x15ce4a*/
  if ( vm_map_find(a6, 0, 0, (unsigned int *)&v21, v18, 0) ) /*0x15ce5f*/
    return 5; /*0x15ce72*/
  v8 = ~page_mask & (page_mask + a1[9]); /*0x15ce89*/
  v17 = a3 + a1[8]; /*0x15ce91*/
  if ( v8 < 0 ) /*0x15ce96*/
    return 2; /*0x15ce9d*/
  if ( v8 <= 0 ) /*0x15cea6*/
    goto LABEL_24; /*0x15cea6*/
  v9 = pmap_create(v8); /*0x15ceb2*/
  v15 = vm_map_create(v9, 0, v8, 1); /*0x15cec0*/
  v20 = 0; /*0x15cec3*/
  if ( vm_allocate_with_pager(v15, &v20, v8, 0, a2, v17) ) /*0x15cedd*/
  {
    vm_map_deallocate(v15); /*0x15ceec*/
    return 5; /*0x15cef6*/
  }
  v10 = a1[9]; /*0x15ceff*/
  if ( v8 != v10 && (!a5 || a5 != v10 + v17) ) /*0x15cf18*/
  {
    v16 = ~page_mask & v10; /*0x15cf27*/
    address = 0; /*0x15cf2a*/
    if ( vm_map_find(kernel_map, 0, 0, &address, page_size, 1) ) /*0x15cf49*/
    {
      vm_map_deallocate(v15); /*0x15cf5b*/
      return 5; /*0x15cf65*/
    }
    if ( vm_map_copy(kernel_map, v15, address, page_size, v16, 0, 0) ) /*0x15cf8a*/
    {
      vm_deallocate(kernel_map, address, page_size); /*0x15cfaa*/
      vm_map_deallocate(v15); /*0x15cfb3*/
      return 4; /*0x15cfbd*/
    }
    bzero((void *)(address + a1[9] - v16), v8 - a1[9]); /*0x15cfd6*/
    v11 = vm_map_copy(a6, kernel_map, v21 + v16, page_size, address, 0, 0); /*0x15d001*/
    vm_deallocate(kernel_map, address, page_size); /*0x15d018*/
    if ( v11 ) /*0x15d022*/
    {
      vm_map_deallocate(v15); /*0x15d028*/
      return 4; /*0x15d032*/
    }
    v8 = v16; /*0x15d038*/
  }
  v12 = vm_map_copy(a6, v15, v21, v8, v20, 0, 0); /*0x15d055*/
  vm_map_deallocate(v15); /*0x15d05b*/
  if ( v12 ) /*0x15d065*/
    return 4; /*0x15d067*/
LABEL_24:
  v13 = a1[10]; /*0x15d073*/
  if ( v13 != 3 ) /*0x15d079*/
    vm_map_protect(a6, v21, v21 + v18, v13, 1); /*0x15d08c*/
  v14 = a1[11]; /*0x15d097*/
  if ( v14 != 3 ) /*0x15d09d*/
    vm_map_protect(a6, v21, v21 + v18, v14, 0); /*0x15d0b0*/
  if ( !a1[8] ) /*0x15d0b8*/
    *a7 = v21; /*0x15d0c4*/
  return 0; /*0x15d0cb*/
}

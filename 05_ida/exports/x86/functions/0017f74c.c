/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17f74c. */
int __cdecl _KernBusMemoryCreateMapping(int a1, int a2, unsigned int *a3, int a4, char a5, int a6)
{
  int v6; // ebx
  unsigned int v8; // ebx
  int v9; // esi
  int v10; // edi
  int v11; // [esp+10h] [ebp-4h]
  int v12; // [esp+1Ch] [ebp+8h]

  v11 = *(_DWORD *)(a4 + 12); /*0x17f764*/
  vm_map_reference(v11); /*0x17f768*/
  if ( a5 ) /*0x17f772*/
    *a3 = *(_DWORD *)(v11 + 20); /*0x17f77a*/
  else
    *a3 &= ~page_mask; /*0x17f787*/
  v6 = vm_map_find(v11, 0, 0, a3, a2, a5); /*0x17f79c*/
  if ( v6 ) /*0x17f7a3*/
  {
    vm_map_deallocate(v11); /*0x17f7a9*/
    return v6; /*0x17f7ae*/
  }
  else
  {
    v8 = *a3 & ~page_mask; /*0x17f7c3*/
    v9 = (a2 + page_mask) & ~page_mask; /*0x17f7c9*/
    vm_map_inherit(v11, v8, v9 + v8, 2u); /*0x17f7d6*/
    v12 = ~page_mask & a1; /*0x17f7e2*/
    if ( a6 ) /*0x17f7ec*/
      v10 = a6 == 1; /*0x17f7f2*/
    else
      v10 = 2; /*0x17f7f8*/
    while ( v9 ) /*0x17f833*/
    {
      pmap_enter_cache_spec(*(_DWORD *)(v11 + 36), v8, v12, 3, 1, v10); /*0x17f81d*/
      v8 += page_size; /*0x17f827*/
      v9 -= page_size; /*0x17f829*/
      v12 += page_size; /*0x17f82b*/
    }
    vm_map_deallocate(v11); /*0x17f839*/
    return 0; /*0x17f83e*/
  }
}

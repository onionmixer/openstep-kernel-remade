/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1956b0. */
int __cdecl destroyEventShmem(int a1, int a2, int a3, unsigned int a4, int a5)
{
  unsigned int v6; // esi
  unsigned int i; // ebx
  int v8; // ebx

  if ( !a2 ) /*0x1956ba*/
    return 4; /*0x1956bc*/
  v6 = ~page_mask & (page_mask + a3); /*0x1956d6*/
  for ( i = 0; i < v6; i += page_size ) /*0x1956dc*/
    pmap_remove(*(_DWORD **)(a2 + 36), (char *)(i + a4), page_size + i + a4); /*0x1956f6*/
  v8 = vm_map_remove((_DWORD *)a2, a4, v6 + a4); /*0x19571b*/
  if ( v8 ) /*0x195722*/
    IOLog(aDestroyeventsh); /*0x19572a*/
  kmem_free(kernel_map, a5, v6); /*0x19573e*/
  vm_map_deallocate(a2); /*0x195747*/
  return v8; /*0x195751*/
}

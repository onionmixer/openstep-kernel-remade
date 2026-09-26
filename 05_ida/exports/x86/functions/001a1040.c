/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a1040. */
int __cdecl PCdestroy(int a1)
{
  int v1; // ebx

  v1 = *(_DWORD *)(*(_DWORD *)(a1 + 40) + 236); /*0x1a104c*/
  pmap_remove( /*0x1a106f*/
    *(_DWORD **)(*(_DWORD *)(v1 + 4) + 36),
    *(char **)(v1 + 8),
    ~page_mask & (*(_DWORD *)(v1 + 8) + page_mask + 1308));
  vm_map_remove(*(_DWORD **)(v1 + 4), *(_DWORD *)(v1 + 8), ~page_mask & (*(_DWORD *)(v1 + 8) + page_mask + 1308)); /*0x1a108e*/
  vm_map_deallocate(*(_DWORD *)(v1 + 4)); /*0x1a1097*/
  PCcancelAllTimers(a1); /*0x1a109d*/
  kmem_free(kernel_map, *(_DWORD *)v1, ~page_mask & (page_mask + 1308)); /*0x1a10bf*/
  return kfree(v1, 0xCu); /*0x1a10cf*/
}

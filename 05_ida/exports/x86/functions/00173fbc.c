/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x173fbc. */
int __cdecl kmem_suballoc(int a1, _DWORD *a2, _DWORD *a3, int a4, int a5)
{
  int v5; // esi
  int v7; // [esp+Ch] [ebp-8h]
  unsigned int v8; // [esp+10h] [ebp-4h] BYREF

  v5 = ~page_mask & (page_mask + a4); /*0x173fd6*/
  vm_object_reference(vm_submap_object); /*0x173fdf*/
  v8 = *(_DWORD *)(a1 + 20); /*0x173fe7*/
  if ( vm_map_find(a1, vm_submap_object, 0, &v8, v5, 1) ) /*0x173ffb*/
    panic(aKmemSuballoc1); /*0x17400c*/
  pmap_reference(*(_DWORD *)(a1 + 36)); /*0x174018*/
  v7 = vm_map_create(*(_DWORD *)(a1 + 36), v8, v5 + v8, a5); /*0x174032*/
  if ( !v7 ) /*0x17403a*/
    panic(aKmemSuballoc2); /*0x174041*/
  if ( vm_map_submap(a1, v8, v5 + v8, v7) ) /*0x174056*/
    panic(aKmemSuballoc3); /*0x174067*/
  *a2 = v8; /*0x174072*/
  *a3 = v8 + v5; /*0x17407a*/
  return v7; /*0x174082*/
}

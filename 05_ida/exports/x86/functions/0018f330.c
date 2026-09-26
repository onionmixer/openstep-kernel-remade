/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18f330. */
int __cdecl pmap_init(_DWORD *a1)
{
  int v1; // esi
  int v2; // edi
  int v3; // ebx
  int result; // eax

  v1 = a1[5]; /*0x18f339*/
  v2 = a1[6]; /*0x18f33c*/
  v3 = a1[3]; /*0x18f33f*/
  kmem_alloc_wired(kernel_map, &pg_desc_tbl, 20 * v3); /*0x18f355*/
  pg_first_phys = v1; /*0x18f35a*/
  pmap_zone = zinit(28, 11200, 0, 0, (int)aPmap); /*0x18f375*/
  pv_entry_zone = zinit(12, 120000, 0, 0, (int)aPvEntry); /*0x18f392*/
  result = zinit(32, 32 * v3, 0, 0, (int)aPgExten); /*0x18f3a6*/
  pg_exten_zone = result; /*0x18f3ab*/
  dword_1F7ACC = (int)&pt_active_queue; /*0x18f3b0*/
  pt_active_queue = (int)&pt_active_queue; /*0x18f3ba*/
  dword_1F7ADC = (int)&pt_free_queue; /*0x18f3c4*/
  pt_free_queue = (int)&pt_free_queue; /*0x18f3ce*/
  dword_1F7AAC = (int)&pd_free_queue; /*0x18f3d8*/
  pd_free_queue = (int)&pd_free_queue; /*0x18f3e2*/
  vm_first_phys = v1; /*0x18f3ec*/
  vm_last_phys = v2; /*0x18f3f2*/
  pmap_initialized = 1; /*0x18f3f8*/
  return result; /*0x18f405*/
}

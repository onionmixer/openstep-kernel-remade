/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x173a68. */
int vm_mem_init()
{
  virtual_avail = vm_page_startup(&mem_region, num_regions, virtual_avail); /*0x173a83*/
  zone_bootstrap(); /*0x173a88*/
  vm_object_init(); /*0x173a8d*/
  vm_map_init(); /*0x173a92*/
  kmem_init(virtual_avail, virtual_end); /*0x173aa5*/
  pmap_init(&mem_region); /*0x173ab6*/
  zone_init(); /*0x173abb*/
  kalloc_init(); /*0x173ac0*/
  vm_pager_init(); /*0x173ac5*/
  return vm_user_init(); /*0x173ad1*/
}

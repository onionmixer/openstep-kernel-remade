
void _vm_mem_init(void)

{
  _virtual_avail = _vm_page_startup(_mem_region,_num_regions,_virtual_avail);
  _zone_bootstrap();
  _vm_object_init();
  _vm_map_init();
  _kmem_init(_virtual_avail,_virtual_end);
  _pmap_init(_mem_region,_num_regions);
  _zone_init();
  _kalloc_init();
  _vm_pager_init();
  _vm_user_init();
  return;
}


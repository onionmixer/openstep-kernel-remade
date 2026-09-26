
void _od_make_free_pages(void)

{
  int iVar1;
  undefined4 uStack_8;
  
  iVar1 = _page_size * 2 * _vm_page_free_target;
  _kmem_alloc_wired(_kernel_map,&uStack_8,iVar1);
  _kmem_free(_kernel_map,uStack_8,iVar1);
  return;
}

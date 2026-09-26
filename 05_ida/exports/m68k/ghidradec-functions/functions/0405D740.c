
void _kmem_free(undefined4 param_1,uint param_2,int param_3)

{
  _vm_map_remove(param_1,~_page_mask & param_2,~_page_mask & _page_mask + param_3 + param_2);
  return;
}

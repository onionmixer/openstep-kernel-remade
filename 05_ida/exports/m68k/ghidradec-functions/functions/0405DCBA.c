
void _kmem_free_wakeup(int param_1,uint param_2,int param_3)

{
  _lock_write(param_1);
  *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
  _vm_map_delete(param_1,~_page_mask & param_2,~_page_mask & _page_mask + param_2 + param_3);
  _thread_wakeup_prim(param_1,0,0);
  _lock_done(param_1);
  return;
}

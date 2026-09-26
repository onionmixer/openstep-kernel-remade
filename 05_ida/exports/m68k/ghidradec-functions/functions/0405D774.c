
undefined4 sub_405D774(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  
  do {
    if (param_3 == 0) {
      return 1;
    }
    while (iVar1 = _vm_page_alloc_sequential(param_1,param_2,1), iVar1 == 0) {
      if (param_4 == 0) {
        return 0;
      }
      _thread_wakeup_prim(&_vm_pages_needed,0,0);
      _thread_sleep(&_vm_page_free_count,&_vm_pages_needed_lock,0);
    }
    _vm_page_zero_fill(iVar1);
    *(byte *)(iVar1 + 0x20) = *(byte *)(iVar1 + 0x20) & 0x7f;
    param_3 = param_3 - _page_size;
    param_2 = _page_size + param_2;
  } while( true );
}

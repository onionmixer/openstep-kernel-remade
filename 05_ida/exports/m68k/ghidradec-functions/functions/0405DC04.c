
undefined4 _kmem_alloc_wait(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uStack_8;
  
  uVar1 = ~_page_mask & _page_mask + param_2;
  do {
    _lock_write(param_1);
    *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
    _lock_set_recursive(param_1);
    uStack_8 = *(undefined4 *)(param_1 + 0x10);
    iVar2 = _vm_map_find(param_1,0,0,&uStack_8,uVar1,1);
    _lock_clear_recursive(param_1);
    if (iVar2 == 0) {
      _lock_done(param_1);
    }
    else {
      if ((uint)(*(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x10)) < uVar1) {
        _lock_done(param_1);
        return 0;
      }
      _assert_wait(param_1,1);
      _lock_done(param_1);
      _thread_block();
    }
  } while (iVar2 != 0);
  return uStack_8;
}

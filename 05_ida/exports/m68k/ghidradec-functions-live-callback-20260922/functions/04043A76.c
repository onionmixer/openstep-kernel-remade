
undefined4 _ipc_table_alloc(uint param_1)

{
  int iVar1;
  undefined4 uStack_8;
  
  if (param_1 < _page_size) {
    uStack_8 = _kalloc(param_1);
  }
  else {
    iVar1 = _kmem_alloc(_kalloc_map,&uStack_8,param_1);
    if (iVar1 != 0) {
      uStack_8 = 0;
    }
  }
  return uStack_8;
}


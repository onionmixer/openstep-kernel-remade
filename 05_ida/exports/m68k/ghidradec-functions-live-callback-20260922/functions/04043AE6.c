
void _ipc_table_free(uint param_1,undefined4 param_2)

{
  if (param_1 < _page_size) {
    _kfree(param_2,param_1);
  }
  else {
    _kmem_free(_kalloc_map,param_2,param_1);
  }
  return;
}


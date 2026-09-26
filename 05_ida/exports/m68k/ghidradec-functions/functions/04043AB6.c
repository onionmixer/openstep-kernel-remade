
undefined4 _ipc_table_realloc(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uStack_8;
  
  iVar1 = _kmem_realloc(_kalloc_map,param_2,param_1,&uStack_8,param_3);
  if (iVar1 != 0) {
    uStack_8 = 0;
  }
  return uStack_8;
}

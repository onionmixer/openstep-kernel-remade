
int sub_4096FD0(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puStack_8;
  
  while (iVar2 = _page_size, iVar1 = param_1[1], iVar1 == 0) {
    _page_table_alloc_size = _page_size + _page_table_alloc_size;
    param_1[4] = _page_size + param_1[4];
    _kmem_alloc_wired(_kernel_map,&puStack_8,iVar2);
    puStack_8 = (undefined4 *)_pmap_resident_extract(_kernel_pmap,puStack_8);
    for (; iVar2 != 0; iVar2 = iVar2 - param_1[2]) {
      *puStack_8 = 0x2a6a6b73;
      puStack_8[1] = *param_1;
      puStack_8[2] = 0;
      if (*param_1 == 0) {
        param_1[1] = (int)puStack_8;
      }
      else {
        *(undefined4 **)(*param_1 + 8) = puStack_8;
      }
      *param_1 = (int)puStack_8;
      puStack_8 = (undefined4 *)(param_1[2] + *param_1);
      param_1[5] = param_1[5] + 1;
    }
  }
  param_1[1] = *(int *)(iVar1 + 8);
  if (param_1[1] == 0) {
    *param_1 = 0;
  }
  else {
    *(undefined4 *)(param_1[1] + 4) = 0;
  }
  param_1[5] = param_1[5] + -1;
  _page_table_memory_size = param_1[2] + _page_table_memory_size;
  param_1[3] = param_1[2] + param_1[3];
  _bzero(iVar1,param_1[2]);
  return iVar1;
}


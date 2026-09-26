
int _kmem_alloc_pageable(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  undefined4 uStack_8;
  
  uStack_8 = *(undefined4 *)(param_1 + 0x10);
  iVar1 = _vm_map_find(param_1,0,0,&uStack_8,~_page_mask & _page_mask + param_3,1);
  if (iVar1 == 0) {
    *param_2 = uStack_8;
    iVar1 = 0;
  }
  return iVar1;
}

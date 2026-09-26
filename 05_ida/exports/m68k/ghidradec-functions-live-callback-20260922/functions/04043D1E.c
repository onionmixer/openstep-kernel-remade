
undefined4 _host_ipc_marequest_info(int param_1,undefined4 param_2,int *param_3,uint *param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iStack_c;
  int iStack_8;
  
  uVar4 = 0;
  if (param_1 == 0) {
    return 0x16;
  }
  uVar3 = *param_4;
  iVar2 = *param_3;
  while( true ) {
    uVar1 = _ipc_marequest_info(param_2,iVar2,uVar3);
    if (uVar1 <= uVar3) {
      if (iVar2 != *param_3) {
        if (uVar1 == 0) {
          _kmem_free(_ipc_kernel_map,iStack_8,uVar4);
          *param_4 = 0;
          return 0;
        }
        uVar3 = ~_page_mask & _page_mask + uVar1 * 4;
        if (uVar4 != uVar3) {
          _kmem_free(_ipc_kernel_map,uVar3 + iStack_8,uVar4 - uVar3);
        }
        _vm_move(_ipc_kernel_map,iStack_8,_ipc_soft_map,uVar3,1,&iStack_c);
        *param_3 = iStack_c;
      }
      *param_4 = uVar1;
      return 0;
    }
    if (iVar2 != *param_3) {
      _kmem_free(_ipc_kernel_map,iStack_8,uVar4);
    }
    uVar4 = ~_page_mask & _page_mask + uVar1 * 4;
    iVar2 = _kmem_alloc_pageable(_ipc_kernel_map,&iStack_8,uVar4);
    if (iVar2 != 0) break;
    uVar3 = uVar4 >> 2;
    iVar2 = iStack_8;
  }
  return 6;
}


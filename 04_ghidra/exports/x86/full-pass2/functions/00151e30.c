/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00151e30 */

undefined4 _host_ipc_marequest_info(int param_1,undefined4 param_2,int *param_3,uint *param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int local_c;
  int local_8;
  
  uVar4 = 0;
  if (param_1 == 0) {
    return 0x16;
  }
  uVar3 = *param_4;
  iVar2 = *param_3;
  while( true ) {
    uVar1 = _ipc_marequest_info(param_2,iVar2,uVar3);
    if (uVar1 <= uVar3) {
      if (*param_3 != iVar2) {
        if (uVar1 == 0) {
          _kmem_free(_ipc_kernel_map,local_8,uVar4);
          *param_4 = 0;
          return 0;
        }
        uVar3 = _page_mask + uVar1 * 4 & ~_page_mask;
        if (uVar3 != uVar4) {
          _kmem_free(_ipc_kernel_map,local_8 + uVar3,uVar4 - uVar3);
        }
        _vm_move(_ipc_kernel_map,local_8,_ipc_soft_map,uVar3,1,&local_c);
        *param_3 = local_c;
      }
      *param_4 = uVar1;
      return 0;
    }
    if (*param_3 != iVar2) {
      _kmem_free(_ipc_kernel_map,local_8,uVar4);
    }
    uVar4 = _page_mask + uVar1 * 4 & ~_page_mask;
    iVar2 = _kmem_alloc_pageable(_ipc_kernel_map,&local_8,uVar4);
    if (iVar2 != 0) break;
    uVar3 = uVar4 >> 2;
    iVar2 = local_8;
  }
  return 6;
}


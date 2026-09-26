/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00173e48 */

int _kmem_alloc_pageable(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  undefined4 local_8;
  
  local_8 = *(undefined4 *)(param_1 + 0x14);
  iVar1 = _vm_map_find(param_1,0,0,&local_8,param_3 + _page_mask & ~_page_mask,1);
  if (iVar1 == 0) {
    *param_2 = local_8;
    iVar1 = 0;
  }
  return iVar1;
}


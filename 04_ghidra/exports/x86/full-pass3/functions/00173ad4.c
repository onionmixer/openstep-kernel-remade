/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00173ad4 */

undefined1 _kmem_alloc(int param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined1 uVar5;
  int local_c;
  int local_8;
  
  iVar1 = _vm_object_allocate(param_3);
  local_c = 0;
  local_8 = *(int *)(param_1 + 0x14);
  uVar4 = param_3 + _page_mask & ~_page_mask;
  iVar3 = 0;
  if (_kernel_object != iVar1) {
    iVar3 = iVar1;
  }
  iVar2 = _vm_map_find(param_1,iVar3,0,&local_8,uVar4,1);
  iVar3 = local_8;
  uVar5 = iVar2 != 0;
  if ((bool)uVar5) {
    if (_kernel_object != iVar1) {
      _vm_object_deallocate(iVar1);
    }
  }
  else {
    if (_kernel_object == iVar1) {
      local_c = local_8;
      _vm_object_reference(iVar1);
      _lock_write(param_1);
      *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
      _vm_map_delete(param_1,local_8,uVar4 + local_8);
      _vm_map_insert(param_1,iVar1,iVar3,local_8,uVar4 + local_8);
      _lock_done(param_1);
    }
    iVar3 = FUN_00173ebc(iVar1,local_c,uVar4,1);
    if (iVar3 == 0) {
      _lock_write(param_1);
      *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
      _vm_map_delete(param_1,local_8,uVar4 + local_8);
      _lock_done(param_1);
      uVar5 = 6;
    }
    else {
      _vm_map_pageable(param_1,local_8,uVar4 + local_8,0);
      *param_2 = local_8;
      uVar5 = 0;
    }
  }
  return uVar5;
}


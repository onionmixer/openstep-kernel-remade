
int sub_405D448(int param_1,int *param_2,int param_3,int param_4,int param_5,undefined4 param_6)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iStack_8;
  
  iVar3 = 0;
  if (param_4 == 0) {
    iStack_8 = *param_2;
  }
  else {
    iStack_8 = *(int *)(param_1 + 0x10);
  }
  uVar1 = ~_page_mask & _page_mask + param_3;
  iVar2 = 0;
  if (param_5 != _kernel_object) {
    iVar2 = param_5;
  }
  iVar2 = _vm_map_find(param_1,iVar2,0,&iStack_8,uVar1,param_4);
  iVar2 = -(int)-(iVar2 != 0);
  if (iVar2 == 0) {
    if (param_5 == _kernel_object) {
      iVar3 = iStack_8 + -0x10000000;
      _vm_object_reference(param_5);
      _lock_write(param_1);
      *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
      _vm_map_delete(param_1,iStack_8,uVar1 + iStack_8);
      _vm_map_insert(param_1,param_5,iVar3,iStack_8,uVar1 + iStack_8);
      _lock_done(param_1);
    }
    iVar3 = sub_405D774(param_5,iVar3,uVar1,param_6);
    if (iVar3 == 0) {
      _lock_write(param_1);
      *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
      _vm_map_delete(param_1,iStack_8,uVar1 + iStack_8);
      _lock_done(param_1);
      iVar2 = 6;
    }
    else {
      _vm_map_pageable(param_1,iStack_8,uVar1 + iStack_8,0);
      *param_2 = iStack_8;
      iVar2 = 0;
    }
  }
  else if (param_5 != _kernel_object) {
    _vm_object_deallocate(param_5);
  }
  return iVar2;
}


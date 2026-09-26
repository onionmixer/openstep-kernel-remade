
undefined4 _vm_map_pageable(int param_1,uint param_2,uint param_3,int param_4)

{
  int iVar1;
  sword sVar2;
  int iVar3;
  undefined4 uVar4;
  bool bVar5;
  int iStack_8;
  
  bVar5 = true;
  _lock_write(param_1);
  *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
  if (param_2 < *(uint *)(param_1 + 0x10)) {
    param_2 = *(uint *)(param_1 + 0x10);
  }
  if (*(uint *)(param_1 + 0x14) < param_3) {
    param_3 = *(uint *)(param_1 + 0x14);
  }
  if (param_3 < param_2) {
    param_2 = param_3;
  }
  iVar3 = _vm_map_lookup_entry(param_1,param_2,&iStack_8);
  if (iVar3 == 0) {
    iVar3 = *(int *)(iStack_8 + 4);
  }
  else {
    iVar3 = iStack_8;
    if (*(uint *)(iStack_8 + 8) < param_2) {
      __vm_map_clip_start(param_1 + 8,iStack_8,param_2);
    }
  }
  iStack_8 = iVar3;
  if (param_4 == 0) {
    for (; (param_1 + 8 != iVar3 && (*(uint *)(iVar3 + 8) < param_3)); iVar3 = *(int *)(iVar3 + 4))
    {
      if (param_3 < *(uint *)(iVar3 + 0xc)) {
        __vm_map_clip_end(param_1 + 8,iVar3,param_3);
      }
      sVar2 = *(sword *)(iVar3 + 0x26);
      *(sword *)(iVar3 + 0x26) = sVar2 + 1;
      if ((sVar2 == 0) && (-1 < (char)*(byte *)(iVar3 + 0x18))) {
        if (((*(byte *)(iVar3 + 0x18) & 2) == 0) || ((*(byte *)(iVar3 + 0x1d) & 2) == 0)) {
          if (*(int *)(iVar3 + 0x10) == 0) {
            uVar4 = _vm_object_allocate(*(int *)(iVar3 + 0xc) - *(int *)(iVar3 + 8));
            *(undefined4 *)(iVar3 + 0x10) = uVar4;
            *(undefined4 *)(iVar3 + 0x14) = 0;
          }
        }
        else {
          _vm_object_shadow(iVar3 + 0x10,iVar3 + 0x14,*(int *)(iVar3 + 0xc) - *(int *)(iVar3 + 8));
          *(byte *)(iVar3 + 0x18) = *(byte *)(iVar3 + 0x18) & 0xfd;
        }
      }
    }
    bVar5 = param_1 != _kernel_map;
    if (bVar5) {
      _lock_set_recursive(param_1);
      _lock_write_to_read(param_1);
    }
    else {
      _lock_done(param_1);
    }
    for (iVar3 = iStack_8; (param_1 + 8 != iVar3 && (*(uint *)(iVar3 + 8) < param_3));
        iVar3 = *(int *)(iVar3 + 4)) {
      if (*(sword *)(iVar3 + 0x26) == 1) {
        _vm_fault_wire(param_1,iVar3);
      }
    }
    if (!bVar5) {
      return 0;
    }
    _lock_clear_recursive(param_1);
  }
  else {
    for (iVar1 = iVar3; (param_1 + 8 != iVar1 && (*(uint *)(iVar1 + 8) < param_3));
        iVar1 = *(int *)(iVar1 + 4)) {
      if (*(sword *)(iVar1 + 0x26) == 0) {
        _lock_done(param_1);
        return 4;
      }
    }
    for (; (param_1 + 8 != iVar3 && (*(uint *)(iVar3 + 8) < param_3)); iVar3 = *(int *)(iVar3 + 4))
    {
      if (param_3 < *(uint *)(iVar3 + 0xc)) {
        __vm_map_clip_end(param_1 + 8,iVar3,param_3);
      }
      sVar2 = *(sword *)(iVar3 + 0x26);
      *(sword *)(iVar3 + 0x26) = sVar2 + -1;
      if (sVar2 == 1) {
        _vm_fault_unwire(param_1,iVar3);
      }
    }
  }
  if (bVar5) {
    _lock_done(param_1);
  }
  return 0;
}


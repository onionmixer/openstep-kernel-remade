
undefined4 _vm_map_remove(int param_1,uint param_2,uint param_3)

{
  undefined4 uVar1;
  
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
  uVar1 = _vm_map_delete(param_1,param_2,param_3);
  _lock_done(param_1);
  return uVar1;
}



undefined4
_vm_map_machine_attribute
          (int param_1,uint param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 uVar1;
  
  if ((param_2 < *(uint *)(param_1 + 0x10)) || (*(uint *)(param_1 + 0x14) < param_3 + param_2)) {
    uVar1 = 4;
  }
  else {
    _lock_write(param_1);
    *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
    uVar1 = _pmap_attribute(*(undefined4 *)(param_1 + 0x20),param_2,param_3,param_4,param_5);
    _lock_done(param_1);
  }
  return uVar1;
}


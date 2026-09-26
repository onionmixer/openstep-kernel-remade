
undefined4 _mach_port_allocate_name(int param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  undefined auStack_c [4];
  undefined auStack_8 [4];
  
  if (param_1 == 0) {
    uVar1 = 0x10;
  }
  else {
    if ((param_3 != 0) && (param_3 != -1)) {
      if (param_2 == 3) {
        uVar1 = _ipc_pset_alloc_name(param_1,param_3,auStack_c);
        return uVar1;
      }
      if (param_2 < 4) {
        if (param_2 == 1) {
          uVar1 = _ipc_port_alloc_name(param_1,param_3,auStack_8);
          return uVar1;
        }
      }
      else if (param_2 == 4) {
        uVar1 = _ipc_object_alloc_dead_name(param_1,param_3);
        return uVar1;
      }
    }
    uVar1 = 0x12;
  }
  return uVar1;
}

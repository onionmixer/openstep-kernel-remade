
undefined4 _mach_port_insert_right(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0x10;
  }
  else if (((param_2 == 0) || (param_2 == -1)) || (2 < param_4 - 0x10U)) {
    uVar1 = 0x12;
  }
  else if ((param_3 == 0) || (param_3 == -1)) {
    uVar1 = 0x14;
  }
  else {
    uVar1 = _ipc_object_copyout_name(param_1,param_3,param_4,0,param_2);
  }
  return uVar1;
}


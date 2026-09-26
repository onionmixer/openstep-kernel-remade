
undefined4 _mach_port_rename(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0x10;
  }
  else if ((param_3 == 0) || (param_3 == -1)) {
    uVar1 = 0x12;
  }
  else {
    uVar1 = _ipc_object_rename(param_1,param_2,param_3);
  }
  return uVar1;
}


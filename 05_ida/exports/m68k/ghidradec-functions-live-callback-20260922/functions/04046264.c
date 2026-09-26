
int _mach_port_type(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined auStack_c [4];
  undefined4 uStack_8;
  
  if (param_1 == 0) {
    iVar1 = 0x10;
  }
  else {
    iVar1 = _ipc_right_lookup_write(param_1,param_2,&uStack_8);
    if (iVar1 == 0) {
      iVar1 = _ipc_right_info(param_1,param_2,uStack_8,param_3,auStack_c);
    }
  }
  return iVar1;
}


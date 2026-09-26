
int _mach_port_destroy(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uStack_8;
  
  if (param_1 == 0) {
    iVar1 = 0x10;
  }
  else {
    iVar1 = _ipc_right_lookup_write(param_1,param_2,&uStack_8);
    if (iVar1 == 0) {
      iVar1 = _ipc_right_destroy(param_1,param_2,uStack_8);
    }
  }
  return iVar1;
}


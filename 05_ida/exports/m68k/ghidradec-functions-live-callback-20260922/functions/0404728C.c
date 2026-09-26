
int _port_set_status(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = _mach_port_get_set_status(param_1,param_2,param_3,param_4);
  if ((iVar1 != 0) && (iVar1 != 6)) {
    iVar1 = 4;
  }
  return iVar1;
}


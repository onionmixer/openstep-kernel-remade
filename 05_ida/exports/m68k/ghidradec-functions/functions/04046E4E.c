
int _port_rename(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = _mach_port_rename(param_1,param_2,param_3);
  if ((iVar1 != 0) && (iVar1 != 0xd)) {
    iVar1 = 4;
  }
  return iVar1;
}

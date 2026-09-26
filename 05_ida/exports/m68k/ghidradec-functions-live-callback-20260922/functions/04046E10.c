
undefined4 _port_type(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_8;
  
  iVar1 = _mach_port_type(param_1,param_2,&uStack_8);
  if (iVar1 == 0) {
    uVar2 = _convert_port_type(uStack_8);
    *param_3 = uVar2;
    uVar2 = 0;
  }
  else {
    uVar2 = 4;
  }
  return uVar2;
}


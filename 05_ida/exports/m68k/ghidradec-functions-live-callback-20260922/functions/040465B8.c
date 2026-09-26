
int _mach_port_set_qlimit(int param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  undefined4 uStack_8;
  
  if (param_1 == 0) {
    iVar1 = 0x10;
  }
  else if (param_3 < 0x11) {
    iVar1 = _ipc_object_translate(param_1,param_2,1,&uStack_8);
    if (iVar1 == 0) {
      _ipc_port_set_qlimit(uStack_8,param_3);
      iVar1 = 0;
    }
  }
  else {
    iVar1 = 0x12;
  }
  return iVar1;
}


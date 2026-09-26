
int _mach_port_mod_refs(int param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uStack_8;
  
  if (param_1 == 0) {
    iVar1 = 0x10;
  }
  else if (param_3 < 5) {
    iVar1 = _ipc_right_lookup_write(param_1,param_2,&uStack_8);
    if (iVar1 == 0) {
      iVar1 = _ipc_right_delta(param_1,param_2,uStack_8,param_3,param_4);
    }
  }
  else {
    iVar1 = 0x12;
  }
  return iVar1;
}


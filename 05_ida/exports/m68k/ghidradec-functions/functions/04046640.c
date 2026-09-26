
int _mach_port_set_seqno(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uStack_8;
  
  if (param_1 == 0) {
    iVar1 = 0x10;
  }
  else {
    iVar1 = _ipc_object_translate(param_1,param_2,1,&uStack_8);
    if (iVar1 == 0) {
      _ipc_port_set_seqno(uStack_8,param_3);
      iVar1 = 0;
    }
  }
  return iVar1;
}

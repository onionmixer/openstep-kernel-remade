
int _port_set_backlog(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uStack_8;
  
  if ((param_1 == 0) || (0xf < param_3 - 1U)) {
    iVar1 = 4;
  }
  else {
    iVar1 = _port_translate_compat(param_1,param_2,&uStack_8);
    if (iVar1 == 0) {
      _ipc_port_set_qlimit(uStack_8,param_3);
      iVar1 = 0;
    }
  }
  return iVar1;
}


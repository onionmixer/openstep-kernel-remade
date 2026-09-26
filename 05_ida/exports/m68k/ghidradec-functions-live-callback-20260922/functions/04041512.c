
int _ipc_port_copyout_send_compat(int param_1,undefined4 param_2)

{
  int iVar1;
  int iStack_8;
  
  if ((param_1 == 0) || (param_1 == -1)) {
    iStack_8 = param_1;
  }
  else {
    iVar1 = _ipc_object_copyout_compat(param_2,param_1,0x11,&iStack_8);
    if (iVar1 != 0) {
      _ipc_port_release_send(param_1);
      iStack_8 = 0;
    }
  }
  return iStack_8;
}


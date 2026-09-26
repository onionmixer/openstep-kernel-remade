
int __lookupd_port(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iStack_c;
  int iStack_8;
  
  iVar2 = *(int *)(_active_threads + 0xc);
  if (param_1 == 0) {
    iStack_8 = _lookupd_port;
    if (_lookupd_port == 0) {
      iStack_c = 0;
      param_1 = iStack_c;
    }
    else {
      uVar3 = _ipc_port_copy_send(_lookupd_port,0x11,1,&iStack_c);
      _ipc_object_copyout(*(undefined4 *)(iVar2 + 0x7c),uVar3);
      param_1 = iStack_c;
    }
  }
  else {
    iVar1 = _suser();
    if ((iVar1 == 0) ||
       (iVar2 = _ipc_object_copyin(*(undefined4 *)(iVar2 + 0x7c),param_1,0x14,&iStack_8), iVar2 != 0
       )) {
      param_1 = 0;
    }
    else {
      if (_lookupd_port != 0) {
        _ipc_port_release_send(_lookupd_port);
      }
      _lookupd_port = iStack_8;
    }
  }
  return param_1;
}


void _ipc_port_release_send(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = 0;
  iVar1 = *param_1;
  *param_1 = iVar1 + -1;
  if (param_1[1] < 0) {
    iVar1 = param_1[6];
    param_1[6] = iVar1 + -1;
    if (iVar1 == 1) {
      iVar2 = param_1[8];
      if (iVar2 == 0) {
        return;
      }
      param_1[8] = 0;
      iVar3 = param_1[5];
    }
    if (iVar2 != 0) {
      _ipc_notify_no_senders(iVar2,iVar3);
    }
  }
  else if (iVar1 == 1) {
    _zfree((&_ipc_object_zones)[(param_1[1] & 0x7fffffffU) >> 0x10],param_1);
  }
  return;
}


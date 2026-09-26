
void _ipc_object_copyout_dest(int param_1,int *param_2,int param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar1 = *param_2;
  *param_2 = iVar1 + -1;
  if (param_3 == 0x11) {
    iVar2 = 0;
    iVar3 = 0;
    iVar1 = param_2[6];
    param_2[6] = iVar1 + -1;
    if ((iVar1 == 1) && (iVar2 = param_2[8], iVar2 != 0)) {
      param_2[8] = 0;
      iVar3 = param_2[5];
    }
    iVar4 = 0;
    if (param_1 == param_2[2]) {
      iVar4 = param_2[3];
    }
    if (iVar2 != 0) {
      _ipc_notify_no_senders(iVar2,iVar3);
    }
  }
  else {
    if (param_3 != 0x12) {
                    /* WARNING: Subroutine does not return */
      _panic(aIpcObjectCopyo);
    }
    if (param_1 == param_2[2]) {
      param_2[7] = param_2[7] + -1;
      iVar4 = param_2[3];
    }
    else {
      *param_2 = iVar1;
      _ipc_notify_send_once(param_2);
    }
  }
  *param_4 = iVar4;
  return;
}

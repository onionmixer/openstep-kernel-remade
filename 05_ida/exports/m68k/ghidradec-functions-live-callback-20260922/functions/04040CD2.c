
void _ipc_port_nsrequest(int param_1,uint param_2,int param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0x20);
  if (((*(int *)(param_1 + 0x18) == 0) && (param_2 <= *(uint *)(param_1 + 0x14))) && (param_3 != 0))
  {
    *(undefined4 *)(param_1 + 0x20) = 0;
    _ipc_notify_no_senders(param_3,*(uint *)(param_1 + 0x14));
  }
  else {
    *(int *)(param_1 + 0x20) = param_3;
  }
  *param_4 = uVar1;
  return;
}


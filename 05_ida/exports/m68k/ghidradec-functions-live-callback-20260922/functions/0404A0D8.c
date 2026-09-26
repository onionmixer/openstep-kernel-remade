
void _send_notification(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uStack_8;
  
  if (param_2 == 0x42) {
    iVar1 = _task_get_special_port(param_1,2,&uStack_8);
    if (iVar1 == 0) {
      _ipc_notify_msg_accepted_compat(uStack_8,param_3);
    }
  }
  return;
}


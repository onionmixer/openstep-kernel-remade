
undefined4 _mach_msg_send_from_kernel(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uStack_8;
  
  if ((*(int *)(param_1 + 8) == 0) || (*(int *)(param_1 + 8) == -1)) {
    uVar1 = 0x10000003;
  }
  else {
    iVar2 = _ipc_kmsg_get_from_kernel(param_1,param_2,0,&uStack_8);
    if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
      _panic(aMachMsgSendFro);
    }
    _ipc_kmsg_copyin_from_kernel(uStack_8);
    _ipc_mqueue_send(uStack_8,0x10000,0,0);
    uVar1 = 0;
  }
  return uVar1;
}


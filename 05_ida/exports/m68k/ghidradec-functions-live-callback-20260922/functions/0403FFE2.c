
void _ipc_notify_msg_accepted_compat(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = _kalloc(0x34);
  if (iVar1 == 0) {
    _printf(aDroppedMsgAcce_0,param_1,param_2);
    _ipc_port_release_send(param_1);
  }
  else {
    *(undefined4 *)(iVar1 + 8) = 0x34;
    *(undefined4 *)(iVar1 + 0xc) = 0;
    *(undefined4 *)(iVar1 + 0x10) = 0;
    *(undefined4 *)(iVar1 + 0x14) = _ipc_notify_msg_accepted_template;
    *(undefined4 *)(iVar1 + 0x18) = dword_40C2228;
    *(undefined4 *)(iVar1 + 0x1c) = dword_40C222C;
    *(undefined4 *)(iVar1 + 0x20) = dword_40C2230;
    *(undefined4 *)(iVar1 + 0x24) = dword_40C2234;
    *(undefined4 *)(iVar1 + 0x28) = dword_40C2238;
    *(undefined4 *)(iVar1 + 0x2c) = dword_40C223C;
    *(undefined4 *)(iVar1 + 0x30) = dword_40C2240;
    *(undefined4 *)(iVar1 + 0x14) = 0x11;
    *(undefined4 *)(iVar1 + 0x1c) = param_1;
    *(undefined4 *)(iVar1 + 0x30) = param_2;
    _ipc_mqueue_send(iVar1,0x10000,0,0);
  }
  return;
}


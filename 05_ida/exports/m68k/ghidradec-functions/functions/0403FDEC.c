
void _ipc_notify_send_once(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = _kalloc(0x2c);
  if (iVar1 == 0) {
    _printf(aDroppedSendOnc,param_1);
    _ipc_port_release_sonce(param_1);
  }
  else {
    *(undefined4 *)(iVar1 + 8) = 0x2c;
    *(undefined4 *)(iVar1 + 0xc) = 0;
    *(undefined4 *)(iVar1 + 0x10) = 0;
    *(undefined4 *)(iVar1 + 0x14) = _ipc_notify_send_once_template;
    *(undefined4 *)(iVar1 + 0x18) = dword_40C22A8;
    *(undefined4 *)(iVar1 + 0x1c) = dword_40C22AC;
    *(undefined4 *)(iVar1 + 0x20) = dword_40C22B0;
    *(undefined4 *)(iVar1 + 0x24) = dword_40C22B4;
    *(undefined4 *)(iVar1 + 0x28) = dword_40C22B8;
    *(undefined4 *)(iVar1 + 0x1c) = param_1;
    _ipc_mqueue_send(iVar1,0x10000,0,0);
  }
  return;
}

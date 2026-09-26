
void _mach_msg_abort_rpc(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (*(int *)(param_1 + 0xa4) != 0) {
    iVar1 = *(int *)(param_1 + 0xb8);
    *(undefined4 *)(param_1 + 0xb8) = 0;
  }
  if (iVar1 != 0) {
    _ipc_port_dealloc_special(iVar1,_ipc_space_reply);
  }
  return;
}


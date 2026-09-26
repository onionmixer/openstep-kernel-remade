
void _ipc_port_set_seqno(int param_1,undefined4 param_2)

{
  _ipc_port_lock_mqueue(param_1);
  *(undefined4 *)(param_1 + 0x30) = param_2;
  return;
}


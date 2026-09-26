
void _ipc_port_dealloc_special(int param_1)

{
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  _ipc_port_clear_receiver(param_1);
  _ipc_port_destroy(param_1);
  return;
}


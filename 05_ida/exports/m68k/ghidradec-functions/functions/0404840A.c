
void _ipc_pset_terminate(int param_1)

{
  _ipc_port_dealloc_special(*(undefined4 *)(param_1 + 0x14c),_ipc_space_kernel);
  _ipc_port_dealloc_special(*(undefined4 *)(param_1 + 0x150),_ipc_space_kernel);
  return;
}

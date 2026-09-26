
void _port_reference(int param_1)

{
  if (param_1 != 0) {
    _ipc_port_copy_send(param_1);
  }
  return;
}

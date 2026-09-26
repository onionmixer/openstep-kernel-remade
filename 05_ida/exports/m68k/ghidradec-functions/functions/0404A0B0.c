
void _port_release(int param_1)

{
  if (param_1 != 0) {
    _ipc_port_release_send(param_1);
  }
  return;
}

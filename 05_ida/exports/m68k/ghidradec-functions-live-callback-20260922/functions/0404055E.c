
void _ipc_object_destroy(undefined4 param_1,uint param_2)

{
  if (param_2 == 0x11) {
    _ipc_port_release_send(param_1);
  }
  else if (param_2 < 0x12) {
    if (param_2 == 0x10) {
      _ipc_port_release_receive(param_1);
    }
  }
  else if (param_2 == 0x12) {
    _ipc_notify_send_once(param_1);
  }
  return;
}


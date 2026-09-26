/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014bd68 */

void _ipc_object_destroy(undefined4 param_1,uint param_2)

{
  if (param_2 == 0x11) {
    _ipc_port_release_send(param_1);
    return;
  }
  if (param_2 < 0x12) {
    if (param_2 != 0x10) {
      return;
    }
    _ipc_port_release_receive(param_1);
    return;
  }
  if (param_2 != 0x12) {
    return;
  }
  _ipc_notify_send_once(param_1);
  return;
}


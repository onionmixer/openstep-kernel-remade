
void _host_self(void)

{
  undefined4 uVar1;
  
  uVar1 = _ipc_port_make_send(_realhost);
  _ipc_port_copyout_send_compat(uVar1,*(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x7c));
  return;
}

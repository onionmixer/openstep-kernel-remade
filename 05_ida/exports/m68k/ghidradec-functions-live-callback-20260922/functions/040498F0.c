
void _mach_thread_self(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(_active_threads + 0xc);
  uVar2 = _retrieve_thread_self_fast(_active_threads);
  _ipc_port_copyout_send(uVar2,*(undefined4 *)(iVar1 + 0x7c));
  return;
}


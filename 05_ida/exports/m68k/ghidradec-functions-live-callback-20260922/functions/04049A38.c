
void _thread_reply(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(_active_threads + 0xc);
  uVar2 = _retrieve_thread_reply(_active_threads);
  _ipc_port_copyout_receiver(uVar2,*(undefined4 *)(iVar1 + 0x7c));
  return;
}


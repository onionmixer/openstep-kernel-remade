
void _task_notify(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(_active_threads + 0xc);
  uVar2 = _retrieve_task_notify(iVar1);
  _ipc_port_copyout_receiver(uVar2,*(undefined4 *)(iVar1 + 0x7c));
  return;
}

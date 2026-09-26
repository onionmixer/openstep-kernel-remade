
void _task_self(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(_active_threads + 0xc);
  uVar2 = _retrieve_task_self_fast(iVar1);
  _ipc_port_copyout_send_compat(uVar2,*(undefined4 *)(iVar1 + 0x7c));
  return;
}


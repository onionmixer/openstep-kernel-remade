
void _thread_force_terminate(int param_1)

{
  int iVar1;
  
  _ipc_thread_disable(param_1);
  iVar1 = *(int *)(param_1 + 0x170);
  *(undefined4 *)(param_1 + 0x170) = 0;
  _thread_halt(param_1,1);
  _ipc_thread_terminate(param_1);
  if (iVar1 != 0) {
    _thread_deallocate(param_1);
  }
  return;
}


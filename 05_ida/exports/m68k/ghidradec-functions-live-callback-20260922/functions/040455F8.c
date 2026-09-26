
bool _mach_msg_interrupt(int param_1)

{
  bool bVar1;
  
  bVar1 = *(int *)(param_1 + 0x94) == 0x10004001;
  if (bVar1) {
    _ipc_thread_rmqueue(*(int *)(param_1 + 0xd4) + 4,param_1);
    _ipc_object_release(*(undefined4 *)(param_1 + 0xd0));
    _thread_set_syscall_return(param_1,0x10004005);
    *(code **)(param_1 + 0x30) = _thread_exception_return;
  }
  return bVar1;
}


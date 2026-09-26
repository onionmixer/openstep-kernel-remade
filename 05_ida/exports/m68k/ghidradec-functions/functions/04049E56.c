
undefined4 _convert_thread_to_port(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0xa4) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = _ipc_port_make_send(*(int *)(param_1 + 0xa4));
  }
  _thread_deallocate(param_1);
  return uVar1;
}

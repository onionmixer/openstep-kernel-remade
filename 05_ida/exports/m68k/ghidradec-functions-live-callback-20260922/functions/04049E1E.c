
undefined4 _convert_task_to_port(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x5c) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = _ipc_port_make_send(*(int *)(param_1 + 0x5c));
  }
  _task_deallocate(param_1);
  return uVar1;
}


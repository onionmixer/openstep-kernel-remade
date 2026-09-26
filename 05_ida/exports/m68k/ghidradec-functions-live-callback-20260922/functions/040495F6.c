
void _ipc_task_enable(int param_1)

{
  if (*(int *)(param_1 + 0x5c) != 0) {
    _ipc_kobject_set(*(int *)(param_1 + 0x5c),param_1,2);
  }
  return;
}


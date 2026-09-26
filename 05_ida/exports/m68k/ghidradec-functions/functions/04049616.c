
void _ipc_task_disable(int param_1)

{
  if (*(int *)(param_1 + 0x5c) != 0) {
    _ipc_kobject_set(*(int *)(param_1 + 0x5c),0,0);
  }
  return;
}

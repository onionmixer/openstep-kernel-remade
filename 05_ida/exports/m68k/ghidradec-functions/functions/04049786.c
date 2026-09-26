
void _ipc_thread_disable(int param_1)

{
  if (*(int *)(param_1 + 0xa4) != 0) {
    _ipc_kobject_set(*(int *)(param_1 + 0xa4),0,0);
  }
  return;
}

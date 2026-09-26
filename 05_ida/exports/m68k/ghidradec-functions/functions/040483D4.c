
void _ipc_pset_disable(int param_1)

{
  _ipc_kobject_set(*(undefined4 *)(param_1 + 0x14c),0,0);
  _ipc_kobject_set(*(undefined4 *)(param_1 + 0x150),0,0);
  *(int *)(param_1 + 0x13c) = *(int *)(param_1 + 0x13c) + -2;
  return;
}

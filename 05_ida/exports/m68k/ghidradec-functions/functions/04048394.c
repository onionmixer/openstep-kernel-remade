
void _ipc_pset_enable(int param_1)

{
  if (*(int *)(param_1 + 0x148) != 0) {
    _ipc_kobject_set(*(undefined4 *)(param_1 + 0x14c),param_1,6);
    _ipc_kobject_set(*(undefined4 *)(param_1 + 0x150),param_1,7);
    *(int *)(param_1 + 0x13c) = *(int *)(param_1 + 0x13c) + 2;
  }
  return;
}


void _ipc_pset_add(int *param_1,int param_2)

{
  *(int **)(param_2 + 0x2c) = param_1;
  *param_1 = *param_1 + 1;
  _ipc_mqueue_move(param_1 + 3,param_2 + 0x3c,param_2);
  _ipc_mqueue_changed(param_2 + 0x3c,0x10004006);
  return;
}

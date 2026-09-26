
void _ipc_pset_remove(int *param_1,int param_2)

{
  *(undefined4 *)(param_2 + 0x2c) = 0;
  *param_1 = *param_1 + -1;
  _ipc_mqueue_move(param_2 + 0x3c,param_1 + 3,param_2);
  return;
}


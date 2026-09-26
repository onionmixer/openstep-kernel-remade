
void _ipc_splay_traverse_finish(undefined4 *param_1)

{
  if (param_1[1] != 0) {
    *param_1 = *(undefined4 *)(param_1[1] + 0x10);
    param_1[3] = param_1 + 2;
    param_1[5] = param_1 + 4;
  }
  return;
}

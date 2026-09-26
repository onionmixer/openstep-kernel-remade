
int * _ipc_port_make_sonce(int *param_1)

{
  param_1[7] = param_1[7] + 1;
  *param_1 = *param_1 + 1;
  return param_1;
}


int * _ipc_port_make_send(int *param_1)

{
  param_1[5] = param_1[5] + 1;
  param_1[6] = param_1[6] + 1;
  *param_1 = *param_1 + 1;
  return param_1;
}



int * _ipc_port_copy_send(int *param_1)

{
  if ((param_1 != (int *)0x0) && (param_1 != (int *)0xffffffff)) {
    if (param_1[1] < 0) {
      *param_1 = *param_1 + 1;
      param_1[6] = param_1[6] + 1;
    }
    else {
      param_1 = (int *)0xffffffff;
    }
  }
  return param_1;
}

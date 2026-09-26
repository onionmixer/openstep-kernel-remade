
void _xdrmbuf_init(undefined4 *param_1,int param_2,undefined4 param_3)

{
  *param_1 = param_3;
  param_1[1] = _xdrmbuf_ops;
  param_1[4] = param_2;
  param_1[3] = *(int *)(param_2 + 4) + param_2;
  param_1[2] = 0;
  param_1[5] = (int)*(sword *)(param_2 + 8);
  return;
}


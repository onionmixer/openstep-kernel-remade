
void _fc_flpctl_bset(int *param_1,byte param_2)

{
  param_2 = param_2 | *(byte *)((int)param_1 + 0x25);
  *(byte *)((int)param_1 + 0x25) = param_2;
  *(byte *)(*param_1 + 8) = param_2;
  return;
}


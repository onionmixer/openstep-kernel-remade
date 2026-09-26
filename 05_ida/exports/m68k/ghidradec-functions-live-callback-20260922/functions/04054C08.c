
void _timer_read(uint *param_1,int *param_2)

{
  uint uVar1;
  
  do {
    uVar1 = *param_1;
  } while (param_1[1] != param_1[2]);
  *param_2 = uVar1 / 1000000 + param_1[1];
  param_2[1] = uVar1 % 1000000;
  return;
}


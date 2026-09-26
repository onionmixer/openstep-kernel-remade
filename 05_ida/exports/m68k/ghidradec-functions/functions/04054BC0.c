
void _timer_normalize(uint *param_1)

{
  uint uVar1;
  
  uVar1 = *param_1;
  param_1[2] = uVar1 / 1000000 + param_1[2];
  *param_1 = *param_1 % 1000000;
  param_1[1] = uVar1 / 1000000 + param_1[1];
  return;
}

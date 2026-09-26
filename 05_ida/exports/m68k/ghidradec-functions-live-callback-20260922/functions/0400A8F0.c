
void _timevaladd(int *param_1,int *param_2)

{
  *param_1 = *param_2 + *param_1;
  param_1[1] = param_2[1] + param_1[1];
  _timevalfix(param_1);
  return;
}


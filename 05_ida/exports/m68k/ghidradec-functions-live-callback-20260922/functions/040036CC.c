
void _ticks_to_timeval(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = param_1 % _hz;
  *param_2 = param_1 / _hz;
  param_2[1] = _tick * iVar1;
  return;
}


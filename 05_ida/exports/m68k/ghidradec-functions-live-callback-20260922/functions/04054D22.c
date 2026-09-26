
int _timer_delta(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  do {
    iVar3 = param_1[1];
    iVar1 = *param_1;
  } while (iVar3 != param_1[2]);
  iVar4 = param_2[1];
  iVar2 = *param_2;
  param_2[1] = iVar3;
  *param_2 = iVar1;
  return (iVar1 + (iVar3 - iVar4) * 1000000) - iVar2;
}


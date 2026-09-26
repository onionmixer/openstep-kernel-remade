
void _ts_diff(uint *param_1,uint *param_2,int *param_3)

{
  int iVar1;
  uint *puVar2;
  
  iVar1 = _ts_greater(param_2,param_1);
  puVar2 = param_1;
  if (iVar1 != 0) {
    puVar2 = param_2;
    param_2 = param_1;
  }
  if (*puVar2 < *param_2) {
    puVar2[1] = puVar2[1] - 1;
  }
  *param_3 = *puVar2 - *param_2;
  param_3[1] = puVar2[1] - param_2[1];
  return;
}


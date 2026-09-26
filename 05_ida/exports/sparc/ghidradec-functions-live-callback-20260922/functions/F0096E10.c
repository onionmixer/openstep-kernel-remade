
void __insque(int *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *param_2;
  param_1[1] = (int)param_2;
  *param_1 = iVar1;
  *param_2 = (int)param_1;
  *(int **)(iVar1 + 4) = param_1;
  return;
}



int _rem_runq(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[2];
  if (iVar1 != 0) {
    *(int *)(*param_1 + 4) = param_1[1];
    *(int *)param_1[1] = *param_1;
    *(int *)(iVar1 + 0x104) = *(int *)(iVar1 + 0x104) + -1;
    param_1[2] = 0;
  }
  return iVar1;
}


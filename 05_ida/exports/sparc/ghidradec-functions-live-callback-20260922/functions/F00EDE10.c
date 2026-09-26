
undefined4 _NXNextHashState(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar1 = param_2[1];
  iVar2 = *(int *)(param_1 + 0xc);
  if (iVar1 == 0) {
    do {
      iVar1 = *param_2 + -1;
      if (*param_2 == 0) {
        return 0;
      }
      *param_2 = iVar1;
      iVar1 = *(int *)(iVar2 + iVar1 * 8);
      param_2[1] = iVar1;
    } while (iVar1 == 0);
    iVar1 = param_2[1];
  }
  param_2[1] = iVar1 + -1;
  piVar3 = (int *)(iVar2 + *param_2 * 8);
  if (*piVar3 == 1) {
    iVar1 = piVar3[1];
  }
  else {
    iVar1 = *(int *)(piVar3[1] + param_2[1] * 4);
  }
  *param_3 = iVar1;
  return 1;
}


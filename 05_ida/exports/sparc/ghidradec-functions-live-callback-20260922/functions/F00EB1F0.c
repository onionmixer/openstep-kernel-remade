
int -[List indexOf:](int param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  piVar1 = *(int **)(param_1 + 4);
  piVar3 = piVar1 + *(int *)(param_1 + 8);
  if (piVar1 < piVar3) {
    iVar2 = *piVar1;
    while (iVar2 != param_3) {
      piVar1 = piVar1 + 1;
      if (piVar3 <= piVar1) {
        return -1;
      }
      iVar2 = *piVar1;
    }
    iVar2 = (int)piVar1 - *(int *)(param_1 + 4) >> 2;
  }
  else {
    iVar2 = -1;
  }
  return iVar2;
}



int -[List replaceObject:with:](int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  if (param_4 == 0) {
    param_3 = 0;
  }
  else {
    piVar2 = *(int **)(param_1 + 4);
    piVar3 = piVar2 + *(int *)(param_1 + 8);
    if (piVar2 < piVar3) {
      iVar1 = *piVar2;
      while (iVar1 != param_3) {
        piVar2 = piVar2 + 1;
        if (piVar3 <= piVar2) {
          return 0;
        }
        iVar1 = *piVar2;
      }
      *piVar2 = param_4;
    }
    else {
      param_3 = 0;
    }
  }
  return param_3;
}


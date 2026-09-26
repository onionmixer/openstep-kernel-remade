
int * _class_getInstanceMethod(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  if (param_1 != 0) {
    if (param_2 == 0) {
      return (int *)0x0;
    }
    piVar3 = *(int **)(param_1 + 0x1c);
    while( true ) {
      if (piVar3 == (int *)0x0) {
        param_1 = *(int *)(param_1 + 4);
      }
      else {
        iVar1 = piVar3[1];
        while( true ) {
          piVar2 = piVar3 + 2;
          while (iVar1 = iVar1 + -1, -1 < iVar1) {
            if (param_2 == *piVar2) {
              return piVar2;
            }
            piVar2 = piVar2 + 3;
          }
          piVar3 = (int *)*piVar3;
          if (piVar3 == (int *)0x0) break;
          iVar1 = piVar3[1];
        }
        param_1 = *(int *)(param_1 + 4);
      }
      if (param_1 == 0) break;
      piVar3 = *(int **)(param_1 + 0x1c);
    }
  }
  return (int *)0x0;
}


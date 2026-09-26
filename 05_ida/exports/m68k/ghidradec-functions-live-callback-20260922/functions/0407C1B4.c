
int * _scsi_reselect(int *param_1,char param_2,char param_3)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  piVar1 = (int *)*param_1;
  while( true ) {
    if (piVar1 == param_1) {
      return (int *)0x0;
    }
    if ((param_2 == *(char *)(piVar1 + 7)) && (param_3 == *(char *)((int)piVar1 + 0x1d))) break;
    piVar1 = (int *)piVar1[2];
  }
  piVar2 = (int *)piVar1[2];
  piVar3 = (int *)piVar1[3];
  if (piVar2 == param_1) {
    param_1[1] = (int)piVar3;
  }
  else {
    piVar2[3] = (int)piVar3;
  }
  if (piVar3 == param_1) {
    *param_1 = (int)piVar2;
  }
  else {
    piVar3[2] = (int)piVar2;
  }
  iVar4 = param_1[4];
  iVar5 = *(int *)(iVar4 + 0x18);
  if (iVar5 == iVar4 + 0x18) {
    *(int **)(iVar4 + 0x1c) = piVar1;
  }
  else {
    *(int **)(iVar5 + 4) = piVar1;
  }
  *piVar1 = iVar5;
  piVar1[1] = param_1[4] + 0x18;
  *(int **)(param_1[4] + 0x18) = piVar1;
  *(char *)(param_1 + 0x18) = *(char *)(param_1 + 0x18) + -1;
  return piVar1;
}


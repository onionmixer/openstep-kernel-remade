
int * sub_4036E8C(int param_1,undefined4 *param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  
  if (*(int *)(param_1 + 0x16) == 0) {
    piVar3 = (int *)0x0;
  }
  else {
    *(int *)(param_1 + 0x16) = *(int *)(param_1 + 0x16) + -1;
    piVar3 = (int *)_kalloc(0x18);
    piVar3[3] = 0;
    piVar3[1] = 0;
    *piVar3 = 0;
    piVar3[2] = 0;
  }
  piVar3[1] = param_3;
  *piVar3 = param_3;
  *(undefined4 *)(param_3 + 0xc) = 0;
  puVar2 = (undefined4 *)(param_1 + 0xe);
  if (param_2 == puVar2) {
    puVar2 = (undefined4 *)*param_2;
    if (puVar2 == param_2) {
      *(int **)(param_1 + 0x12) = piVar3;
    }
    else {
      puVar2[5] = piVar3;
    }
    piVar3[4] = (int)puVar2;
    piVar3[5] = param_1 + 0xe;
    *(int **)(param_1 + 0xe) = piVar3;
  }
  else if (puVar2 == (undefined4 *)param_2[4]) {
    puVar1 = *(undefined4 **)(param_1 + 0x12);
    if (puVar1 == puVar2) {
      *puVar1 = piVar3;
    }
    else {
      puVar1[4] = piVar3;
    }
    piVar3[5] = (int)puVar1;
    piVar3[4] = param_1 + 0xe;
    *(int **)(param_1 + 0x12) = piVar3;
  }
  else {
    piVar3[5] = (int)param_2;
    piVar3[4] = param_2[4];
    param_2[4] = piVar3;
    *(int **)(piVar3[4] + 0x14) = piVar3;
  }
  return piVar3;
}


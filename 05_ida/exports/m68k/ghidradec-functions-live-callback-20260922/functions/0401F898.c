
undefined4 _in_pcballoc(int param_1,int *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)_kalloc(0x3c);
  if (piVar1 == (int *)0x0) {
    uVar2 = 0x37;
  }
  else {
    _bzero(piVar1,0x3c);
    piVar1[2] = (int)param_2;
    piVar1[6] = param_1;
    *piVar1 = *param_2;
    piVar1[1] = (int)param_2;
    *(int **)(*param_2 + 4) = piVar1;
    *param_2 = (int)piVar1;
    *(int **)(param_1 + 8) = piVar1;
    uVar2 = 0;
  }
  return uVar2;
}


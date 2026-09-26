
void sub_4085CEA(int *param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *(int **)(param_2 + 8);
  piVar2 = *(int **)(param_2 + 0xc);
  if (piVar1 == param_1) {
    piVar1[1] = (int)piVar2;
  }
  else {
    piVar1[3] = (int)piVar2;
  }
  if (piVar2 == param_1) {
    *piVar2 = (int)piVar1;
  }
  else {
    piVar2[2] = (int)piVar1;
  }
  _kfree(param_2,0x10);
  return;
}


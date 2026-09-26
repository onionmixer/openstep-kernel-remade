
int sub_F00F0B90(int param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  
  piVar3 = (int *)*(int *)(param_1 + 0x1c);
  piVar2 = (int *)0;
  while (piVar1 = piVar3, piVar1 != (int *)0x0) {
    piVar2 = piVar1;
    piVar3 = (int *)*piVar1;
  }
  return (int)piVar2;
}



int * _firstsegfromheader(int param_1)

{
  uint uVar1;
  int *piVar2;
  
  piVar2 = (int *)(param_1 + 0x1c);
  uVar1 = 0;
  if (*(uint *)(param_1 + 0x10) != 0) {
    do {
      if (*piVar2 == 1) {
        return piVar2;
      }
      piVar2 = (int *)(piVar2[1] + (int)piVar2);
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(uint *)(param_1 + 0x10));
  }
  return (int *)0x0;
}


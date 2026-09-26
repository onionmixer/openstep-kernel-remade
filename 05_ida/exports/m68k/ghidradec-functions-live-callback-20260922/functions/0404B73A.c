
int * _nextsegfromheader(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = param_1 + 0x1c;
  uVar1 = 0;
  if (*(uint *)(param_1 + 0x10) != 0) {
    do {
      if (param_2 == iVar2) break;
      iVar2 = *(int *)(iVar2 + 4) + iVar2;
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(uint *)(param_1 + 0x10));
  }
  if (*(uint *)(param_1 + 0x10) != uVar1) {
    piVar3 = (int *)(*(int *)(iVar2 + 4) + iVar2);
    for (; uVar1 < *(uint *)(param_1 + 0x10); uVar1 = uVar1 + 1) {
      if (*piVar3 == 1) {
        return piVar3;
      }
      piVar3 = (int *)(piVar3[1] + (int)piVar3);
    }
  }
  return (int *)0x0;
}


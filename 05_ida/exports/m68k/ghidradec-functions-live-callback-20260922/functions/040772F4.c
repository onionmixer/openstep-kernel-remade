
int _od_locate_alt(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  
  piVar4 = *(int **)(param_3 + 0xae);
  if ((*piVar4 == 0x4e655854) || (*piVar4 == 0x646c5632)) {
    piVar5 = (int *)((int)piVar4 + 0x22e);
    iVar3 = 0x686;
  }
  else {
    piVar5 = *(int **)(param_3 + 0xb2);
    iVar3 = 0xc00;
  }
  iVar2 = (int)*(sword *)(piVar4 + 0x1e);
  if (*piVar4 == 0x4e655854) {
    iVar2 = iVar2 / (piVar4[0x19] >> 1);
  }
  iVar1 = ((param_5 - *(int *)(param_3 + 0xbe)) - (int)*(sword *)(piVar4 + 0x1c)) /
          (int)*(sword *)((int)piVar4 + 0x76);
  if ((-1 < iVar1) && (iVar1 < *(sword *)(piVar4 + 0x1d))) {
    iVar1 = iVar2 * iVar1;
    iVar2 = iVar2 + iVar1;
    if ((iVar2 < iVar3) && (iVar1 < iVar2)) {
      piVar4 = piVar5 + iVar1;
      do {
        if (param_4 == *piVar4) {
          return iVar1;
        }
        piVar4 = piVar4 + 1;
        iVar1 = iVar1 + 1;
      } while (iVar1 < iVar2);
    }
  }
  iVar2 = 0;
  if (iVar3 != 0) {
    do {
      if (*piVar5 == -1) {
        return -1;
      }
      if (param_4 == *piVar5) {
        return iVar2;
      }
      piVar5 = piVar5 + 1;
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar3);
  }
  return -1;
}


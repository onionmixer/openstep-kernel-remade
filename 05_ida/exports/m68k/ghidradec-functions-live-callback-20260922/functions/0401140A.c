
int _ndqb(int *param_1,uint param_2)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  
  iVar2 = *param_1;
  if (iVar2 < 1) {
    iVar3 = -iVar2;
  }
  else {
    pcVar4 = (char *)param_1[1];
    iVar3 = ((uint)(pcVar4 + 0x34) & 0xffffffc0) - (int)pcVar4;
    if (iVar2 < iVar3) {
      iVar3 = iVar2;
    }
    if (param_2 != 0) {
      pcVar1 = pcVar4 + iVar3;
      for (; pcVar4 < pcVar1; pcVar4 = pcVar4 + 1) {
        if ((param_2 & (int)*pcVar4) != 0) {
          return (int)pcVar4 - param_1[1];
        }
      }
    }
  }
  return iVar3;
}


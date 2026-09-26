
undefined4 -[Object isKindOf:](int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if (iVar2 != 0) {
    iVar1 = iVar2 - param_3;
    do {
      if (iVar1 == 0) {
        return 1;
      }
      iVar2 = *(int *)(iVar2 + 4);
      iVar1 = iVar2 - param_3;
    } while (iVar2 != 0);
  }
  return 0;
}



int sub_4036D9E(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *param_1;
  iVar2 = *(int *)(iVar3 + 0x38);
  if (iVar2 < param_2) {
    iVar1 = *(int *)(iVar3 + 0xc);
    iVar2 = iVar3;
    while (iVar1 != 0) {
      iVar3 = *(int *)(iVar2 + 0xc);
      if (*(int *)(iVar3 + 0x38) < *(int *)(iVar2 + 0x38)) {
        return iVar2;
      }
      if (param_2 < *(int *)(iVar3 + 0x38)) {
        return iVar2;
      }
      iVar2 = iVar3;
      iVar1 = *(int *)(iVar3 + 0xc);
    }
  }
  else {
    if (iVar2 < param_1[2]) {
      if (param_2 < iVar2) {
        return 0;
      }
    }
    else {
      if (*(int *)(iVar3 + 0xc) == 0) {
        return iVar3;
      }
      do {
        iVar2 = *(int *)(iVar3 + 0xc);
        if (*(int *)(iVar2 + 0x38) < *(int *)(iVar3 + 0x38)) break;
        iVar3 = iVar2;
      } while (*(int *)(iVar2 + 0xc) != 0);
    }
    do {
      iVar2 = iVar3;
      if (*(int *)(iVar2 + 0xc) == 0) {
        return iVar2;
      }
      iVar3 = *(int *)(iVar2 + 0xc);
    } while (*(int *)(*(int *)(iVar2 + 0xc) + 0x38) <= param_2);
  }
  return iVar2;
}

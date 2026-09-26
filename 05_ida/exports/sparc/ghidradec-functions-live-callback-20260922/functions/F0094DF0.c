
void _ovbcopy(undefined *param_1,undefined *param_2,int param_3)

{
  undefined uVar1;
  bool bVar2;
  int iVar3;
  
  if (param_3 < 1) {
    return;
  }
  iVar3 = (int)param_1 - (int)param_2;
  if (iVar3 < 0) {
    iVar3 = -iVar3;
  }
  if (iVar3 < param_3) {
    if (param_2 <= param_1) {
      do {
        uVar1 = *param_1;
        param_1 = param_1 + 1;
        *param_2 = uVar1;
        iVar3 = param_3 + -1;
        bVar2 = 0 < param_3;
        param_2 = param_2 + 1;
        param_3 = iVar3;
      } while (iVar3 != 0 && bVar2);
      return;
    }
    do {
      iVar3 = param_3 + -1;
      bVar2 = 0 < param_3;
      param_2[iVar3] = param_1[iVar3];
      param_3 = iVar3;
    } while (iVar3 != 0 && bVar2);
    return;
  }
  return;
}


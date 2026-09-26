
undefined4 _itimerdecr(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1[3];
  if (iVar2 < param_2) {
    if (param_1[2] == 0) {
      iVar2 = param_2 - iVar2;
      goto loc_400A8B6;
    }
    param_1[3] = iVar2 + 1000000;
    param_1[2] = param_1[2] + -1;
  }
  iVar1 = param_1[3];
  param_1[3] = iVar1 - param_2;
  iVar2 = 0;
  if ((param_1[2] != 0) || (iVar1 - param_2 != 0)) {
    return 1;
  }
loc_400A8B6:
  if ((*param_1 == 0) && (param_1[1] == 0)) {
    param_1[3] = 0;
  }
  else {
    param_1[2] = *param_1;
    param_1[3] = param_1[1];
    iVar2 = param_1[3] - iVar2;
    param_1[3] = iVar2;
    if (iVar2 < 0) {
      param_1[3] = iVar2 + 1000000;
      param_1[2] = param_1[2] + -1;
    }
  }
  return 0;
}


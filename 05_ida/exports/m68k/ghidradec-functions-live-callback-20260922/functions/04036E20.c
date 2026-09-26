
void sub_4036E20(undefined4 param_1,int *param_2,int param_3)

{
  int iVar1;
  
  if (param_2[2] < *(int *)(param_3 + 0x38)) {
    iVar1 = *(int *)(*param_2 + 0x38);
    if ((*(int *)(param_3 + 0x38) < iVar1) || (iVar1 < param_2[2])) {
      *(int *)(param_3 + 0xc) = *param_2;
      *param_2 = param_3;
      return;
    }
  }
  iVar1 = sub_4036D9E(param_2,*(undefined4 *)(param_3 + 0x38));
  if (iVar1 == 0) {
    *(int *)(param_3 + 0xc) = *param_2;
    *param_2 = param_3;
  }
  else {
    *(undefined4 *)(param_3 + 0xc) = *(undefined4 *)(iVar1 + 0xc);
    *(int *)(iVar1 + 0xc) = param_3;
    if (iVar1 == param_2[1]) {
      param_2[1] = param_3;
    }
  }
  return;
}


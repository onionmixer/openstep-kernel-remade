
void sub_4018AFE(int *param_1)

{
  int iVar1;
  
  *(int *)(param_1[3] + 8) = param_1[2];
  *(int *)(param_1[2] + 0xc) = param_1[3];
  *(int *)(*param_1 + 4) = param_1[1];
  *(int *)param_1[1] = *param_1;
  _vn_rele(param_1[5]);
  param_1[5] = 0;
  _vn_rele(param_1[4]);
  param_1[4] = 0;
  if (*(int *)((int)param_1 + 0x3a) != 0) {
    _crfree(*(int *)((int)param_1 + 0x3a));
    *(undefined4 *)((int)param_1 + 0x3a) = 0;
  }
  if (*(char *)((int)param_1 + 0x42) != '\0') {
    _kfree(*(undefined4 *)((int)param_1 + 0x3e),(int)*(sword *)(param_1 + 0x11));
    *(undefined *)((int)param_1 + 0x42) = 0;
    *(undefined2 *)(param_1 + 0x11) = 0;
  }
  iVar1 = (int)dword_40B6D68;
  dword_40B6D68 = param_1;
  param_1[2] = iVar1;
  *(int **)(iVar1 + 0xc) = param_1;
  param_1[3] = (int)&_nc_lru;
  param_1[1] = (int)param_1;
  *param_1 = (int)param_1;
  dword_40B6D94 = dword_40B6D94 + -1;
  return;
}


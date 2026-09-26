
int sub_408C210(int *param_1)

{
  int iVar1;
  
  if (((*(byte *)(*param_1 + 0x3d) & 0x20) == 0) && ((*(byte *)(param_1 + 4) & 4) != 0)) {
    iVar1 = (10000000 / *(int *)(unk_40B23D2 + *(char *)(*param_1 + 0x47) * 4)) * 5;
  }
  else {
    iVar1 = (10000000 / *(int *)(unk_40B23D2 + *(char *)(*param_1 + 0x47) * 4)) * 0x19;
  }
  iVar1 = iVar1 * 2;
  if (20000 < iVar1) {
    iVar1 = 20000;
  }
  return iVar1;
}


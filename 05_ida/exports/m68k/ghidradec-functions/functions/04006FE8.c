
void _fixjobc(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *(int *)(param_2 + 8);
  iVar3 = _get_posix_proc((int)*(sword *)(*(int *)(param_1 + 0x42) + 0x30));
  if ((param_2 != *(int *)(iVar3 + 0xe)) && (iVar1 == *(int *)(*(int *)(iVar3 + 0xe) + 8))) {
    if (param_3 == 0) {
      iVar3 = *(int *)(param_2 + 0x10);
      *(int *)(param_2 + 0x10) = iVar3 + -1;
      if (iVar3 == 1) {
        sub_40070AE(param_2);
      }
    }
    else {
      *(int *)(param_2 + 0x10) = *(int *)(param_2 + 0x10) + 1;
    }
  }
  for (iVar3 = *(int *)(param_1 + 0x46); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x4a)) {
    iVar4 = _get_posix_proc((int)*(sword *)(iVar3 + 0x30));
    iVar4 = *(int *)(iVar4 + 0xe);
    if (((param_2 != iVar4) && (iVar1 == *(int *)(iVar4 + 8))) &&
       (*(char *)(iVar3 + 0x13) != '\x05')) {
      if (param_3 == 0) {
        iVar2 = *(int *)(iVar4 + 0x10);
        *(int *)(iVar4 + 0x10) = iVar2 + -1;
        if (iVar2 == 1) {
          sub_40070AE(iVar4);
        }
      }
      else {
        *(int *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x10) + 1;
      }
    }
  }
  return;
}

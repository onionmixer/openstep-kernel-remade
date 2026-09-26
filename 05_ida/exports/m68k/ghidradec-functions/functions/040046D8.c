
int _rewhence(int param_1,int param_2,int param_3)

{
  int iVar1;
  sword sVar2;
  undefined auStack_3e [20];
  int iStack_2a;
  
  if (((*(sword *)(param_1 + 2) == 2) || (param_3 == 2)) &&
     (iVar1 = (**(code **)(*(int *)(*(int *)(param_2 + 0x16) + 0x1c) + 0x14))
                        (*(int *)(param_2 + 0x16),auStack_3e,*(undefined4 *)(_active_u + 0x1a)),
     iVar1 != 0)) {
    return iVar1;
  }
  sVar2 = *(sword *)(param_1 + 2);
  if (sVar2 == 1) {
    *(int *)(param_1 + 4) = *(int *)(param_2 + 0x1a) + *(int *)(param_1 + 4);
  }
  else if (sVar2 < 2) {
    if (sVar2 != 0) {
      return 0x16;
    }
  }
  else {
    if (sVar2 != 2) {
      return 0x16;
    }
    *(int *)(param_1 + 4) = iStack_2a + *(int *)(param_1 + 4);
  }
  sVar2 = (sword)param_3;
  *(sword *)(param_1 + 2) = sVar2;
  if (sVar2 == 1) {
    iStack_2a = *(int *)(param_2 + 0x1a);
  }
  else if (sVar2 != 2) {
    return 0;
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) - iStack_2a;
  return 0;
}

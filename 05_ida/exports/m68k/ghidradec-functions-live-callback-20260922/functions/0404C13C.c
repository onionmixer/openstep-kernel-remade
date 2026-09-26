
int sub_404C13C(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = _active_threads;
  if (*(int *)(param_2 + 0xc) == 0) {
    iVar1 = param_1 + 8;
    iVar3 = sub_404C2E4(_active_threads,iVar1,*(int *)(param_1 + 4) + -8,param_2 + 8);
    if (iVar3 == 0) {
      iVar3 = sub_404C33E(uVar2,iVar1,*(int *)(param_1 + 4) + -8,param_2 + 4);
      if (iVar3 == 0) {
        iVar3 = sub_404C294(uVar2,iVar1,*(int *)(param_1 + 4) + -8);
        if (iVar3 == 0) {
          *(byte *)(param_2 + 0x10) = *(byte *)(param_2 + 0x10) | 0x80;
          *(int *)(param_2 + 0xc) = *(int *)(param_2 + 0xc) + 1;
          iVar3 = 0;
        }
      }
    }
  }
  else {
    iVar3 = 4;
  }
  return iVar3;
}


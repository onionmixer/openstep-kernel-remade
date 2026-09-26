
int sub_404C1C8(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iStack_8;
  
  if (*(int *)(param_2 + 0xc) == 0) {
    iStack_8 = _active_threads;
  }
  else {
    iVar2 = _thread_create(*(undefined4 *)(_active_threads + 0xc),&iStack_8);
    if (iVar2 != 0) {
      return 7;
    }
    _thread_deallocate(iStack_8);
  }
  iVar2 = param_1 + 8;
  iVar1 = sub_404C294(iStack_8,iVar2,*(int *)(param_1 + 4) + -8);
  if (iVar1 == 0) {
    if (*(int *)(param_2 + 0xc) == 0) {
      iVar1 = sub_404C2E4(_active_threads,iVar2,*(int *)(param_1 + 4) + -8,param_2 + 8);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar2 = sub_404C33E(_active_threads,iVar2,*(int *)(param_1 + 4) + -8,param_2 + 4);
      if (iVar2 != 0) {
        return iVar2;
      }
    }
    else {
      _thread_resume(iStack_8);
    }
    *(int *)(param_2 + 0xc) = *(int *)(param_2 + 0xc) + 1;
    iVar1 = 0;
  }
  return iVar1;
}



undefined4 _task_resume(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    uVar2 = 4;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x3c);
    if (iVar1 < 1) {
      uVar2 = 5;
    }
    else {
      *(int *)(param_1 + 0x3c) = iVar1 + -1;
      if (iVar1 == 1) {
        uVar2 = _task_release(param_1);
      }
      else {
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}


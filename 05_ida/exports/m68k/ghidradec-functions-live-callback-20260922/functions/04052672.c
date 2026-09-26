
undefined4 _task_suspend_nowait(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 == 0) {
    uVar1 = 4;
  }
  else {
    iVar2 = *(int *)(param_1 + 0x3c);
    *(int *)(param_1 + 0x3c) = iVar2 + 1;
    if (iVar2 == 0) {
      iVar2 = _task_hold(param_1);
      if (iVar2 != 0) {
        return 5;
      }
      if (param_1 == *(int *)(_active_threads + 0xc)) {
        _thread_hold(_active_threads);
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}



undefined4 _task_suspend(int param_1)

{
  byte *pbVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_1 == 0) {
    uVar2 = 4;
  }
  else {
    iVar3 = *(int *)(param_1 + 0x3c);
    *(int *)(param_1 + 0x3c) = iVar3 + 1;
    if (iVar3 == 0) {
      iVar3 = _task_hold(param_1);
      if ((iVar3 != 0) || (iVar3 = _task_dowait(param_1,0), iVar3 != 0)) {
        return 5;
      }
      if (param_1 == *(int *)(_active_threads + 0xc)) {
        _thread_hold(_active_threads);
        _need_ast = _need_ast | 4;
        if (_need_ast != 0) {
          pbVar1 = (byte *)(*(int *)(_active_threads + 0x24) + 0x54);
          *pbVar1 = *pbVar1 | 0x10;
        }
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}

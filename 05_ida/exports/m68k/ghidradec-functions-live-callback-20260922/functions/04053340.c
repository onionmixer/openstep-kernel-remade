
undefined4 _thread_suspend(int param_1)

{
  int iVar1;
  byte *pbVar2;
  undefined4 uVar3;
  
  if (param_1 == 0) {
    uVar3 = 4;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x88);
    *(int *)(param_1 + 0x88) = iVar1 + 1;
    if (iVar1 == 0) {
      *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + 1;
      *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) | 2;
      if (param_1 == _active_threads) {
        _need_ast = _need_ast | 4;
        if (_need_ast != 0) {
          pbVar2 = (byte *)(*(int *)(_active_threads + 0x24) + 0x54);
          *pbVar2 = *pbVar2 | 0x10;
        }
      }
      else {
        _thread_dowait(param_1,1);
      }
    }
    uVar3 = 0;
  }
  return uVar3;
}


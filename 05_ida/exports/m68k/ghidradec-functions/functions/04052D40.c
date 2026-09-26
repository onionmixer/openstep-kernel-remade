
undefined4 _thread_terminate(int param_1)

{
  byte *pbVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = _active_threads;
  if (param_1 == 0) {
    uVar3 = 4;
  }
  else {
    _ipc_thread_disable(param_1);
    if (iVar2 == param_1) {
      if (*(int *)(param_1 + 0x170) != 0) {
        *(undefined4 *)(param_1 + 0x170) = 0;
        *(uint *)(param_1 + 0x174) = *(uint *)(param_1 + 0x174) | 2;
      }
      _need_ast = _need_ast | 2;
      if (_need_ast != 0) {
        pbVar1 = (byte *)(*(int *)(_active_threads + 0x24) + 0x54);
        *pbVar1 = *pbVar1 | 0x10;
      }
      uVar3 = 0;
    }
    else {
      if ((*(int *)(*(int *)(_active_threads + 0xc) + 4) == 0) || (*(int *)(iVar2 + 0x170) == 0)) {
        _thread_terminate(iVar2);
      }
      else if (*(int *)(param_1 + 0x170) != 0) {
        *(undefined4 *)(param_1 + 0x170) = 0;
        _thread_halt(param_1,1);
        _ipc_thread_terminate(param_1);
        _thread_deallocate(param_1);
        return 0;
      }
      uVar3 = 5;
    }
  }
  return uVar3;
}

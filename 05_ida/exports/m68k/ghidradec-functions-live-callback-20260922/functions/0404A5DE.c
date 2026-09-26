
int _newStack(void)

{
  int iVar1;
  int iVar2;
  int iStack_8;
  
  iVar1 = _kmem_alloc_wired(_kernel_map,&iStack_8,dword_40B371A);
  if (iVar1 == 0) {
    _stackStats = _stackStats + 1;
    *(undefined4 *)(iStack_8 + 8) = 2;
    dword_40C232C = dword_40C232C + 1;
    _stack_init(iStack_8 + 0xc);
    if (1 < dword_40B371E) {
      _lock_write(&_stack_queue_lock);
      iVar2 = dword_40B371A + iStack_8;
      iVar1 = 1;
      if (1 < dword_40B371E) {
        do {
          _stack_init(iVar2 + 0xc);
          sub_404A45C(iVar2);
          iVar2 = dword_40B371A + iVar2;
          iVar1 = iVar1 + 1;
        } while (iVar1 < dword_40B371E);
      }
      _lock_done(&_stack_queue_lock);
    }
    iStack_8 = iStack_8 + 0xc;
  }
  else {
    iStack_8 = 0;
  }
  return iStack_8;
}


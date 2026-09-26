
int * _allocStack(void)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  
  bVar1 = false;
  iVar3 = 0;
  do {
    _lock_write(&_stack_queue_lock);
    if (dword_40AF7D4 == 0) {
      piVar2 = (int *)0x0;
    }
    else {
      if ((int **)dword_40B3712 == &dword_40B3712) {
        piVar2 = (int *)0x0;
      }
      else {
        *(int ***)(*dword_40B3712 + 4) = &dword_40B3712;
        piVar2 = dword_40B3712;
        dword_40B3712 = (int *)*dword_40B3712;
      }
      piVar2[2] = 2;
      piVar2 = piVar2 + 3;
      dword_40AF7D4 = dword_40AF7D4 + -1;
      dword_40C2330 = dword_40C2330 + -1;
      dword_40C232C = dword_40C232C + 1;
    }
    _lock_done(&_stack_queue_lock);
    if ((piVar2 == (int *)0x0) && (piVar2 = (int *)_newStack(), piVar2 == (int *)0x0)) {
      if (bVar1) {
        if (iVar3 != 0) {
          return (int *)0x0;
        }
      }
      else {
        bVar1 = true;
        _uprintf(aMachOutOfKerne);
        if (dword_40AF7DC == 0) {
          _printf(aStackAllocKern);
        }
      }
      _lock_write(&_stack_queue_lock);
      if (dword_40AF7D4 == 0) {
        _assert_wait(&dword_40B3712,0);
        dword_40AF7DC = 1;
        _lock_done(&_stack_queue_lock);
        _thread_block();
        iVar3 = *(int *)(_active_threads + 0x40);
      }
      else {
        _lock_done(&_stack_queue_lock);
        iVar3 = 0;
      }
    }
    else if (bVar1) {
      _uprintf(aContinuing);
    }
  } while (piVar2 == (int *)0x0);
  return piVar2;
}

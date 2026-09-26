
undefined4 _stack_alloc_try(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
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
  if ((piVar2 == (int *)0x0) && (piVar2 = *(int **)(param_1 + 0x2c), piVar2 == (int *)0x0)) {
    uVar1 = 0;
  }
  else {
    _stack_attach(param_1,piVar2,param_2);
    uVar1 = 1;
  }
  return uVar1;
}


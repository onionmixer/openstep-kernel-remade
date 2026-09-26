
int _thread_halt(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  if (_active_threads == param_1) {
                    /* WARNING: Subroutine does not return */
    _panic(aThreadHaltTryi);
  }
  if (param_2 == 0) {
    if ((*(byte *)(param_1 + 0x4b) & 0x10) != 0) {
      *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + 1;
      return 0;
    }
    if ((*(byte *)(_active_threads + 0x177) & 1) != 0) {
      _thread_wakeup_prim(_active_threads + 0x44,0,2);
      return 5;
    }
  }
  else if ((*(byte *)(param_1 + 0x4b) & 0x10) != 0) {
    *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + 1;
    return 0;
  }
  *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + 1;
  uVar1 = *(uint *)(param_1 + 0x48);
  *(uint *)(param_1 + 0x48) = uVar1 | 2;
  if (((*(byte *)(param_1 + 0x177) & 1) != 0) && ((uVar1 & 0x10) == 0)) {
    do {
      *(undefined4 *)(param_1 + 0x44) = 1;
      _thread_sleep(param_1 + 0x44,0,1);
      if ((*(byte *)(param_1 + 0x4b) & 0x10) != 0) {
        return 0;
      }
      if ((*(int *)(_active_threads + 0x40) != 0) && (param_2 == 0)) {
        _thread_release(param_1);
        return 5;
      }
    } while ((*(byte *)(param_1 + 0x177) & 1) != 0);
  }
  *(uint *)(param_1 + 0x174) = *(uint *)(param_1 + 0x174) | 1;
  while( true ) {
    iVar2 = _thread_dowait(param_1,param_2);
    if (iVar2 != 0) {
      *(uint *)(param_1 + 0x174) = *(uint *)(param_1 + 0x174) & 0xfffffffe;
      _thread_wakeup_prim(param_1 + 0x44,0,2);
      _thread_release(param_1);
      return iVar2;
    }
    _clear_wait(param_1,2,1);
    if ((*(byte *)(param_1 + 0x4b) & 0x10) != 0) break;
    if ((((*(code **)(param_1 + 0x30) == _mach_msg_continue) ||
         (*(code **)(param_1 + 0x30) == _mach_msg_receive_continue)) &&
        (iVar2 = _mach_msg_interrupt(param_1), iVar2 != 0)) ||
       ((*(code **)(param_1 + 0x30) == _thread_exception_return ||
        (*(code **)(param_1 + 0x30) == _thread_bootstrap_return)))) {
      *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) | 0x10;
      *(uint *)(param_1 + 0x174) = *(uint *)(param_1 + 0x174) & 0xfffffffe;
      return 0;
    }
    if ((*(uint *)(param_1 + 0x48) & 0xf) != 2) {
                    /* WARNING: Subroutine does not return */
      _panic(aThreadHalt);
    }
    *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) | 0xc;
    _thread_setrun(param_1,0);
  }
  return 0;
}


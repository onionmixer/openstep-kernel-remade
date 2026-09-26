/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00167494 */

int _thread_halt(uint param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  
  uVar3 = _active_threads;
  if (param_1 == _active_threads) {
                    /* WARNING: Subroutine does not return */
    _panic(s_thread_halt__trying_to_halt_curr_001dfc1f);
  }
  if (param_2 == 0) {
    uVar4 = _splsched();
    if (param_1 < uVar3) {
      piVar1 = (int *)(param_1 + 0x20);
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar5 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar5 == 1);
      piVar1 = (int *)(uVar3 + 0x20);
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar5 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar5 == 1);
    }
    else {
      piVar1 = (int *)(uVar3 + 0x20);
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar5 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar5 == 1);
      piVar1 = (int *)(param_1 + 0x20);
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar5 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar5 == 1);
    }
    if ((*(byte *)(param_1 + 0x4c) & 0x10) != 0) {
      *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
      LOCK();
      *(undefined4 *)(uVar3 + 0x20) = 0;
      UNLOCK();
      LOCK();
      *(undefined4 *)(param_1 + 0x20) = 0;
      UNLOCK();
      _splx(uVar4);
      return 0;
    }
    if ((*(byte *)(uVar3 + 0x17c) & 1) != 0) {
      _thread_wakeup_prim(uVar3 + 0x48,0,2);
      LOCK();
      *(undefined4 *)(param_1 + 0x20) = 0;
      UNLOCK();
      LOCK();
      *(undefined4 *)(uVar3 + 0x20) = 0;
      UNLOCK();
      _splx(uVar4);
      return 5;
    }
    LOCK();
    *(undefined4 *)(uVar3 + 0x20) = 0;
    UNLOCK();
  }
  else {
    uVar4 = _splsched();
    piVar1 = (int *)(param_1 + 0x20);
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar5 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar5 == 1);
    if ((*(byte *)(param_1 + 0x4c) & 0x10) != 0) {
      *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
      LOCK();
      *(undefined4 *)(param_1 + 0x20) = 0;
      UNLOCK();
      _splx(uVar4);
      return 0;
    }
  }
  *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
  uVar3 = *(uint *)(param_1 + 0x4c);
  *(uint *)(param_1 + 0x4c) = uVar3 | 2;
  if (((*(byte *)(param_1 + 0x17c) & 1) != 0) && ((uVar3 & 0x10) == 0)) {
    do {
      *(undefined4 *)(param_1 + 0x48) = 1;
      piVar1 = (int *)(param_1 + 0x20);
      _thread_sleep(param_1 + 0x48,piVar1,1);
      if ((*(byte *)(param_1 + 0x4c) & 0x10) != 0) {
        _splx(uVar4);
        return 0;
      }
      if ((*(int *)(_active_threads + 0x44) != 0) && (param_2 == 0)) {
        _splx(uVar4);
        _thread_release(param_1);
        return 5;
      }
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar5 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar5 == 1);
    } while (((*(byte *)(param_1 + 0x17c) & 1) != 0) && ((*(byte *)(param_1 + 0x4c) & 0x10) == 0));
  }
  *(byte *)(param_1 + 0x17c) = *(byte *)(param_1 + 0x17c) | 1;
  while( true ) {
    LOCK();
    *(undefined4 *)(param_1 + 0x20) = 0;
    UNLOCK();
    _splx(uVar4);
    iVar5 = _thread_dowait(param_1,param_2);
    if (iVar5 != 0) {
      uVar4 = _splsched();
      piVar1 = (int *)(param_1 + 0x20);
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar2 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar2 == 1);
      *(uint *)(param_1 + 0x17c) = *(uint *)(param_1 + 0x17c) & 0xfffffffe;
      _thread_wakeup_prim(param_1 + 0x48,0,2);
      LOCK();
      *(undefined4 *)(param_1 + 0x20) = 0;
      UNLOCK();
      _splx(uVar4);
      _thread_release(param_1);
      return iVar5;
    }
    _clear_wait(param_1,2,1);
    if ((*(byte *)(param_1 + 0x4c) & 0x10) != 0) {
      return 0;
    }
    if ((((*(code **)(param_1 + 0x34) == _mach_msg_continue) ||
         (*(code **)(param_1 + 0x34) == _mach_msg_receive_continue)) &&
        (iVar5 = _mach_msg_interrupt(param_1), iVar5 != 0)) ||
       ((*(code **)(param_1 + 0x34) == _thread_exception_return ||
        (*(code **)(param_1 + 0x34) == _thread_bootstrap_return)))) {
      uVar4 = _splsched();
      piVar1 = (int *)(param_1 + 0x20);
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar5 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar5 == 1);
      *(byte *)(param_1 + 0x4c) = *(byte *)(param_1 + 0x4c) | 0x10;
      *(uint *)(param_1 + 0x17c) = *(uint *)(param_1 + 0x17c) & 0xfffffffe;
      LOCK();
      *(undefined4 *)(param_1 + 0x20) = 0;
      UNLOCK();
      _splx(uVar4);
      return 0;
    }
    uVar4 = _splsched();
    piVar1 = (int *)(param_1 + 0x20);
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar5 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar5 == 1);
    if ((*(uint *)(param_1 + 0x4c) & 0xf) != 2) break;
    *(byte *)(param_1 + 0x4c) = *(byte *)(param_1 + 0x4c) | 0xc;
    _thread_setrun(param_1,0);
  }
                    /* WARNING: Subroutine does not return */
  _panic(s_thread_halt_001dfc4b);
}


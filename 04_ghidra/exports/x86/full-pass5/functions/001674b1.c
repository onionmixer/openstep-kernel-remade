/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001674b1 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

int __analysis_fragment_001674b1(void)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint unaff_EBX;
  int unaff_EBP;
  uint unaff_ESI;
  
  if (*(int *)(unaff_EBP + 0xc) == 0) {
    _splsched();
    if (unaff_EBX < unaff_ESI) {
      piVar1 = (int *)(unaff_EBX + 0x20);
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar4 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar4 == 1);
      piVar1 = (int *)(unaff_ESI + 0x20);
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar4 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar4 == 1);
    }
    else {
      piVar1 = (int *)(unaff_ESI + 0x20);
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar4 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar4 == 1);
      piVar1 = (int *)(unaff_EBX + 0x20);
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar4 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar4 == 1);
    }
    if ((*(byte *)(unaff_EBX + 0x4c) & 0x10) != 0) {
      *(int *)(unaff_EBX + 0x40) = *(int *)(unaff_EBX + 0x40) + 1;
      LOCK();
      *(undefined4 *)(unaff_ESI + 0x20) = 0;
      UNLOCK();
      LOCK();
      *(undefined4 *)(unaff_EBX + 0x20) = 0;
      UNLOCK();
      _splx();
      return 0;
    }
    if ((*(byte *)(unaff_ESI + 0x17c) & 1) != 0) {
      _thread_wakeup_prim(unaff_ESI + 0x48,0);
      LOCK();
      *(undefined4 *)(unaff_EBX + 0x20) = 0;
      UNLOCK();
      LOCK();
      *(undefined4 *)(unaff_ESI + 0x20) = 0;
      UNLOCK();
      _splx();
      return 5;
    }
    LOCK();
    *(undefined4 *)(unaff_ESI + 0x20) = 0;
    UNLOCK();
  }
  else {
    _splsched();
    piVar1 = (int *)(unaff_EBX + 0x20);
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar4 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar4 == 1);
    if ((*(byte *)(unaff_EBX + 0x4c) & 0x10) != 0) {
      *(int *)(unaff_EBX + 0x40) = *(int *)(unaff_EBX + 0x40) + 1;
      LOCK();
      *(undefined4 *)(unaff_EBX + 0x20) = 0;
      UNLOCK();
      _splx();
      return 0;
    }
  }
  *(int *)(unaff_EBX + 0x40) = *(int *)(unaff_EBX + 0x40) + 1;
  uVar3 = *(uint *)(unaff_EBX + 0x4c);
  *(uint *)(unaff_EBX + 0x4c) = uVar3 | 2;
  if (((*(byte *)(unaff_EBX + 0x17c) & 1) != 0) && ((uVar3 & 0x10) == 0)) {
    do {
      *(undefined4 *)(unaff_EBX + 0x48) = 1;
      piVar1 = (int *)(unaff_EBX + 0x20);
      _thread_sleep(unaff_EBX + 0x48,piVar1);
      if ((*(byte *)(unaff_EBX + 0x4c) & 0x10) != 0) {
        _splx();
        return 0;
      }
      if ((*(int *)(_active_threads + 0x44) != 0) && (*(int *)(unaff_EBP + 0xc) == 0)) {
        _splx();
        _thread_release();
        return 5;
      }
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar4 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar4 == 1);
    } while (((*(byte *)(unaff_EBX + 0x17c) & 1) != 0) &&
            ((*(byte *)(unaff_EBX + 0x4c) & 0x10) == 0));
  }
  *(byte *)(unaff_EBX + 0x17c) = *(byte *)(unaff_EBX + 0x17c) | 1;
  while( true ) {
    LOCK();
    *(undefined4 *)(unaff_EBX + 0x20) = 0;
    UNLOCK();
    _splx();
    iVar4 = _thread_dowait();
    if (iVar4 != 0) {
      _splsched();
      piVar1 = (int *)(unaff_EBX + 0x20);
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar2 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar2 == 1);
      *(uint *)(unaff_EBX + 0x17c) = *(uint *)(unaff_EBX + 0x17c) & 0xfffffffe;
      _thread_wakeup_prim(unaff_EBX + 0x48,0);
      LOCK();
      *(undefined4 *)(unaff_EBX + 0x20) = 0;
      UNLOCK();
      _splx();
      _thread_release();
      return iVar4;
    }
    _clear_wait();
    if ((*(byte *)(unaff_EBX + 0x4c) & 0x10) != 0) {
      return 0;
    }
    if ((((*(code **)(unaff_EBX + 0x34) == _mach_msg_continue) ||
         (*(code **)(unaff_EBX + 0x34) == _mach_msg_receive_continue)) &&
        (iVar4 = _mach_msg_interrupt(), iVar4 != 0)) ||
       ((*(code **)(unaff_EBX + 0x34) == _thread_exception_return ||
        (*(code **)(unaff_EBX + 0x34) == _thread_bootstrap_return)))) {
      _splsched();
      piVar1 = (int *)(unaff_EBX + 0x20);
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar4 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar4 == 1);
      *(byte *)(unaff_EBX + 0x4c) = *(byte *)(unaff_EBX + 0x4c) | 0x10;
      *(uint *)(unaff_EBX + 0x17c) = *(uint *)(unaff_EBX + 0x17c) & 0xfffffffe;
      LOCK();
      *(undefined4 *)(unaff_EBX + 0x20) = 0;
      UNLOCK();
      _splx();
      return 0;
    }
    _splsched();
    piVar1 = (int *)(unaff_EBX + 0x20);
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar4 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar4 == 1);
    if ((*(uint *)(unaff_EBX + 0x4c) & 0xf) != 2) break;
    *(byte *)(unaff_EBX + 0x4c) = *(byte *)(unaff_EBX + 0x4c) | 0xc;
    _thread_setrun();
  }
                    /* WARNING: Subroutine does not return */
  _panic(s_thread_halt_001dfc4b);
}


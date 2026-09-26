/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016778d */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

int __analysis_fragment_0016778d(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int unaff_EBX;
  
  do {
    *(byte *)(unaff_EBX + 0x4c) = *(byte *)(unaff_EBX + 0x4c) | 0xc;
    _thread_setrun();
    LOCK();
    *(undefined4 *)(unaff_EBX + 0x20) = 0;
    UNLOCK();
    _splx();
    iVar3 = _thread_dowait();
    if (iVar3 != 0) {
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
      return iVar3;
    }
    _clear_wait();
    if ((*(byte *)(unaff_EBX + 0x4c) & 0x10) != 0) {
      return 0;
    }
    if ((((*(code **)(unaff_EBX + 0x34) == _mach_msg_continue) ||
         (*(code **)(unaff_EBX + 0x34) == _mach_msg_receive_continue)) &&
        (iVar3 = _mach_msg_interrupt(), iVar3 != 0)) ||
       ((*(code **)(unaff_EBX + 0x34) == _thread_exception_return ||
        (*(code **)(unaff_EBX + 0x34) == _thread_bootstrap_return)))) {
      _splsched();
      piVar1 = (int *)(unaff_EBX + 0x20);
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar3 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar3 == 1);
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
      iVar3 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar3 == 1);
  } while ((*(uint *)(unaff_EBX + 0x4c) & 0xf) == 2);
                    /* WARNING: Subroutine does not return */
  _panic(s_thread_halt_001dfc4b);
}


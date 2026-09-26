/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001685e4 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_001685e4(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int *unaff_EBX;
  int unaff_EBP;
  int iVar4;
  bool bVar5;
  
LAB_001685e7:
  iVar4 = 0;
  uVar2 = _splsched();
  *(undefined4 *)(unaff_EBP + -4) = uVar2;
  piVar1 = unaff_EBX + 8;
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar3 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar3 == 1);
  piVar1 = unaff_EBX + 8;
  do {
    switch(unaff_EBX[0x13] & 0xf) {
    default:
      goto switchD_0016861e_caseD_2;
    case 6:
      iVar3 = _rem_runq();
      if (iVar3 != 0) {
        unaff_EBX[0x13] = unaff_EBX[0x13] & 0xfffffffb;
        iVar4 = unaff_EBX[0x12];
        unaff_EBX[0x12] = 0;
        goto switchD_0016861e_caseD_2;
      }
    case 7:
    case 0xb:
    case 0xe:
    case 0xf:
      unaff_EBX[0x12] = 1;
      _thread_sleep(unaff_EBX + 0x12,piVar1);
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar3 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar3 == 1);
    }
  } while( true );
switchD_0016861e_caseD_2:
  LOCK();
  unaff_EBX[8] = 0;
  UNLOCK();
  _splx();
  if (iVar4 != 0) {
    _thread_wakeup_prim(unaff_EBX + 0x12,0);
  }
  _thread_deallocate();
  _splsched();
  do {
  } while (_reaper_lock != 0);
  LOCK();
  UNLOCK();
  do {
    unaff_EBX = _reaper_queue;
    _reaper_lock = 1;
    if ((int **)_reaper_queue != &_reaper_queue) {
      *(int ***)(*_reaper_queue + 4) = &_reaper_queue;
      piVar1 = (int *)*_reaper_queue;
      bVar5 = _reaper_queue != (int *)0x0;
      _reaper_queue = piVar1;
      if (bVar5) break;
    }
    _assert_wait(&_reaper_queue);
    LOCK();
    _reaper_lock = 0;
    UNLOCK();
    _splx();
    _thread_block_with_continuation(_reaper_thread_continue);
    _splsched();
    do {
    } while (_reaper_lock != 0);
    LOCK();
    UNLOCK();
  } while( true );
  LOCK();
  _reaper_lock = 0;
  UNLOCK();
  _splx();
  if (_active_threads == unaff_EBX) {
                    /* WARNING: Subroutine does not return */
    _panic(s_thread_dowait_001dfc69);
  }
  goto LAB_001685e7;
}


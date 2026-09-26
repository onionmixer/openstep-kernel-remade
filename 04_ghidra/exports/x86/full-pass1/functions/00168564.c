/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00168564 */

void _reaper_thread_continue(void)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  
  do {
    uVar3 = _splsched();
    do {
    } while (_reaper_lock != 0);
    LOCK();
    UNLOCK();
LAB_00168594:
    piVar2 = _reaper_queue;
    _reaper_lock = 1;
    if ((int **)_reaper_queue != &_reaper_queue) {
      *(int ***)(*_reaper_queue + 4) = &_reaper_queue;
      piVar1 = (int *)*_reaper_queue;
      bVar6 = _reaper_queue != (int *)0x0;
      _reaper_queue = piVar1;
      if (bVar6) {
        LOCK();
        _reaper_lock = 0;
        UNLOCK();
        _splx(uVar3);
        if (_active_threads == piVar2) {
                    /* WARNING: Subroutine does not return */
          _panic(s_thread_dowait_001dfc69);
        }
        iVar5 = 0;
        uVar3 = _splsched();
        piVar1 = piVar2 + 8;
        do {
          do {
          } while (*piVar1 != 0);
          LOCK();
          iVar4 = *piVar1;
          *piVar1 = 1;
          UNLOCK();
        } while (iVar4 == 1);
        piVar1 = piVar2 + 8;
        do {
          switch(piVar2[0x13] & 0xf) {
          default:
            goto switchD_0016861e_caseD_2;
          case 6:
            iVar4 = _rem_runq(piVar2);
            if (iVar4 != 0) {
              piVar2[0x13] = piVar2[0x13] & 0xfffffffb;
              iVar5 = piVar2[0x12];
              piVar2[0x12] = 0;
              goto switchD_0016861e_caseD_2;
            }
          case 7:
          case 0xb:
          case 0xe:
          case 0xf:
            piVar2[0x12] = 1;
            _thread_sleep(piVar2 + 0x12,piVar1,1);
            do {
              do {
              } while (*piVar1 != 0);
              LOCK();
              iVar4 = *piVar1;
              *piVar1 = 1;
              UNLOCK();
            } while (iVar4 == 1);
          }
        } while( true );
      }
    }
    _assert_wait(&_reaper_queue,0);
    LOCK();
    _reaper_lock = 0;
    UNLOCK();
    _splx(uVar3);
    _thread_block_with_continuation(_reaper_thread_continue);
  } while( true );
switchD_0016861e_caseD_2:
  LOCK();
  piVar2[8] = 0;
  UNLOCK();
  _splx(uVar3);
  if (iVar5 != 0) {
    _thread_wakeup_prim(piVar2 + 0x12,0,0);
  }
  _thread_deallocate(piVar2);
  uVar3 = _splsched();
  do {
  } while (_reaper_lock != 0);
  LOCK();
  UNLOCK();
  goto LAB_00168594;
}


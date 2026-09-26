/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00167184 */

void _thread_deallocate_interrupt(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_1 != (undefined4 *)0x0) {
    uVar3 = _splsched();
    piVar1 = param_1 + 8;
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar2 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar2 == 1);
    iVar2 = param_1[9];
    param_1[9] = iVar2 + -1;
    if (iVar2 == 1 || iVar2 + -1 < 0) {
      param_1[9] = 1;
      do {
      } while (_reaper_lock != 0);
      LOCK();
      UNLOCK();
      *param_1 = &_reaper_queue;
      param_1[1] = DAT_001e979c;
      *(undefined4 **)param_1[1] = param_1;
      DAT_001e979c = param_1;
      LOCK();
      _reaper_lock = 0;
      UNLOCK();
      LOCK();
      param_1[8] = 0;
      UNLOCK();
      _splx(uVar3);
      _thread_wakeup_prim(&_reaper_queue,0,0);
    }
    else {
      LOCK();
      param_1[8] = 0;
      UNLOCK();
      _splx(uVar3);
    }
  }
  return;
}


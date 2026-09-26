/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00163498 */

int * _thread_select(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  *(undefined4 *)(param_1 + 0x124) = 1;
  piVar1 = _active_threads;
  if (0 < *(int *)(param_1 + 0x108)) {
    piVar1 = (int *)_choose_thread(param_1);
    iVar2 = _min_quantum;
    goto LAB_001635d3;
  }
  do {
  } while (DAT_001e9710 != 0);
  LOCK();
  DAT_001e9710 = 1;
  UNLOCK();
  if (DAT_001e9718 == 0) {
    if ((_active_threads[0x13] == 4) &&
       ((_active_threads[0x61] == 0 || (_active_threads[0x61] == param_1)))) {
      LOCK();
      DAT_001e9710 = 0;
      UNLOCK();
      piVar3 = _active_threads + 8;
      do {
        do {
        } while (*piVar3 != 0);
        LOCK();
        iVar2 = *piVar3;
        *piVar3 = 1;
        UNLOCK();
      } while (iVar2 == 1);
      if (piVar1[0x1c] != _sched_tick) {
        _update_priority(piVar1);
      }
      LOCK();
      piVar1[8] = 0;
      UNLOCK();
    }
    else {
LAB_0016355a:
      piVar1 = (int *)_choose_pset_thread(param_1,&_default_pset);
    }
  }
  else {
    piVar3 = (int *)(&_default_pset + DAT_001e9714 * 8);
    piVar1 = (int *)*piVar3;
    if (piVar3 == piVar1) {
      DAT_001e9714 = DAT_001e9714 + -1;
      goto LAB_0016355a;
    }
    if (piVar1 == piVar3) {
      piVar1 = (int *)0x0;
    }
    else {
      *(int **)(*piVar1 + 4) = piVar3;
      *piVar3 = *piVar1;
    }
    piVar1[2] = 0;
    if (((DAT_001e9718 != 1 && -1 < DAT_001e9718 + -1) && ((DAT_001e9778 & 2) != 0)) &&
       ((int *)*piVar3 == piVar3)) {
      do {
        DAT_001e9714 = DAT_001e9714 + -1;
        piVar3 = piVar3 + -2;
      } while ((int *)*piVar3 == piVar3);
    }
    LOCK();
    DAT_001e9710 = 0;
    UNLOCK();
    DAT_001e9718 = DAT_001e9718 + -1;
  }
  if (piVar1[0x18] != 2) {
    *(undefined4 *)(param_1 + 0x120) = DAT_001e977c;
    return piVar1;
  }
  iVar2 = piVar1[0x17];
LAB_001635d3:
  *(int *)(param_1 + 0x120) = iVar2;
  return piVar1;
}


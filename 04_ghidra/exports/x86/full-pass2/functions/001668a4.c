/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001668a4 */

undefined4 _task_suspend_nowait(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  
  if (param_1 == (int *)0x0) {
    uVar4 = 4;
  }
  else {
    do {
      do {
      } while (*param_1 != 0);
      LOCK();
      iVar1 = *param_1;
      *param_1 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    iVar1 = param_1[0x11];
    param_1[0x11] = iVar1 + 1;
    LOCK();
    *param_1 = 0;
    piVar3 = _active_threads;
    UNLOCK();
    if (iVar1 == 0) {
      do {
        do {
        } while (*param_1 != 0);
        LOCK();
        iVar1 = *param_1;
        *param_1 = 1;
        UNLOCK();
      } while (iVar1 == 1);
      if (param_1[2] == 0) {
        LOCK();
        *param_1 = 0;
        UNLOCK();
        return 5;
      }
      param_1[6] = param_1[6] + 1;
      for (piVar2 = (int *)param_1[7]; param_1 + 7 != piVar2; piVar2 = (int *)piVar2[4]) {
        if (piVar3 != piVar2) {
          _thread_hold(piVar2);
        }
      }
      LOCK();
      *param_1 = 0;
      UNLOCK();
      if ((int *)_active_threads[3] == param_1) {
        _thread_hold(_active_threads);
      }
    }
    uVar4 = 0;
  }
  return uVar4;
}


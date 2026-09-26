/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015b7d0 */

int _lock_read(int *param_1)

{
  int *piVar1;
  int *piVar2;
  byte bVar3;
  int iVar4;
  
  piVar1 = param_1 + 2;
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar4 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar4 == 1);
  if ((*param_1 != _active_threads) && ((*(byte *)((int)param_1 + 6) & 3) != 0)) {
    piVar1 = param_1 + 2;
    do {
      iVar4 = _lock_wait_time;
      if (0 < _lock_wait_time) {
        LOCK();
        param_1[2] = 0;
        UNLOCK();
        iVar4 = iVar4 + -1;
        if (0 < iVar4) {
          do {
            if ((*(byte *)((int)param_1 + 6) & 3) == 0) break;
            iVar4 = iVar4 + -1;
          } while (0 < iVar4);
        }
        piVar2 = param_1 + 2;
        do {
          do {
          } while (*piVar2 != 0);
          LOCK();
          iVar4 = *piVar2;
          *piVar2 = 1;
          UNLOCK();
        } while (iVar4 == 1);
      }
      bVar3 = *(byte *)((int)param_1 + 6);
      if ((bVar3 & 8) != 0) {
        if ((bVar3 & 3) == 0) break;
        *(byte *)((int)param_1 + 6) = bVar3 | 4;
        _thread_sleep(param_1,piVar1,0);
        do {
          do {
          } while (*piVar1 != 0);
          LOCK();
          iVar4 = *piVar1;
          *piVar1 = 1;
          UNLOCK();
        } while (iVar4 == 1);
      }
    } while ((*(byte *)((int)param_1 + 6) & 3) != 0);
  }
  *(short *)(param_1 + 1) = (short)param_1[1] + 1;
  LOCK();
  iVar4 = param_1[2];
  param_1[2] = 0;
  UNLOCK();
  return iVar4;
}


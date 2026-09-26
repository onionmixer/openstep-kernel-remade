/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015b5d0 */

int _lock_write(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  piVar1 = param_1 + 2;
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar3 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar3 == 1);
  if (*param_1 == _active_threads) {
    *(ushort *)((int)param_1 + 6) =
         *(ushort *)((int)param_1 + 6) & 0xf | (*(ushort *)((int)param_1 + 6) & 0xfff0) + 0x10;
  }
  else {
    if ((*(byte *)((int)param_1 + 6) & 2) != 0) {
      piVar1 = param_1 + 2;
      do {
        iVar3 = _lock_wait_time;
        if (0 < _lock_wait_time) {
          LOCK();
          param_1[2] = 0;
          UNLOCK();
          iVar3 = iVar3 + -1;
          if (0 < iVar3) {
            do {
              if ((*(byte *)((int)param_1 + 6) & 2) == 0) break;
              iVar3 = iVar3 + -1;
            } while (0 < iVar3);
          }
          piVar2 = param_1 + 2;
          do {
            do {
            } while (*piVar2 != 0);
            LOCK();
            iVar3 = *piVar2;
            *piVar2 = 1;
            UNLOCK();
          } while (iVar3 == 1);
        }
        if ((*(byte *)((int)param_1 + 6) & 10) == 10) {
          *(byte *)((int)param_1 + 6) = *(byte *)((int)param_1 + 6) | 4;
          _thread_sleep(param_1,piVar1,0);
          do {
            do {
            } while (*piVar1 != 0);
            LOCK();
            iVar3 = *piVar1;
            *piVar1 = 1;
            UNLOCK();
          } while (iVar3 == 1);
        }
      } while ((*(byte *)((int)param_1 + 6) & 2) != 0);
    }
    *(byte *)((int)param_1 + 6) = *(byte *)((int)param_1 + 6) | 2;
    if ((param_1[1] & 0x1ffffU) != 0) {
      piVar1 = param_1 + 2;
      do {
        iVar3 = _lock_wait_time;
        if (0 < _lock_wait_time) {
          LOCK();
          param_1[2] = 0;
          UNLOCK();
          iVar3 = iVar3 + -1;
          if (0 < iVar3) {
            do {
              if ((param_1[1] & 0x1ffffU) == 0) break;
              iVar3 = iVar3 + -1;
            } while (0 < iVar3);
          }
          piVar2 = param_1 + 2;
          do {
            do {
            } while (*piVar2 != 0);
            LOCK();
            iVar3 = *piVar2;
            *piVar2 = 1;
            UNLOCK();
          } while (iVar3 == 1);
        }
        if ((*(byte *)((int)param_1 + 6) & 8) != 0) {
          if ((param_1[1] & 0x1ffffU) == 0) break;
          *(byte *)((int)param_1 + 6) = *(byte *)((int)param_1 + 6) | 4;
          _thread_sleep(param_1,piVar1,0);
          do {
            do {
            } while (*piVar1 != 0);
            LOCK();
            iVar3 = *piVar1;
            *piVar1 = 1;
            UNLOCK();
          } while (iVar3 == 1);
        }
      } while ((param_1[1] & 0x1ffffU) != 0);
    }
  }
  LOCK();
  iVar3 = param_1[2];
  param_1[2] = 0;
  UNLOCK();
  return iVar3;
}


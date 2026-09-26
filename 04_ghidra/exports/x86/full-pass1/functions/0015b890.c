/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015b890 */

undefined4 _lock_read_to_write(int *param_1)

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
  *(short *)(param_1 + 1) = (short)param_1[1] + -1;
  if (*param_1 == _active_threads) {
    *(ushort *)((int)param_1 + 6) =
         *(ushort *)((int)param_1 + 6) & 0xf | (*(ushort *)((int)param_1 + 6) & 0xfff0) + 0x10;
  }
  else {
    bVar3 = *(byte *)((int)param_1 + 6);
    if ((bVar3 & 1) != 0) {
      if ((param_1[1] & 0x4ffffU) == 0x40000) {
        *(byte *)((int)param_1 + 6) = bVar3 & 0xfb;
        _thread_wakeup_prim(param_1,0,0);
      }
      LOCK();
      param_1[2] = 0;
      UNLOCK();
      return 1;
    }
    *(byte *)((int)param_1 + 6) = bVar3 | 1;
    if ((short)param_1[1] != 0) {
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
              if ((short)param_1[1] == 0) break;
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
        if ((*(byte *)((int)param_1 + 6) & 8) != 0) {
          if ((short)param_1[1] == 0) break;
          *(byte *)((int)param_1 + 6) = *(byte *)((int)param_1 + 6) | 4;
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
      } while ((short)param_1[1] != 0);
    }
  }
  LOCK();
  param_1[2] = 0;
  UNLOCK();
  return 0;
}


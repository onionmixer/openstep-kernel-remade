/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c0944 */

void FUN_001c0944(int param_1)

{
  int iVar1;
  int *piVar2;
  char cVar3;
  int *piVar4;
  int *piVar5;
  
  cVar3 = _objc_msgSend(param_1,PTR_s_isEISAPresent_001f9784);
  if (cVar3 != '\0') {
    return;
  }
  if (_dmaLockDisable != 0) {
    return;
  }
  piVar4 = (int *)_IOMalloc(0xc);
  piVar4[1] = 1;
  *piVar4 = param_1;
  piVar4[2] = 0;
  piVar5 = DAT_001e8728;
  do {
    do {
    } while (*piVar5 != 0);
    LOCK();
    iVar1 = *piVar5;
    *piVar5 = 1;
    UNLOCK();
  } while (iVar1 == 1);
  piVar5 = piVar4;
  piVar2 = piVar4;
  if (DAT_001e871c != (int *)0x0) {
    piVar5 = DAT_001e871c;
    if ((*DAT_001e871c == param_1) && (DAT_001e871c[2] == 0)) {
      DAT_001e871c[1] = DAT_001e871c[1] + 1;
    }
    else {
      do {
        piVar5 = (int *)piVar5[2];
        if (piVar5 == (int *)0x0) {
          *(int **)((int)DAT_001e8720 + 8) = piVar4;
          DAT_001e8720 = piVar4;
          while (piVar5 = DAT_001e871c, piVar2 = DAT_001e8720, DAT_001e871c != piVar4) {
            _thread_sleep(&DAT_001e8724,DAT_001e8728,0);
            piVar5 = DAT_001e8728;
            do {
              do {
              } while (*piVar5 != 0);
              LOCK();
              iVar1 = *piVar5;
              *piVar5 = 1;
              UNLOCK();
            } while (iVar1 == 1);
          }
          goto LAB_001c0a8c;
        }
      } while (*piVar5 != param_1);
      piVar5[1] = piVar5[1] + 1;
      while (DAT_001e871c != piVar5) {
        _thread_sleep(&DAT_001e8724,DAT_001e8728,0);
        piVar2 = DAT_001e8728;
        do {
          do {
          } while (*piVar2 != 0);
          LOCK();
          iVar1 = *piVar2;
          *piVar2 = 1;
          UNLOCK();
        } while (iVar1 == 1);
      }
    }
    LOCK();
    *DAT_001e8728 = 0;
    UNLOCK();
    _IOFree(piVar4,0xc);
    return;
  }
LAB_001c0a8c:
  DAT_001e8720 = piVar2;
  DAT_001e871c = piVar5;
  LOCK();
  *DAT_001e8728 = 0;
  UNLOCK();
  return;
}


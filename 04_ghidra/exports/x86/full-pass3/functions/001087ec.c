/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001087ec */

int _donice(int param_1,int param_2)

{
  short sVar1;
  short sVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  iVar6 = DAT_001e875c;
  sVar1 = *(short *)(*(int *)(_active_u + 0x1c) + 2);
  if ((((sVar1 == 0) || (sVar2 = *(short *)(*(int *)(_active_u + 0x1c) + 6), sVar2 == 0)) ||
      (sVar1 == *(short *)(param_1 + 0x2c))) || (sVar2 == *(short *)(param_1 + 0x2c))) {
    if (0x14 < param_2) {
      param_2 = 0x14;
    }
    if (param_2 < -0x14) {
      param_2 = -0x14;
    }
    if ((param_2 < *(char *)(param_1 + 0x15)) &&
       (iVar4 = _suser(), iVar6 = DAT_001e875c, iVar4 == 0)) {
      *(undefined1 *)(DAT_001e875c + 0x68) = 0xd;
      return iVar6;
    }
    piVar3 = *(int **)(param_1 + 0x68);
    iVar6 = ((int)((char)(*(char *)(param_1 + 0x15) - (*(char *)(param_1 + 0x15) >> 7)) >> 1) +
            piVar3[0x12]) - param_2 / 2;
    *(char *)(param_1 + 0x15) = (char)param_2;
    _task_priority(piVar3,iVar6,0);
    do {
      do {
      } while (*piVar3 != 0);
      LOCK();
      iVar4 = *piVar3;
      *piVar3 = 1;
      UNLOCK();
    } while (iVar4 == 1);
    for (piVar5 = (int *)piVar3[7]; piVar3 + 7 != piVar5; piVar5 = (int *)piVar5[4]) {
      if (piVar5[0x15] < iVar6) {
        _thread_max_priority(piVar5,piVar5[0x60],iVar6);
      }
      iVar4 = _thread_priority(piVar5,iVar6,1);
      if (iVar4 != 0) {
        *(undefined1 *)(DAT_001e875c + 0x68) = 1;
        break;
      }
    }
    LOCK();
    iVar6 = *piVar3;
    *piVar3 = 0;
    UNLOCK();
  }
  else {
    *(undefined1 *)(DAT_001e875c + 0x68) = 1;
  }
  return iVar6;
}


/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010a094 */

int _psig(void)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int local_8;
  
  iVar4 = *_active_u;
  if (_master_cpu != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_psig_not_on_master_001daa10);
  }
  piVar1 = (int *)(iVar4 + 0x70);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar5 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar5 == 1);
  while ((*(int *)(iVar4 + 0x74) != 0 || (*(int *)(iVar4 + 0x78) != 0))) {
    piVar1 = (int *)(iVar4 + 0x70);
    LOCK();
    *(undefined4 *)(iVar4 + 0x70) = 0;
    UNLOCK();
    if (*(int *)(iVar4 + 0x78) != 0) {
      if (_active_threads == *(int *)(iVar4 + 0x78)) {
        return _active_threads;
      }
      _thread_hold(_active_threads);
    }
    _thread_block();
    if ((*(byte *)(_active_threads + 0x17c) & 3) != 0) {
      return _active_threads;
    }
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar5 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar5 == 1);
  }
  cVar2 = *(char *)(iVar4 + 0x17);
  iVar5 = (int)cVar2;
  uVar6 = 1 << (cVar2 - 1U & 0x1f);
  if ((iVar5 != 0) && (((uVar6 & 0x1ef8) == 0 || (iVar5 == *(char *)(DAT_001e875c + 0x78))))) {
    if (*(char *)(DAT_001e875c + 0x70) < '\0') {
      _rpcont();
    }
    iVar3 = _active_u[iVar5 + 0xc];
    if (iVar3 != 0) {
      if ((iVar3 == 1) || ((*(uint *)(iVar4 + 0x1c) & uVar6) != 0)) {
        _log(4,s_psig__processing_masked_or_ignor_001daa23);
      }
      *(undefined1 *)(DAT_001e875c + 0x68) = 0;
      _splhigh();
      if ((*(byte *)(iVar4 + 0x2a) & 0x10) != 0) {
        if (1 < iVar5 - 4U) {
          _active_u[iVar5 + 0xc] = 0;
          *(uint *)(iVar4 + 0x24) = *(uint *)(iVar4 + 0x24) & ~uVar6;
        }
        uVar6 = 0;
      }
      if ((*(uint *)(iVar4 + 0x28) & 0x200) == 0) {
        local_8 = *(int *)(iVar4 + 0x1c);
      }
      else {
        local_8 = _active_u[0x51];
        *(uint *)(iVar4 + 0x28) = *(uint *)(iVar4 + 0x28) & 0xfffffdff;
      }
      *(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) | _active_u[iVar5 + 0x2d] | uVar6;
      *(undefined1 *)(iVar4 + 0x17) = 0;
      if ((0x1ef8 >> (cVar2 - 1U & 0x1f) & 1U) != 0) {
        *(undefined1 *)(DAT_001e875c + 0x78) = 0;
      }
      LOCK();
      *(undefined4 *)(iVar4 + 0x70) = 0;
      UNLOCK();
      _spl0();
      _active_u[0x6b] = _active_u[0x6b] + 1;
      iVar4 = _sendsig(iVar3,iVar5,local_8);
      return iVar4;
    }
    *(byte *)(_active_u + 0x91) = *(byte *)(_active_u + 0x91) | 0x10;
    switch(iVar5) {
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 10:
    case 0xb:
    case 0xc:
      *(int *)(DAT_001e875c + 4) = iVar5;
      *(int *)(iVar4 + 0x78) = _active_threads;
      LOCK();
      *(undefined4 *)(iVar4 + 0x70) = 0;
      UNLOCK();
      _task_hold(*(undefined4 *)(_active_threads + 0xc));
      _task_dowait(*(undefined4 *)(_active_threads + 0xc),0);
      iVar4 = _core();
      if (iVar4 != 0) {
        iVar5 = iVar5 + 0x80;
      }
      break;
    default:
      *(int *)(iVar4 + 0x78) = _active_threads;
      LOCK();
      *(undefined4 *)(iVar4 + 0x70) = 0;
      UNLOCK();
      _task_hold(*(undefined4 *)(_active_threads + 0xc));
      _task_dowait(*(undefined4 *)(_active_threads + 0xc),0);
      break;
    case 0x11:
    case 0x12:
    case 0x15:
    case 0x16:
      goto switchD_0010a263_caseD_11;
    }
                    /* WARNING: Subroutine does not return */
    _exit(iVar5);
  }
switchD_0010a263_caseD_11:
  LOCK();
  iVar5 = *(int *)(iVar4 + 0x70);
  *(int *)(iVar4 + 0x70) = 0;
  UNLOCK();
  return iVar5;
}


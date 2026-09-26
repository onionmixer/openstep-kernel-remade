/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010a0b7 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

int __analysis_fragment_0010a0b7(void)

{
  int *piVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int unaff_EBX;
  int unaff_EBP;
  int iVar6;
  uint uVar7;
  
  piVar1 = (int *)(unaff_EBX + 0x70);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar6 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar6 == 1);
  while ((*(int *)(unaff_EBX + 0x74) != 0 || (*(int *)(unaff_EBX + 0x78) != 0))) {
    piVar1 = (int *)(unaff_EBX + 0x70);
    LOCK();
    *(undefined4 *)(unaff_EBX + 0x70) = 0;
    UNLOCK();
    if (*(int *)(unaff_EBX + 0x78) != 0) {
      if (_active_threads == *(int *)(unaff_EBX + 0x78)) {
        return _active_threads;
      }
      _thread_hold();
    }
    _thread_block();
    if ((*(byte *)(_active_threads + 0x17c) & 3) != 0) {
      return _active_threads;
    }
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar6 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar6 == 1);
  }
  cVar2 = *(char *)(unaff_EBX + 0x17);
  iVar6 = (int)cVar2;
  uVar7 = 1 << (cVar2 - 1U & 0x1f);
  if ((iVar6 != 0) && (((uVar7 & 0x1ef8) == 0 || (iVar6 == *(char *)(DAT_001e875c + 0x78))))) {
    if (*(char *)(DAT_001e875c + 0x70) < '\0') {
      _rpcont();
    }
    iVar4 = _active_u;
    iVar5 = *(int *)(_active_u + 0x30 + iVar6 * 4);
    *(int *)(unaff_EBP + -8) = iVar5;
    if (iVar5 != 0) {
      if ((iVar5 == 1) || ((*(uint *)(unaff_EBX + 0x1c) & uVar7) != 0)) {
        _log(4);
      }
      *(undefined1 *)(DAT_001e875c + 0x68) = 0;
      _splhigh();
      if ((*(byte *)(unaff_EBX + 0x2a) & 0x10) != 0) {
        if (1 < iVar6 - 4U) {
          *(undefined4 *)(_active_u + 0x30 + iVar6 * 4) = 0;
          *(uint *)(unaff_EBX + 0x24) = *(uint *)(unaff_EBX + 0x24) & ~uVar7;
        }
        uVar7 = 0;
      }
      uVar3 = *(uint *)(unaff_EBX + 0x28);
      if ((uVar3 & 0x200) == 0) {
        *(undefined4 *)(unaff_EBP + -4) = *(undefined4 *)(unaff_EBX + 0x1c);
      }
      else {
        *(undefined4 *)(unaff_EBP + -4) = *(undefined4 *)(_active_u + 0x144);
        *(uint *)(unaff_EBX + 0x28) = uVar3 & 0xfffffdff;
      }
      *(uint *)(unaff_EBX + 0x1c) =
           *(uint *)(unaff_EBX + 0x1c) | *(uint *)(_active_u + 0xb4 + iVar6 * 4) | uVar7;
      *(undefined1 *)(unaff_EBX + 0x17) = 0;
      if ((0x1ef8 >> (cVar2 - 1U & 0x1f) & 1U) != 0) {
        *(undefined1 *)(DAT_001e875c + 0x78) = 0;
      }
      LOCK();
      *(undefined4 *)(unaff_EBX + 0x70) = 0;
      UNLOCK();
      _spl0();
      *(int *)(_active_u + 0x1ac) = *(int *)(_active_u + 0x1ac) + 1;
      iVar6 = _sendsig(*(undefined4 *)(unaff_EBP + -8),iVar6);
      return iVar6;
    }
    *(byte *)(iVar4 + 0x244) = *(byte *)(iVar4 + 0x244) | 0x10;
    switch(iVar6) {
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 10:
    case 0xb:
    case 0xc:
      *(int *)(DAT_001e875c + 4) = iVar6;
      *(int *)(unaff_EBX + 0x78) = _active_threads;
      LOCK();
      *(undefined4 *)(unaff_EBX + 0x70) = 0;
      UNLOCK();
      _task_hold();
      _task_dowait(*(undefined4 *)(_active_threads + 0xc),0);
      iVar5 = _core();
      if (iVar5 != 0) {
        iVar6 = iVar6 + 0x80;
      }
      break;
    default:
      *(int *)(unaff_EBX + 0x78) = _active_threads;
      LOCK();
      *(undefined4 *)(unaff_EBX + 0x70) = 0;
      UNLOCK();
      _task_hold();
      _task_dowait(*(undefined4 *)(_active_threads + 0xc),0);
      break;
    case 0x11:
    case 0x12:
    case 0x15:
    case 0x16:
      goto switchD_0010a263_caseD_11;
    }
                    /* WARNING: Subroutine does not return */
    _exit(iVar6);
  }
switchD_0010a263_caseD_11:
  LOCK();
  iVar6 = *(int *)(unaff_EBX + 0x70);
  *(int *)(unaff_EBX + 0x70) = 0;
  UNLOCK();
  return iVar6;
}


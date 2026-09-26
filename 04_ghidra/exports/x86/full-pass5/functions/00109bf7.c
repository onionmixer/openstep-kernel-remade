/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00109bf7 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_00109bf7(void)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int unaff_EBP;
  undefined4 *puVar7;
  uint unaff_EDI;
  undefined4 *puVar8;
  
  piVar1 = (int *)(unaff_EDI + 0x70);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar5 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar5 == 1);
  while ((*(int *)(unaff_EDI + 0x74) != 0 || (*(int *)(unaff_EDI + 0x78) != 0))) {
    LOCK();
    *(undefined4 *)(unaff_EDI + 0x70) = 0;
    UNLOCK();
    if (*(int *)(unaff_EDI + 0x78) != 0) {
      if (_active_threads == *(int *)(unaff_EDI + 0x78)) {
        return 0;
      }
      _thread_hold();
    }
    _thread_block();
    if ((*(byte *)(_active_threads + 0x17c) & 3) != 0) {
      return 1;
    }
    piVar1 = (int *)(unaff_EDI + 0x70);
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar5 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar5 == 1);
  }
switchD_00109f5b_caseD_10:
  if (*(char *)(DAT_001e875c + 0x78) != '\0') {
    *(uint *)(DAT_001e875c + 0x7c) =
         *(uint *)(DAT_001e875c + 0x7c) | 1 << (*(char *)(DAT_001e875c + 0x78) - 1U & 0x1f);
    *(undefined1 *)(DAT_001e875c + 0x78) = 0;
  }
  iVar5 = DAT_001e875c;
  uVar6 = (*(uint *)(DAT_001e875c + 0x7c) | *(uint *)(unaff_EDI + 0x18)) &
          ~*(uint *)(unaff_EDI + 0x1c);
  uVar4 = *(uint *)(unaff_EDI + 0x28);
  *(uint *)(unaff_EBP + -0x40) = uVar4;
  uVar4 = uVar4 & 0x10;
  *(uint *)(unaff_EBP + -0x44) = uVar4;
  if (uVar4 == 0) {
    uVar6 = uVar6 & ~*(uint *)(unaff_EDI + 0x20);
  }
  if ((*(uint *)(unaff_EBP + -0x40) & 0x1000) != 0) {
    uVar6 = uVar6 & 0xffccffff;
  }
  if (uVar6 == 0) {
    *(undefined1 *)(unaff_EDI + 0x17) = 0;
    *(undefined1 *)(DAT_001e875c + 0x78) = 0;
    LOCK();
    *(undefined4 *)(unaff_EDI + 0x70) = 0;
    UNLOCK();
    return 0;
  }
  if ((*(int *)(unaff_EBP + 8) != 0) && (*(int *)(unaff_EBP + -0x44) != 0)) goto LAB_0010a04c;
  iVar3 = 0;
  if (uVar6 != 0) {
    for (; (uVar6 >> iVar3 & 1) == 0; iVar3 = iVar3 + 1) {
    }
  }
  if (uVar6 == 0) {
    iVar3 = -1;
  }
  *(int *)(unaff_EBP + -0x44) = iVar3 + 1;
  uVar4 = 1 << ((byte)iVar3 & 0x1f);
  *(uint *)(unaff_EBP + -0x3c) = uVar4;
  if ((uVar4 & 0x1ef8) != 0) {
    *(undefined1 *)(iVar5 + 0x78) = *(undefined1 *)(unaff_EBP + -0x44);
    *(uint *)(DAT_001e875c + 0x7c) = *(uint *)(DAT_001e875c + 0x7c) & ~*(uint *)(unaff_EBP + -0x3c);
  }
  *(uint *)(unaff_EDI + 0x18) = *(uint *)(unaff_EDI + 0x18) & ~*(uint *)(unaff_EBP + -0x3c);
  *(undefined1 *)(unaff_EDI + 0x17) = *(undefined1 *)(unaff_EBP + -0x44);
  if ((*(uint *)(unaff_EDI + 0x28) & 0x1010) == 0x10) {
    _psignal(*(uint *)(unaff_EDI + 0x44),(char *)0x14);
    iVar5 = _active_threads;
    *(int *)(unaff_EDI + 0x6c) = _active_threads;
    _pcb_synch(iVar5);
    piVar1 = *(int **)(unaff_EDI + 0x68);
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar5 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar5 == 1);
    iVar5 = piVar1[0x11];
    piVar1[0x11] = iVar5 + 1;
    LOCK();
    *piVar1 = 0;
    UNLOCK();
    if (iVar5 == 0) {
      _task_hold();
      *(undefined4 *)(unaff_EDI + 0x74) = 1;
      LOCK();
      *(undefined4 *)(unaff_EDI + 0x70) = 0;
      UNLOCK();
      _task_dowait(piVar1);
      _thread_hold(_active_threads);
    }
    else {
      *(undefined4 *)(unaff_EDI + 0x74) = 1;
      LOCK();
      *(undefined4 *)(unaff_EDI + 0x70) = 0;
      UNLOCK();
    }
    *(undefined1 *)(unaff_EDI + 0x13) = 6;
    *(uint *)(unaff_EDI + 0x28) = *(uint *)(unaff_EDI + 0x28) & 0xffffffdf;
    _wakeup();
    _thread_block();
    piVar1 = (int *)(unaff_EDI + 0x70);
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar5 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar5 == 1);
    *(undefined4 *)(unaff_EDI + 0x74) = 0;
    cVar2 = *(char *)(unaff_EDI + 0x17);
    if (' ' < cVar2) {
      *(int *)(unaff_EBP + -0x44) = cVar2 + -0x20;
      _clear_wait(_active_threads,2);
      *(int *)(unaff_EDI + 0x78) = _active_threads;
      LOCK();
      *(undefined4 *)(unaff_EDI + 0x70) = 0;
      UNLOCK();
      _task_hold();
      _task_dowait(*(undefined4 *)(_active_threads + 0xc),0);
      puVar7 = (undefined4 *)(DAT_001e875c + 0x28);
      puVar8 = (undefined4 *)(unaff_EBP + -0x38);
      for (iVar5 = 0xe; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar8 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar8 = puVar8 + 1;
      }
                    /* WARNING: Subroutine does not return */
      _exit(*(int *)(unaff_EBP + -0x44));
    }
    if ((*(byte *)(_active_threads + 0x17c) & 3) != 0) goto LAB_0010a04c;
    if ((*(byte *)(unaff_EDI + 0x28) & 0x10) == 0) {
      if ((*(uint *)(unaff_EBP + -0x3c) & 0x1ef8) == 0) {
        *(uint *)(unaff_EDI + 0x18) = *(uint *)(unaff_EDI + 0x18) | *(uint *)(unaff_EBP + -0x3c);
      }
      else {
        *(uint *)(DAT_001e875c + 0x7c) =
             *(uint *)(DAT_001e875c + 0x7c) | *(uint *)(unaff_EBP + -0x3c);
      }
      goto switchD_00109f5b_caseD_10;
    }
    *(int *)(unaff_EBP + -0x44) = (int)cVar2;
    if (cVar2 == 0) goto switchD_00109f5b_caseD_10;
    uVar4 = 1 << (cVar2 - 1U & 0x1f);
    *(uint *)(unaff_EBP + -0x3c) = uVar4;
    if ((*(uint *)(unaff_EDI + 0x1c) & uVar4) != 0) {
      if ((uVar4 & 0x1ef8) == 0) {
        *(uint *)(unaff_EDI + 0x18) = *(uint *)(unaff_EDI + 0x18) | *(uint *)(unaff_EBP + -0x3c);
      }
      else {
        *(uint *)(DAT_001e875c + 0x7c) = *(uint *)(DAT_001e875c + 0x7c) | uVar4;
      }
      goto switchD_00109f5b_caseD_10;
    }
  }
  iVar5 = *(int *)(_active_u + 0x30 + *(int *)(unaff_EBP + -0x44) * 4);
  if (iVar5 != 1) {
    if (1 < iVar5) {
      if (iVar5 == 3) goto LAB_0010a018;
      goto switchD_00109f5b_caseD_18;
    }
    if (iVar5 != 0) goto switchD_00109f5b_caseD_18;
    if (*(short *)(unaff_EDI + 0x32) == 0) {
      *(undefined1 *)(DAT_001e875c + 0x78) = 0;
      *(uint *)(DAT_001e875c + 0x7c) =
           *(uint *)(DAT_001e875c + 0x7c) & ~*(uint *)(unaff_EBP + -0x3c);
      goto switchD_00109f5b_caseD_10;
    }
    switch(*(undefined4 *)(unaff_EBP + -0x44)) {
    case 0x10:
    case 0x13:
    case 0x14:
    case 0x17:
    case 0x1c:
      goto switchD_00109f5b_caseD_10;
    case 0x12:
    case 0x15:
    case 0x16:
      if (*(int *)(unaff_EDI + 0x44) == _init_proc) {
        _psignal(unaff_EDI,(char *)0x9);
        goto switchD_00109f5b_caseD_10;
      }
    case 0x11:
      if ((*(byte *)(unaff_EDI + 0x28) & 0x10) == 0) {
        _psignal(*(uint *)(unaff_EDI + 0x44),(char *)0x14);
        _stop();
        *(undefined4 *)(unaff_EDI + 0x74) = 1;
        LOCK();
        *(undefined4 *)(unaff_EDI + 0x70) = 0;
        UNLOCK();
        _thread_block();
        piVar1 = (int *)(unaff_EDI + 0x70);
        do {
          do {
          } while (*piVar1 != 0);
          LOCK();
          iVar5 = *piVar1;
          *piVar1 = 1;
          UNLOCK();
        } while (iVar5 == 1);
        *(undefined4 *)(unaff_EDI + 0x74) = 0;
        if ((*(byte *)(_active_threads + 0x17c) & 3) != 0) {
LAB_0010a04c:
          LOCK();
          *(undefined4 *)(unaff_EDI + 0x70) = 0;
          UNLOCK();
          return 1;
        }
      }
      goto switchD_00109f5b_caseD_10;
    default:
switchD_00109f5b_caseD_18:
      LOCK();
      *(undefined4 *)(unaff_EDI + 0x70) = 0;
      UNLOCK();
      return *(undefined4 *)(unaff_EBP + -0x44);
    }
  }
LAB_0010a018:
  if ((*(byte *)(unaff_EDI + 0x28) & 0x10) == 0) {
    _printf(s_issig_001daa09);
  }
  goto switchD_00109f5b_caseD_10;
}


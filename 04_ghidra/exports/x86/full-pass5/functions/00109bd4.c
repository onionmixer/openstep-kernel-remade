/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00109bd4 */

int _issig(int param_1)

{
  int *piVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int local_48;
  uint local_40;
  undefined4 local_3c [14];
  
  uVar3 = *_active_u;
  if (_master_cpu != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_issig_not_on_master_001da9f5);
  }
  piVar1 = (int *)(uVar3 + 0x70);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar4 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar4 == 1);
  while ((*(int *)(uVar3 + 0x74) != 0 || (*(int *)(uVar3 + 0x78) != 0))) {
    LOCK();
    *(undefined4 *)(uVar3 + 0x70) = 0;
    UNLOCK();
    if (*(int *)(uVar3 + 0x78) != 0) {
      if (_active_threads == *(int *)(uVar3 + 0x78)) {
        return 0;
      }
      _thread_hold(_active_threads);
    }
    _thread_block();
    if ((*(byte *)(_active_threads + 0x17c) & 3) != 0) {
      return 1;
    }
    piVar1 = (int *)(uVar3 + 0x70);
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar4 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar4 == 1);
  }
switchD_00109f5b_caseD_10:
  if (*(char *)(DAT_001e875c + 0x78) != '\0') {
    *(uint *)(DAT_001e875c + 0x7c) =
         *(uint *)(DAT_001e875c + 0x7c) | 1 << (*(char *)(DAT_001e875c + 0x78) - 1U & 0x1f);
    *(undefined1 *)(DAT_001e875c + 0x78) = 0;
  }
  uVar6 = (*(uint *)(DAT_001e875c + 0x7c) | *(uint *)(uVar3 + 0x18)) & ~*(uint *)(uVar3 + 0x1c);
  uVar5 = *(uint *)(uVar3 + 0x28) & 0x10;
  if (uVar5 == 0) {
    uVar6 = uVar6 & ~*(uint *)(uVar3 + 0x20);
  }
  if ((*(uint *)(uVar3 + 0x28) & 0x1000) != 0) {
    uVar6 = uVar6 & 0xffccffff;
  }
  if (uVar6 == 0) {
    *(undefined1 *)(uVar3 + 0x17) = 0;
    *(undefined1 *)(DAT_001e875c + 0x78) = 0;
    LOCK();
    *(undefined4 *)(uVar3 + 0x70) = 0;
    UNLOCK();
    return 0;
  }
  if ((param_1 != 0) && (uVar5 != 0)) goto LAB_0010a04c;
  iVar4 = 0;
  if (uVar6 != 0) {
    for (; (uVar6 >> iVar4 & 1) == 0; iVar4 = iVar4 + 1) {
    }
  }
  if (uVar6 == 0) {
    iVar4 = -1;
  }
  local_48 = iVar4 + 1;
  local_40 = 1 << ((byte)iVar4 & 0x1f);
  if ((local_40 & 0x1ef8) != 0) {
    *(undefined1 *)(DAT_001e875c + 0x78) = (undefined1)local_48;
    *(uint *)(DAT_001e875c + 0x7c) = *(uint *)(DAT_001e875c + 0x7c) & ~local_40;
  }
  *(uint *)(uVar3 + 0x18) = *(uint *)(uVar3 + 0x18) & ~local_40;
  *(undefined1 *)(uVar3 + 0x17) = (undefined1)local_48;
  if ((*(uint *)(uVar3 + 0x28) & 0x1010) == 0x10) {
    _psignal(*(uint *)(uVar3 + 0x44),(char *)0x14);
    iVar4 = _active_threads;
    *(int *)(uVar3 + 0x6c) = _active_threads;
    _pcb_synch(iVar4);
    piVar1 = *(int **)(uVar3 + 0x68);
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar4 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar4 == 1);
    iVar4 = piVar1[0x11];
    piVar1[0x11] = iVar4 + 1;
    LOCK();
    *piVar1 = 0;
    UNLOCK();
    if (iVar4 == 0) {
      _task_hold(piVar1);
      *(undefined4 *)(uVar3 + 0x74) = 1;
      LOCK();
      *(undefined4 *)(uVar3 + 0x70) = 0;
      UNLOCK();
      _task_dowait(piVar1,1);
      _thread_hold(_active_threads);
    }
    else {
      *(undefined4 *)(uVar3 + 0x74) = 1;
      LOCK();
      *(undefined4 *)(uVar3 + 0x70) = 0;
      UNLOCK();
    }
    *(undefined1 *)(uVar3 + 0x13) = 6;
    *(uint *)(uVar3 + 0x28) = *(uint *)(uVar3 + 0x28) & 0xffffffdf;
    _wakeup(*(undefined4 *)(uVar3 + 0x44));
    _thread_block();
    piVar1 = (int *)(uVar3 + 0x70);
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar4 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar4 == 1);
    *(undefined4 *)(uVar3 + 0x74) = 0;
    cVar2 = *(char *)(uVar3 + 0x17);
    if (' ' < cVar2) {
      _clear_wait(_active_threads,2,0);
      *(int *)(uVar3 + 0x78) = _active_threads;
      LOCK();
      *(undefined4 *)(uVar3 + 0x70) = 0;
      UNLOCK();
      _task_hold(*(undefined4 *)(_active_threads + 0xc));
      _task_dowait(*(undefined4 *)(_active_threads + 0xc),0);
      puVar7 = (undefined4 *)(DAT_001e875c + 0x28);
      puVar8 = local_3c;
      for (iVar4 = 0xe; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar8 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar8 = puVar8 + 1;
      }
                    /* WARNING: Subroutine does not return */
      _exit(cVar2 + -0x20);
    }
    if ((*(byte *)(_active_threads + 0x17c) & 3) != 0) goto LAB_0010a04c;
    if ((*(byte *)(uVar3 + 0x28) & 0x10) == 0) {
      if ((local_40 & 0x1ef8) == 0) {
        *(uint *)(uVar3 + 0x18) = *(uint *)(uVar3 + 0x18) | local_40;
      }
      else {
        *(uint *)(DAT_001e875c + 0x7c) = *(uint *)(DAT_001e875c + 0x7c) | local_40;
      }
      goto switchD_00109f5b_caseD_10;
    }
    local_48 = (int)cVar2;
    if (local_48 == 0) goto switchD_00109f5b_caseD_10;
    local_40 = 1 << (cVar2 - 1U & 0x1f);
    if ((*(uint *)(uVar3 + 0x1c) & local_40) != 0) {
      if ((local_40 & 0x1ef8) == 0) {
        *(uint *)(uVar3 + 0x18) = *(uint *)(uVar3 + 0x18) | local_40;
      }
      else {
        *(uint *)(DAT_001e875c + 0x7c) = *(uint *)(DAT_001e875c + 0x7c) | local_40;
      }
      goto switchD_00109f5b_caseD_10;
    }
  }
  uVar5 = _active_u[local_48 + 0xc];
  if (uVar5 != 1) {
    if (1 < (int)uVar5) {
      if (uVar5 == 3) goto LAB_0010a018;
      goto switchD_00109f5b_caseD_18;
    }
    if (uVar5 != 0) goto switchD_00109f5b_caseD_18;
    if (*(short *)(uVar3 + 0x32) == 0) {
      *(undefined1 *)(DAT_001e875c + 0x78) = 0;
      *(uint *)(DAT_001e875c + 0x7c) = *(uint *)(DAT_001e875c + 0x7c) & ~local_40;
      goto switchD_00109f5b_caseD_10;
    }
    switch(local_48) {
    case 0x10:
    case 0x13:
    case 0x14:
    case 0x17:
    case 0x1c:
      goto switchD_00109f5b_caseD_10;
    case 0x12:
    case 0x15:
    case 0x16:
      if (*(int *)(uVar3 + 0x44) == _init_proc) {
        _psignal(uVar3,(char *)0x9);
        goto switchD_00109f5b_caseD_10;
      }
    case 0x11:
      if ((*(byte *)(uVar3 + 0x28) & 0x10) == 0) {
        _psignal(*(uint *)(uVar3 + 0x44),(char *)0x14);
        _stop(uVar3);
        *(undefined4 *)(uVar3 + 0x74) = 1;
        LOCK();
        *(undefined4 *)(uVar3 + 0x70) = 0;
        UNLOCK();
        _thread_block();
        piVar1 = (int *)(uVar3 + 0x70);
        do {
          do {
          } while (*piVar1 != 0);
          LOCK();
          iVar4 = *piVar1;
          *piVar1 = 1;
          UNLOCK();
        } while (iVar4 == 1);
        *(undefined4 *)(uVar3 + 0x74) = 0;
        if ((*(byte *)(_active_threads + 0x17c) & 3) != 0) {
LAB_0010a04c:
          LOCK();
          *(undefined4 *)(uVar3 + 0x70) = 0;
          UNLOCK();
          return 1;
        }
      }
      goto switchD_00109f5b_caseD_10;
    default:
switchD_00109f5b_caseD_18:
      LOCK();
      *(undefined4 *)(uVar3 + 0x70) = 0;
      UNLOCK();
      return local_48;
    }
  }
LAB_0010a018:
  if ((*(byte *)(uVar3 + 0x28) & 0x10) == 0) {
    _printf(s_issig_001daa09);
  }
  goto switchD_00109f5b_caseD_10;
}


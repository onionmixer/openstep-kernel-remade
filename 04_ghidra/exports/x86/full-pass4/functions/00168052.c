/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00168052 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_00168052(void)

{
  int *piVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int unaff_EBX;
  int unaff_EBP;
  int *unaff_ESI;
  int iVar6;
  
  iVar6 = 0;
  uVar3 = _splsched();
  *(undefined4 *)(unaff_EBP + -8) = uVar3;
  do {
    do {
    } while (*unaff_ESI != 0);
    LOCK();
    iVar4 = *unaff_ESI;
    *unaff_ESI = 1;
    UNLOCK();
  } while (iVar4 == 1);
  piVar1 = (int *)(unaff_EBX + 0x20);
  do {
    switch(*(uint *)(unaff_EBX + 0x4c) & 0xf) {
    default:
switchD_0016808e_caseD_2:
      piVar1 = (int *)(unaff_EBX + 0x20);
      LOCK();
      *(undefined4 *)(unaff_EBX + 0x20) = 0;
      UNLOCK();
      _splx();
      if (iVar6 != 0) {
        _thread_wakeup_prim(unaff_EBX + 0x48,0);
      }
      uVar3 = _thread_setstatus();
      *(undefined4 *)(unaff_EBP + -4) = uVar3;
      _splsched();
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar6 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar6 == 1);
      iVar6 = *(int *)(unaff_EBX + 0x40);
      *(int *)(unaff_EBX + 0x40) = iVar6 + -1;
      if (iVar6 == 1) {
        uVar2 = *(uint *)(unaff_EBX + 0x4c);
        uVar5 = uVar2 & 0xffffffed;
        *(uint *)(unaff_EBX + 0x4c) = uVar5;
        if ((uVar2 & 5) == 0) {
          *(uint *)(unaff_EBX + 0x4c) = uVar5 | 4;
          _thread_setrun();
        }
      }
      LOCK();
      *(undefined4 *)(unaff_EBX + 0x20) = 0;
      UNLOCK();
      _splx();
      return *(undefined4 *)(unaff_EBP + -4);
    case 6:
      iVar4 = _rem_runq();
      if (iVar4 != 0) {
        *(uint *)(unaff_EBX + 0x4c) = *(uint *)(unaff_EBX + 0x4c) & 0xfffffffb;
        iVar6 = *(int *)(unaff_EBX + 0x48);
        *(undefined4 *)(unaff_EBX + 0x48) = 0;
        goto switchD_0016808e_caseD_2;
      }
switchD_0016808e_caseD_7:
      *(undefined4 *)(unaff_EBX + 0x48) = 1;
      _thread_sleep(unaff_EBX + 0x48,piVar1);
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar4 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar4 == 1);
      break;
    case 7:
    case 0xb:
    case 0xe:
    case 0xf:
      goto switchD_0016808e_caseD_7;
    }
  } while( true );
}


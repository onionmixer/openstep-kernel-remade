/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00167a11 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_00167a11(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int unaff_EBX;
  int unaff_EBP;
  int iVar4;
  
  iVar4 = 0;
  uVar2 = _splsched();
  *(undefined4 *)(unaff_EBP + -8) = uVar2;
  piVar1 = (int *)(unaff_EBX + 0x20);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar3 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar3 == 1);
  piVar1 = (int *)(unaff_EBX + 0x20);
  do {
    switch(*(uint *)(unaff_EBX + 0x4c) & 0xf) {
    default:
      goto switchD_00167a4e_caseD_2;
    case 6:
      iVar3 = _rem_runq();
      if (iVar3 != 0) {
        *(uint *)(unaff_EBX + 0x4c) = *(uint *)(unaff_EBX + 0x4c) & 0xfffffffb;
        iVar4 = *(int *)(unaff_EBX + 0x48);
        *(undefined4 *)(unaff_EBX + 0x48) = 0;
        goto switchD_00167a4e_caseD_2;
      }
      break;
    case 7:
    case 0xb:
    case 0xe:
    case 0xf:
      break;
    }
    *(undefined4 *)(unaff_EBX + 0x48) = 1;
    _thread_sleep(unaff_EBX + 0x48,piVar1);
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar3 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar3 == 1);
  } while ((*(int *)(_active_threads + 0x44) == 0) || (*(int *)(unaff_EBP + 0xc) != 0));
  *(undefined4 *)(unaff_EBP + -4) = 5;
switchD_00167a4e_caseD_2:
  LOCK();
  *(undefined4 *)(unaff_EBX + 0x20) = 0;
  UNLOCK();
  _splx();
  if (iVar4 != 0) {
    _thread_wakeup_prim(unaff_EBX + 0x48,0);
  }
  return *(undefined4 *)(unaff_EBP + -4);
}


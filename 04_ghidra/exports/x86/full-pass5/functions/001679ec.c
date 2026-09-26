/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001679ec */

undefined4 _thread_dowait(int param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 local_8;
  
  local_8 = 0;
  if (_active_threads == param_1) {
                    /* WARNING: Subroutine does not return */
    _panic(s_thread_dowait_001dfc69);
  }
  iVar4 = 0;
  uVar2 = _splsched();
  piVar1 = (int *)(param_1 + 0x20);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar3 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar3 == 1);
  piVar1 = (int *)(param_1 + 0x20);
  do {
    switch(*(uint *)(param_1 + 0x4c) & 0xf) {
    default:
      goto switchD_00167a4e_caseD_2;
    case 6:
      iVar3 = _rem_runq(param_1);
      if (iVar3 != 0) {
        *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) & 0xfffffffb;
        iVar4 = *(int *)(param_1 + 0x48);
        *(undefined4 *)(param_1 + 0x48) = 0;
        goto switchD_00167a4e_caseD_2;
      }
      break;
    case 7:
    case 0xb:
    case 0xe:
    case 0xf:
      break;
    }
    *(undefined4 *)(param_1 + 0x48) = 1;
    _thread_sleep(param_1 + 0x48,piVar1,1);
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar3 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar3 == 1);
  } while ((*(int *)(_active_threads + 0x44) == 0) || (param_2 != 0));
  local_8 = 5;
switchD_00167a4e_caseD_2:
  LOCK();
  *(undefined4 *)(param_1 + 0x20) = 0;
  UNLOCK();
  _splx(uVar2);
  if (iVar4 != 0) {
    _thread_wakeup_prim(param_1 + 0x48,0,0);
  }
  return local_8;
}


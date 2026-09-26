/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00167b98 */

kern_return_t _thread_suspend(thread_act_t target_act)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  if (target_act == 0) {
    return 4;
  }
  uVar2 = _splsched();
  piVar1 = (int *)(target_act + 0x20);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar4 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar4 == 1);
  iVar4 = *(int *)(target_act + 0x8c);
  *(int *)(target_act + 0x8c) = iVar4 + 1;
  if (iVar4 == 0) {
    *(int *)(target_act + 0x40) = *(int *)(target_act + 0x40) + 1;
    *(byte *)(target_act + 0x4c) = *(byte *)(target_act + 0x4c) | 2;
  }
  piVar1 = (int *)(target_act + 0x20);
  LOCK();
  *(undefined4 *)(target_act + 0x20) = 0;
  UNLOCK();
  _splx(uVar2);
  if (iVar4 == 0) {
    if (_active_threads != target_act) {
      iVar4 = 0;
      uVar2 = _splsched();
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar3 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar3 == 1);
      piVar1 = (int *)(target_act + 0x20);
      do {
        switch(*(uint *)(target_act + 0x4c) & 0xf) {
        default:
switchD_00167c8e_caseD_2:
          LOCK();
          *(undefined4 *)(target_act + 0x20) = 0;
          UNLOCK();
          _splx(uVar2);
          if (iVar4 == 0) {
            return 0;
          }
          _thread_wakeup_prim(target_act + 0x48,0,0);
          return 0;
        case 6:
          iVar3 = _rem_runq(target_act);
          if (iVar3 != 0) {
            *(uint *)(target_act + 0x4c) = *(uint *)(target_act + 0x4c) & 0xfffffffb;
            iVar4 = *(int *)(target_act + 0x48);
            *(undefined4 *)(target_act + 0x48) = 0;
            goto switchD_00167c8e_caseD_2;
          }
switchD_00167c8e_caseD_7:
          *(undefined4 *)(target_act + 0x48) = 1;
          _thread_sleep(target_act + 0x48,piVar1,1);
          do {
            do {
            } while (*piVar1 != 0);
            LOCK();
            iVar3 = *piVar1;
            *piVar1 = 1;
            UNLOCK();
          } while (iVar3 == 1);
          break;
        case 7:
        case 0xb:
        case 0xe:
        case 0xf:
          goto switchD_00167c8e_caseD_7;
        }
      } while( true );
    }
    uVar2 = _splsched();
    _need_ast = _need_ast | 4;
    _splx(uVar2);
  }
  return 0;
}


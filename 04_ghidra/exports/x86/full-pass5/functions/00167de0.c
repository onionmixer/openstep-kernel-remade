/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00167de0 */

kern_return_t
_thread_get_state(thread_act_t target_act,thread_state_flavor_t flavor,thread_state_t old_state,
                 mach_msg_type_number_t *old_stateCnt)

{
  int *piVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  kern_return_t kVar5;
  uint uVar6;
  int iVar7;
  
  if ((target_act == 0) || (_active_threads == target_act)) {
    return 4;
  }
  uVar3 = _splsched();
  piVar1 = (int *)(target_act + 0x20);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar7 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar7 == 1);
  *(int *)(target_act + 0x40) = *(int *)(target_act + 0x40) + 1;
  *(byte *)(target_act + 0x4c) = *(byte *)(target_act + 0x4c) | 2;
  piVar1 = (int *)(target_act + 0x20);
  LOCK();
  *(undefined4 *)(target_act + 0x20) = 0;
  UNLOCK();
  _splx(uVar3);
  if (_active_threads == target_act) {
                    /* WARNING: Subroutine does not return */
    _panic(s_thread_dowait_001dfc69);
  }
  iVar7 = 0;
  uVar3 = _splsched();
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar4 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar4 == 1);
  piVar1 = (int *)(target_act + 0x20);
  do {
    switch(*(uint *)(target_act + 0x4c) & 0xf) {
    default:
switchD_00167e9e_caseD_2:
      piVar1 = (int *)(target_act + 0x20);
      LOCK();
      *(undefined4 *)(target_act + 0x20) = 0;
      UNLOCK();
      _splx(uVar3);
      if (iVar7 != 0) {
        _thread_wakeup_prim(target_act + 0x48,0,0);
      }
      kVar5 = _thread_getstatus(target_act,flavor,old_state,old_stateCnt);
      uVar3 = _splsched();
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar7 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar7 == 1);
      iVar7 = *(int *)(target_act + 0x40);
      *(int *)(target_act + 0x40) = iVar7 + -1;
      if (iVar7 == 1) {
        uVar2 = *(uint *)(target_act + 0x4c);
        uVar6 = uVar2 & 0xffffffed;
        *(uint *)(target_act + 0x4c) = uVar6;
        if ((uVar2 & 5) == 0) {
          *(uint *)(target_act + 0x4c) = uVar6 | 4;
          _thread_setrun(target_act,1);
        }
      }
      LOCK();
      *(undefined4 *)(target_act + 0x20) = 0;
      UNLOCK();
      _splx(uVar3);
      return kVar5;
    case 6:
      iVar4 = _rem_runq(target_act);
      if (iVar4 != 0) {
        *(uint *)(target_act + 0x4c) = *(uint *)(target_act + 0x4c) & 0xfffffffb;
        iVar7 = *(int *)(target_act + 0x48);
        *(undefined4 *)(target_act + 0x48) = 0;
        goto switchD_00167e9e_caseD_2;
      }
switchD_00167e9e_caseD_7:
      *(undefined4 *)(target_act + 0x48) = 1;
      _thread_sleep(target_act + 0x48,piVar1,1);
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
      goto switchD_00167e9e_caseD_7;
    }
  } while( true );
}


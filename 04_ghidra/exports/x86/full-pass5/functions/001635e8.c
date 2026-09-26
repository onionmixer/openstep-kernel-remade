/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001635e8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _thread_invoke(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  int *piVar8;
  uint uVar9;
  
  if (param_1 == param_3) {
    piVar8 = (int *)(param_1 + 0x20);
    do {
      do {
      } while (*piVar8 != 0);
      LOCK();
      iVar6 = *piVar8;
      *piVar8 = 1;
      UNLOCK();
    } while (iVar6 == 1);
    *(uint *)(param_3 + 0x4c) = *(uint *)(param_3 + 0x4c) & 0xfffffff7;
    LOCK();
    *(undefined4 *)(param_3 + 0x20) = 0;
    UNLOCK();
    if (param_2 != 0) {
      _spl0();
      _call_continuation(param_2);
    }
    return 1;
  }
  piVar8 = (int *)(param_3 + 0x20);
  do {
    do {
    } while (*piVar8 != 0);
    LOCK();
    iVar6 = *piVar8;
    *piVar8 = 1;
    UNLOCK();
  } while (iVar6 == 1);
  if ((*(int *)(param_1 + 0x30) == _active_stacks) || (param_2 == 0)) {
    if (((*(uint *)(param_3 + 0x4c) & 0x100) != 0) &&
       (((*(uint *)(param_3 + 0x4c) & 0x200) != 0 ||
        (iVar6 = _stack_alloc_try(param_3,_thread_continue), iVar6 == 0)))) {
LAB_00163983:
      _thread_swapin(param_3);
      LOCK();
      *(undefined4 *)(param_3 + 0x20) = 0;
      UNLOCK();
      __c_thread_invoke_misses = __c_thread_invoke_misses + 1;
      return 0;
    }
LAB_00163998:
    *(uint *)(param_3 + 0x4c) = *(uint *)(param_3 + 0x4c) & 0xfffffef7;
    LOCK();
    *(undefined4 *)(param_3 + 0x20) = 0;
    UNLOCK();
    _need_ast = _need_ast & 0xbffffffc | *(uint *)(param_3 + 0x17c);
    _switch_unix_context(param_3);
    __c_thread_invoke_csw = __c_thread_invoke_csw + 1;
    uVar7 = _switch_context(param_1,param_2,param_3);
    _thread_dispatch(uVar7);
    return 1;
  }
  uVar5 = *(uint *)(param_3 + 0x4c) & 0x300;
  if (uVar5 != 0x100) {
    if ((0x100 < uVar5) && (uVar5 == 0x200)) goto LAB_00163983;
    goto LAB_00163998;
  }
  *(uint *)(param_3 + 0x4c) = *(uint *)(param_3 + 0x4c) & 0xfffffef7;
  LOCK();
  *(undefined4 *)(param_3 + 0x20) = 0;
  UNLOCK();
  _need_ast = _need_ast & 0xbffffffc | *(uint *)(param_3 + 0x17c);
  _switch_unix_context(param_3);
  _stack_handoff(param_1,param_3);
  piVar8 = (int *)(param_1 + 0x20);
  do {
    do {
    } while (*piVar8 != 0);
    LOCK();
    iVar6 = *piVar8;
    *piVar8 = 1;
    UNLOCK();
  } while (iVar6 == 1);
  *(int *)(param_1 + 0x34) = param_2;
  iVar6 = *(int *)(param_1 + 0x4c);
  if (iVar6 == 0xc) {
LAB_00163904:
    *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) | 0x100;
    _thread_setrun(param_1,0);
  }
  else {
    if (iVar6 < 0xd) {
      if (iVar6 != 5) {
        if (iVar6 < 6) {
          if (iVar6 != 4) goto LAB_00163934;
          goto LAB_00163904;
        }
        if (7 < iVar6) {
LAB_00163934:
                    /* WARNING: Subroutine does not return */
          _panic(s_thread_invoke_001df564);
        }
LAB_00163770:
        *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) & 0xfffffffb | 0x100;
        if (*(int *)(param_1 + 0x48) != 0) {
          *(undefined4 *)(param_1 + 0x48) = 0;
          LOCK();
          *(undefined4 *)(param_1 + 0x20) = 0;
          UNLOCK();
          uVar9 = param_1 + 0x48;
          uVar5 = uVar9;
          if ((int)uVar9 < 0) {
            uVar5 = ~uVar9;
          }
          uVar7 = _splsched();
          piVar8 = &_wait_lock + (int)uVar5 % 0x3b;
          do {
            do {
            } while (*piVar8 != 0);
            LOCK();
            iVar6 = *piVar8;
            *piVar8 = 1;
            UNLOCK();
          } while (iVar6 == 1);
          piVar2 = (int *)(&_wait_queue)[((int)uVar5 % 0x3b) * 2];
          while (piVar4 = piVar2, &_wait_queue + ((int)uVar5 % 0x3b) * 2 != piVar4) {
            piVar2 = (int *)*piVar4;
            if (piVar4[0xf] == uVar9) {
              piVar1 = piVar4 + 8;
              do {
                do {
                } while (*piVar1 != 0);
                LOCK();
                iVar6 = *piVar1;
                *piVar1 = 1;
                UNLOCK();
              } while (iVar6 == 1);
              *(int *)(*piVar4 + 4) = piVar4[1];
              *(int *)piVar4[1] = *piVar4;
              piVar4[0xf] = 0;
              if (piVar4[0x51] != 0) {
                _reset_timeout(piVar4 + 0x46);
              }
              uVar3 = piVar4[0x13];
              switch(uVar3 & 0xf) {
              case 1:
              case 9:
              case 0xb:
                piVar4[0x13] = uVar3 & 0xfffffffe | 4;
                piVar4[0x11] = 0;
                _thread_setrun(piVar4,1);
                break;
              default:
                    /* WARNING: Subroutine does not return */
                _panic(s_thread_wakeup_001df556);
              case 3:
              case 5:
              case 7:
              case 0xd:
              case 0xf:
                piVar4[0x13] = uVar3 & 0xfffffffe;
                piVar4[0x11] = 0;
              }
              LOCK();
              piVar4[8] = 0;
              UNLOCK();
            }
          }
          LOCK();
          *piVar8 = 0;
          UNLOCK();
          _splx(uVar7);
          goto LAB_00163946;
        }
        goto LAB_00163941;
      }
    }
    else if (iVar6 != 0xf) {
      if (0xf < iVar6) {
        if (iVar6 == 0x16) goto LAB_00163770;
        if (iVar6 != 0x84) goto LAB_00163934;
        *(undefined4 *)(param_1 + 0x4c) = 0x184;
        goto LAB_00163941;
      }
      if (iVar6 != 0xd) {
        if (iVar6 != 0xe) goto LAB_00163934;
        goto LAB_00163904;
      }
    }
    *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) & 0xfffffffb | 0x100;
  }
LAB_00163941:
  LOCK();
  *(undefined4 *)(param_1 + 0x20) = 0;
  UNLOCK();
LAB_00163946:
  __c_thread_invoke_hits = __c_thread_invoke_hits + 1;
  _spl0();
  _call_continuation(*(undefined4 *)(param_3 + 0x34));
  return 1;
}


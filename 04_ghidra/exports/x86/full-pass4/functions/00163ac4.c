/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00163ac4 */

undefined4 _thread_dispatch(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  undefined4 uVar9;
  
  piVar1 = (int *)(param_1 + 0x20);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar3 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar3 == 1);
  if (*(int *)(param_1 + 0x34) != 0) {
    *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) | 0x100;
    _stack_free(param_1);
  }
  uVar7 = *(uint *)(param_1 + 0x4c) & 0xfffffcff;
  if (uVar7 == 0xc) {
LAB_00163cf8:
    _thread_setrun(param_1,0);
  }
  else {
    if ((int)uVar7 < 0xd) {
      if (uVar7 != 5) {
        if (5 < (int)uVar7) {
          if (7 < (int)uVar7) {
LAB_00163d0c:
                    /* WARNING: Subroutine does not return */
            _panic(s_thread_dispatch_001df572);
          }
LAB_00163b70:
          *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) & 0xfffffffb;
          if (*(int *)(param_1 + 0x48) != 0) {
            *(undefined4 *)(param_1 + 0x48) = 0;
            LOCK();
            *(undefined4 *)(param_1 + 0x20) = 0;
            UNLOCK();
            uVar7 = param_1 + 0x48;
            uVar8 = uVar7;
            if ((int)uVar7 < 0) {
              uVar8 = ~uVar7;
            }
            uVar9 = _splsched();
            piVar1 = &_wait_lock + (int)uVar8 % 0x3b;
            do {
              do {
              } while (*piVar1 != 0);
              LOCK();
              iVar3 = *piVar1;
              *piVar1 = 1;
              UNLOCK();
            } while (iVar3 == 1);
            piVar4 = (int *)(&_wait_queue)[((int)uVar8 % 0x3b) * 2];
            while (piVar6 = piVar4, &_wait_queue + ((int)uVar8 % 0x3b) * 2 != piVar6) {
              piVar4 = (int *)*piVar6;
              if (piVar6[0xf] == uVar7) {
                piVar2 = piVar6 + 8;
                do {
                  do {
                  } while (*piVar2 != 0);
                  LOCK();
                  iVar3 = *piVar2;
                  *piVar2 = 1;
                  UNLOCK();
                } while (iVar3 == 1);
                *(int *)(*piVar6 + 4) = piVar6[1];
                *(int *)piVar6[1] = *piVar6;
                piVar6[0xf] = 0;
                if (piVar6[0x51] != 0) {
                  _reset_timeout(piVar6 + 0x46);
                }
                uVar5 = piVar6[0x13];
                switch(uVar5 & 0xf) {
                case 1:
                case 9:
                case 0xb:
                  piVar6[0x13] = uVar5 & 0xfffffffe | 4;
                  piVar6[0x11] = 0;
                  _thread_setrun(piVar6,1);
                  break;
                default:
                    /* WARNING: Subroutine does not return */
                  _panic(s_thread_wakeup_001df556);
                case 3:
                case 5:
                case 7:
                case 0xd:
                case 0xf:
                  piVar6[0x13] = uVar5 & 0xfffffffe;
                  piVar6[0x11] = 0;
                }
                LOCK();
                piVar6[8] = 0;
                UNLOCK();
              }
            }
            LOCK();
            *piVar1 = 0;
            UNLOCK();
            uVar9 = _splx(uVar9);
            return uVar9;
          }
          goto LAB_00163d16;
        }
        if (uVar7 != 4) goto LAB_00163d0c;
        goto LAB_00163cf8;
      }
    }
    else if (uVar7 != 0xf) {
      if (0xf < (int)uVar7) {
        if (uVar7 != 0x16) {
          if (uVar7 != 0x84) goto LAB_00163d0c;
          goto LAB_00163d16;
        }
        goto LAB_00163b70;
      }
      if (uVar7 != 0xd) {
        if (uVar7 != 0xe) goto LAB_00163d0c;
        goto LAB_00163cf8;
      }
    }
    *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) & 0xfffffffb;
  }
LAB_00163d16:
  LOCK();
  uVar9 = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(param_1 + 0x20) = 0;
  UNLOCK();
  return uVar9;
}


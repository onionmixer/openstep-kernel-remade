/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001631a0 */

void _thread_wakeup_prim(uint param_1,int param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int *piVar6;
  uint uVar7;
  undefined4 uVar8;
  
  uVar7 = param_1;
  if ((int)param_1 < 0) {
    uVar7 = ~param_1;
  }
  uVar8 = _splsched();
  piVar2 = &_wait_lock + (int)uVar7 % 0x3b;
  do {
    do {
    } while (*piVar2 != 0);
    LOCK();
    iVar3 = *piVar2;
    *piVar2 = 1;
    UNLOCK();
  } while (iVar3 == 1);
  piVar4 = (int *)(&_wait_queue)[((int)uVar7 % 0x3b) * 2];
  do {
    do {
      piVar6 = piVar4;
      if (&_wait_queue + ((int)uVar7 % 0x3b) * 2 == piVar6) goto LAB_00163307;
      piVar4 = (int *)*piVar6;
    } while (piVar6[0xf] != param_1);
    piVar1 = piVar6 + 8;
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar3 = *piVar1;
      *piVar1 = 1;
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
      piVar6[0x11] = param_3;
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
      piVar6[0x11] = param_3;
    }
    LOCK();
    piVar6[8] = 0;
    UNLOCK();
  } while (param_2 == 0);
LAB_00163307:
  LOCK();
  *piVar2 = 0;
  UNLOCK();
  _splx(uVar8);
  return;
}


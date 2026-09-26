/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016303c */

void _clear_wait(int *param_1,int param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar4 = _splsched();
  piVar1 = param_1 + 8;
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar3 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar3 == 1);
  if ((param_3 == 0) || ((*(byte *)(param_1 + 0x13) & 8) == 0)) {
    uVar6 = param_1[0xf];
    if (uVar6 != 0) {
      LOCK();
      param_1[8] = 0;
      UNLOCK();
      uVar5 = uVar6;
      if ((int)uVar6 < 0) {
        uVar5 = ~uVar6;
      }
      piVar1 = &_wait_lock + (int)uVar5 % 0x3b;
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar3 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar3 == 1);
      piVar2 = param_1 + 8;
      do {
        do {
        } while (*piVar2 != 0);
        LOCK();
        iVar3 = *piVar2;
        *piVar2 = 1;
        UNLOCK();
      } while (iVar3 == 1);
      if (param_1[0xf] == uVar6) {
        *(int *)(*param_1 + 4) = param_1[1];
        *(int *)param_1[1] = *param_1;
        param_1[0xf] = 0;
        uVar6 = 0;
      }
      LOCK();
      *piVar1 = 0;
      UNLOCK();
      if (uVar6 != 0) goto switchD_0016311b_caseD_2;
    }
    uVar6 = param_1[0x13];
    if (param_1[0x51] != 0) {
      _reset_timeout(param_1 + 0x46);
    }
    switch(uVar6 & 0xf) {
    case 1:
    case 9:
    case 0xb:
      param_1[0x13] = uVar6 & 0xfffffffe | 4;
      param_1[0x11] = param_2;
      _thread_setrun(param_1,1);
      break;
    case 3:
    case 5:
    case 7:
    case 0xd:
    case 0xf:
      param_1[0x13] = uVar6 & 0xfffffffe;
      param_1[0x11] = param_2;
    }
  }
switchD_0016311b_caseD_2:
  LOCK();
  param_1[8] = 0;
  UNLOCK();
  _splx(uVar4);
  return;
}


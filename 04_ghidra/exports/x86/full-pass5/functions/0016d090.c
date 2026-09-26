/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016d090 */

undefined4 _kern_serv_callout(undefined4 *param_1,code *param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  
  piVar1 = (int *)*param_1;
  iVar5 = _curipl();
  if ((iVar5 == 0) && (iVar5 = _task_self(), piVar1[2] == iVar5)) {
    (*param_2)(param_3);
  }
  else {
    uVar6 = _splhigh();
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar5 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar5 == 1);
    piVar4 = piVar1 + 0xf;
    piVar2 = (int *)piVar1[0xf];
    if (piVar4 == piVar2) {
      LOCK();
      *piVar1 = 0;
      UNLOCK();
      _splx(uVar6);
      return 6;
    }
    piVar3 = (int *)piVar2[2];
    if (piVar4 == piVar3) {
      piVar1[0x10] = (int)piVar3;
    }
    else {
      piVar3[3] = (int)piVar4;
    }
    piVar1[0xf] = (int)piVar3;
    *piVar2 = (int)param_2;
    piVar2[1] = param_3;
    piVar4 = (int *)piVar1[0xe];
    if (piVar1 + 0xd == piVar4) {
      piVar1[0xd] = (int)piVar2;
    }
    else {
      piVar4[2] = (int)piVar2;
    }
    piVar2[3] = (int)piVar4;
    piVar2[2] = (int)(piVar1 + 0xd);
    piVar1[0xe] = (int)piVar2;
    LOCK();
    *piVar1 = 0;
    UNLOCK();
    _splx(uVar6);
    _calloutDispatchUnique(FUN_0016d164,piVar1[3]);
  }
  return 0;
}


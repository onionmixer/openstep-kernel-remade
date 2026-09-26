/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00168784 */

undefined4 _thread_priority(int param_1,uint param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  if ((param_1 == 0) || (0x1f < param_2)) {
    uVar4 = 4;
  }
  else {
    uVar3 = _splsched();
    piVar1 = (int *)(param_1 + 0x20);
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar2 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar2 == 1);
    if (*(int *)(param_1 + 0x54) < (int)param_2) {
      uVar4 = 5;
    }
    else {
      if (*(int *)(param_1 + 100) < 0) {
        *(uint *)(param_1 + 0x50) = param_2;
        _compute_priority(param_1,1);
      }
      else {
        *(uint *)(param_1 + 100) = param_2;
      }
      if (param_3 != 0) {
        *(uint *)(param_1 + 0x54) = param_2;
      }
    }
    LOCK();
    *(undefined4 *)(param_1 + 0x20) = 0;
    UNLOCK();
    _splx(uVar3);
  }
  return uVar4;
}


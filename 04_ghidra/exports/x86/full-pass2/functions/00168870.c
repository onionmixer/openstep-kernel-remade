/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00168870 */

undefined4 _thread_max_priority(int param_1,int param_2,uint param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (((param_1 == 0) || (param_2 == 0)) || (0x1f < param_3)) {
    uVar3 = 4;
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
    *(uint *)(param_1 + 0x54) = param_3;
    if ((int)param_3 < *(int *)(param_1 + 0x50)) {
      *(uint *)(param_1 + 0x50) = param_3;
      _compute_priority(param_1,1);
    }
    else if ((-1 < *(int *)(param_1 + 100)) && ((int)param_3 < *(int *)(param_1 + 100))) {
      *(uint *)(param_1 + 100) = param_3;
    }
    LOCK();
    *(undefined4 *)(param_1 + 0x20) = 0;
    UNLOCK();
    _splx(uVar3);
    uVar3 = 0;
  }
  return uVar3;
}


/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00168814 */

void _thread_set_own_priority(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = _active_threads;
  uVar4 = _splsched();
  piVar1 = (int *)(iVar3 + 0x20);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar2 == 1);
  if (param_1 < *(int *)(iVar3 + 0x54)) {
    *(int *)(iVar3 + 0x54) = param_1;
  }
  *(int *)(iVar3 + 0x50) = param_1;
  _compute_priority(iVar3,1);
  LOCK();
  *(undefined4 *)(iVar3 + 0x20) = 0;
  UNLOCK();
  _splx(uVar4);
  return;
}


/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00162e7c */

void _thread_set_timeout(undefined4 param_1)

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
  if ((*(byte *)(iVar3 + 0x4c) & 1) != 0) {
    _set_timeout(iVar3 + 0x118,param_1);
  }
  LOCK();
  *(undefined4 *)(iVar3 + 0x20) = 0;
  UNLOCK();
  _splx(uVar4);
  return;
}


/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a1514 */

void FUN_001a1514(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = _active_threads;
  iVar3 = *(int *)(*(int *)(_active_threads + 0x28) + 0x70);
  if (iVar3 == 0) {
    iVar3 = _thread_user_state(_active_threads);
  }
  else {
    iVar3 = iVar3 + 0x84;
  }
  piVar1 = *(int **)(*(int *)(iVar2 + 0x28) + 0xec);
  iVar4 = 0;
  if (piVar1 != (int *)0x0) {
    iVar4 = *piVar1;
  }
  if (iVar4 == 0) {
    iVar4 = 0;
  }
  else if (*(uint *)(iVar4 + 0x84) < 8) {
    iVar4 = iVar4 + 0x88 + *(uint *)(iVar4 + 0x84) * 0x84;
  }
  else {
    iVar4 = 0;
  }
  if (*(int *)(iVar4 + 0x54) != 0) {
    *(undefined4 *)(iVar4 + 0x58) = 1;
    _PCcallMonitor(iVar2,iVar3);
  }
  if ((*(int *)(iVar4 + 0x58) == 0) &&
     ((*(int *)(iVar4 + 0x74) != 0 || (iVar4 = _PCtimersPending(iVar4), iVar4 != 0)))) {
    _PCcallMonitor(iVar2,iVar3);
  }
  _thread_exception_return();
  return;
}


/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00167424 */

void _thread_force_terminate(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  _ipc_thread_disable(param_1);
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
  iVar2 = *(int *)(param_1 + 0x178);
  *(undefined4 *)(param_1 + 0x178) = 0;
  LOCK();
  *(undefined4 *)(param_1 + 0x20) = 0;
  UNLOCK();
  _splx(uVar3);
  _thread_halt(param_1,1);
  _ipc_thread_terminate(param_1);
  if (iVar2 != 0) {
    _thread_deallocate(param_1);
  }
  return;
}


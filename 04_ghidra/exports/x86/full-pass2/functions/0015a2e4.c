/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015a2e4 */

undefined4 _convert_task_to_port(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  piVar1 = (int *)(param_1 + 100);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar2 == 1);
  if (*(int *)(param_1 + 0x68) == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = _ipc_port_make_send(*(int *)(param_1 + 0x68));
  }
  LOCK();
  *(undefined4 *)(param_1 + 100) = 0;
  UNLOCK();
  _task_deallocate(param_1);
  return uVar3;
}


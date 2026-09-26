/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00159aa4 */

int _retrieve_task_notify(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_1 + 0x88);
  piVar1 = (int *)(iVar2 + 8);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar3 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar3 == 1);
  if (*(int *)(iVar2 + 0xc) == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(iVar2 + 0x44);
    if ((iVar3 != 0) && (iVar3 != -1)) {
      _ipc_object_reference(iVar3);
    }
  }
  LOCK();
  *(undefined4 *)(iVar2 + 8) = 0;
  UNLOCK();
  return iVar3;
}


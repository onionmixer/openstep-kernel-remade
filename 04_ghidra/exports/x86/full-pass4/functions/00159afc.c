/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00159afc */

int _retrieve_thread_reply(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(param_1 + 0xa8);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar2 == 1);
  if (*(int *)(param_1 + 0xac) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(param_1 + 0xb8);
    if ((iVar2 != 0) && (iVar2 != -1)) {
      _ipc_object_reference(iVar2);
    }
  }
  LOCK();
  *(undefined4 *)(param_1 + 0xa8) = 0;
  UNLOCK();
  return iVar2;
}


/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00159900 */

int * _retrieve_thread_self_fast(int param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)(param_1 + 0xa8);
  do {
    do {
    } while (*piVar2 != 0);
    LOCK();
    iVar1 = *piVar2;
    *piVar2 = 1;
    UNLOCK();
  } while (iVar1 == 1);
  piVar2 = *(int **)(param_1 + 0xb0);
  if (*(int **)(param_1 + 0xac) == piVar2) {
    do {
      do {
      } while (*piVar2 != 0);
      LOCK();
      iVar1 = *piVar2;
      *piVar2 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    piVar2[1] = piVar2[1] + 1;
    piVar2[7] = piVar2[7] + 1;
    LOCK();
    *piVar2 = 0;
    UNLOCK();
  }
  else {
    piVar2 = (int *)_ipc_port_copy_send(piVar2);
  }
  LOCK();
  *(undefined4 *)(param_1 + 0xa8) = 0;
  UNLOCK();
  return piVar2;
}


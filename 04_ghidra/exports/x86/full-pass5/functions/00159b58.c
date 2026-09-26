/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00159b58 */

void _task_self(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = *(int *)(_active_threads + 0xc);
  piVar3 = (int *)(iVar2 + 100);
  do {
    do {
    } while (*piVar3 != 0);
    LOCK();
    iVar1 = *piVar3;
    *piVar3 = 1;
    UNLOCK();
  } while (iVar1 == 1);
  piVar3 = *(int **)(iVar2 + 0x6c);
  if (*(int **)(iVar2 + 0x68) == piVar3) {
    do {
      do {
      } while (*piVar3 != 0);
      LOCK();
      iVar1 = *piVar3;
      *piVar3 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    piVar3[1] = piVar3[1] + 1;
    piVar3[7] = piVar3[7] + 1;
    LOCK();
    *piVar3 = 0;
    UNLOCK();
  }
  else {
    piVar3 = (int *)_ipc_port_copy_send(piVar3);
  }
  LOCK();
  *(undefined4 *)(iVar2 + 100) = 0;
  UNLOCK();
  _ipc_port_copyout_send_compat(piVar3,*(undefined4 *)(iVar2 + 0x88));
  return;
}


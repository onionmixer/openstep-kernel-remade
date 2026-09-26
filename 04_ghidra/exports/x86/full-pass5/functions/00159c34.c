/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00159c34 */

void _thread_self(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar3 = _active_threads;
  iVar2 = *(int *)(_active_threads + 0xc);
  piVar4 = (int *)(_active_threads + 0xa8);
  do {
    do {
    } while (*piVar4 != 0);
    LOCK();
    iVar1 = *piVar4;
    *piVar4 = 1;
    UNLOCK();
  } while (iVar1 == 1);
  piVar4 = *(int **)(iVar3 + 0xb0);
  if (*(int **)(iVar3 + 0xac) == piVar4) {
    do {
      do {
      } while (*piVar4 != 0);
      LOCK();
      iVar1 = *piVar4;
      *piVar4 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    piVar4[1] = piVar4[1] + 1;
    piVar4[7] = piVar4[7] + 1;
    LOCK();
    *piVar4 = 0;
    UNLOCK();
  }
  else {
    piVar4 = (int *)_ipc_port_copy_send(piVar4);
  }
  LOCK();
  *(undefined4 *)(iVar3 + 0xa8) = 0;
  UNLOCK();
  _ipc_port_copyout_send_compat(piVar4,*(undefined4 *)(iVar2 + 0x88));
  return;
}


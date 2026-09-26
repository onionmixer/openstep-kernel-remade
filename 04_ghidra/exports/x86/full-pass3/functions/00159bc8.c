/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00159bc8 */

void _task_notify(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = *(int *)(_active_threads + 0xc);
  iVar3 = *(int *)(iVar2 + 0x88);
  piVar1 = (int *)(iVar3 + 8);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar4 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar4 == 1);
  if (*(int *)(iVar3 + 0xc) == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = *(int *)(iVar3 + 0x44);
    if ((iVar4 != 0) && (iVar4 != -1)) {
      _ipc_object_reference(iVar4);
    }
  }
  LOCK();
  *(undefined4 *)(iVar3 + 8) = 0;
  UNLOCK();
  _ipc_port_copyout_receiver(iVar4,*(undefined4 *)(iVar2 + 0x88));
  return;
}


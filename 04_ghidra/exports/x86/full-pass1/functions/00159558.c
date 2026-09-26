/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00159558 */

undefined4 _ipc_task_terminate(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  piVar1 = (int *)(param_1 + 100);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar2 == 1);
  iVar2 = *(int *)(param_1 + 0x68);
  if (iVar2 == 0) {
    LOCK();
    uVar4 = *(undefined4 *)(param_1 + 100);
    *(undefined4 *)(param_1 + 100) = 0;
    UNLOCK();
  }
  else {
    *(undefined4 *)(param_1 + 0x68) = 0;
    LOCK();
    *(undefined4 *)(param_1 + 100) = 0;
    UNLOCK();
    iVar5 = *(int *)(param_1 + 0x6c);
    if ((iVar5 != 0) && (iVar5 != -1)) {
      _ipc_port_release_send(iVar5);
    }
    iVar5 = *(int *)(param_1 + 0x70);
    if ((iVar5 != 0) && (iVar5 != -1)) {
      _ipc_port_release_send(iVar5);
    }
    iVar5 = *(int *)(param_1 + 0x74);
    if ((iVar5 != 0) && (iVar5 != -1)) {
      _ipc_port_release_send(iVar5);
    }
    iVar5 = 0;
    do {
      iVar3 = *(int *)(param_1 + 0x78 + iVar5 * 4);
      if ((iVar3 != 0) && (iVar3 != -1)) {
        _ipc_port_release_send(iVar3);
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < 4);
    _ipc_space_destroy(*(undefined4 *)(param_1 + 0x88));
    uVar4 = _ipc_port_dealloc_special(iVar2,_ipc_space_kernel);
  }
  return uVar4;
}


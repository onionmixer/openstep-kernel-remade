/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00159770 */

undefined4 _ipc_thread_terminate(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 local_c;
  undefined4 local_8;
  
  piVar1 = (int *)(param_1 + 0xa8);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar2 == 1);
  iVar2 = *(int *)(param_1 + 0xac);
  if (iVar2 != 0) {
    *(undefined4 *)(param_1 + 0xac) = 0;
    LOCK();
    *(undefined4 *)(param_1 + 0xa8) = 0;
    UNLOCK();
    iVar3 = *(int *)(param_1 + 0xb0);
    if ((iVar3 != 0) && (iVar3 != -1)) {
      _ipc_port_release_send(iVar3);
    }
    iVar3 = *(int *)(param_1 + 0xb4);
    if ((iVar3 != 0) && (iVar3 != -1)) {
      _ipc_port_release_send(iVar3);
    }
    iVar3 = *(int *)(param_1 + 0xc0);
    if ((iVar3 != 0) && (iVar3 != -1)) {
      _ipc_port_dealloc_special(iVar3,_ipc_space_reply);
    }
    puVar4 = *(undefined4 **)(param_1 + 0xb8);
    if ((puVar4 != (undefined4 *)0x0) && (puVar4 != (undefined4 *)0xffffffff)) {
      iVar3 = *(int *)(*(int *)(param_1 + 0xc) + 0x88);
      piVar1 = (int *)(iVar3 + 8);
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar5 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar5 == 1);
      if ((*(int *)(iVar3 + 0xc) == 0) ||
         (iVar5 = _ipc_right_reverse(iVar3,puVar4,&local_8,&local_c), iVar5 == 0)) {
        LOCK();
        *(undefined4 *)(iVar3 + 8) = 0;
        UNLOCK();
      }
      else {
        LOCK();
        *puVar4 = 0;
        UNLOCK();
        _ipc_right_destroy(iVar3,local_8,local_c);
      }
      _ipc_port_release_send(puVar4);
    }
    uVar6 = _ipc_port_dealloc_special(iVar2,_ipc_space_kernel);
    return uVar6;
  }
  LOCK();
  uVar6 = *(undefined4 *)(param_1 + 0xa8);
  *(undefined4 *)(param_1 + 0xa8) = 0;
  UNLOCK();
  return uVar6;
}


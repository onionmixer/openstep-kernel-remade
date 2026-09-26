/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014c89c */

undefined4 _ipc_port_clear_receiver(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  piVar3 = *(int **)(param_1 + 0x30);
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)(param_1 + 0x40);
    do {
      do {
      } while (*piVar3 != 0);
      LOCK();
      iVar1 = *piVar3;
      *piVar3 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    _ipc_mqueue_changed(param_1 + 0x40,0x10004009);
    LOCK();
    *(undefined4 *)(param_1 + 0x40) = 0;
    UNLOCK();
  }
  else {
    do {
      do {
      } while (*piVar3 != 0);
      LOCK();
      iVar1 = *piVar3;
      *piVar3 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    _ipc_pset_remove(piVar3,param_1);
    LOCK();
    *piVar3 = 0;
    UNLOCK();
    if (piVar3[1] == 0) {
      _zfree((&_ipc_object_zones)[*(ushort *)((int)piVar3 + 10) & 0x7fff],piVar3);
    }
  }
  *(undefined4 *)(param_1 + 0x18) = 0;
  piVar3 = (int *)(param_1 + 0x40);
  do {
    do {
    } while (*piVar3 != 0);
    LOCK();
    iVar1 = *piVar3;
    *piVar3 = 1;
    UNLOCK();
  } while (iVar1 == 1);
  *(undefined4 *)(param_1 + 0x34) = 0;
  LOCK();
  uVar2 = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(param_1 + 0x40) = 0;
  UNLOCK();
  return uVar2;
}


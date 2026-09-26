/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014c748 */

int * _ipc_port_lock_mqueue(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = *(int **)(param_1 + 0x30);
  if (piVar3 != (int *)0x0) {
    do {
      do {
      } while (*piVar3 != 0);
      LOCK();
      iVar2 = *piVar3;
      *piVar3 = 1;
      UNLOCK();
    } while (iVar2 == 1);
    if (piVar3[2] < 0) {
      piVar1 = piVar3 + 4;
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar2 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar2 == 1);
      LOCK();
      *piVar3 = 0;
      UNLOCK();
      return piVar3 + 4;
    }
    _ipc_pset_remove(piVar3,param_1);
    LOCK();
    *piVar3 = 0;
    UNLOCK();
    if (piVar3[1] == 0) {
      _zfree((&_ipc_object_zones)[*(ushort *)((int)piVar3 + 10) & 0x7fff],piVar3);
    }
  }
  piVar3 = (int *)(param_1 + 0x40);
  do {
    do {
    } while (*piVar3 != 0);
    LOCK();
    iVar2 = *piVar3;
    *piVar3 = 1;
    UNLOCK();
  } while (iVar2 == 1);
  return (int *)(param_1 + 0x40);
}


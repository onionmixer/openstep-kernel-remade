/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014d244 */

void _ipc_port_dealloc_special(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  do {
    do {
    } while (*param_1 != 0);
    LOCK();
    iVar1 = *param_1;
    *param_1 = 1;
    UNLOCK();
  } while (iVar1 == 1);
  param_1[4] = 0;
  param_1[3] = 0;
  piVar2 = (int *)param_1[0xc];
  if (piVar2 == (int *)0x0) {
    piVar2 = param_1 + 0x10;
    do {
      do {
      } while (*piVar2 != 0);
      LOCK();
      iVar1 = *piVar2;
      *piVar2 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    _ipc_mqueue_changed(param_1 + 0x10,0x10004009);
    LOCK();
    param_1[0x10] = 0;
    UNLOCK();
  }
  else {
    do {
      do {
      } while (*piVar2 != 0);
      LOCK();
      iVar1 = *piVar2;
      *piVar2 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    _ipc_pset_remove(piVar2,param_1);
    LOCK();
    *piVar2 = 0;
    UNLOCK();
    if (piVar2[1] == 0) {
      _zfree((&_ipc_object_zones)[*(ushort *)((int)piVar2 + 10) & 0x7fff],piVar2);
    }
  }
  param_1[6] = 0;
  piVar2 = param_1 + 0x10;
  do {
    do {
    } while (*piVar2 != 0);
    LOCK();
    iVar1 = *piVar2;
    *piVar2 = 1;
    UNLOCK();
  } while (iVar1 == 1);
  param_1[0xd] = 0;
  LOCK();
  param_1[0x10] = 0;
  UNLOCK();
  _ipc_port_destroy(param_1);
  return;
}


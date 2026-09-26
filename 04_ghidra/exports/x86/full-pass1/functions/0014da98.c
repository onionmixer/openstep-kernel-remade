/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014da98 */

void _ipc_pset_destroy(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  
  param_1[2] = param_1[2] & 0x7fffffff;
  piVar1 = param_1 + 4;
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar2 == 1);
  _ipc_mqueue_changed(param_1 + 4,0x10004009);
  LOCK();
  param_1[4] = 0;
  UNLOCK();
  iVar2 = param_1[1];
  param_1[1] = iVar2 + -1;
  LOCK();
  *param_1 = 0;
  UNLOCK();
  if (iVar2 == 1) {
    _zfree((&_ipc_object_zones)[*(ushort *)((int)param_1 + 10) & 0x7fff],param_1);
  }
  return;
}


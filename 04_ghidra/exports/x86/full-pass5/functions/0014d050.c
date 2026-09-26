/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014d050 */

int _ipc_port_release_send(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = 0;
  do {
    do {
    } while (*param_1 != 0);
    LOCK();
    iVar1 = *param_1;
    *param_1 = 1;
    UNLOCK();
  } while (iVar1 == 1);
  iVar1 = param_1[1];
  param_1[1] = iVar1 + -1;
  if (param_1[2] < 0) {
    iVar1 = param_1[7];
    param_1[7] = iVar1 + -1;
    if ((iVar1 == 1) && (iVar2 = param_1[9], iVar2 != 0)) {
      param_1[9] = 0;
      iVar3 = param_1[6];
    }
    LOCK();
    iVar1 = *param_1;
    *param_1 = 0;
    UNLOCK();
    if (iVar2 != 0) {
      iVar1 = _ipc_notify_no_senders(iVar2,iVar3);
    }
  }
  else {
    iVar1 = iVar1 + -1;
    LOCK();
    *param_1 = 0;
    UNLOCK();
    if (iVar1 == 0) {
      iVar1 = _zfree((&_ipc_object_zones)[*(ushort *)((int)param_1 + 10) & 0x7fff],param_1);
    }
  }
  return iVar1;
}


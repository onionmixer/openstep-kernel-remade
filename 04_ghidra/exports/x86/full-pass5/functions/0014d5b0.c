/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014d5b0 */

int _ipc_port_copyout_receiver(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if ((param_1 == (int *)0x0) || (param_1 == (int *)0xffffffff)) {
    iVar2 = 0;
  }
  else {
    do {
      do {
      } while (*param_1 != 0);
      LOCK();
      iVar2 = *param_1;
      *param_1 = 1;
      UNLOCK();
    } while (iVar2 == 1);
    iVar2 = 0;
    if (param_1[3] == param_2) {
      iVar2 = param_1[4];
    }
    iVar1 = param_1[1];
    param_1[1] = iVar1 + -1;
    LOCK();
    *param_1 = 0;
    UNLOCK();
    if (iVar1 == 1) {
      _zfree((&_ipc_object_zones)[*(ushort *)((int)param_1 + 10) & 0x7fff],param_1);
    }
  }
  return iVar2;
}


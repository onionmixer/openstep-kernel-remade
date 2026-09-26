/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001476ec */

undefined4 _ipc_kmsg_put(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  *(undefined4 *)(param_2 + 0x10) = 0;
  iVar1 = _copyoutmsg(param_2 + 0x14,param_1,param_3);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = 0x10004008;
  }
  if ((*(int *)(param_2 + 8) == 0x100) && (_ipc_kmsg_cache == 0)) {
    _ipc_kmsg_cache = param_2;
    return uVar2;
  }
  iVar1 = *(int *)(param_2 + 8);
  if (iVar1 < 1) {
    if (iVar1 == -2) {
      _KernDeviceInterruptMsgRelease(param_2);
      return uVar2;
    }
    if (iVar1 == -1) {
      return uVar2;
    }
    if (iVar1 == -3) {
      _netipc_msg_release(param_2);
      return uVar2;
    }
  }
  _kfree(param_2,iVar1);
  return uVar2;
}


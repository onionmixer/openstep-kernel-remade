/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00147550 */

void _ipc_kmsg_free(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 == -2) {
    _KernDeviceInterruptMsgRelease(param_1);
    return;
  }
  if (iVar1 != -1) {
    if (iVar1 == -3) {
      _netipc_msg_release(param_1);
      return;
    }
    _kfree(param_1,iVar1);
  }
  return;
}


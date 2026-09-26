/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00147770 */

void _ipc_kmsg_put_to_kernel(void *param_1,int param_2,size_t param_3)

{
  int iVar1;
  
  _bcopy((void *)(param_2 + 0x14),param_1,param_3);
  iVar1 = *(int *)(param_2 + 8);
  if (iVar1 < 1) {
    if (iVar1 == -2) {
      _KernDeviceInterruptMsgRelease(param_2);
      return;
    }
    if (iVar1 == -1) {
      return;
    }
    if (iVar1 == -3) {
      _netipc_msg_release(param_2);
      return;
    }
  }
  _kfree(param_2,iVar1);
  return;
}


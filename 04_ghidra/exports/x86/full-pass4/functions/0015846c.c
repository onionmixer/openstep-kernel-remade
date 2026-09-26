/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015846c */

undefined4 _mach_msg_send_from_kernel(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_8;
  
  if ((*(int *)(param_1 + 8) != 0) && (*(int *)(param_1 + 8) != -1)) {
    iVar1 = _ipc_kmsg_get_from_kernel(param_1,param_2,0,&local_8);
    if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_mach_msg_send_from_kernel_001dec47);
    }
    _ipc_kmsg_copyin_from_kernel(local_8);
    _ipc_mqueue_send(local_8,0x10000,0,0);
    return 0;
  }
  return 0x10000003;
}


/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001586d4 */

void _msg_send_from_kernel(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 local_8;
  
  uVar3 = *(int *)(param_1 + 4) + 3U & 0xfffffffc;
  iVar1 = _ipc_kmsg_get_from_kernel(param_1,uVar3,*(int *)(param_1 + 4) - uVar3,&local_8);
  if (iVar1 == 0) {
    _ipc_kmsg_copyin_compat_from_kernel(local_8);
    if ((param_2 & 2) != 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_msg_send_from_kernel_001dec6a);
    }
    uVar2 = 0x30000;
    if ((param_2 & 1) != 0) {
      uVar2 = 0x30010;
    }
    iVar1 = _ipc_mqueue_send(local_8,uVar2,param_3,0);
    if (iVar1 != 0) {
      _ipc_kmsg_destroy(local_8);
    }
  }
  _msg_return_translate(iVar1);
  return;
}


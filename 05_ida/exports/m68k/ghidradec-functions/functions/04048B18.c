
void _msg_send_from_kernel(int param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uStack_8;
  
  uVar1 = *(int *)(param_1 + 4) + 3U & 0xfffffffc;
  iVar2 = _ipc_kmsg_get_from_kernel(param_1,uVar1,*(int *)(param_1 + 4) - uVar1,&uStack_8);
  if (iVar2 == 0) {
    _ipc_kmsg_copyin_compat_from_kernel(uStack_8);
    if ((param_2 & 2) != 0) {
                    /* WARNING: Subroutine does not return */
      _panic(aMsgSendFromKer);
    }
    uVar3 = 0x30000;
    if ((param_2 & 1) != 0) {
      uVar3 = 0x30010;
    }
    iVar2 = _ipc_mqueue_send(uStack_8,uVar3,param_3,0);
    if (iVar2 != 0) {
      _ipc_kmsg_destroy(uStack_8);
    }
  }
  _msg_return_translate(iVar2);
  return;
}

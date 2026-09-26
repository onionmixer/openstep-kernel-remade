
undefined4 _msg_send(int param_1,uint param_2,undefined4 param_3)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iStack_8;
  
  uVar3 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x7c);
  uVar1 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 8);
  uVar2 = *(int *)(param_1 + 4) + 3U & 0xfffffffc;
  if (uVar2 < 0x2001) {
    iVar4 = _ipc_kmsg_get_from_kernel(param_1,uVar2,*(int *)(param_1 + 4) - uVar2,&iStack_8);
    if (iVar4 == 0) {
      iVar4 = _ipc_kmsg_copyin_compat(iStack_8,uVar3,uVar1);
      if (iVar4 == 0) {
        if ((param_2 & 2) != 0) {
                    /* WARNING: Subroutine does not return */
          _panic(aMsgSendNotify);
        }
        do {
          if ((param_2 & 0x20) == 0) {
            uVar3 = 0;
            if ((param_2 & 1) != 0) {
              uVar3 = 0x10;
            }
          }
          else {
            uVar3 = 0x20000;
            if ((param_2 & 1) != 0) {
              uVar3 = 0x20010;
            }
          }
          iVar4 = _ipc_mqueue_send(iStack_8,uVar3,param_3,0);
          if (iVar4 != 0x10000007) break;
          while ((*(uint *)(_active_threads + 0x177) & 0x3ffffff) >> 0x18 != 0) {
            _thread_halt_self_with_continuation(0);
          }
        } while ((param_2 & 4) == 0);
        if (iVar4 != 0) {
          _ipc_kmsg_destroy(iStack_8);
        }
      }
      else if (*(int *)(iStack_8 + 8) < 1) {
        _ipc_kmsg_free(iStack_8);
      }
      else {
        _kfree(iStack_8,*(int *)(iStack_8 + 8));
      }
    }
    uVar3 = _msg_return_translate(iVar4);
  }
  else {
    uVar3 = 0xffffff93;
  }
  return uVar3;
}

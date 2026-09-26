/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00158774 */

undefined4 _msg_send(int param_1,uint param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int local_8;
  
  uVar2 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x88);
  uVar1 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0xc);
  uVar4 = *(int *)(param_1 + 4) + 3U & 0xfffffffc;
  if (uVar4 < 0x2001) {
    iVar3 = _ipc_kmsg_get_from_kernel(param_1,uVar4,*(int *)(param_1 + 4) - uVar4,&local_8);
    if (iVar3 == 0) {
      iVar3 = _ipc_kmsg_copyin_compat(local_8,uVar2,uVar1);
      if (iVar3 == 0) {
        if ((param_2 & 2) != 0) {
                    /* WARNING: Subroutine does not return */
          _panic(s_msg_send_notify_001dec7f);
        }
        do {
          if ((param_2 & 0x20) == 0) {
            uVar2 = 0;
            if ((param_2 & 1) != 0) {
              uVar2 = 0x10;
            }
          }
          else {
            uVar2 = 0x20000;
            if ((param_2 & 1) != 0) {
              uVar2 = 0x20010;
            }
          }
          iVar3 = _ipc_mqueue_send(local_8,uVar2,param_3,0);
          if (iVar3 != 0x10000007) break;
          while ((*(byte *)(_active_threads + 0x17c) & 3) != 0) {
            _thread_halt_self_with_continuation(0);
          }
        } while ((param_2 & 4) == 0);
        if (iVar3 != 0) {
          _ipc_kmsg_destroy(local_8);
        }
        uVar2 = _msg_return_translate(iVar3);
      }
      else {
        if (*(int *)(local_8 + 8) < 1) {
          _ipc_kmsg_free(local_8);
        }
        else {
          _kfree(local_8,*(int *)(local_8 + 8));
        }
        uVar2 = _msg_return_translate(iVar3);
      }
    }
    else {
      uVar2 = _msg_return_translate(iVar3);
    }
  }
  else {
    uVar2 = 0xffffff93;
  }
  return uVar2;
}


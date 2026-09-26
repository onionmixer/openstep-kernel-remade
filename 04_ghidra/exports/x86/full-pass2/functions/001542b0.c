/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001542b0 */

undefined4 _msg_send_trap(undefined4 param_1,uint param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  code *pcVar6;
  int local_8;
  
  uVar2 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x88);
  uVar3 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0xc);
  uVar5 = param_3 + 3U & 0xfffffffc;
  if (0x2000 < uVar5) {
    return 0xffffff93;
  }
  iVar1 = _ipc_kmsg_get(param_1,uVar5,param_3 - uVar5,&local_8);
  if (iVar1 != 0) {
    uVar2 = _msg_return_translate(iVar1);
    return uVar2;
  }
  iVar1 = _ipc_kmsg_copyin_compat(local_8,uVar2,uVar3);
  if (iVar1 != 0) {
    if (*(int *)(local_8 + 8) < 1) {
      _ipc_kmsg_free(local_8);
    }
    else {
      _kfree(local_8,*(int *)(local_8 + 8));
    }
    uVar2 = _msg_return_translate(iVar1);
    return uVar2;
  }
  if ((param_2 & 2) == 0) {
    if ((param_2 & 0x20) == 0) {
      pcVar6 = (code *)0x0;
      uVar2 = 0;
      if ((param_2 & 1) != 0) {
        uVar2 = 0x10;
      }
    }
    else {
      pcVar6 = _msg_send_switch_continue;
      uVar2 = 0x20000;
      if ((param_2 & 1) != 0) {
        uVar2 = 0x20010;
      }
    }
    iVar1 = _ipc_mqueue_send(local_8,uVar2,param_4,pcVar6);
LAB_00154428:
    if (iVar1 == 0) goto LAB_00154438;
  }
  else {
    uVar3 = 0;
    if ((param_2 & 1) != 0) {
      uVar3 = param_4;
    }
    uVar4 = 0x10;
    if ((param_2 & 0x20) != 0) {
      uVar4 = 0x20010;
    }
    iVar1 = _ipc_mqueue_send(local_8,uVar4,uVar3,0);
    if (iVar1 != 0x10000004) goto LAB_00154428;
    iVar1 = _ipc_marequest_create(uVar2,*(undefined4 *)(local_8 + 0x1c),0,local_8 + 0xc);
    if (iVar1 == 0) {
      _ipc_mqueue_send(local_8,0x10000,0,0);
      return 0xffffff97;
    }
  }
  _ipc_kmsg_destroy(local_8);
LAB_00154438:
  uVar2 = _msg_return_translate(iVar1);
  return uVar2;
}


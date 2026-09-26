
undefined4 _msg_send_trap(undefined4 param_1,uint param_2,int param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  code *pcVar6;
  int iStack_8;
  
  uVar5 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x7c);
  uVar3 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 8);
  uVar1 = param_3 + 3U & 0xfffffffc;
  if (0x2000 < uVar1) {
    return 0xffffff93;
  }
  iVar2 = _ipc_kmsg_get(param_1,uVar1,param_3 - uVar1,&iStack_8);
  if (iVar2 != 0) goto loc_40458DE;
  iVar2 = _ipc_kmsg_copyin_compat(iStack_8,uVar5,uVar3);
  if (iVar2 != 0) {
    if (*(int *)(iStack_8 + 8) < 1) {
      _ipc_kmsg_free(iStack_8);
    }
    else {
      _kfree(iStack_8,*(int *)(iStack_8 + 8));
    }
    goto loc_40458DE;
  }
  if ((param_2 & 2) == 0) {
    if ((param_2 & 0x20) == 0) {
      pcVar6 = (code *)0x0;
      uVar5 = 0;
      if ((param_2 & 1) != 0) {
        uVar5 = 0x10;
      }
    }
    else {
      pcVar6 = _msg_send_switch_continue;
      uVar5 = 0x20000;
      if ((param_2 & 1) != 0) {
        uVar5 = 0x20010;
      }
    }
    iVar2 = _ipc_mqueue_send(iStack_8,uVar5,param_4,pcVar6);
loc_40458CE:
    if (iVar2 == 0) goto loc_40458DE;
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
    iVar2 = _ipc_mqueue_send(iStack_8,uVar4,uVar3,0);
    if (iVar2 != 0x10000004) goto loc_40458CE;
    iVar2 = _ipc_marequest_create(uVar5,*(undefined4 *)(iStack_8 + 0x1c),0,iStack_8 + 0xc);
    if (iVar2 == 0) {
      _ipc_mqueue_send(iStack_8,0x10000,0,0);
      return 0xffffff97;
    }
  }
  _ipc_kmsg_destroy(iStack_8);
loc_40458DE:
  uVar5 = _msg_return_translate(iVar2);
  return uVar5;
}

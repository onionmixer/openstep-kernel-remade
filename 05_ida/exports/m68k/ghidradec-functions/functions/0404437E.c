
uint _mach_msg_send(undefined4 param_1,byte param_2,undefined4 param_3,undefined4 param_4,
                   int param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int iStack_8;
  
  uVar1 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x7c);
  uVar2 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 8);
  uVar3 = _ipc_kmsg_get(param_1,param_3,0,&iStack_8);
  if (uVar3 != 0) {
    return uVar3;
  }
  if ((char)param_2 < '\0') {
    iVar6 = param_5;
    if (param_5 == 0) {
      uVar3 = 0x1000000b;
      goto loc_40443FE;
    }
  }
  else {
    iVar6 = 0;
  }
  uVar3 = _ipc_kmsg_copyin(iStack_8,uVar1,uVar2,iVar6);
  if (uVar3 != 0) {
loc_40443FE:
    if (*(int *)(iStack_8 + 8) < 1) {
      _ipc_kmsg_free(iStack_8);
    }
    else {
      _kfree(iStack_8,*(int *)(iStack_8 + 8));
    }
    return uVar3;
  }
  if ((param_2 & 0x20) == 0) {
    uVar3 = _ipc_mqueue_send(iStack_8,param_2 & 0x10,param_4,0);
  }
  else {
    uVar4 = 0;
    if ((param_2 & 0x10) != 0) {
      uVar4 = param_4;
    }
    uVar3 = _ipc_mqueue_send(iStack_8,0x10,uVar4,0);
    if (uVar3 == 0x10000004) {
      if (param_5 == 0) {
        uVar3 = 0x1000000b;
      }
      else {
        uVar3 = _ipc_marequest_create(uVar1,*(undefined4 *)(iStack_8 + 0x1c),param_5,iStack_8 + 0xc)
        ;
        if (uVar3 == 0) {
          _ipc_mqueue_send(iStack_8,0x10000,0,0);
          return 0x10000005;
        }
      }
      goto loc_40444A8;
    }
  }
  if (uVar3 == 0) {
    return 0;
  }
loc_40444A8:
  uVar5 = _ipc_kmsg_copyout_pseudo(iStack_8,uVar1,uVar2);
  _ipc_kmsg_put(param_1,iStack_8,*(int *)(iStack_8 + 0x10) + *(int *)(iStack_8 + 0x18));
  return uVar5 | uVar3;
}

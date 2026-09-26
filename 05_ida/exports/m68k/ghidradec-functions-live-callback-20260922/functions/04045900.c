
undefined4
_msg_receive_trap(int param_1,uint param_2,uint param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int iStack_18;
  undefined auStack_14 [4];
  int iStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uVar5 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x7c);
  uVar1 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 8);
  iVar3 = _ipc_mqueue_copyin(uVar5,param_4,&uStack_8,&uStack_c);
  iVar2 = _active_threads;
  if (iVar3 == 0) {
    *(int *)(_active_threads + 0xbc) = param_1;
    *(uint *)(iVar2 + 0xc0) = param_2;
    *(uint *)(iVar2 + 0xc4) = param_3;
    *(undefined4 *)(iVar2 + 200) = param_5;
    *(undefined4 *)(iVar2 + 0xd0) = uStack_c;
    *(undefined4 *)(iVar2 + 0xd4) = uStack_8;
    uVar4 = 0xffffffff;
    if ((param_2 & 0x1000) != 0) {
      uVar4 = param_3;
    }
    iVar3 = _ipc_mqueue_receive(uStack_8,param_2 & 0x100,uVar4,param_5,0,_msg_receive_continue,
                                &iStack_10,auStack_14);
    _ipc_object_release(uStack_c);
    if (iVar3 == 0) {
      if (*(uint *)(iStack_10 + 0x18) <= param_3) {
        _ipc_kmsg_copyout_compat(iStack_10,uVar5,uVar1);
        iVar2 = *(int *)(iStack_10 + 0x10) + *(int *)(iStack_10 + 0x18);
        *(int *)(iStack_10 + 0x18) = iVar2;
        uVar5 = _ipc_kmsg_put(param_1,iStack_10,iVar2);
        uVar5 = _msg_return_translate(uVar5);
        return uVar5;
      }
      _ipc_kmsg_destroy(iStack_10);
      return 0xffffff34;
    }
    if (iVar3 == 0x10004004) {
      iStack_18 = iStack_10;
      _copyoutmsg(&iStack_18,param_1 + 4,4);
    }
  }
  uVar5 = _msg_return_translate(iVar3);
  return uVar5;
}


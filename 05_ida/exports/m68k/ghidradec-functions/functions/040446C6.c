
void _mach_msg_receive_continue(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  int iStack_10;
  undefined4 uStack_c;
  int iStack_8;
  
  uVar6 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x7c);
  uVar1 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 8);
  iVar2 = *(int *)(_active_threads + 0xbc);
  uVar7 = *(uint *)(_active_threads + 0xc0);
  uVar3 = *(uint *)(_active_threads + 0xc4);
  iVar8 = *(int *)(_active_threads + 0xcc);
  uVar4 = *(undefined4 *)(_active_threads + 0xd0);
  if ((uVar7 & 0x800) == 0) {
    iVar5 = _ipc_mqueue_receive(*(undefined4 *)(_active_threads + 0xd4),uVar7 & 0x100,0xffffffff,
                                *(undefined4 *)(_active_threads + 200),1,_mach_msg_receive_continue,
                                &iStack_8,&uStack_c);
    _ipc_object_release(uVar4);
    if (iVar5 != 0) {
      _thread_syscall_return(iVar5);
    }
    *(undefined4 *)(iStack_8 + 0x24) = uStack_c;
    if (uVar3 < *(uint *)(iStack_8 + 0x18)) {
      _ipc_kmsg_copyout_dest(iStack_8,uVar6);
      _ipc_kmsg_put(iVar2,iStack_8,0x18);
      _thread_syscall_return(0x10004004);
    }
  }
  else {
    iVar5 = _ipc_mqueue_receive(*(undefined4 *)(_active_threads + 0xd4),uVar7 & 0x100,uVar3,
                                *(undefined4 *)(_active_threads + 200),1,_mach_msg_receive_continue,
                                &iStack_8,&uStack_c);
    _ipc_object_release(uVar4);
    if (iVar5 != 0) {
      if (iVar5 == 0x10004004) {
        iStack_10 = iStack_8;
        _copyoutmsg(&iStack_10,iVar2 + 4,4);
      }
      _thread_syscall_return(iVar5);
    }
    *(undefined4 *)(iStack_8 + 0x24) = uStack_c;
  }
  if ((uVar7 & 0x200) == 0) {
    iVar8 = 0;
loc_4044816:
    uVar7 = _ipc_kmsg_copyout(iStack_8,uVar6,uVar1,iVar8);
    if (uVar7 == 0) goto loc_4044882;
  }
  else {
    if (iVar8 != 0) goto loc_4044816;
    uVar7 = 0x10004007;
  }
  if ((uVar7 & 0xffffc3ff) == 0x1000400c) {
    _ipc_kmsg_put(iVar2,iStack_8,*(int *)(iStack_8 + 0x10) + *(int *)(iStack_8 + 0x18));
  }
  else {
    _ipc_kmsg_copyout_dest(iStack_8,uVar6);
    _ipc_kmsg_put(iVar2,iStack_8,0x18);
  }
  _thread_syscall_return(uVar7);
loc_4044882:
  uVar6 = _ipc_kmsg_put(iVar2,iStack_8,*(int *)(iStack_8 + 0x10) + *(int *)(iStack_8 + 0x18));
  _thread_syscall_return(uVar6);
  return;
}

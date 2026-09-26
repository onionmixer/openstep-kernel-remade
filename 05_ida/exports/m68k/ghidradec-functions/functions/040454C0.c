
void _mach_msg_continue(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uStack_c;
  int iStack_8;
  
  uVar6 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x7c);
  uVar1 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 8);
  uVar2 = *(undefined4 *)(_active_threads + 0xbc);
  uVar5 = *(uint *)(_active_threads + 0xc4);
  uVar3 = *(undefined4 *)(_active_threads + 0xd0);
  iVar4 = _ipc_mqueue_receive(*(undefined4 *)(_active_threads + 0xd4),0,0xffffffff,0,1,
                              _mach_msg_continue,&iStack_8,&uStack_c);
  _ipc_object_release(uVar3);
  if (iVar4 != 0) {
    _thread_syscall_return(iVar4);
  }
  *(undefined4 *)(iStack_8 + 0x24) = uStack_c;
  if (uVar5 < *(uint *)(iStack_8 + 0x18)) {
    _ipc_kmsg_copyout_dest(iStack_8,uVar6);
    _ipc_kmsg_put(uVar2,iStack_8,0x18);
    _thread_syscall_return(0x10004004);
  }
  uVar5 = _ipc_kmsg_copyout(iStack_8,uVar6,uVar1,0);
  if (uVar5 != 0) {
    if ((uVar5 & 0xffffc3ff) == 0x1000400c) {
      _ipc_kmsg_put(uVar2,iStack_8,*(int *)(iStack_8 + 0x10) + *(int *)(iStack_8 + 0x18));
    }
    else {
      _ipc_kmsg_copyout_dest(iStack_8,uVar6);
      _ipc_kmsg_put(uVar2,iStack_8,0x18);
    }
    _thread_syscall_return(uVar5);
  }
  uVar6 = _ipc_kmsg_put(uVar2,iStack_8,*(int *)(iStack_8 + 0x10) + *(int *)(iStack_8 + 0x18));
  _thread_syscall_return(uVar6);
  return;
}

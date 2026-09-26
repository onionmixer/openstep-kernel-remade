
void _msg_receive_continue(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int iStack_10;
  undefined auStack_c [4];
  int iStack_8;
  
  iVar1 = *(int *)(_active_threads + 0xbc);
  uVar2 = *(uint *)(_active_threads + 0xc4);
  uVar5 = *(undefined4 *)(_active_threads + 0xd0);
  uVar3 = 0xffffffff;
  if ((*(uint *)(_active_threads + 0xc0) & 0x1000) != 0) {
    uVar3 = uVar2;
  }
  iVar4 = _ipc_mqueue_receive(*(undefined4 *)(_active_threads + 0xd4),
                              *(uint *)(_active_threads + 0xc0) & 0x100,uVar3,
                              *(undefined4 *)(_active_threads + 200),1,_msg_receive_continue,
                              &iStack_8,auStack_c);
  _ipc_object_release(uVar5);
  if (iVar4 != 0) {
    if (iVar4 == 0x10004004) {
      iStack_10 = iStack_8;
      _copyoutmsg(&iStack_10,iVar1 + 4,4);
    }
    uVar5 = _msg_return_translate(iVar4);
    _thread_syscall_return(uVar5);
  }
  if (uVar2 < *(uint *)(iStack_8 + 0x18)) {
    _ipc_kmsg_destroy(iStack_8);
    _thread_syscall_return(0xffffff34);
  }
  _ipc_kmsg_copyout_compat
            (iStack_8,*(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x7c),
             *(undefined4 *)(*(int *)(_active_threads + 0xc) + 8));
  iVar4 = *(int *)(iStack_8 + 0x10) + *(int *)(iStack_8 + 0x18);
  *(int *)(iStack_8 + 0x18) = iVar4;
  uVar5 = _ipc_kmsg_put(iVar1,iStack_8,iVar4);
  uVar5 = _msg_return_translate(uVar5);
  _thread_syscall_return(uVar5);
  return;
}


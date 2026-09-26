
void _msg_receive_continue(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int local_10;
  undefined1 local_c [4];
  int local_8;
  
  iVar1 = *(int *)(_active_threads + 0xc4);
  uVar2 = *(uint *)(_active_threads + 0xcc);
  uVar5 = *(undefined4 *)(_active_threads + 0xd8);
  uVar3 = 0xffffffff;
  if ((*(uint *)(_active_threads + 200) & 0x1000) != 0) {
    uVar3 = uVar2;
  }
  iVar4 = _ipc_mqueue_receive(*(undefined4 *)(_active_threads + 0xdc),
                              *(uint *)(_active_threads + 200) & 0x100,uVar3,
                              *(undefined4 *)(_active_threads + 0xd0),1,_msg_receive_continue,
                              &local_8,local_c);
  _ipc_object_release(uVar5);
  if (iVar4 != 0) {
    if (iVar4 == 0x10004004) {
      local_10 = local_8;
      _copyout(&local_10,iVar1 + 4,4);
    }
    uVar5 = _msg_return_translate(iVar4);
                    /* WARNING: Subroutine does not return */
    _thread_syscall_return(uVar5);
  }
  if (uVar2 < *(uint *)(local_8 + 0x18)) {
    _ipc_kmsg_destroy(local_8);
                    /* WARNING: Subroutine does not return */
    _thread_syscall_return(0xffffff34);
  }
  _ipc_kmsg_copyout_compat
            (local_8,*(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x88),
             *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0xc));
  iVar4 = *(int *)(local_8 + 0x18) + *(int *)(local_8 + 0x10);
  *(int *)(local_8 + 0x18) = iVar4;
  uVar5 = _ipc_kmsg_put(iVar1,local_8,iVar4);
  uVar5 = _msg_return_translate(uVar5);
                    /* WARNING: Subroutine does not return */
  _thread_syscall_return(uVar5);
}



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
  int local_10;
  undefined4 local_c;
  int local_8;
  
  uVar6 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x88);
  uVar1 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0xc);
  iVar2 = *(int *)(_active_threads + 0xc4);
  uVar7 = *(uint *)(_active_threads + 200);
  uVar3 = *(uint *)(_active_threads + 0xcc);
  iVar8 = *(int *)(_active_threads + 0xd4);
  uVar4 = *(undefined4 *)(_active_threads + 0xd8);
  if ((uVar7 & 0x800) == 0) {
    iVar5 = _ipc_mqueue_receive(*(undefined4 *)(_active_threads + 0xdc),uVar7 & 0x100,0xffffffff,
                                *(undefined4 *)(_active_threads + 0xd0),1,_mach_msg_receive_continue
                                ,&local_8,&local_c);
    _ipc_object_release(uVar4);
    if (iVar5 != 0) {
                    /* WARNING: Subroutine does not return */
      _thread_syscall_return(iVar5);
    }
    *(undefined4 *)(local_8 + 0x24) = local_c;
    if (uVar3 < *(uint *)(local_8 + 0x18)) {
      _ipc_kmsg_copyout_dest(local_8,uVar6);
      _ipc_kmsg_put(iVar2,local_8,0x18);
                    /* WARNING: Subroutine does not return */
      _thread_syscall_return(0x10004004);
    }
  }
  else {
    iVar5 = _ipc_mqueue_receive(*(undefined4 *)(_active_threads + 0xdc),uVar7 & 0x100,uVar3,
                                *(undefined4 *)(_active_threads + 0xd0),1,_mach_msg_receive_continue
                                ,&local_8,&local_c);
    _ipc_object_release(uVar4);
    if (iVar5 != 0) {
      if (iVar5 == 0x10004004) {
        local_10 = local_8;
        _copyout(&local_10,iVar2 + 4,4);
      }
                    /* WARNING: Subroutine does not return */
      _thread_syscall_return(iVar5);
    }
    *(undefined4 *)(local_8 + 0x24) = local_c;
  }
  if ((uVar7 & 0x200) == 0) {
    iVar8 = 0;
  }
  else if (iVar8 == 0) {
    uVar7 = 0x10004007;
    goto LAB_00152a79;
  }
  uVar7 = _ipc_kmsg_copyout(local_8,uVar6,uVar1,iVar8);
  if (uVar7 == 0) {
    uVar6 = _ipc_kmsg_put(iVar2,local_8,*(int *)(local_8 + 0x18) + *(int *)(local_8 + 0x10));
                    /* WARNING: Subroutine does not return */
    _thread_syscall_return(uVar6);
  }
LAB_00152a79:
  if ((uVar7 & 0xffffc3ff) == 0x1000400c) {
    _ipc_kmsg_put(iVar2,local_8,*(int *)(local_8 + 0x18) + *(int *)(local_8 + 0x10));
  }
  else {
    _ipc_kmsg_copyout_dest(local_8,uVar6);
    _ipc_kmsg_put(iVar2,local_8,0x18);
  }
                    /* WARNING: Subroutine does not return */
  _thread_syscall_return(uVar7);
}


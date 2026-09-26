/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00153f34 */

void _mach_msg_continue(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 local_c;
  int local_8;
  
  uVar6 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x88);
  uVar1 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0xc);
  uVar2 = *(undefined4 *)(_active_threads + 0xc4);
  uVar5 = *(uint *)(_active_threads + 0xcc);
  uVar3 = *(undefined4 *)(_active_threads + 0xd8);
  iVar4 = _ipc_mqueue_receive(*(undefined4 *)(_active_threads + 0xdc),0,0xffffffff,0,1,
                              _mach_msg_continue,&local_8,&local_c);
  _ipc_object_release(uVar3);
  if (iVar4 != 0) {
    _thread_syscall_return(iVar4);
  }
  *(undefined4 *)(local_8 + 0x24) = local_c;
  if (uVar5 < *(uint *)(local_8 + 0x18)) {
    _ipc_kmsg_copyout_dest(local_8,uVar6);
    _ipc_kmsg_put(uVar2,local_8,0x18);
    _thread_syscall_return(0x10004004);
  }
  uVar5 = _ipc_kmsg_copyout(local_8,uVar6,uVar1,0);
  if (uVar5 != 0) {
    if ((uVar5 & 0xffffc3ff) == 0x1000400c) {
      _ipc_kmsg_put(uVar2,local_8,*(int *)(local_8 + 0x18) + *(int *)(local_8 + 0x10));
    }
    else {
      _ipc_kmsg_copyout_dest(local_8,uVar6);
      _ipc_kmsg_put(uVar2,local_8,0x18);
    }
    _thread_syscall_return(uVar5);
  }
  uVar6 = _ipc_kmsg_put(uVar2,local_8,*(int *)(local_8 + 0x18) + *(int *)(local_8 + 0x10));
  _thread_syscall_return(uVar6);
  return;
}


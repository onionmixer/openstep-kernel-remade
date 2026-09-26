
/* WARNING: Removing unreachable block (ram,0xf005fd80) */
/* WARNING: Removing unreachable block (ram,0xf005fd60) */
/* WARNING: Removing unreachable block (ram,0xf005fd04) */
/* WARNING: Removing unreachable block (ram,0xf005fc1c) */
/* WARNING: Removing unreachable block (ram,0xf005fbe0) */
/* WARNING: Removing unreachable block (ram,0xf005fcb0) */
/* WARNING: Removing unreachable block (ram,0xf005fc7c) */
/* WARNING: Removing unreachable block (ram,0xf005fc68) */
/* WARNING: Removing unreachable block (ram,0xf005fca0) */
/* WARNING: Removing unreachable block (ram,0xf005fcbc) */
/* WARNING: Removing unreachable block (ram,0xf005fbec) */
/* WARNING: Removing unreachable block (ram,0xf005fc24) */
/* WARNING: Removing unreachable block (ram,0xf005fd4c) */
/* WARNING: Removing unreachable block (ram,0xf005fd68) */
/* WARNING: Removing unreachable block (ram,0xf005fd88) */
/* WARNING: Removing unreachable block (ram,0xf005fc5c) */
/* WARNING: Heritage AFTER dead removal. Example location: o1 : 0xf005fc5c */
/* WARNING: Restarted to delay deadcode elimination for space: register */

int _mach_msg_receive_continue(void)

{
  int iVar1;
  undefined8 in_o0_1;
  undefined4 uVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar4;
  undefined4 uVar5;
  undefined4 unaff_l3;
  undefined4 uVar6;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  uint uVar7;
  undefined4 unaff_l6;
  int iVar8;
  undefined4 unaff_l7;
  undefined4 uVar9;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  iVar1 = (int)((qword)in_o0_1 >> 0x20);
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  uVar5 = *(undefined4 *)(_active_threads + 0xc4);
  uVar4 = *(uint *)(_active_threads + 200);
  uVar7 = *(uint *)(_active_threads + 0xcc);
  iVar8 = *(int *)(_active_threads + 0xd4);
  uVar6 = *(undefined4 *)(_active_threads + 0xd8);
  uVar9 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0xc);
  uVar2 = (undefined4)in_o0_1;
  if ((uVar4 & 0x800) == 0) {
    _ipc_mqueue_receive(*(undefined4 *)(_active_threads + 0xdc),uVar2,0xffffffff,
                        *(undefined4 *)(_active_threads + 0xd0),1,_mach_msg_receive_continue);
    _ipc_object_release(uVar6);
    iVar3 = *(int *)((int)register0x00000038 + -0xc);
    if (iVar1 != 0) {
      _thread_syscall_return(iVar1);
      iVar3 = *(int *)((int)register0x00000038 + -0xc);
    }
    *(undefined4 *)(iVar3 + 0x24) = *(undefined4 *)((int)register0x00000038 + -0x10);
    if (uVar7 < *(uint *)(iVar3 + 0x18)) {
      _ipc_kmsg_copyout_dest(iVar3);
      _ipc_kmsg_put(uVar5,uVar2,0x18);
      _thread_syscall_return(0x10004004);
    }
  }
  else {
    _ipc_mqueue_receive(*(undefined4 *)(_active_threads + 0xdc),uVar2,uVar7,
                        *(undefined4 *)(_active_threads + 0xd0),1,_mach_msg_receive_continue);
    _ipc_object_release(uVar6);
    if (iVar1 != 0) {
      if (iVar1 == 0x10004004) {
        *(undefined4 *)((int)register0x00000038 + -0x14) =
             *(undefined4 *)((int)register0x00000038 + -0xc);
        _copyout((undefined *)((int)register0x00000038 + -0x14),uVar2,4);
      }
      _thread_syscall_return(iVar1);
    }
    in_o0_1 = *(undefined8 *)((int)register0x00000038 + -0x10);
    *(int *)((int)in_o0_1 + 0x24) = (int)((qword)in_o0_1 >> 0x20);
  }
  uVar2 = (undefined4)in_o0_1;
  if ((uVar4 & 0x200) == 0) {
    iVar8 = 0;
  }
  else if (iVar8 == 0) {
    uVar4 = 0x10004007;
    goto loc_F005FD10;
  }
  uVar4 = (uint)((qword)in_o0_1 >> 0x20);
  _ipc_kmsg_copyout(uVar4,uVar2,uVar9,iVar8);
loc_F005FD10:
  if (uVar4 != 0) {
    if ((uVar4 & 0xffffc3ff) == 0x1000400c) {
      iVar8 = *(int *)(*(int *)((int)register0x00000038 + -0xc) + 0x18) +
              *(int *)(*(int *)((int)register0x00000038 + -0xc) + 0x10);
    }
    else {
      _ipc_kmsg_copyout_dest(*(undefined4 *)((int)register0x00000038 + -0xc));
      iVar8 = 0x18;
    }
    _ipc_kmsg_put(uVar5,uVar2,iVar8);
    _thread_syscall_return(uVar4);
  }
  _ipc_kmsg_put(uVar5,uVar2,
                *(int *)(*(int *)((int)register0x00000038 + -0xc) + 0x18) +
                *(int *)(*(int *)((int)register0x00000038 + -0xc) + 0x10));
  _thread_syscall_return();
  return iVar1;
}

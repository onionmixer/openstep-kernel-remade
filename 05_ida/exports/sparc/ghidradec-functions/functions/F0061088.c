
/* WARNING: Removing unreachable block (ram,0xf00611c0) */
/* WARNING: Removing unreachable block (ram,0xf00611a0) */
/* WARNING: Removing unreachable block (ram,0xf0061148) */
/* WARNING: Removing unreachable block (ram,0xf0061128) */
/* WARNING: Removing unreachable block (ram,0xf00610f4) */
/* WARNING: Removing unreachable block (ram,0xf00610e0) */
/* WARNING: Removing unreachable block (ram,0xf0061118) */
/* WARNING: Removing unreachable block (ram,0xf0061134) */
/* WARNING: Removing unreachable block (ram,0xf006118c) */
/* WARNING: Removing unreachable block (ram,0xf00611a8) */
/* WARNING: Removing unreachable block (ram,0xf00611c8) */
/* WARNING: Removing unreachable block (ram,0xf00610d4) */

undefined8 _mach_msg_continue(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 uVar3;
  undefined4 unaff_l1;
  undefined4 uVar4;
  undefined4 unaff_l3;
  undefined4 uVar5;
  undefined4 unaff_l4;
  uint uVar6;
  undefined4 unaff_l5;
  undefined4 uVar7;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
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
  uVar6 = *(uint *)(_active_threads + 0xcc);
  uVar3 = *(undefined4 *)(_active_threads + 0xd8);
  uVar4 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x88);
  uVar7 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0xc);
  iVar1 = *(int *)(_active_threads + 0xdc);
  _ipc_mqueue_receive(iVar1,0,0xffffffff,0,1,_mach_msg_continue,
                      (undefined *)((int)register0x00000038 + -0xc),
                      (undefined *)((int)register0x00000038 + -0x10));
  _ipc_object_release(uVar3);
  iVar2 = *(int *)((int)register0x00000038 + -0xc);
  if (iVar1 != 0) {
    _thread_syscall_return(iVar1);
    iVar2 = *(int *)((int)register0x00000038 + -0xc);
  }
  *(undefined4 *)(iVar2 + 0x24) = *(undefined4 *)((int)register0x00000038 + -0x10);
  if (uVar6 < *(uint *)(iVar2 + 0x18)) {
    _ipc_kmsg_copyout_dest(iVar2,uVar4);
    _ipc_kmsg_put(uVar5,*(undefined4 *)((int)register0x00000038 + -0xc),0x18);
    _thread_syscall_return(0x10004004);
  }
  uVar6 = *(uint *)((int)register0x00000038 + -0xc);
  _ipc_kmsg_copyout(uVar6,uVar4,uVar7,0);
  if (uVar6 != 0) {
    if ((uVar6 & 0xffffc3ff) == 0x1000400c) {
      iVar1 = *(int *)((int)register0x00000038 + -0xc);
      iVar2 = *(int *)(iVar1 + 0x18) + *(int *)(iVar1 + 0x10);
    }
    else {
      _ipc_kmsg_copyout_dest(*(undefined4 *)((int)register0x00000038 + -0xc),uVar4);
      iVar1 = *(int *)((int)register0x00000038 + -0xc);
      iVar2 = 0x18;
    }
    _ipc_kmsg_put(uVar5,iVar1,iVar2);
    _thread_syscall_return(uVar6);
  }
  iVar1 = *(int *)((int)register0x00000038 + -0xc);
  _ipc_kmsg_put(uVar5,iVar1,*(int *)(iVar1 + 0x18) + *(int *)(iVar1 + 0x10));
  _thread_syscall_return();
  return CONCAT44(param_2,param_1);
}

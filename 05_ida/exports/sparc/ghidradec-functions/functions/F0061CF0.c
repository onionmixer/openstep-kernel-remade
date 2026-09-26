
/* WARNING: Removing unreachable block (ram,0xf0061dfc) */
/* WARNING: Removing unreachable block (ram,0xf0061dd8) */
/* WARNING: Removing unreachable block (ram,0xf0061db4) */
/* WARNING: Removing unreachable block (ram,0xf0061d90) */
/* WARNING: Removing unreachable block (ram,0xf0061d58) */
/* WARNING: Removing unreachable block (ram,0xf0061d88) */
/* WARNING: Removing unreachable block (ram,0xf0061d98) */
/* WARNING: Removing unreachable block (ram,0xf0061dbc) */
/* WARNING: Removing unreachable block (ram,0xf0061df4) */
/* WARNING: Removing unreachable block (ram,0xf0061e04) */
/* WARNING: Removing unreachable block (ram,0xf0061d4c) */

undefined8 _msg_receive_continue(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 uVar3;
  uint uVar4;
  undefined4 unaff_l3;
  int iVar5;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
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
  iVar5 = *(int *)(_active_threads + 0xc4);
  uVar4 = *(uint *)(_active_threads + 0xcc);
  uVar3 = *(undefined4 *)(_active_threads + 0xd8);
  iVar1 = *(int *)(_active_threads + 0xdc);
  uVar2 = 0xffffffff;
  if ((*(uint *)(_active_threads + 200) & 0x1000) != 0) {
    uVar2 = uVar4;
  }
  _ipc_mqueue_receive(iVar1,*(uint *)(_active_threads + 200) & 0x100,uVar2,
                      *(undefined4 *)(_active_threads + 0xd0),1,_msg_receive_continue,
                      (undefined *)((int)register0x00000038 + -0xc),
                      (undefined *)((int)register0x00000038 + -0x10));
  _ipc_object_release(uVar3);
  if (iVar1 != 0) {
    if (iVar1 == 0x10004004) {
      *(undefined4 *)((int)register0x00000038 + -0x14) =
           *(undefined4 *)((int)register0x00000038 + -0xc);
      _copyout((undefined *)((int)register0x00000038 + -0x14),iVar5 + 4,4);
    }
    _msg_return_translate(iVar1);
    _thread_syscall_return();
  }
  if (uVar4 < *(uint *)(*(int *)((int)register0x00000038 + -0xc) + 0x18)) {
    _ipc_kmsg_destroy(*(int *)((int)register0x00000038 + -0xc));
    _thread_syscall_return(0xffffff34);
  }
  _ipc_kmsg_copyout_compat
            (*(undefined4 *)((int)register0x00000038 + -0xc),
             *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x88),
             *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0xc));
  iVar1 = *(int *)((int)register0x00000038 + -0xc);
  *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + *(int *)(iVar1 + 0x10);
  _ipc_kmsg_put(iVar5);
  _msg_return_translate();
  _thread_syscall_return();
  return CONCAT44(param_2,param_1);
}

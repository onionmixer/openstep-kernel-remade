
/* WARNING: Removing unreachable block (ram,0xf00616ec) */
/* WARNING: Removing unreachable block (ram,0xf0061714) */
/* WARNING: Removing unreachable block (ram,0xf00616b8) */
/* WARNING: Removing unreachable block (ram,0xf00616ac) */
/* WARNING: Removing unreachable block (ram,0xf0061748) */
/* WARNING: Removing unreachable block (ram,0xf0061730) */
/* WARNING: Removing unreachable block (ram,0xf0061738) */
/* WARNING: Removing unreachable block (ram,0xf0061640) */

undefined8
_msg_receive_trap(int param_1,uint param_2,uint param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar5;
  undefined4 uVar6;
  undefined4 unaff_l3;
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
  iVar5 = *(int *)(*(int *)(_active_threads + 0xc) + 0x88);
  uVar6 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0xc);
  iVar4 = iVar5;
  _ipc_mqueue_copyin(iVar5,param_4,(undefined *)((int)register0x00000038 + -0xc),
                     (undefined *)((int)register0x00000038 + -0x10));
  iVar2 = _active_threads;
  uVar1 = *(undefined4 *)((int)register0x00000038 + -0x10);
  if (iVar4 == 0) {
    iVar4 = *(int *)((int)register0x00000038 + -0xc);
    *(int *)(_active_threads + 0xc4) = param_1;
    *(uint *)(iVar2 + 200) = param_2;
    *(uint *)(iVar2 + 0xcc) = param_3;
    *(undefined4 *)(iVar2 + 0xd0) = param_5;
    *(undefined4 *)(iVar2 + 0xd8) = uVar1;
    *(int *)(iVar2 + 0xdc) = iVar4;
    uVar3 = 0xffffffff;
    if ((param_2 & 0x1000) != 0) {
      uVar3 = param_3;
    }
    _ipc_mqueue_receive(iVar4,param_2 & 0x100,uVar3,param_5,0,_msg_receive_continue,
                        (undefined *)((int)register0x00000038 + -0x14),
                        (undefined *)((int)register0x00000038 + -0x18));
    _ipc_object_release(*(undefined4 *)((int)register0x00000038 + -0x10));
    if (iVar4 == 0) {
      iVar2 = *(int *)((int)register0x00000038 + -0x14);
      if (param_3 < *(uint *)(iVar2 + 0x18)) {
        _ipc_kmsg_destroy(iVar2);
        iVar4 = -0xcc;
        goto locret_F0061754;
      }
      _ipc_kmsg_copyout_compat(iVar2,iVar5,uVar6);
      iVar2 = *(int *)((int)register0x00000038 + -0x14);
      *(int *)(iVar2 + 0x18) = *(int *)(iVar2 + 0x18) + *(int *)(iVar2 + 0x10);
      _ipc_kmsg_put(param_1);
      iVar4 = param_1;
    }
    else if (iVar4 == 0x10004004) {
      *(undefined4 *)((int)register0x00000038 + -0x1c) =
           *(undefined4 *)((int)register0x00000038 + -0x14);
      _copyout((undefined *)((int)register0x00000038 + -0x1c),param_1 + 4,4);
    }
  }
  _msg_return_translate();
locret_F0061754:
  return CONCAT44(param_2,iVar4);
}

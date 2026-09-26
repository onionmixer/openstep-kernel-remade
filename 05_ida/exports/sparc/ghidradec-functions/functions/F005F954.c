
/* WARNING: Removing unreachable block (ram,0xf005fb50) */
/* WARNING: Removing unreachable block (ram,0xf005fb6c) */
/* WARNING: Removing unreachable block (ram,0xf005fa18) */
/* WARNING: Removing unreachable block (ram,0xf005f9dc) */
/* WARNING: Removing unreachable block (ram,0xf005fa90) */
/* WARNING: Removing unreachable block (ram,0xf005fa58) */
/* WARNING: Removing unreachable block (ram,0xf005fa64) */
/* WARNING: Removing unreachable block (ram,0xf005faa0) */
/* WARNING: Removing unreachable block (ram,0xf005f9e8) */
/* WARNING: Removing unreachable block (ram,0xf005faf4) */
/* WARNING: Removing unreachable block (ram,0xf005fb40) */
/* WARNING: Removing unreachable block (ram,0xf005fb34) */
/* WARNING: Removing unreachable block (ram,0xf005f97c) */
/* WARNING: Heritage AFTER dead removal. Example location: o1 : 0xf005f97c */
/* WARNING: Restarted to delay deadcode elimination for space: register */

uint _mach_msg_receive(uint param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  qword in_o0_1;
  undefined8 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 uVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar6;
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
  
  iVar4 = _active_threads;
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
  uVar1 = (uint)(in_o0_1 >> 0x20);
  uVar5 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0xc);
  _ipc_mqueue_copyin(*(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x88),(int)in_o0_1,
                     (undefined *)((int)register0x00000038 + -0xc),
                     (undefined *)((int)register0x00000038 + -0x10));
  if (uVar1 != 0) {
    return uVar1;
  }
  *(undefined4 *)(iVar4 + 0xc4) = 0;
  *(int *)(iVar4 + 200) = (int)in_o0_1;
  *(uint *)(iVar4 + 0xcc) = param_1;
  *(undefined4 *)(iVar4 + 0xd0) = param_3;
  *(int *)(iVar4 + 0xd4) = param_4;
  uVar2 = *(undefined8 *)((int)register0x00000038 + -0x10);
  uVar1 = (uint)((qword)uVar2 >> 0x20);
  *(uint *)(iVar4 + 0xd8) = uVar1;
  uVar3 = (undefined4)uVar2;
  *(undefined4 *)(iVar4 + 0xdc) = uVar3;
  if ((in_o0_1 & 0x800) == 0) {
    _ipc_mqueue_receive(uVar3,uVar3,0xffffffff,param_3,0,_mach_msg_receive_continue);
    _ipc_object_release(*(undefined4 *)((int)register0x00000038 + -0x10));
    iVar4 = *(int *)((int)register0x00000038 + -0x14);
    if (uVar1 != 0) {
      return uVar1;
    }
    *(undefined4 *)(iVar4 + 0x24) = *(undefined4 *)((int)register0x00000038 + -0x18);
    if (param_1 < *(uint *)(iVar4 + 0x18)) {
      _ipc_kmsg_copyout_dest(iVar4);
      _ipc_kmsg_put(0,uVar3,0x18);
      return 0x10004004;
    }
  }
  else {
    _ipc_mqueue_receive(uVar3,uVar3,param_1,param_3,0,_mach_msg_receive_continue);
    _ipc_object_release(*(undefined4 *)((int)register0x00000038 + -0x10));
    if (uVar1 != 0) {
      if (uVar1 != 0x10004004) {
        return uVar1;
      }
      *(undefined4 *)((int)register0x00000038 + -0x1c) =
           *(undefined4 *)((int)register0x00000038 + -0x14);
      _copyout((undefined *)((int)register0x00000038 + -0x1c),uVar3,4);
      return 0x10004004;
    }
    uVar2 = *(undefined8 *)((int)register0x00000038 + -0x18);
    *(int *)((int)uVar2 + 0x24) = (int)((qword)uVar2 >> 0x20);
  }
  uVar3 = (undefined4)uVar2;
  uVar1 = (uint)((qword)uVar2 >> 0x20);
  if ((in_o0_1 & 0x200) == 0) {
    param_4 = 0;
  }
  else if (param_4 == 0) {
    uVar6 = 0x10004007;
    goto loc_F005FB00;
  }
  _ipc_kmsg_copyout(uVar1,uVar3,uVar5,param_4);
  uVar6 = uVar1;
loc_F005FB00:
  if (uVar6 == 0) {
    _ipc_kmsg_put(0,uVar3,*(int *)(*(int *)((int)register0x00000038 + -0x14) + 0x18) +
                          *(int *)(*(int *)((int)register0x00000038 + -0x14) + 0x10));
  }
  else {
    uVar1 = uVar6;
    if ((uVar6 & 0xffffc3ff) == 0x1000400c) {
      _ipc_kmsg_put(0,uVar3,*(int *)(*(int *)((int)register0x00000038 + -0x14) + 0x18) +
                            *(int *)(*(int *)((int)register0x00000038 + -0x14) + 0x10));
    }
    else {
      _ipc_kmsg_copyout_dest();
      _ipc_kmsg_put(0,uVar3,0x18);
    }
  }
  return uVar1;
}

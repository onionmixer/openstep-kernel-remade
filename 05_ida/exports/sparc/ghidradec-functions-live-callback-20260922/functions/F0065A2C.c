
/* WARNING: Removing unreachable block (ram,0xf0065be0) */
/* WARNING: Removing unreachable block (ram,0xf0065bec) */
/* WARNING: Removing unreachable block (ram,0xf0065b84) */
/* WARNING: Removing unreachable block (ram,0xf0065b3c) */
/* WARNING: Removing unreachable block (ram,0xf0065b04) */
/* WARNING: Removing unreachable block (ram,0xf0065a84) */
/* WARNING: Removing unreachable block (ram,0xf0065a70) */
/* WARNING: Removing unreachable block (ram,0xf0065acc) */
/* WARNING: Removing unreachable block (ram,0xf0065b30) */
/* WARNING: Removing unreachable block (ram,0xf0065b74) */
/* WARNING: Removing unreachable block (ram,0xf0065ba4) */
/* WARNING: Removing unreachable block (ram,0xf0065bfc) */
/* WARNING: Removing unreachable block (ram,0xf0065c18) */
/* WARNING: Removing unreachable block (ram,0xf0065a5c) */

undefined8
_mach_msg(int param_1,undefined *param_2,undefined4 param_3,uint param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 unaff_l0;
  uint uVar5;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 uVar6;
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
  bool bVar7;
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
  uVar5 = *(uint *)(*(int *)(_active_threads + 0xc) + 0x88);
  uVar6 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0xc);
  if (((uint)param_2 & 1) != 0) {
    iVar1 = param_1;
    _ipc_kmsg_get_from_kernel(param_1,param_3,0,(undefined *)((int)register0x00000038 + -0xc));
    if (iVar1 != 0) {
      _panic(aMachMsg);
    }
    iVar1 = *(int *)((int)register0x00000038 + -0xc);
    _ipc_kmsg_copyin(iVar1,uVar5,uVar6,0);
    iVar2 = *(int *)((int)register0x00000038 + -0xc);
    if (iVar1 != 0) {
      iVar1 = *(int *)(iVar2 + 8);
      if (0 < iVar1) {
        _kfree();
        return CONCAT44(iVar1,iVar2);
      }
      _ipc_kmsg_free();
      return CONCAT44(iVar1,iVar2);
    }
    iVar1 = *(int *)((int)register0x00000038 + -0xc);
    do {
      _ipc_mqueue_send(iVar1,0,0,0);
      bVar7 = iVar1 == 0x10000007;
      iVar1 = *(int *)((int)register0x00000038 + -0xc);
    } while (bVar7);
  }
  if (((uint)param_2 & 2) != 0) {
    param_2 = (undefined *)((int)register0x00000038 + -0x18);
    do {
      uVar3 = uVar5;
      _ipc_mqueue_copyin(uVar5,param_5,(undefined *)((int)register0x00000038 + -0x10),
                         (undefined *)((int)register0x00000038 + -0x14));
      if (uVar3 != 0) goto locret_F0065C24;
      uVar3 = *(uint *)((int)register0x00000038 + -0x10);
      _ipc_mqueue_receive(uVar3,0,0xffffffff,0,0,0,(undefined *)((int)register0x00000038 + -0xc),
                          param_2);
      _ipc_object_release(*(undefined4 *)((int)register0x00000038 + -0x14));
    } while (uVar3 == 0x10004005);
    uVar4 = *(uint *)((int)register0x00000038 + -0xc);
    if (uVar3 != 0) goto locret_F0065C24;
    *(undefined4 *)(uVar4 + 0x24) = *(undefined4 *)((int)register0x00000038 + -0x18);
    if (param_4 < *(uint *)(uVar4 + 0x18)) {
      _ipc_kmsg_copyout_dest(uVar4,uVar5);
      _ipc_kmsg_put_to_kernel(param_1,*(undefined4 *)((int)register0x00000038 + -0xc),0x18);
      uVar3 = 0x10004004;
      goto locret_F0065C24;
    }
    _ipc_kmsg_copyout(uVar4,uVar5,uVar6,0);
    if (uVar4 != 0) {
      uVar3 = uVar4;
      if ((uVar4 & 0xffffc3ff) == 0x1000400c) {
        iVar1 = *(int *)((int)register0x00000038 + -0xc);
        _ipc_kmsg_put_to_kernel(param_1,iVar1,*(int *)(iVar1 + 0x18) + *(int *)(iVar1 + 0x10));
      }
      else {
        _ipc_kmsg_copyout_dest(*(undefined4 *)((int)register0x00000038 + -0xc),uVar5);
        _ipc_kmsg_put_to_kernel(param_1,*(undefined4 *)((int)register0x00000038 + -0xc),0x18);
      }
      goto locret_F0065C24;
    }
    iVar1 = *(int *)((int)register0x00000038 + -0xc);
    _ipc_kmsg_put_to_kernel(param_1,iVar1,*(int *)(iVar1 + 0x18) + *(int *)(iVar1 + 0x10));
  }
  uVar3 = 0;
locret_F0065C24:
  return CONCAT44(param_2,uVar3);
}


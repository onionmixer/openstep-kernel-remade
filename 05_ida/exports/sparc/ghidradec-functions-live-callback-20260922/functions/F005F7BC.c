
/* WARNING: Removing unreachable block (ram,0xf005f928) */
/* WARNING: Removing unreachable block (ram,0xf005f8d0) */
/* WARNING: Removing unreachable block (ram,0xf005f910) */
/* WARNING: Removing unreachable block (ram,0xf005f88c) */
/* WARNING: Removing unreachable block (ram,0xf005f8f0) */
/* WARNING: Removing unreachable block (ram,0xf005f944) */
/* WARNING: Removing unreachable block (ram,0xf005f7e4) */
/* WARNING: Removing unreachable block (ram,0xf005f83c) */

undefined8 _mach_msg_send(uint param_1,uint param_2,undefined4 param_3,uint param_4,int param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 unaff_l0;
  undefined4 uVar5;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint uVar6;
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
  uVar6 = *(uint *)(*(int *)(_active_threads + 0xc) + 0x88);
  uVar5 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0xc);
  uVar3 = param_1;
  _ipc_kmsg_get(param_1,param_3,0,(undefined *)((int)register0x00000038 + -0xc));
  if (uVar3 != 0) goto locret_F005F94C;
  if ((param_2 & 0x80) == 0) {
    iVar1 = *(int *)((int)register0x00000038 + -0xc);
    iVar2 = 0;
loc_F005F83C:
    _ipc_kmsg_copyin(iVar1,uVar6,uVar5,iVar2);
  }
  else {
    iVar1 = *(int *)((int)register0x00000038 + -0xc);
    iVar2 = param_5;
    if (param_5 != 0) goto loc_F005F83C;
    iVar1 = 0x1000000b;
  }
  iVar2 = *(int *)((int)register0x00000038 + -0xc);
  if (iVar1 != 0) {
    iVar1 = *(int *)(iVar2 + 8);
    if (iVar1 < 1) {
      _ipc_kmsg_free();
      return CONCAT44(iVar1,iVar2);
    }
    _kfree();
    return CONCAT44(iVar1,iVar2);
  }
  if ((param_2 & 0x20) == 0) {
    uVar3 = *(uint *)((int)register0x00000038 + -0xc);
    _ipc_mqueue_send(uVar3,param_2 & 0x10,param_4,0);
    bVar7 = uVar3 == 0;
  }
  else {
    uVar3 = *(uint *)((int)register0x00000038 + -0xc);
    _ipc_mqueue_send(uVar3,0x10,param_4 & -(uint)((param_2 & 0x10) != 0),0);
    bVar7 = uVar3 == 0;
    if (uVar3 == 0x10000004) {
      if (param_5 == 0) {
        uVar3 = 0x1000000b;
      }
      else {
        uVar3 = uVar6;
        _ipc_marequest_create
                  (uVar6,*(undefined4 *)(*(int *)((int)register0x00000038 + -0xc) + 0x1c),param_5,
                   *(int *)((int)register0x00000038 + -0xc) + 0xc);
      }
      bVar7 = false;
      if (uVar3 == 0) {
        _ipc_mqueue_send(*(undefined4 *)((int)register0x00000038 + -0xc),0x10000,0,0);
        uVar3 = 0x10000005;
        goto locret_F005F94C;
      }
    }
  }
  if (!bVar7) {
    uVar4 = *(uint *)((int)register0x00000038 + -0xc);
    _ipc_kmsg_copyout_pseudo(uVar4,uVar6,uVar5);
    iVar2 = *(int *)((int)register0x00000038 + -0xc);
    uVar3 = uVar3 | uVar4;
    _ipc_kmsg_put(param_1,iVar2,*(int *)(iVar2 + 0x18) + *(int *)(iVar2 + 0x10));
  }
locret_F005F94C:
  return CONCAT44(param_2,uVar3);
}


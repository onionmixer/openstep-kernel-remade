
/* WARNING: Removing unreachable block (ram,0xf0065fa4) */
/* WARNING: Removing unreachable block (ram,0xf0065fbc) */
/* WARNING: Removing unreachable block (ram,0xf0065ee8) */
/* WARNING: Removing unreachable block (ram,0xf0065edc) */
/* WARNING: Removing unreachable block (ram,0xf0065f14) */
/* WARNING: Removing unreachable block (ram,0xf0065f84) */
/* WARNING: Removing unreachable block (ram,0xf0065fcc) */
/* WARNING: Removing unreachable block (ram,0xf0065e94) */

undefined8 _msg_receive(int param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar3;
  undefined4 unaff_l3;
  uint uVar4;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 uVar5;
  undefined4 unaff_l7;
  undefined4 uVar6;
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
  uVar5 = *(undefined4 *)(param_1 + 0xc);
  uVar4 = *(uint *)(param_1 + 4);
  iVar3 = *(int *)(*(int *)(_active_threads + 0xc) + 0x88);
  uVar6 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0xc);
  do {
    iVar2 = iVar3;
    _ipc_mqueue_copyin(iVar3,uVar5,(undefined *)((int)register0x00000038 + -0xc),
                       (undefined *)((int)register0x00000038 + -0x10));
    if (iVar2 != 0) goto loc_F0065FCC;
    iVar2 = *(int *)((int)register0x00000038 + -0xc);
    uVar1 = 0xffffffff;
    if ((param_2 & 0x1000) != 0) {
      uVar1 = uVar4;
    }
    _ipc_mqueue_receive(iVar2,param_2 & 0x100,uVar1,param_3,0,0,
                        (undefined *)((int)register0x00000038 + -0x14),
                        (undefined *)((int)register0x00000038 + -0x18));
    _ipc_object_release(*(undefined4 *)((int)register0x00000038 + -0x10));
    if (iVar2 == 0x10004005) {
      uVar1 = *(uint *)(_active_threads + 0x18c);
      while ((uVar1 & 3) != 0) {
        _thread_halt_self_with_continuation(0);
        uVar1 = *(uint *)(_active_threads + 0x18c);
      }
      if ((param_2 & 0x400) != 0) break;
    }
  } while (iVar2 == 0x10004005);
  if (iVar2 == 0) {
    iVar2 = *(int *)((int)register0x00000038 + -0x14);
    if (uVar4 < *(uint *)(iVar2 + 0x18)) {
      _ipc_kmsg_destroy(iVar2);
      iVar2 = 0x10004004;
    }
    else {
      _ipc_kmsg_copyout_compat(iVar2,iVar3,uVar6);
      iVar3 = *(int *)((int)register0x00000038 + -0x14);
      *(int *)(iVar3 + 0x18) = *(int *)(iVar3 + 0x18) + *(int *)(iVar3 + 0x10);
      _ipc_kmsg_put_to_kernel(param_1);
    }
  }
  else if (iVar2 == 0x10004004) {
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)((int)register0x00000038 + -0x14);
  }
loc_F0065FCC:
  _msg_return_translate(iVar2);
  return CONCAT44(param_2,iVar2);
}



/* WARNING: Removing unreachable block (ram,0xf0065d68) */
/* WARNING: Removing unreachable block (ram,0xf0065e3c) */
/* WARNING: Removing unreachable block (ram,0xf0065e04) */
/* WARNING: Removing unreachable block (ram,0xf0065d44) */
/* WARNING: Removing unreachable block (ram,0xf0065dd4) */
/* WARNING: Removing unreachable block (ram,0xf0065d84) */
/* WARNING: Removing unreachable block (ram,0xf0065d30) */
/* WARNING: Removing unreachable block (ram,0xf0065e48) */
/* WARNING: Removing unreachable block (ram,0xf0065d18) */

undefined8 _msg_send(int param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 unaff_l0;
  undefined4 uVar2;
  undefined4 unaff_l1;
  undefined4 uVar3;
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
  uVar1 = *(int *)(param_1 + 4) + 3U & 0xfffffffc;
  uVar3 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x88);
  uVar2 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0xc);
  if (uVar1 < 0x2001) {
    _ipc_kmsg_get_from_kernel
              (param_1,uVar1,*(int *)(param_1 + 4) - uVar1,
               (undefined *)((int)register0x00000038 + -0xc));
    if (param_1 == 0) {
      param_1 = *(int *)((int)register0x00000038 + -0xc);
      _ipc_kmsg_copyin_compat(param_1,uVar3,uVar2);
      if (param_1 == 0) {
        if ((param_2 & 2) == 0) {
          do {
            if ((param_2 & 0x20) == 0) {
              param_1 = *(int *)((int)register0x00000038 + -0xc);
              uVar1 = -(param_2 & 1) & 0x10;
            }
            else {
              param_1 = *(int *)((int)register0x00000038 + -0xc);
              uVar1 = 0x20000;
              if ((param_2 & 1) != 0) {
                uVar1 = 0x20010;
              }
            }
            _ipc_mqueue_send(param_1,uVar1,param_3,0);
            if (param_1 == 0x10000007) {
              uVar1 = *(uint *)(_active_threads + 0x18c);
              while ((uVar1 & 3) != 0) {
                _thread_halt_self_with_continuation(0);
                uVar1 = *(uint *)(_active_threads + 0x18c);
              }
              if ((param_2 & 4) != 0) break;
            }
          } while (param_1 == 0x10000007);
        }
        else {
          _panic(aMsgSendNotify);
        }
        if (param_1 != 0) {
          _ipc_kmsg_destroy(*(undefined4 *)((int)register0x00000038 + -0xc));
        }
      }
      else if (*(int *)(*(int *)((int)register0x00000038 + -0xc) + 8) < 1) {
        _ipc_kmsg_free();
      }
      else {
        _kfree();
      }
    }
    _msg_return_translate();
  }
  else {
    param_1 = -0x6d;
  }
  return CONCAT44(param_2,param_1);
}


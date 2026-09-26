
/* WARNING: Removing unreachable block (ram,0xf00614ec) */
/* WARNING: Removing unreachable block (ram,0xf00615e8) */
/* WARNING: Removing unreachable block (ram,0xf0061560) */
/* WARNING: Removing unreachable block (ram,0xf00615d4) */
/* WARNING: Removing unreachable block (ram,0xf00614c8) */
/* WARNING: Removing unreachable block (ram,0xf0061530) */
/* WARNING: Removing unreachable block (ram,0xf006157c) */
/* WARNING: Removing unreachable block (ram,0xf00614b4) */
/* WARNING: Removing unreachable block (ram,0xf00615f4) */
/* WARNING: Removing unreachable block (ram,0xf006149c) */

undefined8 _msg_send_trap(int param_1,uint param_2,int param_3,uint param_4)

{
  uint uVar1;
  code *pcVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 uVar4;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar5;
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
  uVar1 = param_3 + 3U & 0xfffffffc;
  iVar3 = *(int *)(*(int *)(_active_threads + 0xc) + 0x88);
  uVar4 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0xc);
  if (uVar1 < 0x2001) {
    _ipc_kmsg_get(param_1,uVar1,param_3 - uVar1,(undefined *)((int)register0x00000038 + -0xc));
    if (param_1 == 0) {
      param_1 = *(int *)((int)register0x00000038 + -0xc);
      _ipc_kmsg_copyin_compat(param_1,iVar3,uVar4);
      if (param_1 == 0) {
        bVar5 = (param_2 & 0x20) == 0;
        if ((param_2 & 2) == 0) {
          if (bVar5) {
            param_1 = *(int *)((int)register0x00000038 + -0xc);
            iVar3 = (param_2 & 1) << 4;
            pcVar2 = (code *)0x0;
          }
          else {
            param_1 = *(int *)((int)register0x00000038 + -0xc);
            if ((param_2 & 1) == 0) {
              iVar3 = 0x20000;
            }
            else {
              iVar3 = 0x20010;
            }
            pcVar2 = _msg_send_switch_continue;
          }
          _ipc_mqueue_send(param_1,iVar3,param_4,pcVar2);
          bVar5 = param_1 == 0;
        }
        else {
          param_1 = *(int *)((int)register0x00000038 + -0xc);
          if (bVar5) {
            uVar4 = 0x10;
          }
          else {
            uVar4 = 0x20010;
          }
          _ipc_mqueue_send(param_1,uVar4,param_4 & -(param_2 & 1),0);
          bVar5 = param_1 == 0;
          if (param_1 == 0x10000004) {
            _ipc_marequest_create
                      (iVar3,*(undefined4 *)(*(int *)((int)register0x00000038 + -0xc) + 0x1c),0,
                       *(int *)((int)register0x00000038 + -0xc) + 0xc);
            bVar5 = false;
            param_1 = iVar3;
            if (iVar3 == 0) {
              _ipc_mqueue_send(*(undefined4 *)((int)register0x00000038 + -0xc),0x10000,0,0);
              param_1 = -0x69;
              goto locret_F0061600;
            }
          }
        }
        if (!bVar5) {
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
locret_F0061600:
  return CONCAT44(param_2,param_1);
}



/* WARNING: Removing unreachable block (ram,0xf00617f0) */
/* WARNING: Removing unreachable block (ram,0xf0061cd4) */
/* WARNING: Removing unreachable block (ram,0xf0061b10) */
/* WARNING: Removing unreachable block (ram,0xf0061ca4) */
/* WARNING: Removing unreachable block (ram,0xf0061c40) */
/* WARNING: Removing unreachable block (ram,0xf0061bb4) */
/* WARNING: Removing unreachable block (ram,0xf0061b3c) */
/* WARNING: Removing unreachable block (ram,0xf0061938) */
/* WARNING: Removing unreachable block (ram,0xf0061884) */
/* WARNING: Removing unreachable block (ram,0xf0061a84) */
/* WARNING: Removing unreachable block (ram,0xf0061a0c) */
/* WARNING: Removing unreachable block (ram,0xf00619d4) */
/* WARNING: Removing unreachable block (ram,0xf0061a54) */
/* WARNING: Removing unreachable block (ram,0xf006181c) */
/* WARNING: Removing unreachable block (ram,0xf00617cc) */
/* WARNING: Removing unreachable block (ram,0xf0061834) */
/* WARNING: Removing unreachable block (ram,0xf00619a4) */
/* WARNING: Removing unreachable block (ram,0xf00619f0) */
/* WARNING: Removing unreachable block (ram,0xf0061a68) */
/* WARNING: Removing unreachable block (ram,0xf0061860) */
/* WARNING: Removing unreachable block (ram,0xf00618f0) */
/* WARNING: Removing unreachable block (ram,0xf0061ab8) */
/* WARNING: Removing unreachable block (ram,0xf0061b7c) */
/* WARNING: Removing unreachable block (ram,0xf0061bd0) */
/* WARNING: Removing unreachable block (ram,0xf0061c4c) */
/* WARNING: Removing unreachable block (ram,0xf0061c80) */
/* WARNING: Removing unreachable block (ram,0xf0061cb8) */
/* WARNING: Removing unreachable block (ram,0xf00617b8) */
/* WARNING: Removing unreachable block (ram,0xf0061cdc) */
/* WARNING: Removing unreachable block (ram,0xf00617a0) */

undefined8
_msg_rpc_trap(int *param_1,uint param_2,int param_3,uint param_4,uint param_5,undefined4 param_6)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 unaff_l0;
  int *piVar5;
  undefined4 unaff_l1;
  int *piVar6;
  undefined4 uVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar8;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar9;
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
  uVar4 = param_3 + 3U & 0xfffffffc;
  piVar6 = *(int **)(*(int *)(_active_threads + 0xc) + 0x88);
  uVar7 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0xc);
  if (0x2000 < uVar4) {
    piVar8 = (int *)0xffffff93;
    goto locret_F0061CE8;
  }
  piVar8 = param_1;
  _ipc_kmsg_get(param_1,uVar4,param_3 - uVar4,(undefined *)((int)register0x00000038 + -0xc));
  if (piVar8 == (int *)0x0) {
    piVar8 = *(int **)((int)register0x00000038 + -0xc);
    _ipc_kmsg_copyin_compat(piVar8,piVar6,uVar7);
    iVar1 = *(int *)((int)register0x00000038 + -0xc);
    if (piVar8 == (int *)0x0) {
      piVar5 = *(int **)(iVar1 + 0x20);
      if ((piVar5 == (int *)0x0) || (piVar5 == (int *)0xffffffff)) {
loc_F0061974:
        bVar9 = (param_2 & 0x20) == 0;
        if ((param_2 & 2) == 0) {
          if (bVar9) {
            piVar8 = *(int **)((int)register0x00000038 + -0xc);
            iVar1 = (param_2 & 1) << 4;
          }
          else {
            piVar8 = *(int **)((int)register0x00000038 + -0xc);
            if ((param_2 & 1) == 0) {
              iVar1 = 0x20000;
            }
            else {
              iVar1 = 0x20010;
            }
          }
          _ipc_mqueue_send(piVar8,iVar1,param_5,0);
          bVar9 = piVar8 == (int *)0x0;
        }
        else {
          piVar8 = *(int **)((int)register0x00000038 + -0xc);
          if (bVar9) {
            uVar3 = 0x10;
          }
          else {
            uVar3 = 0x20010;
          }
          _ipc_mqueue_send(piVar8,uVar3,param_5 & -(param_2 & 1),0);
          bVar9 = piVar8 == (int *)0x0;
          if (piVar8 == (int *)0x10000004) {
            piVar8 = piVar6;
            _ipc_marequest_create
                      (piVar6,*(undefined4 *)(*(int *)((int)register0x00000038 + -0xc) + 0x1c),0,
                       *(int *)((int)register0x00000038 + -0xc) + 0xc);
            bVar9 = false;
            if (piVar8 == (int *)0x0) {
              _ipc_mqueue_send(*(undefined4 *)((int)register0x00000038 + -0xc),0x10000,0,0);
              if (piVar5 != (int *)0x0) {
                piVar8 = (int *)0xffffff97;
                if (piVar5 == (int *)0xffffffff) goto locret_F0061CE8;
                _ipc_object_release(piVar5);
              }
              piVar8 = (int *)0xffffff97;
              goto locret_F0061CE8;
            }
          }
        }
        if (bVar9) {
loc_F0061A98:
          if (piVar5 != (int *)0x0) {
            if (piVar5 == (int *)0xffffffff) {
              piVar8 = (int *)0xffffff36;
              goto locret_F0061CE8;
            }
            do {
              do {
              } while (*piVar5 != 0);
              piVar8 = piVar5;
              _simple_lock_try();
            } while (piVar8 == (int *)0x0);
            if ((int *)piVar5[3] == piVar6) {
              piVar8 = (int *)piVar5[0xc];
              if (piVar8 != (int *)0x0) {
                do {
                  do {
                  } while (*piVar8 != 0);
                  piVar2 = piVar8;
                  _simple_lock_try();
                } while (piVar2 == (int *)0x0);
                if (piVar8[2] < 0) {
                  *piVar8 = 0;
                  piVar5[1] = piVar5[1] + -1;
                  *piVar5 = 0;
                  goto loc_F0061B74;
                }
                _ipc_pset_remove(piVar8,piVar5);
                *piVar8 = 0;
                if (piVar8[1] == 0) {
                  _zfree((&_ipc_object_zones)[(piVar8[2] & 0x7fffffffU) >> 0x10],piVar8);
                }
              }
              do {
                do {
                  piVar8 = piVar5 + 0x10;
                } while (*piVar8 != 0);
                piVar2 = piVar8;
                _simple_lock_try();
              } while (piVar2 == (int *)0x0);
              *piVar5 = 0;
              iVar1 = _active_threads;
              *(int **)(_active_threads + 0xc4) = param_1;
              *(uint *)(iVar1 + 200) = param_2;
              *(uint *)(iVar1 + 0xcc) = param_4;
              *(undefined4 *)(iVar1 + 0xd0) = param_6;
              *(int **)(iVar1 + 0xd8) = piVar5;
              *(int **)(iVar1 + 0xdc) = piVar8;
              uVar4 = 0xffffffff;
              if ((param_2 & 0x1000) != 0) {
                uVar4 = param_4;
              }
              _ipc_mqueue_receive(piVar8,param_2 & 0x100,uVar4,param_6,0,_msg_receive_continue,
                                  (undefined *)((int)register0x00000038 + -0xc),
                                  (undefined *)((int)register0x00000038 + -0x10));
              _ipc_object_release(piVar5);
              if (piVar8 == (int *)0x0) {
                if (param_4 < *(uint *)(*(int *)((int)register0x00000038 + -0xc) + 0x18)) {
                  _ipc_kmsg_destroy(*(int *)((int)register0x00000038 + -0xc));
                  piVar8 = (int *)0xffffff34;
                  goto locret_F0061CE8;
                }
                goto loc_F0061CB4;
              }
              if (piVar8 == (int *)0x10004004) {
                *(undefined4 *)((int)register0x00000038 + -0x14) =
                     *(undefined4 *)((int)register0x00000038 + -0xc);
                _copyout((undefined *)((int)register0x00000038 + -0x14),param_1 + 1,4);
              }
              goto loc_F0061CDC;
            }
            iVar1 = piVar5[1];
            piVar5[1] = iVar1 + -1;
            *piVar5 = 0;
            if (iVar1 + -1 == 0) {
              _zfree((&_ipc_object_zones)[(piVar5[2] & 0x7fffffffU) >> 0x10],piVar5);
              piVar8 = (int *)0xffffff36;
              goto locret_F0061CE8;
            }
          }
loc_F0061B74:
          piVar8 = (int *)0xffffff36;
          goto locret_F0061CE8;
        }
        _ipc_kmsg_destroy(*(undefined4 *)((int)register0x00000038 + -0xc));
        if ((piVar5 != (int *)0x0) && (piVar5 != (int *)0xffffffff)) {
          _ipc_object_release(piVar5);
        }
      }
      else {
        piVar8 = *(int **)(iVar1 + 0x1c);
        _ipc_object_reference(piVar5);
        do {
          do {
          } while (*piVar8 != 0);
          piVar2 = piVar8;
          _simple_lock_try();
        } while (piVar2 == (int *)0x0);
        iVar1 = *(int *)((int)register0x00000038 + -0xc);
        if (piVar8[3] != _ipc_space_kernel) {
          *piVar8 = 0;
          goto loc_F0061974;
        }
        *piVar8 = 0;
        _ipc_kobject_server();
        *(int *)((int)register0x00000038 + -0xc) = iVar1;
        if (iVar1 == 0) goto loc_F0061A98;
        do {
          do {
          } while (*piVar5 != 0);
          piVar8 = piVar5;
          _simple_lock_try();
        } while (piVar8 == (int *)0x0);
        if ((((-1 < piVar5[2]) || ((int *)piVar5[3] != piVar6)) || (piVar5[0xc] != 0)) ||
           (piVar8 = piVar5 + 0x10,
           param_4 < (uint)(*(int *)(*(int *)((int)register0x00000038 + -0xc) + 0x18) +
                           *(int *)(*(int *)((int)register0x00000038 + -0xc) + 0x10)))) {
loc_F0061928:
          *piVar5 = 0;
          _ipc_mqueue_send(*(undefined4 *)((int)register0x00000038 + -0xc),0x10000,0,0);
          goto loc_F0061A98;
        }
        do {
          do {
          } while (*piVar8 != 0);
          piVar2 = piVar8;
          _simple_lock_try();
        } while (piVar2 == (int *)0x0);
        if ((piVar5[0x12] != 0) || (piVar5[0x11] != 0)) {
          *piVar8 = 0;
          goto loc_F0061928;
        }
        piVar5[0xd] = piVar5[0xd] + 1;
        *piVar8 = 0;
        piVar5[1] = piVar5[1] + -1;
        *piVar5 = 0;
loc_F0061CB4:
        _ipc_kmsg_copyout_compat(*(undefined4 *)((int)register0x00000038 + -0xc),piVar6,uVar7);
        iVar1 = *(int *)((int)register0x00000038 + -0xc);
        *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + *(int *)(iVar1 + 0x10);
        _ipc_kmsg_put(param_1);
        piVar8 = param_1;
      }
    }
    else if (*(int *)(iVar1 + 8) < 1) {
      _ipc_kmsg_free();
    }
    else {
      _kfree();
    }
  }
loc_F0061CDC:
  _msg_return_translate();
locret_F0061CE8:
  return CONCAT44(param_2,piVar8);
}


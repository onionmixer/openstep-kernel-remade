
/* WARNING: Removing unreachable block (ram,0xf0066070) */
/* WARNING: Removing unreachable block (ram,0xf0066558) */
/* WARNING: Removing unreachable block (ram,0xf006635c) */
/* WARNING: Removing unreachable block (ram,0xf00664b4) */
/* WARNING: Removing unreachable block (ram,0xf0066474) */
/* WARNING: Removing unreachable block (ram,0xf006641c) */
/* WARNING: Removing unreachable block (ram,0xf00663c8) */
/* WARNING: Removing unreachable block (ram,0xf0066304) */
/* WARNING: Removing unreachable block (ram,0xf0066170) */
/* WARNING: Removing unreachable block (ram,0xf00660e0) */
/* WARNING: Removing unreachable block (ram,0xf00662b4) */
/* WARNING: Removing unreachable block (ram,0xf006627c) */
/* WARNING: Removing unreachable block (ram,0xf00660b4) */
/* WARNING: Removing unreachable block (ram,0xf006604c) */
/* WARNING: Removing unreachable block (ram,0xf006609c) */
/* WARNING: Removing unreachable block (ram,0xf006624c) */
/* WARNING: Removing unreachable block (ram,0xf00661fc) */
/* WARNING: Removing unreachable block (ram,0xf00662d0) */
/* WARNING: Removing unreachable block (ram,0xf0066104) */
/* WARNING: Removing unreachable block (ram,0xf00661b8) */
/* WARNING: Removing unreachable block (ram,0xf0066388) */
/* WARNING: Removing unreachable block (ram,0xf0066400) */
/* WARNING: Removing unreachable block (ram,0xf0066468) */
/* WARNING: Removing unreachable block (ram,0xf0066520) */
/* WARNING: Removing unreachable block (ram,0xf00664e0) */
/* WARNING: Removing unreachable block (ram,0xf0066538) */
/* WARNING: Removing unreachable block (ram,0xf0066038) */
/* WARNING: Removing unreachable block (ram,0xf0066564) */
/* WARNING: Removing unreachable block (ram,0xf0066020) */

undefined8 _msg_rpc(int *param_1,uint param_2,uint param_3,undefined4 param_4,undefined4 param_5)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  undefined4 unaff_l0;
  int *piVar5;
  undefined4 unaff_l1;
  int *piVar6;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  int iVar7;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 uVar8;
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
  uVar4 = param_1[1] + 3U & 0xfffffffc;
  iVar7 = *(int *)(*(int *)(_active_threads + 0xc) + 0x88);
  uVar8 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0xc);
  if (0x2000 < uVar4) {
    param_1 = (int *)0xffffff93;
    goto locret_F0066570;
  }
  piVar1 = param_1;
  _ipc_kmsg_get_from_kernel
            (param_1,uVar4,param_1[1] - uVar4,(undefined *)((int)register0x00000038 + -0xc));
  if (piVar1 == (int *)0x0) {
    piVar1 = *(int **)((int)register0x00000038 + -0xc);
    _ipc_kmsg_copyin_compat(piVar1,iVar7,uVar8);
    iVar2 = *(int *)((int)register0x00000038 + -0xc);
    if (piVar1 == (int *)0x0) {
      piVar6 = *(int **)(iVar2 + 0x20);
      if ((piVar6 == (int *)0x0) || (piVar6 == (int *)0xffffffff)) {
loc_F00661F4:
        if ((param_2 & 2) == 0) {
          do {
            if ((param_2 & 0x20) == 0) {
              piVar1 = *(int **)((int)register0x00000038 + -0xc);
              uVar4 = -(param_2 & 1) & 0x10;
            }
            else {
              piVar1 = *(int **)((int)register0x00000038 + -0xc);
              uVar4 = 0x20000;
              if ((param_2 & 1) != 0) {
                uVar4 = 0x20010;
              }
            }
            _ipc_mqueue_send(piVar1,uVar4,param_4,0);
            if (piVar1 == (int *)0x10000007) {
              uVar4 = *(uint *)(_active_threads + 0x18c);
              while ((uVar4 & 3) != 0) {
                _thread_halt_self_with_continuation(0);
                uVar4 = *(uint *)(_active_threads + 0x18c);
              }
              if ((param_2 & 4) != 0) break;
            }
          } while (piVar1 == (int *)0x10000007);
        }
        else {
          _panic(aMsgRpcNotify);
        }
        if (piVar1 == (int *)0x0) {
loc_F00662E4:
          if (piVar6 != (int *)0x0) {
            if (piVar6 == (int *)0xffffffff) {
              param_1 = (int *)0xffffff36;
              goto locret_F0066570;
            }
            do {
              do {
              } while (*piVar6 != 0);
              piVar1 = piVar6;
              _simple_lock_try();
            } while (piVar1 == (int *)0x0);
            if (piVar6[3] == iVar7) {
              piVar1 = (int *)piVar6[0xc];
              if (piVar1 != (int *)0x0) {
                do {
                  do {
                  } while (*piVar1 != 0);
                  piVar5 = piVar1;
                  _simple_lock_try();
                } while (piVar5 == (int *)0x0);
                if (piVar1[2] < 0) {
                  *piVar1 = 0;
                  piVar6[1] = piVar6[1] + -1;
                  *piVar6 = 0;
                  goto loc_F00663C0;
                }
                _ipc_pset_remove(piVar1,piVar6);
                *piVar1 = 0;
                if (piVar1[1] == 0) {
                  _zfree((&_ipc_object_zones)[(piVar1[2] & 0x7fffffffU) >> 0x10],piVar1);
                }
              }
              do {
                do {
                  piVar1 = piVar6 + 0x10;
                } while (*piVar1 != 0);
                piVar5 = piVar1;
                _simple_lock_try();
              } while (piVar5 == (int *)0x0);
              *piVar6 = 0;
              uVar4 = 0xffffffff;
              if ((param_2 & 0x1000) != 0) {
                uVar4 = param_3;
              }
              _ipc_mqueue_receive(piVar1,param_2 & 0x100,uVar4,param_5,0,0,
                                  (undefined *)((int)register0x00000038 + -0xc),
                                  (undefined *)((int)register0x00000038 + -0x10));
              _ipc_object_release(piVar6);
              if (piVar1 == (int *)0x0) {
                if (*(uint *)(*(int *)((int)register0x00000038 + -0xc) + 0x18) <= param_3)
                goto loc_F0066534;
                _ipc_kmsg_destroy(*(int *)((int)register0x00000038 + -0xc));
                piVar1 = (int *)0x10004004;
              }
              else if (piVar1 == (int *)0x10004005) {
                uVar4 = *(uint *)(_active_threads + 0x18c);
                while ((uVar4 & 3) != 0) {
                  _thread_halt_self_with_continuation(0);
                  uVar4 = *(uint *)(_active_threads + 0x18c);
                }
                param_1[1] = param_3;
                if ((param_2 & 0x400) == 0) {
                  _msg_receive(param_1,param_2,param_5);
                  goto locret_F0066570;
                }
              }
              else if (piVar1 == (int *)0x10004004) {
                param_1[1] = *(int *)((int)register0x00000038 + -0xc);
              }
              goto loc_F0066564;
            }
            iVar7 = piVar6[1];
            piVar6[1] = iVar7 + -1;
            *piVar6 = 0;
            if (iVar7 + -1 == 0) {
              _zfree((&_ipc_object_zones)[(piVar6[2] & 0x7fffffffU) >> 0x10],piVar6);
              param_1 = (int *)0xffffff36;
              goto locret_F0066570;
            }
          }
loc_F00663C0:
          param_1 = (int *)0xffffff36;
          goto locret_F0066570;
        }
        _ipc_kmsg_destroy(*(undefined4 *)((int)register0x00000038 + -0xc));
        if ((piVar6 != (int *)0x0) && (piVar6 != (int *)0xffffffff)) {
          _ipc_object_release(piVar6);
        }
      }
      else {
        piVar5 = *(int **)(iVar2 + 0x1c);
        _ipc_object_reference(piVar6);
        do {
          do {
          } while (*piVar5 != 0);
          piVar3 = piVar5;
          _simple_lock_try();
        } while (piVar3 == (int *)0x0);
        iVar2 = *(int *)((int)register0x00000038 + -0xc);
        if (piVar5[3] != _ipc_space_kernel) {
          *piVar5 = 0;
          goto loc_F00661F4;
        }
        *piVar5 = 0;
        _ipc_kobject_server();
        *(int *)((int)register0x00000038 + -0xc) = iVar2;
        if (iVar2 == 0) goto loc_F00662E4;
        do {
          do {
          } while (*piVar6 != 0);
          piVar1 = piVar6;
          _simple_lock_try();
        } while (piVar1 == (int *)0x0);
        if ((((-1 < piVar6[2]) || (piVar6[3] != iVar7)) || (piVar6[0xc] != 0)) ||
           (piVar1 = piVar6 + 0x10,
           param_3 < (uint)(*(int *)(*(int *)((int)register0x00000038 + -0xc) + 0x18) +
                           *(int *)(*(int *)((int)register0x00000038 + -0xc) + 0x10)))) {
loc_F00661A8:
          *piVar6 = 0;
          _ipc_mqueue_send(*(undefined4 *)((int)register0x00000038 + -0xc),0x10000,0,0);
          goto loc_F00662E4;
        }
        do {
          do {
          } while (*piVar1 != 0);
          piVar5 = piVar1;
          _simple_lock_try();
        } while (piVar5 == (int *)0x0);
        if ((piVar6[0x12] != 0) || (piVar6[0x11] != 0)) {
          *piVar1 = 0;
          goto loc_F00661A8;
        }
        piVar6[0xd] = piVar6[0xd] + 1;
        *piVar1 = 0;
        piVar6[1] = piVar6[1] + -1;
        *piVar6 = 0;
loc_F0066534:
        piVar1 = *(int **)((int)register0x00000038 + -0xc);
        _ipc_kmsg_copyout_compat(piVar1,iVar7,uVar8);
        iVar7 = *(int *)((int)register0x00000038 + -0xc);
        *(int *)(iVar7 + 0x18) = *(int *)(iVar7 + 0x18) + *(int *)(iVar7 + 0x10);
        _ipc_kmsg_put_to_kernel(param_1);
      }
    }
    else if (*(int *)(iVar2 + 8) < 1) {
      _ipc_kmsg_free();
    }
    else {
      _kfree();
    }
  }
loc_F0066564:
  _msg_return_translate();
  param_1 = piVar1;
locret_F0066570:
  return CONCAT44(param_2,param_1);
}

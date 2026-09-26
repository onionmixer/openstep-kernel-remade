
/* WARNING: Removing unreachable block (ram,0xf0064b60) */
/* WARNING: Removing unreachable block (ram,0xf0064af4) */
/* WARNING: Removing unreachable block (ram,0xf0064ad8) */
/* WARNING: Removing unreachable block (ram,0xf0064a58) */
/* WARNING: Removing unreachable block (ram,0xf00649e8) */
/* WARNING: Removing unreachable block (ram,0xf006499c) */
/* WARNING: Removing unreachable block (ram,0xf00649b8) */
/* WARNING: Removing unreachable block (ram,0xf0064a24) */
/* WARNING: Removing unreachable block (ram,0xf0064aac) */
/* WARNING: Removing unreachable block (ram,0xf0064aec) */
/* WARNING: Removing unreachable block (ram,0xf0064b28) */
/* WARNING: Removing unreachable block (ram,0xf0064b44) */
/* WARNING: Removing unreachable block (ram,0xf006498c) */

undefined8 _exception_raise_continue_slow(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  code *pcVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  int *piVar6;
  undefined4 unaff_i2;
  int *piVar7;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  iVar1 = _active_threads;
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
  *(undefined4 *)((int)register0x00000038 + 0x48) = param_2;
  *(undefined4 *)((int)register0x00000038 + 0x4c) = param_3;
  piVar6 = *(int **)(_active_threads + 0xc4);
  piVar7 = piVar6 + 0x10;
  if (param_1 == (int *)0x10004005) {
    uVar2 = *(uint *)(_active_threads + 0x18c);
joined_r0xf0064974:
    while ((uVar2 & 3) != 0) {
      if (piVar6 == (int *)0x0) {
loc_F0064994:
        *(undefined4 *)(iVar1 + 0xc4) = 0;
      }
      else {
        if (piVar6 != (int *)0xffffffff) {
          _ipc_object_release(piVar6);
          goto loc_F0064994;
        }
        *(undefined4 *)(iVar1 + 0xc4) = 0;
      }
      piVar7 = (int *)0x0;
      _thread_halt_self_with_continuation(0);
      do {
        do {
        } while (*(int *)(iVar1 + 0xa8) != 0);
        piVar6 = (int *)(iVar1 + 0xa8);
        _simple_lock_try();
      } while (piVar6 == (int *)0x0);
      piVar6 = *(int **)(iVar1 + 0xc0);
      *(int **)(iVar1 + 0xc4) = piVar6;
      if (piVar6 == (int *)0x0) {
loc_F00649F0:
        uVar2 = *(uint *)(iVar1 + 0x18c);
      }
      else {
        if (piVar6 != (int *)0xffffffff) {
          piVar7 = piVar6 + 0x10;
          _ipc_object_reference();
          goto loc_F00649F0;
        }
        uVar2 = *(uint *)(iVar1 + 0x18c);
      }
      *(undefined4 *)(iVar1 + 0xa8) = 0;
    }
    if ((piVar6 != (int *)0x0) && (piVar6 != (int *)0xffffffff)) {
      do {
        do {
        } while (*piVar6 != 0);
        piVar3 = piVar6;
        _simple_lock_try();
      } while (piVar3 == (int *)0x0);
      if (piVar6[2] < 0) {
        do {
          do {
          } while (*piVar7 != 0);
          piVar3 = piVar7;
          _simple_lock_try();
        } while (piVar3 == (int *)0x0);
        *piVar6 = 0;
        if (*(int *)(iVar1 + 0x38) == 0) {
          pcVar5 = (code *)0x0;
        }
        else {
          pcVar5 = _exception_raise_continue;
        }
        param_1 = piVar7;
        _ipc_mqueue_receive(piVar7,0,0xffffffff,0,0,pcVar5,
                            (undefined *)((int)register0x00000038 + 0x48),
                            (undefined *)((int)register0x00000038 + 0x4c));
        if (param_1 != (int *)0x10004005) goto loc_F0064AC4;
        uVar2 = *(uint *)(iVar1 + 0x18c);
        goto joined_r0xf0064974;
      }
      *piVar6 = 0;
    }
    param_1 = (int *)0x10004009;
  }
loc_F0064AC4:
  if ((piVar6 != (int *)0x0) && (piVar6 != (int *)0xffffffff)) {
    _ipc_object_release(piVar6);
  }
  if (param_1 == (int *)0x0) {
    _ipc_port_release_sonce(piVar6);
    param_1 = *(int **)((int)register0x00000038 + 0x48);
    _exception_parse_reply();
  }
  if ((param_1 == (int *)0x0) || (param_1 == (int *)0x10004009)) {
    if (*(int *)(iVar1 + 0x38) == 0) goto locret_F0064B68;
    _call_continuation();
    iVar4 = *(int *)(iVar1 + 200);
  }
  else {
    iVar4 = *(int *)(iVar1 + 200);
  }
  if (iVar4 == 0) {
    _exception_no_server();
  }
  else {
    _exception_try_task(iVar4,*(undefined4 *)(iVar1 + 0xcc),*(undefined4 *)(iVar1 + 0xd0));
  }
locret_F0064B68:
  return CONCAT44(piVar6,param_1);
}


/* WARNING: Removing unreachable block (ram,0xf006480c) */
/* WARNING: Removing unreachable block (ram,0xf006476c) */
/* WARNING: Removing unreachable block (ram,0xf00646c4) */
/* WARNING: Removing unreachable block (ram,0xf00646ac) */
/* WARNING: Removing unreachable block (ram,0xf0064668) */
/* WARNING: Removing unreachable block (ram,0xf006463c) */
/* WARNING: Removing unreachable block (ram,0xf0064604) */
/* WARNING: Removing unreachable block (ram,0xf006452c) */
/* WARNING: Removing unreachable block (ram,0xf0064500) */
/* WARNING: Removing unreachable block (ram,0xf00644a4) */
/* WARNING: Removing unreachable block (ram,0xf0064464) */
/* WARNING: Removing unreachable block (ram,0xf00643c0) */
/* WARNING: Removing unreachable block (ram,0xf00642dc) */
/* WARNING: Removing unreachable block (ram,0xf00641f0) */
/* WARNING: Removing unreachable block (ram,0xf0064194) */
/* WARNING: Removing unreachable block (ram,0xf006414c) */
/* WARNING: Removing unreachable block (ram,0xf00640fc) */
/* WARNING: Removing unreachable block (ram,0xf00640d0) */
/* WARNING: Removing unreachable block (ram,0xf0064130) */
/* WARNING: Removing unreachable block (ram,0xf0064178) */
/* WARNING: Removing unreachable block (ram,0xf00641d8) */
/* WARNING: Removing unreachable block (ram,0xf0064244) */
/* WARNING: Removing unreachable block (ram,0xf0064378) */
/* WARNING: Removing unreachable block (ram,0xf0064458) */
/* WARNING: Removing unreachable block (ram,0xf0064480) */
/* WARNING: Removing unreachable block (ram,0xf00644c8) */
/* WARNING: Removing unreachable block (ram,0xf006451c) */
/* WARNING: Removing unreachable block (ram,0xf0064534) */
/* WARNING: Removing unreachable block (ram,0xf0064624) */
/* WARNING: Removing unreachable block (ram,0xf0064658) */
/* WARNING: Removing unreachable block (ram,0xf006467c) */
/* WARNING: Removing unreachable block (ram,0xf00646b4) */
/* WARNING: Removing unreachable block (ram,0xf0064754) */
/* WARNING: Removing unreachable block (ram,0xf00647b8) */
/* WARNING: Removing unreachable block (ram,0xf006481c) */
/* WARNING: Removing unreachable block (ram,0xf00640b8) */

undefined8
_exception_raise(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  code *pcVar11;
  undefined4 unaff_l0;
  int *piVar12;
  undefined4 unaff_l1;
  int iVar13;
  undefined4 unaff_l3;
  int *piVar14;
  undefined4 unaff_l4;
  undefined4 *puVar15;
  undefined4 unaff_l5;
  int *piVar16;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  uint uVar17;
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
  
  iVar2 = _ipc_kmsg_cache;
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
  if (_ipc_kmsg_cache == 0) {
    iVar2 = 0x100;
    _kalloc();
    if (iVar2 == 0) {
      _panic(aExceptionRaise);
    }
    *(undefined4 *)(iVar2 + 8) = 0x100;
    *(undefined4 *)(iVar2 + 0xc) = 0;
  }
  else {
    _ipc_kmsg_cache = 0;
  }
  *(undefined4 *)(iVar2 + 0x10) = 0;
  do {
    do {
    } while (*(int *)(iVar1 + 0xa8) != 0);
    piVar14 = (int *)(iVar1 + 0xa8);
    _simple_lock_try();
  } while (piVar14 == (int *)0x0);
  piVar14 = *(int **)(iVar1 + 0xc0);
  if (piVar14 == (int *)0x0) {
    *(undefined4 *)(iVar1 + 0xa8) = 0;
    piVar14 = _ipc_space_reply;
    _ipc_port_alloc_special();
    do {
      do {
      } while (*(int *)(iVar1 + 0xa8) != 0);
      piVar12 = (int *)(iVar1 + 0xa8);
      _simple_lock_try();
    } while (piVar12 == (int *)0x0);
    if ((piVar14 == (int *)0x0) || (*(int *)(iVar1 + 0xc0) != 0)) {
      _panic(aExceptionRaise_0);
    }
    *(int **)(iVar1 + 0xc0) = piVar14;
  }
  do {
    do {
    } while (*piVar14 != 0);
    piVar12 = piVar14;
    _simple_lock_try();
    piVar16 = piVar14 + 0x10;
  } while (piVar12 == (int *)0x0);
  *(undefined4 *)(iVar1 + 0xa8) = 0;
  piVar14[8] = piVar14[8] + 1;
  piVar14[1] = piVar14[1] + 2;
  *(int **)(iVar1 + 0xc4) = piVar14;
  do {
    do {
    } while (*piVar16 != 0);
    piVar12 = piVar16;
    _simple_lock_try();
  } while (piVar12 == (int *)0x0);
  *piVar14 = 0;
  piVar12 = param_1;
  _simple_lock_try();
  if (piVar12 == (int *)0x0) {
    *piVar16 = 0;
    goto loc_F00646D0;
  }
  if ((param_1[2] < 0) && (param_1[3] != _ipc_space_kernel)) {
    piVar12 = (int *)(param_1[0xc] + 0x10);
    if (param_1[0xc] == 0) {
      piVar12 = param_1 + 0x10;
    }
    piVar3 = piVar12;
    _simple_lock_try();
    if (piVar3 != (int *)0x0) {
      *param_1 = 0;
      iVar13 = piVar12[2];
      if ((((iVar13 == 0) || (*(int *)(iVar1 + 0x38) == 0)) ||
          ((*(code **)(iVar13 + 0x34) != _mach_msg_continue &&
           (((*(code **)(iVar13 + 0x34) != _mach_msg_receive_continue ||
             (*(uint *)(iVar13 + 0x9c) < 0x40)) || ((*(uint *)(iVar13 + 200) & 0x200) != 0)))))) ||
         (iVar6 = iVar1, _thread_handoff(iVar1,_exception_raise_continue,iVar13), iVar6 == 0)) {
        *piVar16 = 0;
        *piVar12 = 0;
        goto loc_F00646D0;
      }
      iVar6 = piVar14[0x12];
      if (iVar6 == 0) {
        piVar14[0x12] = iVar1;
      }
      else {
        iVar8 = *(int *)(iVar6 + 0x94);
        *(int *)(iVar1 + 0x90) = iVar6;
        *(int *)(iVar1 + 0x94) = iVar8;
        *(int *)(iVar6 + 0x94) = iVar1;
        *(int *)(iVar8 + 0x90) = iVar1;
      }
      *(undefined4 *)(iVar1 + 0x98) = 0x10004001;
      *(undefined4 *)(iVar1 + 0x9c) = 0xffffffff;
      *piVar16 = 0;
      iVar6 = *(int *)(iVar13 + 0x90);
      if (iVar6 == iVar13) {
        piVar12[2] = 0;
      }
      else {
        iVar8 = *(int *)(iVar13 + 0x94);
        piVar12[2] = iVar6;
        *(int *)(iVar6 + 0x94) = iVar8;
        *(int *)(iVar8 + 0x90) = iVar6;
        *(int *)(iVar13 + 0x90) = iVar13;
        *(int *)(iVar13 + 0x94) = iVar13;
      }
      *piVar12 = 0;
      piVar12 = *(int **)(iVar13 + 0xd8);
      do {
        do {
        } while (*piVar12 != 0);
        piVar3 = piVar12;
        _simple_lock_try();
      } while (piVar3 == (int *)0x0);
      iVar6 = piVar12[1];
      piVar12[1] = iVar6 + -1;
      *piVar12 = 0;
      if (iVar6 + -1 == 0) {
        _zfree((&_ipc_object_zones)[(piVar12[2] & 0x7fffffffU) >> 0x10],piVar12);
      }
      uVar17 = *(uint *)(*(int *)(iVar13 + 0xc) + 0x88);
      *(undefined4 *)(iVar2 + 0x14) = 0x80001112;
      *(undefined4 *)(iVar2 + 0x18) = 0x40;
      *(undefined4 *)(iVar2 + 0x24) = 0;
      *(undefined4 *)(iVar2 + 0x28) = 0x960;
      *(undefined4 *)(iVar2 + 0x2c) = _exc_port_proto;
      *(undefined4 *)(iVar2 + 0x34) = _exc_port_proto;
      *(undefined4 *)(iVar2 + 0x3c) = _exc_code_proto;
      *(undefined4 *)(iVar2 + 0x40) = param_4;
      *(undefined4 *)(iVar2 + 0x44) = _exc_code_proto;
      *(undefined4 *)(iVar2 + 0x48) = param_5;
      *(undefined4 *)(iVar2 + 0x4c) = _exc_code_proto;
      *(undefined4 *)(iVar2 + 0x50) = param_6;
      puVar15 = (undefined4 *)(iVar2 + 0x14);
      if (*(uint *)(iVar13 + 0xcc) < 0x40) {
        *(undefined4 *)(iVar2 + 0x14) = 0x80001211;
        *(int **)(iVar2 + 0x1c) = param_1;
        *(int **)(iVar2 + 0x20) = piVar14;
        *(undefined4 *)(iVar2 + 0x30) = param_2;
        *(undefined4 *)(iVar2 + 0x38) = param_3;
        _ipc_kmsg_destroy(iVar2);
        _thread_syscall_return(0x10004004);
      }
      do {
        do {
        } while (*(int *)(uVar17 + 8) != 0);
        piVar12 = (int *)(uVar17 + 8);
        _simple_lock_try();
      } while (piVar12 == (int *)0x0);
      do {
        do {
        } while (*param_1 != 0);
        piVar12 = param_1;
        _simple_lock_try();
      } while (piVar12 == (int *)0x0);
      if (-1 < param_1[2]) goto loc_F00644DC;
      piVar12 = piVar14;
      _simple_lock_try();
      if (piVar12 == (int *)0x0) goto loc_F00644DC;
      iVar6 = piVar14[2];
loc_F0064540:
      if (-1 < iVar6) {
        *piVar14 = 0;
loc_F00644DC:
        *param_1 = 0;
        *(undefined4 *)(uVar17 + 8) = 0;
        *puVar15 = 0x80001211;
        *(int **)(iVar2 + 0x1c) = param_1;
        *(int **)(iVar2 + 0x20) = piVar14;
        puVar4 = puVar15;
        _ipc_kmsg_copyout_header(puVar15,uVar17,0);
        if (puVar4 == (undefined4 *)0x0) goto loc_F006461C;
        *(undefined4 *)(iVar2 + 0x30) = param_2;
        *(undefined4 *)(iVar2 + 0x38) = param_3;
        _ipc_kmsg_copyout_dest(iVar2,uVar17);
        _ipc_kmsg_put(*(undefined4 *)(iVar13 + 0xc4),iVar2,0x18);
        _thread_syscall_return(puVar4);
        iVar6 = piVar14[2];
        goto loc_F0064540;
      }
      *piVar14 = 0;
      iVar10 = *(int *)(uVar17 + 0x14);
      iVar6 = *(int *)(iVar10 + 8);
      iVar8 = iVar6 * 0x10;
      if (iVar6 == 0) goto loc_F00644DC;
      iVar9 = iVar10 + iVar8;
      *(undefined4 *)(iVar10 + 8) = *(undefined4 *)(iVar9 + 8);
      *(undefined4 *)(iVar9 + 8) = 0;
      uVar7 = *(int *)(iVar10 + iVar8) + 0x1000000;
      *(uint *)(iVar2 + 0x1c) = iVar6 << 8 | uVar7 >> 0x18;
      *(uint *)(iVar10 + iVar8) = uVar7 | 0x40001;
      *(int **)(iVar9 + 4) = piVar14;
      *(undefined4 *)(uVar17 + 8) = 0;
      param_1[1] = param_1[1] + -1;
      iVar6 = 0;
      if (param_1[3] == uVar17) {
        iVar6 = param_1[4];
      }
      *(int *)(iVar2 + 0x20) = iVar6;
      iVar6 = param_1[7];
      param_1[7] = iVar6 + -1;
      if ((iVar6 + -1 == 0) && (iVar6 = param_1[9], iVar6 != 0)) {
        param_1[9] = 0;
        *param_1 = 0;
        _ipc_notify_no_senders(iVar6,param_1[6]);
      }
      else {
        *param_1 = 0;
      }
loc_F006461C:
      uVar7 = uVar17;
      _ipc_kmsg_copyout_object(uVar17,param_2,0x11,iVar2 + 0x30);
      _ipc_kmsg_copyout_object(uVar17,param_3,0x11,iVar2 + 0x38);
      if ((uVar7 | uVar17) == 0) {
        *(undefined4 *)(iVar2 + 0x10) = 0;
      }
      else {
        _ipc_kmsg_put(*(undefined4 *)(iVar13 + 0xc4),iVar2,*(undefined4 *)(iVar2 + 0x18));
        _thread_syscall_return(uVar7 | uVar17 | 0x1000400c);
        *(undefined4 *)(iVar2 + 0x10) = 0;
      }
      iVar6 = iVar2 + 0x14;
      _copyoutmsg(iVar6,*(undefined4 *)(iVar13 + 0xc4),0x40);
      if (iVar6 == 0) {
        if (_ipc_kmsg_cache != 0) {
          uVar5 = *(undefined4 *)(iVar13 + 0xc4);
          goto loc_F00646A8;
        }
      }
      else {
        uVar5 = *(undefined4 *)(iVar13 + 0xc4);
loc_F00646A8:
        _ipc_kmsg_put(uVar5,iVar2,*(undefined4 *)(iVar2 + 0x18));
        _thread_syscall_return();
      }
      _ipc_kmsg_cache = iVar2;
      _thread_syscall_return(0);
      goto loc_F00646D0;
    }
  }
  *piVar16 = 0;
  *param_1 = 0;
loc_F00646D0:
  *(undefined4 *)(iVar2 + 0x14) = 0x80001211;
  *(undefined4 *)(iVar2 + 0x18) = 0x40;
  *(int **)(iVar2 + 0x1c) = param_1;
  *(int **)(iVar2 + 0x20) = piVar14;
  *(undefined4 *)(iVar2 + 0x24) = 0;
  *(undefined4 *)(iVar2 + 0x28) = 0x960;
  *(undefined4 *)(iVar2 + 0x2c) = _exc_port_proto;
  *(undefined4 *)(iVar2 + 0x30) = param_2;
  *(undefined4 *)(iVar2 + 0x34) = _exc_port_proto;
  *(undefined4 *)(iVar2 + 0x38) = param_3;
  *(undefined4 *)(iVar2 + 0x3c) = _exc_code_proto;
  *(undefined4 *)(iVar2 + 0x40) = param_4;
  *(undefined4 *)(iVar2 + 0x44) = _exc_code_proto;
  *(undefined4 *)(iVar2 + 0x48) = param_5;
  _exception_raise_misses = _exception_raise_misses + 1;
  *(undefined4 *)(iVar2 + 0x4c) = _exc_code_proto;
  *(undefined4 *)(iVar2 + 0x50) = param_6;
  _ipc_mqueue_send(iVar2,0x10000,0,0);
  do {
    do {
    } while (*piVar14 != 0);
    piVar12 = piVar14;
    _simple_lock_try();
  } while (piVar12 == (int *)0x0);
  if (piVar14[2] < 0) {
    do {
      do {
      } while (*piVar16 != 0);
      piVar12 = piVar16;
      _simple_lock_try();
    } while (piVar12 == (int *)0x0);
    *piVar14 = 0;
    if (*(int *)(iVar1 + 0x38) == 0) {
      pcVar11 = (code *)0x0;
    }
    else {
      pcVar11 = _exception_raise_continue;
    }
    _ipc_mqueue_receive(piVar16,0,0xffffffff,0,0,pcVar11,
                        (undefined *)((int)register0x00000038 + -0xc),
                        (undefined *)((int)register0x00000038 + -0x10));
  }
  else {
    *piVar14 = 0;
  }
  _exception_raise_continue_slow();
  return CONCAT44(param_2,param_1);
}


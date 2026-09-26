
void _exception_raise(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                     undefined4 param_5,undefined4 param_6)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  undefined4 uVar12;
  code *pcVar13;
  int *piVar14;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  iVar6 = _ipc_kmsg_cache;
  iVar5 = _active_threads;
  if (_ipc_kmsg_cache == 0) {
    iVar6 = _kalloc(0x100);
    if (iVar6 == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(aExceptionRaise);
    }
    *(undefined4 *)(iVar6 + 8) = 0x100;
    *(undefined4 *)(iVar6 + 0xc) = 0;
  }
  else {
    _ipc_kmsg_cache = 0;
  }
  *(undefined4 *)(iVar6 + 0x10) = 0;
  piVar7 = *(int **)(iVar5 + 0xb8);
  if (piVar7 == (int *)0x0) {
    piVar7 = (int *)_ipc_port_alloc_special(_ipc_space_reply);
    if ((piVar7 == (int *)0x0) || (*(int *)(iVar5 + 0xb8) != 0)) {
                    /* WARNING: Subroutine does not return */
      _panic(aExceptionRaise);
    }
    *(int **)(iVar5 + 0xb8) = piVar7;
  }
  piVar7[7] = piVar7[7] + 1;
  *piVar7 = *piVar7 + 2;
  *(int **)(iVar5 + 0xbc) = piVar7;
  if ((param_1[1] < 0) && (param_1[2] != _ipc_space_kernel)) {
    if (param_1[0xb] == 0) {
      piVar14 = param_1 + 0xf;
    }
    else {
      piVar14 = (int *)(param_1[0xb] + 0xc);
    }
    iVar2 = piVar14[1];
    if (((iVar2 != 0) && (*(int *)(iVar5 + 0x34) != 0)) &&
       ((*(code **)(iVar2 + 0x30) == _mach_msg_continue ||
        (((*(code **)(iVar2 + 0x30) == _mach_msg_receive_continue &&
          (0x3f < *(uint *)(iVar2 + 0x98))) && ((*(byte *)(iVar2 + 0xc2) & 2) == 0)))))) {
      iVar8 = _thread_handoff(iVar5,_exception_raise_continue,iVar2);
      if (iVar8 != 0) {
        iVar8 = piVar7[0x10];
        if (iVar8 == 0) {
          piVar7[0x10] = iVar5;
        }
        else {
          iVar9 = *(int *)(iVar8 + 0x90);
          *(int *)(iVar5 + 0x8c) = iVar8;
          *(int *)(iVar5 + 0x90) = iVar9;
          *(int *)(iVar8 + 0x90) = iVar5;
          *(int *)(iVar9 + 0x8c) = iVar5;
        }
        *(undefined4 *)(iVar5 + 0x94) = 0x10004001;
        *(undefined4 *)(iVar5 + 0x98) = 0xffffffff;
        iVar8 = *(int *)(iVar2 + 0x8c);
        if (iVar2 == iVar8) {
          piVar14[1] = 0;
        }
        else {
          iVar9 = *(int *)(iVar2 + 0x90);
          piVar14[1] = iVar8;
          *(int *)(iVar8 + 0x90) = iVar9;
          *(int *)(iVar9 + 0x8c) = iVar8;
          *(int *)(iVar2 + 0x8c) = iVar2;
          *(int *)(iVar2 + 0x90) = iVar2;
        }
        piVar14 = *(int **)(iVar2 + 0xd0);
        iVar8 = *piVar14;
        *piVar14 = iVar8 + -1;
        if (iVar8 == 1) {
          _zfree((&_ipc_object_zones)[*(word *)(piVar14 + 1) & 0x7fff],piVar14);
        }
        puVar4 = (undefined4 *)(iVar6 + 0x14);
        iVar8 = *(int *)(*(int *)(iVar2 + 0xc) + 0x7c);
        *puVar4 = 0x80001112;
        *(undefined4 *)(iVar6 + 0x18) = 0x40;
        *(undefined4 *)(iVar6 + 0x24) = 0;
        *(undefined4 *)(iVar6 + 0x28) = 0x960;
        *(undefined4 *)(iVar6 + 0x2c) = _exc_port_proto;
        *(undefined4 *)(iVar6 + 0x34) = _exc_port_proto;
        *(undefined4 *)(iVar6 + 0x3c) = _exc_code_proto;
        *(undefined4 *)(iVar6 + 0x40) = param_4;
        *(undefined4 *)(iVar6 + 0x44) = _exc_code_proto;
        *(undefined4 *)(iVar6 + 0x48) = param_5;
        *(undefined4 *)(iVar6 + 0x4c) = _exc_code_proto;
        *(undefined4 *)(iVar6 + 0x50) = param_6;
        if (*(uint *)(iVar2 + 0xc4) < 0x40) {
          *puVar4 = 0x80001211;
          *(int **)(iVar6 + 0x1c) = param_1;
          *(int **)(iVar6 + 0x20) = piVar7;
          *(undefined4 *)(iVar6 + 0x30) = param_2;
          *(undefined4 *)(iVar6 + 0x38) = param_3;
          _ipc_kmsg_destroy(iVar6);
          _thread_syscall_return(0x10004004);
        }
        if (param_1[1] < 0) goto loc_4047AE8;
        do {
          do {
            *puVar4 = 0x80001211;
            *(int **)(iVar6 + 0x1c) = param_1;
            *(int **)(iVar6 + 0x20) = piVar7;
            iVar9 = _ipc_kmsg_copyout_header(puVar4,iVar8,0);
            if (iVar9 == 0) goto loc_4047B7A;
            *(undefined4 *)(iVar6 + 0x30) = param_2;
            *(undefined4 *)(iVar6 + 0x38) = param_3;
            _ipc_kmsg_copyout_dest(iVar6,iVar8);
            _ipc_kmsg_put(*(undefined4 *)(iVar2 + 0xbc),iVar6,0x18);
            _thread_syscall_return(iVar9);
loc_4047AE8:
          } while (-1 < piVar7[1]);
          iVar9 = *(int *)(iVar8 + 0xc);
          iVar3 = *(int *)(iVar9 + 8);
        } while (iVar3 == 0);
        puVar1 = (uint *)(iVar9 + iVar3 * 0x10);
        *(uint *)(iVar9 + 8) = puVar1[2];
        puVar1[2] = 0;
        uVar10 = *puVar1;
        *(uint *)(iVar6 + 0x1c) = uVar10 + 0x1000000 >> 0x18 | iVar3 << 8;
        *puVar1 = uVar10 + 0x1000000 | 0x40001;
        puVar1[1] = (uint)piVar7;
        *param_1 = *param_1 + -1;
        iVar9 = 0;
        if (iVar8 == param_1[2]) {
          iVar9 = param_1[3];
        }
        *(int *)(iVar6 + 0x20) = iVar9;
        iVar9 = param_1[6];
        param_1[6] = iVar9 + -1;
        if ((iVar9 == 1) && (iVar9 = param_1[8], iVar9 != 0)) {
          param_1[8] = 0;
          _ipc_notify_no_senders(iVar9,param_1[5]);
        }
loc_4047B7A:
        uVar10 = _ipc_kmsg_copyout_object(iVar8,param_2,0x11,iVar6 + 0x30);
        uVar11 = _ipc_kmsg_copyout_object(iVar8,param_3,0x11,iVar6 + 0x38);
        if ((uVar11 | uVar10) != 0) {
          _ipc_kmsg_put(*(undefined4 *)(iVar2 + 0xbc),iVar6,*(undefined4 *)(iVar6 + 0x18));
          _thread_syscall_return(uVar11 | uVar10 | 0x1000400c);
        }
        *(undefined4 *)(iVar6 + 0x10) = 0;
        iVar8 = _copyoutmsg(iVar6 + 0x14,*(undefined4 *)(iVar2 + 0xbc),0x40);
        if ((iVar8 != 0) || (_ipc_kmsg_cache != 0)) {
          uVar12 = _ipc_kmsg_put(*(undefined4 *)(iVar2 + 0xbc),iVar6,*(undefined4 *)(iVar6 + 0x18));
          _thread_syscall_return(uVar12);
        }
        _ipc_kmsg_cache = iVar6;
        _thread_syscall_return(0);
      }
    }
  }
  _exception_raise_misses = _exception_raise_misses + 1;
  *(undefined4 *)(iVar6 + 0x14) = 0x80001211;
  *(undefined4 *)(iVar6 + 0x18) = 0x40;
  *(int **)(iVar6 + 0x1c) = param_1;
  *(int **)(iVar6 + 0x20) = piVar7;
  *(undefined4 *)(iVar6 + 0x24) = 0;
  *(undefined4 *)(iVar6 + 0x28) = 0x960;
  *(undefined4 *)(iVar6 + 0x2c) = _exc_port_proto;
  *(undefined4 *)(iVar6 + 0x30) = param_2;
  *(undefined4 *)(iVar6 + 0x34) = _exc_port_proto;
  *(undefined4 *)(iVar6 + 0x38) = param_3;
  *(undefined4 *)(iVar6 + 0x3c) = _exc_code_proto;
  *(undefined4 *)(iVar6 + 0x40) = param_4;
  *(undefined4 *)(iVar6 + 0x44) = _exc_code_proto;
  *(undefined4 *)(iVar6 + 0x48) = param_5;
  *(undefined4 *)(iVar6 + 0x4c) = _exc_code_proto;
  *(undefined4 *)(iVar6 + 0x50) = param_6;
  _ipc_mqueue_send(iVar6,0x10000,0,0);
  if (piVar7[1] < 0) {
    pcVar13 = (code *)0x0;
    if (*(int *)(iVar5 + 0x34) != 0) {
      pcVar13 = _exception_raise_continue;
    }
    uVar12 = _ipc_mqueue_receive(piVar7 + 0xf,0,0xffffffff,0,0,pcVar13,&uStack_8,&uStack_c);
  }
  else {
    uStack_c = 0;
    uStack_8 = 0;
    uVar12 = 0x10004009;
  }
  _exception_raise_continue_slow(uVar12,uStack_8,uStack_c);
  return;
}

/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00156cc8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

kern_return_t
_exception_raise(mach_port_t exception_port,mach_port_t thread,mach_port_t task,
                exception_type_t exception,exception_data_t code,mach_msg_type_number_t codeCnt)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  code *pcVar10;
  kern_return_t kVar11;
  int *piVar12;
  int *piVar13;
  undefined4 uVar14;
  int *local_28;
  int *local_14;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar4 = _ipc_kmsg_cache;
  iVar3 = _active_threads;
  if (_ipc_kmsg_cache == 0) {
    iVar4 = _kalloc(0x100);
    if (iVar4 == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_exception_raise_001deb70);
    }
    *(undefined4 *)(iVar4 + 8) = 0x100;
    *(undefined4 *)(iVar4 + 0xc) = 0;
  }
  else {
    _ipc_kmsg_cache = 0;
  }
  *(undefined4 *)(iVar4 + 0x10) = 0;
  piVar12 = (int *)(iVar3 + 0xa8);
  do {
    do {
    } while (*piVar12 != 0);
    LOCK();
    iVar1 = *piVar12;
    *piVar12 = 1;
    UNLOCK();
  } while (iVar1 == 1);
  local_14 = *(int **)(iVar3 + 0xc0);
  if (local_14 == (int *)0x0) {
    piVar12 = (int *)(iVar3 + 0xa8);
    LOCK();
    *(undefined4 *)(iVar3 + 0xa8) = 0;
    UNLOCK();
    local_14 = (int *)_ipc_port_alloc_special(_ipc_space_reply);
    do {
      do {
      } while (*piVar12 != 0);
      LOCK();
      iVar1 = *piVar12;
      *piVar12 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    if ((local_14 == (int *)0x0) || (*(int *)(iVar3 + 0xc0) != 0)) {
                    /* WARNING: Subroutine does not return */
      _panic(s_exception_raise_001deb80);
    }
    *(int **)(iVar3 + 0xc0) = local_14;
  }
  do {
    do {
    } while (*local_14 != 0);
    LOCK();
    iVar1 = *local_14;
    *local_14 = 1;
    UNLOCK();
  } while (iVar1 == 1);
  LOCK();
  *(undefined4 *)(iVar3 + 0xa8) = 0;
  UNLOCK();
  local_14[8] = local_14[8] + 1;
  local_14[1] = local_14[1] + 2;
  *(int **)(iVar3 + 0xc4) = local_14;
  piVar12 = local_14 + 0x10;
  do {
    do {
    } while (*piVar12 != 0);
    LOCK();
    iVar1 = *piVar12;
    *piVar12 = 1;
    UNLOCK();
  } while (iVar1 == 1);
  LOCK();
  *local_14 = 0;
  UNLOCK();
  LOCK();
  iVar1 = *(int *)exception_port;
  *(undefined4 *)exception_port = 1;
  UNLOCK();
  if (iVar1 == 1) {
    LOCK();
    *piVar12 = 0;
    UNLOCK();
    goto LAB_001572c0;
  }
  if ((*(int *)(exception_port + 8) < 0) && (*(int *)(exception_port + 0xc) != _ipc_space_kernel)) {
    if (*(int *)(exception_port + 0x30) == 0) {
      local_28 = (int *)(exception_port + 0x40);
    }
    else {
      local_28 = (int *)(*(int *)(exception_port + 0x30) + 0x10);
    }
    LOCK();
    iVar1 = *local_28;
    *local_28 = 1;
    UNLOCK();
    if (iVar1 != 1) {
      LOCK();
      *(undefined4 *)exception_port = 0;
      UNLOCK();
      iVar1 = local_28[2];
      if (((iVar1 != 0) && (*(int *)(iVar3 + 0x38) != 0)) &&
         ((*(code **)(iVar1 + 0x34) == _mach_msg_continue ||
          (((*(code **)(iVar1 + 0x34) == _mach_msg_receive_continue &&
            (0x3f < *(uint *)(iVar1 + 0x9c))) && ((*(byte *)(iVar1 + 0xc9) & 2) == 0)))))) {
        iVar5 = _thread_handoff(iVar3,_exception_raise_continue,iVar1);
        if (iVar5 != 0) {
          iVar5 = local_14[0x12];
          if (iVar5 == 0) {
            local_14[0x12] = iVar3;
          }
          else {
            iVar6 = *(int *)(iVar5 + 0x94);
            *(int *)(iVar3 + 0x90) = iVar5;
            *(int *)(iVar3 + 0x94) = iVar6;
            *(int *)(iVar5 + 0x94) = iVar3;
            *(int *)(iVar6 + 0x90) = iVar3;
          }
          *(undefined4 *)(iVar3 + 0x98) = 0x10004001;
          *(undefined4 *)(iVar3 + 0x9c) = 0xffffffff;
          LOCK();
          *piVar12 = 0;
          UNLOCK();
          iVar5 = *(int *)(iVar1 + 0x90);
          if (iVar5 == iVar1) {
            local_28[2] = 0;
          }
          else {
            iVar6 = *(int *)(iVar1 + 0x94);
            local_28[2] = iVar5;
            *(int *)(iVar5 + 0x94) = iVar6;
            *(int *)(iVar6 + 0x90) = iVar5;
            *(int *)(iVar1 + 0x90) = iVar1;
            *(int *)(iVar1 + 0x94) = iVar1;
          }
          LOCK();
          *local_28 = 0;
          UNLOCK();
          piVar13 = *(int **)(iVar1 + 0xd8);
          do {
            do {
            } while (*piVar13 != 0);
            LOCK();
            iVar5 = *piVar13;
            *piVar13 = 1;
            UNLOCK();
          } while (iVar5 == 1);
          iVar5 = piVar13[1];
          piVar13[1] = iVar5 + -1;
          LOCK();
          *piVar13 = 0;
          UNLOCK();
          if (iVar5 == 1) {
            _zfree((&_ipc_object_zones)[*(ushort *)((int)piVar13 + 10) & 0x7fff],piVar13);
          }
          iVar5 = *(int *)(*(int *)(iVar1 + 0xc) + 0x88);
          *(undefined4 *)(iVar4 + 0x14) = 0x80001112;
          *(undefined4 *)(iVar4 + 0x18) = 0x40;
          *(undefined4 *)(iVar4 + 0x24) = 0;
          *(undefined4 *)(iVar4 + 0x28) = 0x960;
          *(undefined4 *)(iVar4 + 0x2c) = _exc_port_proto;
          *(undefined4 *)(iVar4 + 0x34) = _exc_port_proto;
          *(undefined4 *)(iVar4 + 0x3c) = _exc_code_proto;
          *(exception_type_t *)(iVar4 + 0x40) = exception;
          *(undefined4 *)(iVar4 + 0x44) = _exc_code_proto;
          *(exception_data_t *)(iVar4 + 0x48) = code;
          *(undefined4 *)(iVar4 + 0x4c) = _exc_code_proto;
          *(mach_msg_type_number_t *)(iVar4 + 0x50) = codeCnt;
          if (*(uint *)(iVar1 + 0xcc) < 0x40) {
            *(undefined4 *)(iVar4 + 0x14) = 0x80001211;
            *(mach_port_t *)(iVar4 + 0x1c) = exception_port;
            *(int **)(iVar4 + 0x20) = local_14;
            *(mach_port_t *)(iVar4 + 0x30) = thread;
            *(mach_port_t *)(iVar4 + 0x38) = task;
            _ipc_kmsg_destroy(iVar4);
            _thread_syscall_return(0x10004004);
          }
          piVar13 = (int *)(iVar5 + 8);
          do {
            do {
            } while (*piVar13 != 0);
            LOCK();
            iVar6 = *piVar13;
            *piVar13 = 1;
            UNLOCK();
          } while (iVar6 == 1);
          do {
            do {
            } while (*(int *)exception_port != 0);
            LOCK();
            iVar6 = *(int *)exception_port;
            *(undefined4 *)exception_port = 1;
            UNLOCK();
          } while (iVar6 == 1);
          if (*(int *)(exception_port + 8) < 0) {
            LOCK();
            iVar6 = *local_14;
            *local_14 = 1;
            UNLOCK();
            if (iVar6 != 1) goto LAB_0015713f;
          }
          do {
            while( true ) {
              LOCK();
              *(undefined4 *)exception_port = 0;
              UNLOCK();
              LOCK();
              *(undefined4 *)(iVar5 + 8) = 0;
              UNLOCK();
              *(undefined4 *)(iVar4 + 0x14) = 0x80001211;
              *(mach_port_t *)(iVar4 + 0x1c) = exception_port;
              *(int **)(iVar4 + 0x20) = local_14;
              iVar6 = _ipc_kmsg_copyout_header((undefined4 *)(iVar4 + 0x14),iVar5,0);
              if (iVar6 == 0) goto LAB_0015720f;
              *(mach_port_t *)(iVar4 + 0x30) = thread;
              *(mach_port_t *)(iVar4 + 0x38) = task;
              _ipc_kmsg_copyout_dest(iVar4,iVar5);
              _ipc_kmsg_put(*(undefined4 *)(iVar1 + 0xc4),iVar4,0x18);
              _thread_syscall_return(iVar6);
LAB_0015713f:
              if (local_14[2] < 0) break;
              LOCK();
              *local_14 = 0;
              UNLOCK();
            }
            LOCK();
            *local_14 = 0;
            UNLOCK();
            iVar6 = *(int *)(iVar5 + 0x14);
            iVar2 = *(int *)(iVar6 + 8);
          } while (iVar2 == 0);
          puVar7 = (uint *)(iVar2 * 0x10 + iVar6);
          *(uint *)(iVar6 + 8) = puVar7[2];
          puVar7[2] = 0;
          uVar8 = *puVar7;
          *(uint *)(iVar4 + 0x1c) = uVar8 + 0x1000000 >> 0x18 | iVar2 << 8;
          *puVar7 = uVar8 + 0x1000000 | 0x40001;
          puVar7[1] = (uint)local_14;
          LOCK();
          *(undefined4 *)(iVar5 + 8) = 0;
          UNLOCK();
          *(int *)(exception_port + 4) = *(int *)(exception_port + 4) + -1;
          uVar14 = 0;
          if (*(int *)(exception_port + 0xc) == iVar5) {
            uVar14 = *(undefined4 *)(exception_port + 0x10);
          }
          *(undefined4 *)(iVar4 + 0x20) = uVar14;
          iVar6 = *(int *)(exception_port + 0x1c);
          *(int *)(exception_port + 0x1c) = iVar6 + -1;
          if (iVar6 == 1) {
            iVar6 = *(int *)(exception_port + 0x24);
            if (iVar6 == 0) goto LAB_00157208;
            *(undefined4 *)(exception_port + 0x24) = 0;
            LOCK();
            *(undefined4 *)exception_port = 0;
            UNLOCK();
            _ipc_notify_no_senders(iVar6,*(undefined4 *)(exception_port + 0x18));
          }
          else {
LAB_00157208:
            LOCK();
            *(undefined4 *)exception_port = 0;
            UNLOCK();
          }
LAB_0015720f:
          uVar8 = _ipc_kmsg_copyout_object(iVar5,thread,0x11,iVar4 + 0x30);
          uVar9 = _ipc_kmsg_copyout_object(iVar5,task,0x11,iVar4 + 0x38);
          if ((uVar9 | uVar8) != 0) {
            _ipc_kmsg_put(*(undefined4 *)(iVar1 + 0xc4),iVar4,*(undefined4 *)(iVar4 + 0x18));
            _thread_syscall_return(uVar9 | uVar8 | 0x1000400c);
          }
          *(undefined4 *)(iVar4 + 0x10) = 0;
          iVar5 = _copyoutmsg(iVar4 + 0x14,*(undefined4 *)(iVar1 + 0xc4),0x40);
          if ((iVar5 != 0) || (_ipc_kmsg_cache != 0)) {
            uVar14 = _ipc_kmsg_put(*(undefined4 *)(iVar1 + 0xc4),iVar4,*(undefined4 *)(iVar4 + 0x18)
                                  );
            _thread_syscall_return(uVar14);
          }
          _ipc_kmsg_cache = iVar4;
          _thread_syscall_return(0);
          goto LAB_001572c0;
        }
      }
      LOCK();
      *piVar12 = 0;
      UNLOCK();
      LOCK();
      *local_28 = 0;
      UNLOCK();
      goto LAB_001572c0;
    }
  }
  LOCK();
  *piVar12 = 0;
  UNLOCK();
  LOCK();
  *(undefined4 *)exception_port = 0;
  UNLOCK();
LAB_001572c0:
  __exception_raise_misses = __exception_raise_misses + 1;
  *(undefined4 *)(iVar4 + 0x14) = 0x80001211;
  *(undefined4 *)(iVar4 + 0x18) = 0x40;
  *(mach_port_t *)(iVar4 + 0x1c) = exception_port;
  *(int **)(iVar4 + 0x20) = local_14;
  *(undefined4 *)(iVar4 + 0x24) = 0;
  *(undefined4 *)(iVar4 + 0x28) = 0x960;
  *(undefined4 *)(iVar4 + 0x2c) = _exc_port_proto;
  *(mach_port_t *)(iVar4 + 0x30) = thread;
  *(undefined4 *)(iVar4 + 0x34) = _exc_port_proto;
  *(mach_port_t *)(iVar4 + 0x38) = task;
  *(undefined4 *)(iVar4 + 0x3c) = _exc_code_proto;
  *(exception_type_t *)(iVar4 + 0x40) = exception;
  *(undefined4 *)(iVar4 + 0x44) = _exc_code_proto;
  *(exception_data_t *)(iVar4 + 0x48) = code;
  *(undefined4 *)(iVar4 + 0x4c) = _exc_code_proto;
  *(mach_msg_type_number_t *)(iVar4 + 0x50) = codeCnt;
  _ipc_mqueue_send(iVar4,0x10000,0,0);
  do {
    do {
    } while (*local_14 != 0);
    LOCK();
    iVar4 = *local_14;
    *local_14 = 1;
    UNLOCK();
  } while (iVar4 == 1);
  if (local_14[2] < 0) {
    do {
      do {
      } while (*piVar12 != 0);
      LOCK();
      iVar4 = *piVar12;
      *piVar12 = 1;
      UNLOCK();
    } while (iVar4 == 1);
    LOCK();
    *local_14 = 0;
    UNLOCK();
    pcVar10 = (code *)0x0;
    if (*(int *)(iVar3 + 0x38) != 0) {
      pcVar10 = _exception_raise_continue;
    }
    uVar14 = _ipc_mqueue_receive(piVar12,0,0xffffffff,0,0,pcVar10,&local_8,&local_c);
  }
  else {
    LOCK();
    *local_14 = 0;
    UNLOCK();
    local_c = 0;
    local_8 = 0;
    uVar14 = 0x10004009;
  }
  kVar11 = _exception_raise_continue_slow(uVar14,local_8,local_c);
  return kVar11;
}


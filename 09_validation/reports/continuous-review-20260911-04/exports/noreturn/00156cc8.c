
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

kern_return_t
_exception_raise(mach_port_t exception_port,mach_port_t thread,mach_port_t task,
                exception_type_t exception,exception_data_t code,mach_msg_type_number_t codeCnt)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  code *pcVar9;
  kern_return_t kVar10;
  int *piVar11;
  undefined4 uVar12;
  int *local_28;
  int *local_14;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar3 = _ipc_kmsg_cache;
  iVar8 = _active_threads;
  if (_ipc_kmsg_cache == 0) {
    iVar3 = _kalloc(0x100);
    if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_exception_raise_001deb70);
    }
    *(undefined4 *)(iVar3 + 8) = 0x100;
    *(undefined4 *)(iVar3 + 0xc) = 0;
  }
  else {
    _ipc_kmsg_cache = 0;
  }
  *(undefined4 *)(iVar3 + 0x10) = 0;
  piVar11 = (int *)(iVar8 + 0xa8);
  do {
    do {
    } while (*piVar11 != 0);
    LOCK();
    iVar1 = *piVar11;
    *piVar11 = 1;
    UNLOCK();
  } while (iVar1 == 1);
  local_14 = *(int **)(iVar8 + 0xc0);
  if (local_14 == (int *)0x0) {
    piVar11 = (int *)(iVar8 + 0xa8);
    LOCK();
    *(undefined4 *)(iVar8 + 0xa8) = 0;
    UNLOCK();
    local_14 = (int *)_ipc_port_alloc_special(_ipc_space_reply);
    do {
      do {
      } while (*piVar11 != 0);
      LOCK();
      iVar1 = *piVar11;
      *piVar11 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    if ((local_14 == (int *)0x0) || (*(int *)(iVar8 + 0xc0) != 0)) {
                    /* WARNING: Subroutine does not return */
      _panic(s_exception_raise_001deb80);
    }
    *(int **)(iVar8 + 0xc0) = local_14;
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
  *(undefined4 *)(iVar8 + 0xa8) = 0;
  UNLOCK();
  local_14[8] = local_14[8] + 1;
  local_14[1] = local_14[1] + 2;
  *(int **)(iVar8 + 0xc4) = local_14;
  piVar11 = local_14 + 0x10;
  do {
    do {
    } while (*piVar11 != 0);
    LOCK();
    iVar1 = *piVar11;
    *piVar11 = 1;
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
    *piVar11 = 0;
    UNLOCK();
  }
  else {
    if ((*(int *)(exception_port + 8) < 0) && (*(int *)(exception_port + 0xc) != _ipc_space_kernel))
    {
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
        if (((iVar1 != 0) && (*(int *)(iVar8 + 0x38) != 0)) &&
           ((*(code **)(iVar1 + 0x34) == _mach_msg_continue ||
            (((*(code **)(iVar1 + 0x34) == _mach_msg_receive_continue &&
              (0x3f < *(uint *)(iVar1 + 0x9c))) && ((*(byte *)(iVar1 + 0xc9) & 2) == 0)))))) {
          iVar4 = _thread_handoff(iVar8,_exception_raise_continue,iVar1);
          if (iVar4 != 0) {
            iVar4 = local_14[0x12];
            if (iVar4 == 0) {
              local_14[0x12] = iVar8;
            }
            else {
              iVar2 = *(int *)(iVar4 + 0x94);
              *(int *)(iVar8 + 0x90) = iVar4;
              *(int *)(iVar8 + 0x94) = iVar2;
              *(int *)(iVar4 + 0x94) = iVar8;
              *(int *)(iVar2 + 0x90) = iVar8;
            }
            *(undefined4 *)(iVar8 + 0x98) = 0x10004001;
            *(undefined4 *)(iVar8 + 0x9c) = 0xffffffff;
            LOCK();
            *piVar11 = 0;
            UNLOCK();
            iVar8 = *(int *)(iVar1 + 0x90);
            if (iVar8 == iVar1) {
              local_28[2] = 0;
            }
            else {
              iVar4 = *(int *)(iVar1 + 0x94);
              local_28[2] = iVar8;
              *(int *)(iVar8 + 0x94) = iVar4;
              *(int *)(iVar4 + 0x90) = iVar8;
              *(int *)(iVar1 + 0x90) = iVar1;
              *(int *)(iVar1 + 0x94) = iVar1;
            }
            LOCK();
            *local_28 = 0;
            UNLOCK();
            piVar11 = *(int **)(iVar1 + 0xd8);
            do {
              do {
              } while (*piVar11 != 0);
              LOCK();
              iVar8 = *piVar11;
              *piVar11 = 1;
              UNLOCK();
            } while (iVar8 == 1);
            iVar8 = piVar11[1];
            piVar11[1] = iVar8 + -1;
            LOCK();
            *piVar11 = 0;
            UNLOCK();
            if (iVar8 == 1) {
              _zfree((&_ipc_object_zones)[*(ushort *)((int)piVar11 + 10) & 0x7fff],piVar11);
            }
            iVar8 = *(int *)(*(int *)(iVar1 + 0xc) + 0x88);
            *(undefined4 *)(iVar3 + 0x14) = 0x80001112;
            *(undefined4 *)(iVar3 + 0x18) = 0x40;
            *(undefined4 *)(iVar3 + 0x24) = 0;
            *(undefined4 *)(iVar3 + 0x28) = 0x960;
            *(undefined4 *)(iVar3 + 0x2c) = _exc_port_proto;
            *(undefined4 *)(iVar3 + 0x34) = _exc_port_proto;
            *(undefined4 *)(iVar3 + 0x3c) = _exc_code_proto;
            *(exception_type_t *)(iVar3 + 0x40) = exception;
            *(undefined4 *)(iVar3 + 0x44) = _exc_code_proto;
            *(exception_data_t *)(iVar3 + 0x48) = code;
            *(undefined4 *)(iVar3 + 0x4c) = _exc_code_proto;
            *(mach_msg_type_number_t *)(iVar3 + 0x50) = codeCnt;
            if (*(uint *)(iVar1 + 0xcc) < 0x40) {
              *(undefined4 *)(iVar3 + 0x14) = 0x80001211;
              *(mach_port_t *)(iVar3 + 0x1c) = exception_port;
              *(int **)(iVar3 + 0x20) = local_14;
              *(mach_port_t *)(iVar3 + 0x30) = thread;
              *(mach_port_t *)(iVar3 + 0x38) = task;
              _ipc_kmsg_destroy(iVar3);
                    /* WARNING: Subroutine does not return */
              _thread_syscall_return(0x10004004);
            }
            piVar11 = (int *)(iVar8 + 8);
            do {
              do {
              } while (*piVar11 != 0);
              LOCK();
              iVar4 = *piVar11;
              *piVar11 = 1;
              UNLOCK();
            } while (iVar4 == 1);
            do {
              do {
              } while (*(int *)exception_port != 0);
              LOCK();
              iVar4 = *(int *)exception_port;
              *(undefined4 *)exception_port = 1;
              UNLOCK();
            } while (iVar4 == 1);
            if (*(int *)(exception_port + 8) < 0) {
              LOCK();
              iVar4 = *local_14;
              *local_14 = 1;
              UNLOCK();
              if (iVar4 != 1) {
                if (local_14[2] < 0) {
                  LOCK();
                  *local_14 = 0;
                  UNLOCK();
                  iVar4 = *(int *)(iVar8 + 0x14);
                  iVar2 = *(int *)(iVar4 + 8);
                  if (iVar2 != 0) {
                    puVar5 = (uint *)(iVar2 * 0x10 + iVar4);
                    *(uint *)(iVar4 + 8) = puVar5[2];
                    puVar5[2] = 0;
                    uVar6 = *puVar5;
                    *(uint *)(iVar3 + 0x1c) = uVar6 + 0x1000000 >> 0x18 | iVar2 << 8;
                    *puVar5 = uVar6 + 0x1000000 | 0x40001;
                    puVar5[1] = (uint)local_14;
                    LOCK();
                    *(undefined4 *)(iVar8 + 8) = 0;
                    UNLOCK();
                    *(int *)(exception_port + 4) = *(int *)(exception_port + 4) + -1;
                    uVar12 = 0;
                    if (*(int *)(exception_port + 0xc) == iVar8) {
                      uVar12 = *(undefined4 *)(exception_port + 0x10);
                    }
                    *(undefined4 *)(iVar3 + 0x20) = uVar12;
                    iVar4 = *(int *)(exception_port + 0x1c);
                    *(int *)(exception_port + 0x1c) = iVar4 + -1;
                    if (iVar4 == 1) {
                      iVar4 = *(int *)(exception_port + 0x24);
                      if (iVar4 != 0) {
                        *(undefined4 *)(exception_port + 0x24) = 0;
                        LOCK();
                        *(undefined4 *)exception_port = 0;
                        UNLOCK();
                        _ipc_notify_no_senders(iVar4,*(undefined4 *)(exception_port + 0x18));
                        goto LAB_0015720f;
                      }
                    }
                    LOCK();
                    *(undefined4 *)exception_port = 0;
                    UNLOCK();
                    goto LAB_0015720f;
                  }
                }
                else {
                  LOCK();
                  *local_14 = 0;
                  UNLOCK();
                }
              }
            }
            LOCK();
            *(undefined4 *)exception_port = 0;
            UNLOCK();
            LOCK();
            *(undefined4 *)(iVar8 + 8) = 0;
            UNLOCK();
            *(undefined4 *)(iVar3 + 0x14) = 0x80001211;
            *(mach_port_t *)(iVar3 + 0x1c) = exception_port;
            *(int **)(iVar3 + 0x20) = local_14;
            iVar4 = _ipc_kmsg_copyout_header((undefined4 *)(iVar3 + 0x14),iVar8,0);
            if (iVar4 != 0) {
              *(mach_port_t *)(iVar3 + 0x30) = thread;
              *(mach_port_t *)(iVar3 + 0x38) = task;
              _ipc_kmsg_copyout_dest(iVar3,iVar8);
              _ipc_kmsg_put(*(undefined4 *)(iVar1 + 0xc4),iVar3,0x18);
                    /* WARNING: Subroutine does not return */
              _thread_syscall_return(iVar4);
            }
LAB_0015720f:
            uVar6 = _ipc_kmsg_copyout_object(iVar8,thread,0x11,iVar3 + 0x30);
            uVar7 = _ipc_kmsg_copyout_object(iVar8,task,0x11,iVar3 + 0x38);
            if ((uVar7 | uVar6) != 0) {
              _ipc_kmsg_put(*(undefined4 *)(iVar1 + 0xc4),iVar3,*(undefined4 *)(iVar3 + 0x18));
                    /* WARNING: Subroutine does not return */
              _thread_syscall_return(uVar7 | uVar6 | 0x1000400c);
            }
            *(undefined4 *)(iVar3 + 0x10) = 0;
            iVar8 = _copyoutmsg(iVar3 + 0x14,*(undefined4 *)(iVar1 + 0xc4),0x40);
            if ((iVar8 == 0) && (_ipc_kmsg_cache == 0)) {
              _ipc_kmsg_cache = iVar3;
                    /* WARNING: Subroutine does not return */
              _thread_syscall_return(0);
            }
            uVar12 = _ipc_kmsg_put(*(undefined4 *)(iVar1 + 0xc4),iVar3,*(undefined4 *)(iVar3 + 0x18)
                                  );
                    /* WARNING: Subroutine does not return */
            _thread_syscall_return(uVar12);
          }
        }
        LOCK();
        *piVar11 = 0;
        UNLOCK();
        LOCK();
        *local_28 = 0;
        UNLOCK();
        goto LAB_001572c0;
      }
    }
    LOCK();
    *piVar11 = 0;
    UNLOCK();
    LOCK();
    *(undefined4 *)exception_port = 0;
    UNLOCK();
  }
LAB_001572c0:
  __exception_raise_misses = __exception_raise_misses + 1;
  *(undefined4 *)(iVar3 + 0x14) = 0x80001211;
  *(undefined4 *)(iVar3 + 0x18) = 0x40;
  *(mach_port_t *)(iVar3 + 0x1c) = exception_port;
  *(int **)(iVar3 + 0x20) = local_14;
  *(undefined4 *)(iVar3 + 0x24) = 0;
  *(undefined4 *)(iVar3 + 0x28) = 0x960;
  *(undefined4 *)(iVar3 + 0x2c) = _exc_port_proto;
  *(mach_port_t *)(iVar3 + 0x30) = thread;
  *(undefined4 *)(iVar3 + 0x34) = _exc_port_proto;
  *(mach_port_t *)(iVar3 + 0x38) = task;
  *(undefined4 *)(iVar3 + 0x3c) = _exc_code_proto;
  *(exception_type_t *)(iVar3 + 0x40) = exception;
  *(undefined4 *)(iVar3 + 0x44) = _exc_code_proto;
  *(exception_data_t *)(iVar3 + 0x48) = code;
  *(undefined4 *)(iVar3 + 0x4c) = _exc_code_proto;
  *(mach_msg_type_number_t *)(iVar3 + 0x50) = codeCnt;
  _ipc_mqueue_send(iVar3,0x10000,0,0);
  do {
    do {
    } while (*local_14 != 0);
    LOCK();
    iVar3 = *local_14;
    *local_14 = 1;
    UNLOCK();
  } while (iVar3 == 1);
  if (local_14[2] < 0) {
    do {
      do {
      } while (*piVar11 != 0);
      LOCK();
      iVar3 = *piVar11;
      *piVar11 = 1;
      UNLOCK();
    } while (iVar3 == 1);
    LOCK();
    *local_14 = 0;
    UNLOCK();
    pcVar9 = (code *)0x0;
    if (*(int *)(iVar8 + 0x38) != 0) {
      pcVar9 = _exception_raise_continue;
    }
    uVar12 = _ipc_mqueue_receive(piVar11,0,0xffffffff,0,0,pcVar9,&local_8,&local_c);
  }
  else {
    LOCK();
    *local_14 = 0;
    UNLOCK();
    local_c = 0;
    local_8 = 0;
    uVar12 = 0x10004009;
  }
  kVar10 = _exception_raise_continue_slow(uVar12,local_8,local_c);
  return kVar10;
}


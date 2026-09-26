/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00156d0d */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_00156d0d(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint *puVar7;
  uint uVar8;
  code *pcVar9;
  int *piVar10;
  int unaff_EBP;
  int unaff_ESI;
  undefined4 uVar11;
  
  *(undefined4 *)(unaff_ESI + 8) = 0x100;
  *(undefined4 *)(unaff_ESI + 0xc) = 0;
  *(undefined4 *)(unaff_ESI + 0x10) = 0;
  piVar10 = (int *)(*(int *)(unaff_EBP + -0xc) + 0xa8);
  do {
    do {
    } while (*piVar10 != 0);
    LOCK();
    iVar1 = *piVar10;
    *piVar10 = 1;
    UNLOCK();
  } while (iVar1 == 1);
  iVar1 = *(int *)(*(int *)(unaff_EBP + -0xc) + 0xc0);
  *(int *)(unaff_EBP + -0x10) = iVar1;
  if (iVar1 == 0) {
    *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0xc) + 0xa8;
    LOCK();
    *(undefined4 *)(*(int *)(unaff_EBP + -0xc) + 0xa8) = 0;
    UNLOCK();
    uVar4 = _ipc_port_alloc_special();
    *(undefined4 *)(unaff_EBP + -0x10) = uVar4;
    piVar10 = *(int **)(unaff_EBP + -0x24);
    do {
      do {
      } while (*piVar10 != 0);
      LOCK();
      iVar1 = *piVar10;
      *piVar10 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    if ((*(int *)(unaff_EBP + -0x10) == 0) || (*(int *)(*(int *)(unaff_EBP + -0xc) + 0xc0) != 0)) {
                    /* WARNING: Subroutine does not return */
      _panic(s_exception_raise_001deb80);
    }
    *(undefined4 *)(*(int *)(unaff_EBP + -0xc) + 0xc0) = *(undefined4 *)(unaff_EBP + -0x10);
  }
  do {
    do {
    } while (**(int **)(unaff_EBP + -0x10) != 0);
    piVar10 = *(int **)(unaff_EBP + -0x10);
    LOCK();
    iVar1 = *piVar10;
    *piVar10 = 1;
    UNLOCK();
  } while (iVar1 == 1);
  iVar1 = *(int *)(unaff_EBP + -0xc);
  LOCK();
  *(undefined4 *)(iVar1 + 0xa8) = 0;
  UNLOCK();
  piVar10[8] = piVar10[8] + 1;
  piVar10[1] = piVar10[1] + 2;
  *(int **)(iVar1 + 0xc4) = piVar10;
  *(int **)(unaff_EBP + -0x14) = piVar10 + 0x10;
  do {
    do {
    } while (**(int **)(unaff_EBP + -0x14) != 0);
    LOCK();
    iVar1 = **(int **)(unaff_EBP + -0x14);
    **(int **)(unaff_EBP + -0x14) = 1;
    UNLOCK();
  } while (iVar1 == 1);
  LOCK();
  **(undefined4 **)(unaff_EBP + -0x10) = 0;
  UNLOCK();
  LOCK();
  iVar1 = **(int **)(unaff_EBP + 8);
  **(int **)(unaff_EBP + 8) = 1;
  UNLOCK();
  if (iVar1 == 1) {
    LOCK();
    **(undefined4 **)(unaff_EBP + -0x14) = 0;
    UNLOCK();
    goto LAB_001572c0;
  }
  if ((*(int *)(*(int *)(unaff_EBP + 8) + 8) < 0) &&
     (*(int *)(*(int *)(unaff_EBP + 8) + 0xc) != _ipc_space_kernel)) {
    iVar1 = *(int *)(*(int *)(unaff_EBP + 8) + 0x30);
    if (iVar1 == 0) {
      *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + 8) + 0x40;
    }
    else {
      *(int *)(unaff_EBP + -0x24) = iVar1 + 0x10;
    }
    LOCK();
    iVar1 = **(int **)(unaff_EBP + -0x24);
    **(int **)(unaff_EBP + -0x24) = 1;
    UNLOCK();
    if (iVar1 != 1) {
      LOCK();
      **(undefined4 **)(unaff_EBP + 8) = 0;
      UNLOCK();
      iVar1 = *(int *)(*(int *)(unaff_EBP + -0x24) + 8);
      if (((iVar1 != 0) && (*(int *)(*(int *)(unaff_EBP + -0xc) + 0x38) != 0)) &&
         ((*(code **)(iVar1 + 0x34) == _mach_msg_continue ||
          (((*(code **)(iVar1 + 0x34) == _mach_msg_receive_continue &&
            (0x3f < *(uint *)(iVar1 + 0x9c))) && ((*(byte *)(iVar1 + 0xc9) & 2) == 0)))))) {
        iVar5 = _thread_handoff(*(undefined4 *)(unaff_EBP + -0xc),_exception_raise_continue);
        if (iVar5 != 0) {
          iVar5 = *(int *)(*(int *)(unaff_EBP + -0x14) + 8);
          if (iVar5 == 0) {
            *(undefined4 *)(*(int *)(unaff_EBP + -0x14) + 8) = *(undefined4 *)(unaff_EBP + -0xc);
          }
          else {
            iVar6 = *(int *)(iVar5 + 0x94);
            iVar2 = *(int *)(unaff_EBP + -0xc);
            *(int *)(iVar2 + 0x90) = iVar5;
            *(int *)(iVar2 + 0x94) = iVar6;
            *(int *)(iVar5 + 0x94) = iVar2;
            *(int *)(iVar6 + 0x90) = iVar2;
          }
          iVar5 = *(int *)(unaff_EBP + -0xc);
          *(undefined4 *)(iVar5 + 0x98) = 0x10004001;
          *(undefined4 *)(iVar5 + 0x9c) = 0xffffffff;
          LOCK();
          **(undefined4 **)(unaff_EBP + -0x14) = 0;
          UNLOCK();
          iVar5 = *(int *)(iVar1 + 0x90);
          if (iVar5 == iVar1) {
            *(undefined4 *)(*(int *)(unaff_EBP + -0x24) + 8) = 0;
          }
          else {
            iVar6 = *(int *)(iVar1 + 0x94);
            *(int *)(*(int *)(unaff_EBP + -0x24) + 8) = iVar5;
            *(int *)(iVar5 + 0x94) = iVar6;
            *(int *)(iVar6 + 0x90) = iVar5;
            *(int *)(iVar1 + 0x90) = iVar1;
            *(int *)(iVar1 + 0x94) = iVar1;
          }
          LOCK();
          **(undefined4 **)(unaff_EBP + -0x24) = 0;
          UNLOCK();
          *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(iVar1 + 0xd8);
          do {
            do {
            } while (**(int **)(unaff_EBP + -0x24) != 0);
            piVar10 = *(int **)(unaff_EBP + -0x24);
            LOCK();
            iVar5 = *piVar10;
            *piVar10 = 1;
            UNLOCK();
          } while (iVar5 == 1);
          iVar5 = piVar10[1];
          piVar10[1] = iVar5 + -1;
          LOCK();
          *piVar10 = 0;
          UNLOCK();
          if (iVar5 == 1) {
            _zfree((&_ipc_object_zones)[*(ushort *)((int)piVar10 + 10) & 0x7fff]);
          }
          *(int *)(unaff_EBP + -0x18) = unaff_ESI + 0x14;
          *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(*(int *)(iVar1 + 0xc) + 0x88);
          *(undefined4 *)(unaff_ESI + 0x14) = 0x80001112;
          *(undefined4 *)(unaff_ESI + 0x18) = 0x40;
          *(undefined4 *)(unaff_ESI + 0x24) = 0;
          *(undefined4 *)(unaff_ESI + 0x28) = 0x960;
          *(undefined4 *)(unaff_ESI + 0x2c) = _exc_port_proto;
          *(undefined4 *)(unaff_ESI + 0x34) = _exc_port_proto;
          *(undefined4 *)(unaff_ESI + 0x3c) = _exc_code_proto;
          *(undefined4 *)(unaff_ESI + 0x40) = *(undefined4 *)(unaff_EBP + 0x14);
          *(undefined4 *)(unaff_ESI + 0x44) = _exc_code_proto;
          *(undefined4 *)(unaff_ESI + 0x48) = *(undefined4 *)(unaff_EBP + 0x18);
          *(undefined4 *)(unaff_ESI + 0x4c) = _exc_code_proto;
          *(undefined4 *)(unaff_ESI + 0x50) = *(undefined4 *)(unaff_EBP + 0x1c);
          if (*(uint *)(iVar1 + 0xcc) < 0x40) {
            *(undefined4 *)(unaff_ESI + 0x14) = 0x80001211;
            *(undefined4 *)(unaff_ESI + 0x1c) = *(undefined4 *)(unaff_EBP + 8);
            *(undefined4 *)(unaff_ESI + 0x20) = *(undefined4 *)(unaff_EBP + -0x10);
            *(undefined4 *)(unaff_ESI + 0x30) = *(undefined4 *)(unaff_EBP + 0xc);
            *(undefined4 *)(unaff_ESI + 0x38) = *(undefined4 *)(unaff_EBP + 0x10);
            _ipc_kmsg_destroy();
            _thread_syscall_return(0x10004004);
          }
          piVar10 = (int *)(*(int *)(unaff_EBP + -0x1c) + 8);
          do {
            do {
            } while (*piVar10 != 0);
            LOCK();
            iVar5 = *piVar10;
            *piVar10 = 1;
            UNLOCK();
          } while (iVar5 == 1);
          do {
            do {
            } while (**(int **)(unaff_EBP + 8) != 0);
            piVar10 = *(int **)(unaff_EBP + 8);
            LOCK();
            iVar5 = *piVar10;
            *piVar10 = 1;
            UNLOCK();
          } while (iVar5 == 1);
          if (piVar10[2] < 0) {
            LOCK();
            iVar5 = **(int **)(unaff_EBP + -0x10);
            **(int **)(unaff_EBP + -0x10) = 1;
            UNLOCK();
            if (iVar5 != 1) goto LAB_0015713f;
          }
          do {
            while( true ) {
              LOCK();
              **(undefined4 **)(unaff_EBP + 8) = 0;
              UNLOCK();
              LOCK();
              *(undefined4 *)(*(int *)(unaff_EBP + -0x1c) + 8) = 0;
              UNLOCK();
              puVar3 = *(undefined4 **)(unaff_EBP + -0x18);
              *puVar3 = 0x80001211;
              puVar3[2] = *(undefined4 *)(unaff_EBP + 8);
              puVar3[3] = *(undefined4 *)(unaff_EBP + -0x10);
              iVar5 = *(int *)(unaff_EBP + -0x18);
              iVar6 = _ipc_kmsg_copyout_header(iVar5,*(undefined4 *)(unaff_EBP + -0x1c));
              *(int *)(unaff_EBP + -0x24) = iVar6;
              if (iVar6 == 0) goto LAB_0015720f;
              *(undefined4 *)(iVar5 + 0x1c) = *(undefined4 *)(unaff_EBP + 0xc);
              *(undefined4 *)(iVar5 + 0x24) = *(undefined4 *)(unaff_EBP + 0x10);
              _ipc_kmsg_copyout_dest();
              _ipc_kmsg_put(*(undefined4 *)(iVar1 + 0xc4));
              _thread_syscall_return(*(undefined4 *)(unaff_EBP + -0x24));
LAB_0015713f:
              if ((int)(*(undefined4 **)(unaff_EBP + -0x10))[2] < 0) break;
              LOCK();
              **(undefined4 **)(unaff_EBP + -0x10) = 0;
              UNLOCK();
            }
            LOCK();
            **(undefined4 **)(unaff_EBP + -0x10) = 0;
            UNLOCK();
            iVar5 = *(int *)(*(int *)(unaff_EBP + -0x1c) + 0x14);
            iVar6 = *(int *)(iVar5 + 8);
            *(int *)(unaff_EBP + -0x20) = iVar6;
          } while (iVar6 == 0);
          puVar7 = (uint *)(iVar6 * 0x10 + iVar5);
          *(uint *)(iVar5 + 8) = puVar7[2];
          puVar7[2] = 0;
          uVar8 = *puVar7;
          *(uint *)(unaff_EBP + -0x24) = uVar8 + 0x1000000;
          *(uint *)(*(int *)(unaff_EBP + -0x18) + 8) =
               uVar8 + 0x1000000 >> 0x18 | *(int *)(unaff_EBP + -0x20) << 8;
          *puVar7 = *(uint *)(unaff_EBP + -0x24) | 0x40001;
          puVar7[1] = *(uint *)(unaff_EBP + -0x10);
          iVar5 = *(int *)(unaff_EBP + -0x1c);
          LOCK();
          *(undefined4 *)(iVar5 + 8) = 0;
          UNLOCK();
          iVar6 = *(int *)(unaff_EBP + 8);
          *(int *)(iVar6 + 4) = *(int *)(iVar6 + 4) + -1;
          uVar4 = 0;
          if (*(int *)(iVar6 + 0xc) == iVar5) {
            uVar4 = *(undefined4 *)(iVar6 + 0x10);
          }
          *(undefined4 *)(*(int *)(unaff_EBP + -0x18) + 0xc) = uVar4;
          iVar5 = *(int *)(unaff_EBP + 8);
          iVar6 = *(int *)(iVar5 + 0x1c);
          *(int *)(iVar5 + 0x1c) = iVar6 + -1;
          if (iVar6 == 1) {
            iVar5 = *(int *)(iVar5 + 0x24);
            *(int *)(unaff_EBP + -0x24) = iVar5;
            if (iVar5 == 0) goto LAB_00157208;
            puVar3 = *(undefined4 **)(unaff_EBP + 8);
            puVar3[9] = 0;
            LOCK();
            *puVar3 = 0;
            UNLOCK();
            _ipc_notify_no_senders(iVar5);
          }
          else {
LAB_00157208:
            LOCK();
            **(undefined4 **)(unaff_EBP + 8) = 0;
            UNLOCK();
          }
LAB_0015720f:
          uVar4 = *(undefined4 *)(unaff_EBP + -0x1c);
          uVar11 = _ipc_kmsg_copyout_object(uVar4,*(undefined4 *)(unaff_EBP + 0xc),0x11);
          *(undefined4 *)(unaff_EBP + -0x24) = uVar11;
          uVar8 = _ipc_kmsg_copyout_object
                            (uVar4,*(undefined4 *)(unaff_EBP + 0x10),0x11,
                             *(int *)(unaff_EBP + -0x18) + 0x24);
          uVar8 = uVar8 | *(uint *)(unaff_EBP + -0x24);
          *(uint *)(unaff_EBP + -0x24) = uVar8;
          if (uVar8 != 0) {
            _ipc_kmsg_put(*(undefined4 *)(iVar1 + 0xc4));
            _thread_syscall_return(*(uint *)(unaff_EBP + -0x24) | 0x1000400c);
          }
          *(undefined4 *)(unaff_ESI + 0x10) = 0;
          iVar5 = _copyoutmsg(unaff_ESI + 0x14,*(undefined4 *)(iVar1 + 0xc4));
          if ((iVar5 != 0) || (_ipc_kmsg_cache != 0)) {
            uVar4 = _ipc_kmsg_put(*(undefined4 *)(iVar1 + 0xc4));
            *(undefined4 *)(unaff_EBP + -0x24) = uVar4;
            _thread_syscall_return(uVar4);
          }
          _ipc_kmsg_cache = unaff_ESI;
          _thread_syscall_return();
          goto LAB_001572c0;
        }
      }
      LOCK();
      **(undefined4 **)(unaff_EBP + -0x14) = 0;
      UNLOCK();
      LOCK();
      **(undefined4 **)(unaff_EBP + -0x24) = 0;
      UNLOCK();
      goto LAB_001572c0;
    }
  }
  LOCK();
  **(undefined4 **)(unaff_EBP + -0x14) = 0;
  UNLOCK();
  LOCK();
  **(undefined4 **)(unaff_EBP + 8) = 0;
  UNLOCK();
LAB_001572c0:
  __exception_raise_misses = __exception_raise_misses + 1;
  *(undefined4 *)(unaff_ESI + 0x14) = 0x80001211;
  *(undefined4 *)(unaff_ESI + 0x18) = 0x40;
  *(undefined4 *)(unaff_ESI + 0x1c) = *(undefined4 *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_ESI + 0x20) = *(undefined4 *)(unaff_EBP + -0x10);
  *(undefined4 *)(unaff_ESI + 0x24) = 0;
  *(undefined4 *)(unaff_ESI + 0x28) = 0x960;
  *(undefined4 *)(unaff_ESI + 0x2c) = _exc_port_proto;
  *(undefined4 *)(unaff_ESI + 0x30) = *(undefined4 *)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_ESI + 0x34) = _exc_port_proto;
  *(undefined4 *)(unaff_ESI + 0x38) = *(undefined4 *)(unaff_EBP + 0x10);
  *(undefined4 *)(unaff_ESI + 0x3c) = _exc_code_proto;
  *(undefined4 *)(unaff_ESI + 0x40) = *(undefined4 *)(unaff_EBP + 0x14);
  *(undefined4 *)(unaff_ESI + 0x44) = _exc_code_proto;
  *(undefined4 *)(unaff_ESI + 0x48) = *(undefined4 *)(unaff_EBP + 0x18);
  *(undefined4 *)(unaff_ESI + 0x4c) = _exc_code_proto;
  *(undefined4 *)(unaff_ESI + 0x50) = *(undefined4 *)(unaff_EBP + 0x1c);
  _ipc_mqueue_send();
  do {
    do {
    } while (**(int **)(unaff_EBP + -0x10) != 0);
    piVar10 = *(int **)(unaff_EBP + -0x10);
    LOCK();
    iVar1 = *piVar10;
    *piVar10 = 1;
    UNLOCK();
  } while (iVar1 == 1);
  if (piVar10[2] < 0) {
    do {
      do {
      } while (**(int **)(unaff_EBP + -0x14) != 0);
      LOCK();
      iVar1 = **(int **)(unaff_EBP + -0x14);
      **(int **)(unaff_EBP + -0x14) = 1;
      UNLOCK();
    } while (iVar1 == 1);
    LOCK();
    **(undefined4 **)(unaff_EBP + -0x10) = 0;
    UNLOCK();
    pcVar9 = (code *)0x0;
    if (*(int *)(*(int *)(unaff_EBP + -0xc) + 0x38) != 0) {
      pcVar9 = _exception_raise_continue;
    }
    uVar4 = _ipc_mqueue_receive(*(undefined4 *)(unaff_EBP + -0x14),0,0xffffffff,0,0,pcVar9,
                                unaff_EBP + -4);
    *(undefined4 *)(unaff_EBP + -0x24) = uVar4;
    uVar4 = *(undefined4 *)(unaff_EBP + -4);
    uVar11 = *(undefined4 *)(unaff_EBP + -0x24);
  }
  else {
    LOCK();
    *piVar10 = 0;
    UNLOCK();
    uVar4 = 0;
    uVar11 = 0x10004009;
  }
  _exception_raise_continue_slow(uVar11,uVar4);
  return;
}


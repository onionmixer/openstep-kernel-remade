/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00156db0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_00156db0(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  code *pcVar8;
  int *piVar9;
  int unaff_EBP;
  int unaff_ESI;
  undefined4 uVar10;
  undefined4 uVar11;
  
  *(undefined4 *)(*(int *)(unaff_EBP + -0xc) + 0xc0) = *(undefined4 *)(unaff_EBP + -0x10);
  do {
    do {
    } while (**(int **)(unaff_EBP + -0x10) != 0);
    piVar9 = *(int **)(unaff_EBP + -0x10);
    LOCK();
    iVar1 = *piVar9;
    *piVar9 = 1;
    UNLOCK();
  } while (iVar1 == 1);
  iVar1 = *(int *)(unaff_EBP + -0xc);
  LOCK();
  *(undefined4 *)(iVar1 + 0xa8) = 0;
  UNLOCK();
  piVar9[8] = piVar9[8] + 1;
  piVar9[1] = piVar9[1] + 2;
  *(int **)(iVar1 + 0xc4) = piVar9;
  *(int **)(unaff_EBP + -0x14) = piVar9 + 0x10;
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
        iVar4 = _thread_handoff(*(undefined4 *)(unaff_EBP + -0xc),_exception_raise_continue);
        if (iVar4 != 0) {
          iVar4 = *(int *)(*(int *)(unaff_EBP + -0x14) + 8);
          if (iVar4 == 0) {
            *(undefined4 *)(*(int *)(unaff_EBP + -0x14) + 8) = *(undefined4 *)(unaff_EBP + -0xc);
          }
          else {
            iVar5 = *(int *)(iVar4 + 0x94);
            iVar2 = *(int *)(unaff_EBP + -0xc);
            *(int *)(iVar2 + 0x90) = iVar4;
            *(int *)(iVar2 + 0x94) = iVar5;
            *(int *)(iVar4 + 0x94) = iVar2;
            *(int *)(iVar5 + 0x90) = iVar2;
          }
          iVar4 = *(int *)(unaff_EBP + -0xc);
          *(undefined4 *)(iVar4 + 0x98) = 0x10004001;
          *(undefined4 *)(iVar4 + 0x9c) = 0xffffffff;
          LOCK();
          **(undefined4 **)(unaff_EBP + -0x14) = 0;
          UNLOCK();
          iVar4 = *(int *)(iVar1 + 0x90);
          if (iVar4 == iVar1) {
            *(undefined4 *)(*(int *)(unaff_EBP + -0x24) + 8) = 0;
          }
          else {
            iVar5 = *(int *)(iVar1 + 0x94);
            *(int *)(*(int *)(unaff_EBP + -0x24) + 8) = iVar4;
            *(int *)(iVar4 + 0x94) = iVar5;
            *(int *)(iVar5 + 0x90) = iVar4;
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
            piVar9 = *(int **)(unaff_EBP + -0x24);
            LOCK();
            iVar4 = *piVar9;
            *piVar9 = 1;
            UNLOCK();
          } while (iVar4 == 1);
          iVar4 = piVar9[1];
          piVar9[1] = iVar4 + -1;
          LOCK();
          *piVar9 = 0;
          UNLOCK();
          if (iVar4 == 1) {
            _zfree((&_ipc_object_zones)[*(ushort *)((int)piVar9 + 10) & 0x7fff]);
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
          piVar9 = (int *)(*(int *)(unaff_EBP + -0x1c) + 8);
          do {
            do {
            } while (*piVar9 != 0);
            LOCK();
            iVar4 = *piVar9;
            *piVar9 = 1;
            UNLOCK();
          } while (iVar4 == 1);
          do {
            do {
            } while (**(int **)(unaff_EBP + 8) != 0);
            piVar9 = *(int **)(unaff_EBP + 8);
            LOCK();
            iVar4 = *piVar9;
            *piVar9 = 1;
            UNLOCK();
          } while (iVar4 == 1);
          if (piVar9[2] < 0) {
            LOCK();
            iVar4 = **(int **)(unaff_EBP + -0x10);
            **(int **)(unaff_EBP + -0x10) = 1;
            UNLOCK();
            if (iVar4 != 1) goto LAB_0015713f;
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
              iVar4 = *(int *)(unaff_EBP + -0x18);
              iVar5 = _ipc_kmsg_copyout_header(iVar4,*(undefined4 *)(unaff_EBP + -0x1c));
              *(int *)(unaff_EBP + -0x24) = iVar5;
              if (iVar5 == 0) goto LAB_0015720f;
              *(undefined4 *)(iVar4 + 0x1c) = *(undefined4 *)(unaff_EBP + 0xc);
              *(undefined4 *)(iVar4 + 0x24) = *(undefined4 *)(unaff_EBP + 0x10);
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
            iVar4 = *(int *)(*(int *)(unaff_EBP + -0x1c) + 0x14);
            iVar5 = *(int *)(iVar4 + 8);
            *(int *)(unaff_EBP + -0x20) = iVar5;
          } while (iVar5 == 0);
          puVar6 = (uint *)(iVar5 * 0x10 + iVar4);
          *(uint *)(iVar4 + 8) = puVar6[2];
          puVar6[2] = 0;
          uVar7 = *puVar6;
          *(uint *)(unaff_EBP + -0x24) = uVar7 + 0x1000000;
          *(uint *)(*(int *)(unaff_EBP + -0x18) + 8) =
               uVar7 + 0x1000000 >> 0x18 | *(int *)(unaff_EBP + -0x20) << 8;
          *puVar6 = *(uint *)(unaff_EBP + -0x24) | 0x40001;
          puVar6[1] = *(uint *)(unaff_EBP + -0x10);
          iVar4 = *(int *)(unaff_EBP + -0x1c);
          LOCK();
          *(undefined4 *)(iVar4 + 8) = 0;
          UNLOCK();
          iVar5 = *(int *)(unaff_EBP + 8);
          *(int *)(iVar5 + 4) = *(int *)(iVar5 + 4) + -1;
          uVar11 = 0;
          if (*(int *)(iVar5 + 0xc) == iVar4) {
            uVar11 = *(undefined4 *)(iVar5 + 0x10);
          }
          *(undefined4 *)(*(int *)(unaff_EBP + -0x18) + 0xc) = uVar11;
          iVar4 = *(int *)(unaff_EBP + 8);
          iVar5 = *(int *)(iVar4 + 0x1c);
          *(int *)(iVar4 + 0x1c) = iVar5 + -1;
          if (iVar5 == 1) {
            iVar4 = *(int *)(iVar4 + 0x24);
            *(int *)(unaff_EBP + -0x24) = iVar4;
            if (iVar4 == 0) goto LAB_00157208;
            puVar3 = *(undefined4 **)(unaff_EBP + 8);
            puVar3[9] = 0;
            LOCK();
            *puVar3 = 0;
            UNLOCK();
            _ipc_notify_no_senders(iVar4);
          }
          else {
LAB_00157208:
            LOCK();
            **(undefined4 **)(unaff_EBP + 8) = 0;
            UNLOCK();
          }
LAB_0015720f:
          uVar11 = *(undefined4 *)(unaff_EBP + -0x1c);
          uVar10 = _ipc_kmsg_copyout_object(uVar11,*(undefined4 *)(unaff_EBP + 0xc),0x11);
          *(undefined4 *)(unaff_EBP + -0x24) = uVar10;
          uVar7 = _ipc_kmsg_copyout_object
                            (uVar11,*(undefined4 *)(unaff_EBP + 0x10),0x11,
                             *(int *)(unaff_EBP + -0x18) + 0x24);
          uVar7 = uVar7 | *(uint *)(unaff_EBP + -0x24);
          *(uint *)(unaff_EBP + -0x24) = uVar7;
          if (uVar7 != 0) {
            _ipc_kmsg_put(*(undefined4 *)(iVar1 + 0xc4));
            _thread_syscall_return(*(uint *)(unaff_EBP + -0x24) | 0x1000400c);
          }
          *(undefined4 *)(unaff_ESI + 0x10) = 0;
          iVar4 = _copyoutmsg(unaff_ESI + 0x14,*(undefined4 *)(iVar1 + 0xc4));
          if ((iVar4 != 0) || (_ipc_kmsg_cache != 0)) {
            uVar11 = _ipc_kmsg_put(*(undefined4 *)(iVar1 + 0xc4));
            *(undefined4 *)(unaff_EBP + -0x24) = uVar11;
            _thread_syscall_return(uVar11);
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
    piVar9 = *(int **)(unaff_EBP + -0x10);
    LOCK();
    iVar1 = *piVar9;
    *piVar9 = 1;
    UNLOCK();
  } while (iVar1 == 1);
  if (piVar9[2] < 0) {
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
    pcVar8 = (code *)0x0;
    if (*(int *)(*(int *)(unaff_EBP + -0xc) + 0x38) != 0) {
      pcVar8 = _exception_raise_continue;
    }
    uVar11 = _ipc_mqueue_receive(*(undefined4 *)(unaff_EBP + -0x14),0,0xffffffff,0,0,pcVar8,
                                 unaff_EBP + -4);
    *(undefined4 *)(unaff_EBP + -0x24) = uVar11;
    uVar11 = *(undefined4 *)(unaff_EBP + -4);
    uVar10 = *(undefined4 *)(unaff_EBP + -0x24);
  }
  else {
    LOCK();
    *piVar9 = 0;
    UNLOCK();
    uVar11 = 0;
    uVar10 = 0x10004009;
  }
  _exception_raise_continue_slow(uVar10,uVar11);
  return;
}


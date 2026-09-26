/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00158bce */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_00158bce(void)

{
  int *piVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint *puVar5;
  int unaff_EBP;
  int *unaff_ESI;
  uint uStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  int *piStack_4;
  
  if (*(int *)(unaff_EBP + -0x2c) != 0) {
    piStack_4 = (int *)0x158c5a;
    _ipc_kmsg_destroy();
    if ((unaff_ESI != (int *)0x0) && (unaff_ESI != (int *)0xffffffff)) {
      piStack_4 = (int *)0x158c6c;
      _ipc_object_release();
    }
    piStack_4 = (int *)0x158c78;
    uVar3 = _msg_return_translate();
    return uVar3;
  }
  if ((unaff_ESI != (int *)0x0) && (unaff_ESI != (int *)0xffffffff)) {
    do {
      do {
      } while (*unaff_ESI != 0);
      LOCK();
      iVar4 = *unaff_ESI;
      *unaff_ESI = 1;
      UNLOCK();
    } while (iVar4 == 1);
    if (unaff_ESI[3] == *(int *)(unaff_EBP + -0x1c)) {
      piVar1 = (int *)unaff_ESI[0xc];
      if (piVar1 != (int *)0x0) {
        do {
          do {
          } while (*piVar1 != 0);
          LOCK();
          iVar4 = *piVar1;
          *piVar1 = 1;
          UNLOCK();
        } while (iVar4 == 1);
        if (piVar1[2] < 0) {
          LOCK();
          *piVar1 = 0;
          UNLOCK();
          unaff_ESI[1] = unaff_ESI[1] + -1;
          LOCK();
          *unaff_ESI = 0;
          UNLOCK();
          return 0xffffff36;
        }
        iStack_8 = 0x158d13;
        piStack_4 = piVar1;
        _ipc_pset_remove();
        LOCK();
        *piVar1 = 0;
        UNLOCK();
        if (piVar1[1] == 0) {
          piStack_4 = (int *)(&_ipc_object_zones)[*(ushort *)((int)piVar1 + 10) & 0x7fff];
          iStack_8 = 0x158d38;
          _zfree();
        }
      }
      piVar1 = unaff_ESI + 0x10;
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar4 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar4 == 1);
      LOCK();
      *unaff_ESI = 0;
      UNLOCK();
      piStack_4 = (int *)(unaff_EBP + -4);
      iStack_8 = 0;
      iStack_c = 0;
      iStack_10 = *(undefined4 *)(unaff_EBP + 0x18);
      uStack_14 = 0xffffffff;
      if ((*(uint *)(unaff_EBP + 0xc) & 0x1000) != 0) {
        uStack_14 = *(uint *)(unaff_EBP + 0x10);
      }
      uVar3 = _ipc_mqueue_receive(piVar1,*(uint *)(unaff_EBP + 0xc) & 0x100);
      *(undefined4 *)(unaff_EBP + -0x2c) = uVar3;
      piStack_4 = (int *)0x158d94;
      _ipc_object_release();
      if (*(int *)(unaff_EBP + -0x2c) == 0) {
        if (*(uint *)(*(int *)(unaff_EBP + -4) + 0x18) <= *(uint *)(unaff_EBP + 0x10)) {
          piStack_4 = *(int **)(unaff_EBP + -0x1c);
          iStack_8 = *(undefined4 *)(unaff_EBP + -4);
          iStack_c = 0x158f59;
          uVar3 = _ipc_kmsg_copyout_compat();
          *(undefined4 *)(unaff_EBP + -0x2c) = uVar3;
          iStack_10 = *(int *)(unaff_EBP + -4);
          iStack_c = *(int *)(iStack_10 + 0x18) + *(int *)(iStack_10 + 0x10);
          *(int *)(iStack_10 + 0x18) = iStack_c;
          uStack_14 = *(uint *)(unaff_EBP + 8);
          _ipc_kmsg_put_to_kernel();
          uVar3 = _msg_return_translate(*(undefined4 *)(unaff_EBP + -0x2c));
          return uVar3;
        }
        piStack_4 = (int *)0x158f39;
        _ipc_kmsg_destroy();
        piStack_4 = (int *)0x10004004;
        iStack_8 = 0x158f43;
        uVar3 = _msg_return_translate();
        return uVar3;
      }
      if (*(int *)(unaff_EBP + -0x2c) == 0x10004005) {
        while ((*(byte *)(_active_threads + 0x17c) & 3) != 0) {
          piStack_4 = (int *)0x158db7;
          _thread_halt_self_with_continuation();
        }
        *(undefined4 *)(*(int *)(unaff_EBP + 8) + 4) = *(undefined4 *)(unaff_EBP + 0x10);
        if ((*(uint *)(unaff_EBP + 0xc) & 0x400) == 0) {
          iVar4 = *(int *)(_active_threads + 0xc);
          *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(iVar4 + 0x88);
          *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(iVar4 + 0xc);
          *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(*(int *)(unaff_EBP + 8) + 0xc);
          uVar2 = *(uint *)(unaff_EBP + 0x10);
          do {
            piStack_4 = (int *)(unaff_EBP + -0xc);
            iStack_8 = *(int *)(unaff_EBP + -0x28);
            iStack_c = *(int *)(unaff_EBP + -0x2c);
            iStack_10 = 0x158e19;
            iVar4 = _ipc_mqueue_copyin();
            puVar5 = (uint *)&stack0x00000004;
            if (iVar4 != 0) goto LAB_00158eff;
            piStack_4 = (int *)(unaff_EBP + -0x14);
            iStack_8 = 0;
            iStack_c = 0;
            iStack_10 = *(int *)(unaff_EBP + 0x18);
            uStack_14 = 0xffffffff;
            if ((*(byte *)(unaff_EBP + 0xd) & 0x10) != 0) {
              uStack_14 = uVar2;
            }
            iVar4 = _ipc_mqueue_receive(*(undefined4 *)(unaff_EBP + -0xc),
                                        *(uint *)(unaff_EBP + 0xc) & 0x100);
            piStack_4 = (int *)0x158e64;
            _ipc_object_release();
            if (iVar4 != 0x10004005) break;
            while ((*(byte *)(_active_threads + 0x17c) & 3) != 0) {
              piStack_4 = (int *)0x158e7b;
              _thread_halt_self_with_continuation();
            }
          } while ((*(byte *)(unaff_EBP + 0xd) & 4) == 0);
          if (iVar4 == 0) {
            if (uVar2 < *(uint *)(*(int *)(unaff_EBP + -0x14) + 0x18)) {
              piStack_4 = (int *)0x158ec6;
              _ipc_kmsg_destroy();
              piStack_4 = (int *)0x10004004;
              iStack_8 = 0x158ed0;
              uVar3 = _msg_return_translate();
              return uVar3;
            }
            piStack_4 = *(int **)(unaff_EBP + -0x2c);
            iStack_c = 0x158ee6;
            iStack_8 = *(int *)(unaff_EBP + -0x14);
            iVar4 = _ipc_kmsg_copyout_compat();
            iStack_10 = *(int *)(unaff_EBP + -0x14);
            iStack_c = *(int *)(iStack_10 + 0x18) + *(int *)(iStack_10 + 0x10);
            *(int *)(iStack_10 + 0x18) = iStack_c;
            uStack_14 = *(uint *)(unaff_EBP + 8);
            puVar5 = &uStack_14;
            _ipc_kmsg_put_to_kernel();
          }
          else {
            puVar5 = (uint *)&stack0x00000004;
            if (iVar4 == 0x10004004) {
              *(undefined4 *)(*(int *)(unaff_EBP + 8) + 4) = *(undefined4 *)(unaff_EBP + -0x14);
              puVar5 = (uint *)&stack0x00000004;
            }
          }
LAB_00158eff:
          *(int *)((int)puVar5 + -4) = iVar4;
          *(undefined4 *)((int)puVar5 + -8) = 0x158f05;
          uVar3 = _msg_return_translate();
          return uVar3;
        }
      }
      else if (*(int *)(unaff_EBP + -0x2c) == 0x10004004) {
        *(undefined4 *)(*(int *)(unaff_EBP + 8) + 4) = *(undefined4 *)(unaff_EBP + -4);
      }
      piStack_4 = (int *)0x158f23;
      uVar3 = _msg_return_translate();
      return uVar3;
    }
    iVar4 = unaff_ESI[1];
    unaff_ESI[1] = iVar4 + -1;
    LOCK();
    *unaff_ESI = 0;
    UNLOCK();
    if (iVar4 == 1) {
      piStack_4 = (int *)(&_ipc_object_zones)[*(ushort *)((int)unaff_ESI + 10) & 0x7fff];
      iStack_8 = 0x158cd1;
      _zfree();
    }
  }
  return 0xffffff36;
}


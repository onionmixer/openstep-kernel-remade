/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00154594 */

undefined4
_msg_rpc_trap(int param_1,uint param_2,int param_3,uint param_4,undefined4 param_5,
             undefined4 param_6)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  int local_10;
  undefined1 local_c [4];
  int local_8;
  
  iVar8 = *(int *)(*(int *)(_active_threads + 0xc) + 0x88);
  uVar4 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0xc);
  uVar7 = param_3 + 3U & 0xfffffffc;
  if (0x2000 < uVar7) {
    return 0xffffff93;
  }
  iVar3 = _ipc_kmsg_get(param_1,uVar7,param_3 - uVar7,&local_8);
  if (iVar3 != 0) {
    uVar4 = _msg_return_translate(iVar3);
    return uVar4;
  }
  iVar3 = _ipc_kmsg_copyin_compat(local_8,iVar8,uVar4);
  if (iVar3 != 0) {
    if (*(int *)(local_8 + 8) < 1) {
      _ipc_kmsg_free(local_8);
    }
    else {
      _kfree(local_8,*(int *)(local_8 + 8));
    }
    uVar4 = _msg_return_translate(iVar3);
    return uVar4;
  }
  piVar1 = *(int **)(local_8 + 0x20);
  if ((piVar1 == (int *)0x0) || (piVar1 == (int *)0xffffffff)) {
LAB_0015473c:
    if ((param_2 & 2) == 0) {
      if ((param_2 & 0x20) == 0) {
        uVar6 = 0;
        if ((param_2 & 1) != 0) {
          uVar6 = 0x10;
        }
      }
      else {
        uVar6 = 0x20000;
        if ((param_2 & 1) != 0) {
          uVar6 = 0x20010;
        }
      }
      iVar3 = _ipc_mqueue_send(local_8,uVar6,param_5,0);
    }
    else {
      uVar6 = 0;
      if ((param_2 & 1) != 0) {
        uVar6 = param_5;
      }
      uVar5 = 0x10;
      if ((param_2 & 0x20) != 0) {
        uVar5 = 0x20010;
      }
      iVar3 = _ipc_mqueue_send(local_8,uVar5,uVar6,0);
      if (iVar3 == 0x10000004) {
        iVar3 = _ipc_marequest_create(iVar8,*(undefined4 *)(local_8 + 0x1c),0,local_8 + 0xc);
        if (iVar3 == 0) {
          _ipc_mqueue_send(local_8,0x10000,0,0);
          if ((piVar1 != (int *)0x0) && (piVar1 != (int *)0xffffffff)) {
            _ipc_object_release(piVar1);
          }
          return 0xffffff97;
        }
        goto LAB_00154820;
      }
    }
    if (iVar3 != 0) {
LAB_00154820:
      _ipc_kmsg_destroy(local_8);
      if ((piVar1 != (int *)0x0) && (piVar1 != (int *)0xffffffff)) {
        _ipc_object_release(piVar1);
      }
      uVar4 = _msg_return_translate(iVar3);
      return uVar4;
    }
LAB_0015484c:
    if ((piVar1 != (int *)0x0) && (piVar1 != (int *)0xffffffff)) {
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar3 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar3 == 1);
      if (piVar1[3] == iVar8) {
        piVar2 = (int *)piVar1[0xc];
        if (piVar2 != (int *)0x0) {
          do {
            do {
            } while (*piVar2 != 0);
            LOCK();
            iVar3 = *piVar2;
            *piVar2 = 1;
            UNLOCK();
          } while (iVar3 == 1);
          if (piVar2[2] < 0) {
            LOCK();
            *piVar2 = 0;
            UNLOCK();
            piVar1[1] = piVar1[1] + -1;
            LOCK();
            *piVar1 = 0;
            UNLOCK();
            goto LAB_001548cd;
          }
          _ipc_pset_remove(piVar2,piVar1);
          LOCK();
          *piVar2 = 0;
          UNLOCK();
          if (piVar2[1] == 0) {
            _zfree((&_ipc_object_zones)[*(ushort *)((int)piVar2 + 10) & 0x7fff],piVar2);
          }
        }
        piVar2 = piVar1 + 0x10;
        do {
          do {
          } while (*piVar2 != 0);
          LOCK();
          iVar3 = *piVar2;
          *piVar2 = 1;
          UNLOCK();
        } while (iVar3 == 1);
        LOCK();
        *piVar1 = 0;
        iVar3 = _active_threads;
        UNLOCK();
        *(int *)(_active_threads + 0xc4) = param_1;
        *(uint *)(iVar3 + 200) = param_2;
        *(uint *)(iVar3 + 0xcc) = param_4;
        *(undefined4 *)(iVar3 + 0xd0) = param_6;
        *(int **)(iVar3 + 0xd8) = piVar1;
        *(int **)(iVar3 + 0xdc) = piVar2;
        uVar7 = 0xffffffff;
        if ((param_2 & 0x1000) != 0) {
          uVar7 = param_4;
        }
        iVar3 = _ipc_mqueue_receive(piVar2,param_2 & 0x100,uVar7,param_6,0,_msg_receive_continue,
                                    &local_8,local_c);
        _ipc_object_release(piVar1);
        if (iVar3 != 0) {
          if (iVar3 == 0x10004004) {
            local_10 = local_8;
            _copyout(&local_10,param_1 + 4,4);
          }
          uVar4 = _msg_return_translate(iVar3);
          return uVar4;
        }
        if (param_4 < *(uint *)(local_8 + 0x18)) {
          _ipc_kmsg_destroy(local_8);
          return 0xffffff34;
        }
        goto LAB_001549dc;
      }
      iVar8 = piVar1[1];
      piVar1[1] = iVar8 + -1;
      LOCK();
      *piVar1 = 0;
      UNLOCK();
      if (iVar8 == 1) {
        _zfree((&_ipc_object_zones)[*(ushort *)((int)piVar1 + 10) & 0x7fff],piVar1);
      }
    }
LAB_001548cd:
    uVar4 = 0xffffff36;
  }
  else {
    piVar2 = *(int **)(local_8 + 0x1c);
    _ipc_object_reference(piVar1);
    do {
      do {
      } while (*piVar2 != 0);
      LOCK();
      iVar3 = *piVar2;
      *piVar2 = 1;
      UNLOCK();
    } while (iVar3 == 1);
    if (piVar2[3] != _ipc_space_kernel) {
      LOCK();
      *piVar2 = 0;
      UNLOCK();
      goto LAB_0015473c;
    }
    LOCK();
    *piVar2 = 0;
    UNLOCK();
    local_8 = _ipc_kobject_server(local_8);
    if (local_8 == 0) goto LAB_0015484c;
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar3 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar3 == 1);
    if ((((-1 < piVar1[2]) || (piVar1[3] != iVar8)) || (piVar1[0xc] != 0)) ||
       (param_4 < (uint)(*(int *)(local_8 + 0x18) + *(int *)(local_8 + 0x10)))) {
LAB_00154704:
      LOCK();
      *piVar1 = 0;
      UNLOCK();
      _ipc_mqueue_send(local_8,0x10000,0,0);
      goto LAB_0015484c;
    }
    piVar2 = piVar1 + 0x10;
    do {
      do {
      } while (*piVar2 != 0);
      LOCK();
      iVar3 = *piVar2;
      *piVar2 = 1;
      UNLOCK();
    } while (iVar3 == 1);
    if ((piVar1[0x12] != 0) || (piVar1[0x11] != 0)) {
      LOCK();
      *piVar2 = 0;
      UNLOCK();
      goto LAB_00154704;
    }
    piVar1[0xd] = piVar1[0xd] + 1;
    LOCK();
    *piVar2 = 0;
    UNLOCK();
    piVar1[1] = piVar1[1] + -1;
    LOCK();
    *piVar1 = 0;
    UNLOCK();
LAB_001549dc:
    _ipc_kmsg_copyout_compat(local_8,iVar8,uVar4);
    iVar8 = *(int *)(local_8 + 0x18) + *(int *)(local_8 + 0x10);
    *(int *)(local_8 + 0x18) = iVar8;
    uVar4 = _ipc_kmsg_put(param_1,local_8,iVar8);
    uVar4 = _msg_return_translate(uVar4);
  }
  return uVar4;
}


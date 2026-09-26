/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001589fc */

undefined4 _msg_rpc(uint param_1,uint param_2,uint param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  uint *puVar7;
  uint uStack_54;
  int iStack_50;
  undefined4 *puStack_4c;
  uint uStack_48;
  int *piStack_44;
  int local_18 [2];
  undefined4 local_10 [2];
  int local_8;
  
  iVar1 = *(int *)(*(int *)(_active_threads + 0xc) + 0x88);
  uStack_48 = *(int *)(param_1 + 4) + 3U & 0xfffffffc;
  piStack_44 = (int *)(*(int *)(param_1 + 4) - uStack_48);
  if (0x2000 < uStack_48) {
    return 0xffffff93;
  }
  puStack_4c = (undefined4 *)param_1;
  iStack_50 = 0x158a4f;
  iVar5 = _ipc_kmsg_get_from_kernel();
  if (iVar5 != 0) {
    piStack_44 = (int *)0x158a5f;
    uVar6 = _msg_return_translate();
    return uVar6;
  }
  uStack_48 = local_8;
  puStack_4c = (undefined4 *)0x158a81;
  piStack_44 = (int *)iVar1;
  iVar5 = _ipc_kmsg_copyin_compat();
  if (iVar5 != 0) {
    if (*(int *)(local_8 + 8) < 1) {
      piStack_44 = (int *)0x158a9b;
      _ipc_kmsg_free();
    }
    else {
      piStack_44 = (int *)local_8;
      uStack_48 = 0x158a6b;
      _kfree();
    }
    piStack_44 = (int *)0x158aa7;
    uVar6 = _msg_return_translate();
    return uVar6;
  }
  piVar2 = *(int **)(local_8 + 0x20);
  if ((piVar2 == (int *)0x0) || (piVar2 == (int *)0xffffffff)) {
LAB_00158bbc:
    if ((param_2 & 2) != 0) {
                    /* WARNING: Subroutine does not return */
      piStack_44 = (int *)&UNK_00158bce;
      _panic(s_msg_rpc_notify_001dec8f);
    }
    do {
      if ((param_2 & 0x20) == 0) {
        uStack_48 = 0;
        if ((param_2 & 1) != 0) {
          uStack_48 = 0x10;
        }
      }
      else {
        uStack_48 = 0x20000;
        if ((param_2 & 1) != 0) {
          uStack_48 = 0x20010;
        }
      }
      piStack_44 = (int *)param_4;
      puStack_4c = (undefined4 *)local_8;
      iStack_50 = 0x158c11;
      iVar5 = _ipc_mqueue_send();
      if (iVar5 != 0x10000007) break;
      while ((*(byte *)(_active_threads + 0x17c) & 3) != 0) {
        piStack_44 = (int *)0x158c2b;
        _thread_halt_self_with_continuation();
      }
    } while ((param_2 & 4) == 0);
    if (iVar5 != 0) {
      piStack_44 = (int *)0x158c5a;
      _ipc_kmsg_destroy();
      if ((piVar2 != (int *)0x0) && (piVar2 != (int *)0xffffffff)) {
        piStack_44 = (int *)0x158c6c;
        _ipc_object_release();
      }
      piStack_44 = (int *)0x158c78;
      uVar6 = _msg_return_translate();
      return uVar6;
    }
LAB_00158c80:
    if ((piVar2 != (int *)0x0) && (piVar2 != (int *)0xffffffff)) {
      do {
        do {
        } while (*piVar2 != 0);
        LOCK();
        iVar5 = *piVar2;
        *piVar2 = 1;
        UNLOCK();
      } while (iVar5 == 1);
      if (piVar2[3] == iVar1) {
        piVar3 = (int *)piVar2[0xc];
        if (piVar3 != (int *)0x0) {
          do {
            do {
            } while (*piVar3 != 0);
            LOCK();
            iVar5 = *piVar3;
            *piVar3 = 1;
            UNLOCK();
          } while (iVar5 == 1);
          if (piVar3[2] < 0) {
            LOCK();
            *piVar3 = 0;
            UNLOCK();
            piVar2[1] = piVar2[1] + -1;
            LOCK();
            *piVar2 = 0;
            UNLOCK();
            goto LAB_00158d01;
          }
          uStack_48 = 0x158d13;
          piStack_44 = piVar3;
          _ipc_pset_remove();
          LOCK();
          *piVar3 = 0;
          UNLOCK();
          if (piVar3[1] == 0) {
            piStack_44 = (int *)(&_ipc_object_zones)[*(ushort *)((int)piVar3 + 10) & 0x7fff];
            uStack_48 = 0x158d38;
            _zfree();
          }
        }
        piVar3 = piVar2 + 0x10;
        do {
          do {
          } while (*piVar3 != 0);
          LOCK();
          iVar5 = *piVar3;
          *piVar3 = 1;
          UNLOCK();
        } while (iVar5 == 1);
        LOCK();
        *piVar2 = 0;
        UNLOCK();
        piStack_44 = &local_8;
        uStack_48 = 0;
        puStack_4c = (undefined4 *)0x0;
        iStack_50 = param_5;
        uStack_54 = 0xffffffff;
        if ((param_2 & 0x1000) != 0) {
          uStack_54 = param_3;
        }
        iVar5 = _ipc_mqueue_receive(piVar3,param_2 & 0x100);
        piStack_44 = (int *)0x158d94;
        _ipc_object_release();
        if (iVar5 != 0) {
          if (iVar5 == 0x10004005) {
            while ((*(byte *)(_active_threads + 0x17c) & 3) != 0) {
              piStack_44 = (int *)0x158db7;
              _thread_halt_self_with_continuation();
            }
            *(uint *)(param_1 + 4) = param_3;
            if ((param_2 & 0x400) == 0) {
              puVar4 = *(undefined4 **)(*(int *)(_active_threads + 0xc) + 0x88);
              iVar1 = *(int *)(param_1 + 0xc);
              do {
                piStack_44 = local_10;
                iStack_50 = 0x158e19;
                puStack_4c = puVar4;
                uStack_48 = iVar1;
                iVar5 = _ipc_mqueue_copyin();
                puVar7 = (uint *)&stack0xffffffc4;
                if (iVar5 != 0) goto LAB_00158eff;
                piStack_44 = local_18;
                uStack_48 = 0;
                puStack_4c = (undefined4 *)0x0;
                iStack_50 = param_5;
                uStack_54 = 0xffffffff;
                if ((param_2 & 0x1000) != 0) {
                  uStack_54 = param_3;
                }
                iVar5 = _ipc_mqueue_receive(local_10[0],param_2 & 0x100);
                piStack_44 = (undefined4 *)0x158e64;
                _ipc_object_release();
                if (iVar5 != 0x10004005) break;
                while ((*(byte *)(_active_threads + 0x17c) & 3) != 0) {
                  piStack_44 = (undefined4 *)0x158e7b;
                  _thread_halt_self_with_continuation();
                }
              } while ((param_2 & 0x400) == 0);
              if (iVar5 == 0) {
                if (param_3 < *(uint *)(local_18[0] + 0x18)) {
                  piStack_44 = (int *)0x158ec6;
                  _ipc_kmsg_destroy();
                  piStack_44 = (int *)0x10004004;
                  uStack_48 = 0x158ed0;
                  uVar6 = _msg_return_translate();
                  return uVar6;
                }
                uStack_48 = local_18[0];
                puStack_4c = (undefined4 *)0x158ee6;
                piStack_44 = puVar4;
                iVar5 = _ipc_kmsg_copyout_compat();
                puStack_4c = (undefined4 *)
                             (*(int *)(local_18[0] + 0x18) + *(int *)(local_18[0] + 0x10));
                *(undefined4 **)(local_18[0] + 0x18) = puStack_4c;
                iStack_50 = local_18[0];
                puVar7 = &uStack_54;
                uStack_54 = param_1;
                _ipc_kmsg_put_to_kernel();
              }
              else {
                puVar7 = (uint *)&stack0xffffffc4;
                if (iVar5 == 0x10004004) {
                  *(int *)(param_1 + 4) = local_18[0];
                  puVar7 = (uint *)&stack0xffffffc4;
                }
              }
LAB_00158eff:
              *(int *)((int)puVar7 + -4) = iVar5;
              *(undefined4 *)((int)puVar7 + -8) = 0x158f05;
              uVar6 = _msg_return_translate();
              return uVar6;
            }
          }
          else if (iVar5 == 0x10004004) {
            *(int *)(param_1 + 4) = local_8;
          }
          piStack_44 = (int *)0x158f23;
          uVar6 = _msg_return_translate();
          return uVar6;
        }
        if (param_3 < *(uint *)(local_8 + 0x18)) {
          piStack_44 = (int *)0x158f39;
          _ipc_kmsg_destroy();
          piStack_44 = (int *)0x10004004;
          uStack_48 = 0x158f43;
          uVar6 = _msg_return_translate();
          return uVar6;
        }
        goto LAB_00158f48;
      }
      iVar1 = piVar2[1];
      piVar2[1] = iVar1 + -1;
      LOCK();
      *piVar2 = 0;
      UNLOCK();
      if (iVar1 == 1) {
        piStack_44 = (int *)(&_ipc_object_zones)[*(ushort *)((int)piVar2 + 10) & 0x7fff];
        uStack_48 = 0x158cd1;
        _zfree();
      }
    }
LAB_00158d01:
    uVar6 = 0xffffff36;
  }
  else {
    piVar3 = *(int **)(local_8 + 0x1c);
    piStack_44 = (int *)0x158acc;
    _ipc_object_reference();
    do {
      do {
      } while (*piVar3 != 0);
      LOCK();
      iVar5 = *piVar3;
      *piVar3 = 1;
      UNLOCK();
    } while (iVar5 == 1);
    if (piVar3[3] != _ipc_space_kernel) {
      LOCK();
      *piVar3 = 0;
      UNLOCK();
      goto LAB_00158bbc;
    }
    LOCK();
    *piVar3 = 0;
    UNLOCK();
    piStack_44 = (int *)0x158aff;
    local_8 = _ipc_kobject_server();
    if (local_8 == 0) goto LAB_00158c80;
    do {
      do {
      } while (*piVar2 != 0);
      LOCK();
      iVar5 = *piVar2;
      *piVar2 = 1;
      UNLOCK();
    } while (iVar5 == 1);
    if ((((-1 < piVar2[2]) || (piVar2[3] != iVar1)) || (piVar2[0xc] != 0)) ||
       (param_3 < (uint)(*(int *)(local_8 + 0x18) + *(int *)(local_8 + 0x10)))) {
      LOCK();
      *piVar2 = 0;
      UNLOCK();
LAB_00158b95:
      piStack_44 = (int *)0x0;
      uStack_48 = 0x10000;
      iStack_50 = 0x158b9a;
      puStack_4c = (undefined4 *)local_8;
      _ipc_mqueue_send();
      goto LAB_00158c80;
    }
    piVar3 = piVar2 + 0x10;
    do {
      do {
      } while (*piVar3 != 0);
      LOCK();
      iVar5 = *piVar3;
      *piVar3 = 1;
      UNLOCK();
    } while (iVar5 == 1);
    if ((piVar2[0x12] != 0) || (piVar2[0x11] != 0)) {
      LOCK();
      *piVar3 = 0;
      UNLOCK();
      LOCK();
      *piVar2 = 0;
      UNLOCK();
      goto LAB_00158b95;
    }
    piVar2[0xd] = piVar2[0xd] + 1;
    LOCK();
    *piVar3 = 0;
    UNLOCK();
    piVar2[1] = piVar2[1] + -1;
    LOCK();
    *piVar2 = 0;
    UNLOCK();
LAB_00158f48:
    uStack_48 = local_8;
    puStack_4c = (undefined4 *)0x158f59;
    piStack_44 = (int *)iVar1;
    uVar6 = _ipc_kmsg_copyout_compat();
    puStack_4c = (undefined4 *)(*(int *)(local_8 + 0x18) + *(int *)(local_8 + 0x10));
    *(undefined4 **)(local_8 + 0x18) = puStack_4c;
    iStack_50 = local_8;
    uStack_54 = param_1;
    _ipc_kmsg_put_to_kernel();
    uVar6 = _msg_return_translate(uVar6);
  }
  return uVar6;
}


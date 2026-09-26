/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014e844 */

undefined4
_ipc_right_delta(int param_1,undefined4 param_2,uint *param_3,undefined4 param_4,int param_5)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int local_18;
  int local_14;
  int local_10;
  uint local_8;
  
  local_8 = *param_3;
  switch(param_4) {
  case 0:
    local_10 = 0;
    local_14 = 0;
    local_18 = 0;
    if ((local_8 & 0x10000) == 0) goto LAB_0014ef58;
    uVar5 = local_8 & 0xffff;
    if ((param_5 < 0) && (uVar5 <= (uint)-param_5 && -uVar5 != param_5)) goto LAB_0014ef68;
    if ((0 < param_5) && ((uVar1 = uVar5 + 1 + param_5, uVar1 <= uVar5 + 1 || (0xffff < uVar1))))
    goto LAB_0014ef78;
    piVar3 = (int *)param_3[1];
    do {
      do {
      } while (*piVar3 != 0);
      LOCK();
      iVar4 = *piVar3;
      *piVar3 = 1;
      UNLOCK();
    } while (iVar4 == 1);
    if (piVar3[2] < 0) {
      if (uVar5 + param_5 == 0) {
        iVar4 = piVar3[7];
        piVar3[7] = iVar4 + -1;
        if ((iVar4 == 1) && (local_14 = piVar3[9], local_14 != 0)) {
          piVar3[9] = 0;
          local_18 = piVar3[6];
        }
        if ((local_8 & 0x20000) == 0) {
          if (param_3[2] == 0) {
            local_10 = 0;
          }
          else {
            local_10 = _ipc_port_dncancel(piVar3,param_2,param_3[2]);
            param_3[2] = 0;
            if ((*param_3 & 0x400000) != 0) {
              _ipc_space_release(param_1);
              local_10 = 0;
            }
          }
          _ipc_hash_delete(param_1,piVar3,param_2,param_3);
          if ((local_8 & 0x200000) != 0) {
            _ipc_marequest_cancel(param_1,param_2);
          }
          piVar3[1] = piVar3[1] + -1;
          param_3[1] = 0;
          _ipc_entry_dealloc(param_1,param_2,param_3);
          goto LAB_0014ef08;
        }
        local_8 = local_8 & 0xfffe0000;
      }
      else {
        local_8 = local_8 + param_5;
      }
      *param_3 = local_8;
LAB_0014ef08:
      LOCK();
      *piVar3 = 0;
      UNLOCK();
      LOCK();
      *(undefined4 *)(param_1 + 8) = 0;
      UNLOCK();
      if (local_14 != 0) {
        _ipc_notify_no_senders(local_14,local_18);
      }
      if (local_10 == 0) {
        return 0;
      }
      _ipc_notify_port_deleted(local_10,param_2);
      return 0;
    }
    LOCK();
    *piVar3 = 0;
    UNLOCK();
    uVar5 = *param_3;
    if ((uVar5 & 0x10000) != 0) {
      if ((uVar5 & 0x200000) != 0) {
        uVar5 = uVar5 & 0xffdfffff;
        _ipc_marequest_cancel(param_1,param_2);
      }
      _ipc_hash_delete(param_1,piVar3,param_2,param_3);
    }
    _ipc_object_release(piVar3);
    if ((uVar5 & 0x400000) == 0) {
      uVar5 = uVar5 & 0xffe0ffff | 0x100000;
      if (param_3[2] != 0) {
        param_3[2] = 0;
        uVar5 = uVar5 + 1;
      }
      *param_3 = uVar5;
      param_3[1] = 0;
    }
    else {
      param_3[2] = 0;
      param_3[1] = 0;
      _ipc_entry_dealloc(param_1,param_2,param_3);
    }
    break;
  case 1:
    iVar4 = 0;
    if ((local_8 & 0x20000) == 0) goto LAB_0014ef58;
    if (param_5 == 0) {
LAB_0014ef4c:
      LOCK();
      *(undefined4 *)(param_1 + 8) = 0;
      UNLOCK();
      return 0;
    }
    if (param_5 != -1) goto LAB_0014ef68;
    if ((local_8 & 0x200000) != 0) {
      local_8 = local_8 & 0xffdfffff;
      _ipc_marequest_cancel(param_1,param_2);
    }
    piVar3 = (int *)param_3[1];
    do {
      do {
      } while (*piVar3 != 0);
      LOCK();
      iVar2 = *piVar3;
      *piVar3 = 1;
      UNLOCK();
    } while (iVar2 == 1);
    if ((local_8 & 0x400000) == 0) {
      if ((local_8 & 0x10000) != 0) {
        local_8 = local_8 & 0xffe0ffff | 0x100000;
        if (param_3[2] != 0) {
          param_3[2] = 0;
          local_8 = local_8 + 1;
        }
        *param_3 = local_8;
        param_3[1] = 0;
        goto LAB_0014e9e2;
      }
      uVar5 = param_3[2];
      if (uVar5 != 0) goto LAB_0014e99c;
      iVar4 = 0;
    }
    else {
      uVar5 = param_3[2];
LAB_0014e99c:
      iVar4 = _ipc_port_dncancel(piVar3,param_2,uVar5);
      param_3[2] = 0;
      if ((*param_3 & 0x400000) != 0) {
        _ipc_space_release(param_1);
        iVar4 = 0;
      }
    }
    param_3[1] = 0;
    _ipc_entry_dealloc(param_1,param_2,param_3);
LAB_0014e9e2:
    LOCK();
    *(undefined4 *)(param_1 + 8) = 0;
    UNLOCK();
    _ipc_port_clear_receiver(piVar3);
    _ipc_port_destroy(piVar3);
    if (iVar4 == 0) {
      return 0;
    }
    _ipc_notify_port_deleted(iVar4,param_2);
    return 0;
  case 2:
    if ((local_8 & 0x40000) == 0) goto LAB_0014ef58;
    if (1 < param_5 + 1U) goto LAB_0014ef68;
    piVar3 = (int *)param_3[1];
    do {
      do {
      } while (*piVar3 != 0);
      LOCK();
      iVar4 = *piVar3;
      *piVar3 = 1;
      UNLOCK();
    } while (iVar4 == 1);
    if (piVar3[2] < 0) {
      if (param_5 != 0) {
        if (param_3[2] == 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = _ipc_port_dncancel(piVar3,param_2,param_3[2]);
          param_3[2] = 0;
          if ((*param_3 & 0x400000) != 0) {
            _ipc_space_release(param_1);
            iVar4 = 0;
          }
        }
        LOCK();
        *piVar3 = 0;
        UNLOCK();
        param_3[1] = 0;
        _ipc_entry_dealloc(param_1,param_2,param_3);
        LOCK();
        *(undefined4 *)(param_1 + 8) = 0;
        UNLOCK();
        _ipc_notify_send_once(piVar3);
        if (iVar4 == 0) {
          return 0;
        }
        _ipc_notify_port_deleted(iVar4,param_2);
        return 0;
      }
      LOCK();
      *piVar3 = 0;
      UNLOCK();
      goto LAB_0014ef4c;
    }
    LOCK();
    *piVar3 = 0;
    UNLOCK();
    uVar5 = *param_3;
    if ((uVar5 & 0x10000) != 0) {
      if ((uVar5 & 0x200000) != 0) {
        uVar5 = uVar5 & 0xffdfffff;
        _ipc_marequest_cancel(param_1,param_2);
      }
      _ipc_hash_delete(param_1,piVar3,param_2,param_3);
    }
    _ipc_object_release(piVar3);
    if ((uVar5 & 0x400000) == 0) {
      uVar5 = uVar5 & 0xffe0ffff | 0x100000;
      if (param_3[2] != 0) {
        param_3[2] = 0;
        uVar5 = uVar5 + 1;
      }
      *param_3 = uVar5;
      param_3[1] = 0;
    }
    else {
      param_3[2] = 0;
      param_3[1] = 0;
      _ipc_entry_dealloc(param_1,param_2,param_3);
    }
    break;
  case 3:
    if ((local_8 & 0x80000) == 0) goto LAB_0014ef58;
    if (param_5 == 0) goto LAB_0014ef4c;
    if (param_5 == -1) {
      piVar3 = (int *)param_3[1];
      param_3[1] = 0;
      _ipc_entry_dealloc(param_1,param_2,param_3);
      do {
        do {
        } while (*piVar3 != 0);
        LOCK();
        iVar4 = *piVar3;
        *piVar3 = 1;
        UNLOCK();
      } while (iVar4 == 1);
      LOCK();
      *(undefined4 *)(param_1 + 8) = 0;
      UNLOCK();
      _ipc_pset_destroy(piVar3);
      return 0;
    }
    goto LAB_0014ef68;
  case 4:
    if ((local_8 & 0x50000) == 0) {
      if ((local_8 & 0x100000) == 0) goto LAB_0014ef58;
    }
    else {
      piVar3 = (int *)param_3[1];
      do {
        do {
        } while (*piVar3 != 0);
        LOCK();
        iVar4 = *piVar3;
        *piVar3 = 1;
        UNLOCK();
      } while (iVar4 == 1);
      if (piVar3[2] < 0) {
        LOCK();
        *piVar3 = 0;
        UNLOCK();
        goto LAB_0014ef58;
      }
      LOCK();
      *piVar3 = 0;
      UNLOCK();
      uVar5 = *param_3;
      if ((uVar5 & 0x10000) != 0) {
        if ((uVar5 & 0x200000) != 0) {
          uVar5 = uVar5 & 0xffdfffff;
          _ipc_marequest_cancel(param_1,param_2);
        }
        _ipc_hash_delete(param_1,piVar3,param_2,param_3);
      }
      _ipc_object_release(piVar3);
      if ((uVar5 & 0x400000) == 0) {
        uVar5 = uVar5 & 0xffe0ffff | 0x100000;
        if (param_3[2] != 0) {
          param_3[2] = 0;
          uVar5 = uVar5 + 1;
        }
        *param_3 = uVar5;
        param_3[1] = 0;
      }
      else {
        param_3[2] = 0;
        param_3[1] = 0;
        _ipc_entry_dealloc(param_1,param_2,param_3);
      }
      if ((local_8 & 0x400000) != 0) goto LAB_0014ef88;
      local_8 = *param_3;
    }
    uVar5 = local_8 & 0xffff;
    if ((-1 < param_5) || ((uint)-param_5 < uVar5 || -uVar5 == param_5)) {
      if ((param_5 < 1) || ((uVar5 < param_5 + uVar5 && (param_5 + uVar5 < 0x10000)))) {
        if (param_5 + uVar5 == 0) {
          _ipc_entry_dealloc(param_1,param_2,param_3);
        }
        else {
          *param_3 = local_8 + param_5;
        }
        LOCK();
        *(undefined4 *)(param_1 + 8) = 0;
        UNLOCK();
        return 0;
      }
LAB_0014ef78:
      LOCK();
      *(undefined4 *)(param_1 + 8) = 0;
      UNLOCK();
      return 0x13;
    }
LAB_0014ef68:
    LOCK();
    *(undefined4 *)(param_1 + 8) = 0;
    UNLOCK();
    return 0x12;
  default:
                    /* WARNING: Subroutine does not return */
    _panic(s_ipc_right_delta__strange_right_001de998);
  }
  if ((local_8 & 0x400000) != 0) {
LAB_0014ef88:
    LOCK();
    *(undefined4 *)(param_1 + 8) = 0;
    UNLOCK();
    return 0xf;
  }
LAB_0014ef58:
  LOCK();
  *(undefined4 *)(param_1 + 8) = 0;
  UNLOCK();
  return 0x11;
}


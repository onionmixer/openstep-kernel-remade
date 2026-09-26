/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014e3f4 */

undefined4 _ipc_right_dealloc(int param_1,undefined4 param_2,uint *param_3)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_8 = *param_3;
  uVar3 = local_8 & 0x1f0000;
  if (uVar3 == 0x30000) {
    iVar4 = 0;
    iVar5 = 0;
    piVar2 = (int *)param_3[1];
    do {
      do {
      } while (*piVar2 != 0);
      LOCK();
      iVar1 = *piVar2;
      *piVar2 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    if ((short)local_8 == 1) {
      iVar1 = piVar2[7];
      piVar2[7] = iVar1 + -1;
      if ((iVar1 == 1) && (iVar4 = piVar2[9], iVar4 != 0)) {
        piVar2[9] = 0;
        iVar5 = piVar2[6];
      }
      local_8 = local_8 & 0xfffe0000;
    }
    else {
      local_8 = local_8 - 1;
    }
    *param_3 = local_8;
    LOCK();
    *piVar2 = 0;
    UNLOCK();
    LOCK();
    *(undefined4 *)(param_1 + 8) = 0;
    UNLOCK();
    if (iVar4 == 0) {
      return 0;
    }
    _ipc_notify_no_senders(iVar4,iVar5);
    return 0;
  }
  if (uVar3 < 0x30001) {
    if (uVar3 != 0x10000) {
LAB_0014e818:
      LOCK();
      *(undefined4 *)(param_1 + 8) = 0;
      UNLOCK();
      return 0x11;
    }
    local_c = 0;
    local_10 = 0;
    local_14 = 0;
    piVar2 = (int *)param_3[1];
    do {
      do {
      } while (*piVar2 != 0);
      LOCK();
      iVar4 = *piVar2;
      *piVar2 = 1;
      UNLOCK();
    } while (iVar4 == 1);
    if (piVar2[2] < 0) {
      if ((short)local_8 == 1) {
        iVar4 = piVar2[7];
        piVar2[7] = iVar4 + -1;
        if ((iVar4 == 1) && (local_10 = piVar2[9], local_10 != 0)) {
          piVar2[9] = 0;
          local_14 = piVar2[6];
        }
        if (param_3[2] == 0) {
          local_c = 0;
        }
        else {
          local_c = _ipc_port_dncancel(piVar2,param_2,param_3[2]);
          param_3[2] = 0;
          if ((*param_3 & 0x400000) != 0) {
            _ipc_space_release(param_1);
            local_c = 0;
          }
        }
        _ipc_hash_delete(param_1,piVar2,param_2,param_3);
        if ((local_8 & 0x200000) != 0) {
          _ipc_marequest_cancel(param_1,param_2);
        }
        piVar2[1] = piVar2[1] + -1;
        param_3[1] = 0;
        _ipc_entry_dealloc(param_1,param_2,param_3);
      }
      else {
        *param_3 = local_8 - 1;
      }
      LOCK();
      *piVar2 = 0;
      UNLOCK();
      LOCK();
      *(undefined4 *)(param_1 + 8) = 0;
      UNLOCK();
      if (local_10 != 0) {
        _ipc_notify_no_senders(local_10,local_14);
      }
      if (local_c == 0) {
        return 0;
      }
      _ipc_notify_port_deleted(local_c,param_2);
      return 0;
    }
    LOCK();
    *piVar2 = 0;
    UNLOCK();
    uVar3 = *param_3;
    if ((uVar3 & 0x10000) != 0) {
      if ((uVar3 & 0x200000) != 0) {
        uVar3 = uVar3 & 0xffdfffff;
        _ipc_marequest_cancel(param_1,param_2);
      }
      _ipc_hash_delete(param_1,piVar2,param_2,param_3);
    }
    _ipc_object_release(piVar2);
    if ((uVar3 & 0x400000) == 0) {
      uVar3 = uVar3 & 0xffe0ffff | 0x100000;
      if (param_3[2] != 0) {
        param_3[2] = 0;
        uVar3 = uVar3 + 1;
      }
      *param_3 = uVar3;
      param_3[1] = 0;
    }
    else {
      param_3[2] = 0;
      param_3[1] = 0;
      _ipc_entry_dealloc(param_1,param_2,param_3);
    }
  }
  else {
    if (uVar3 != 0x40000) {
      if (uVar3 != 0x100000) goto LAB_0014e818;
      goto LAB_0014e43e;
    }
    piVar2 = (int *)param_3[1];
    do {
      do {
      } while (*piVar2 != 0);
      LOCK();
      iVar4 = *piVar2;
      *piVar2 = 1;
      UNLOCK();
    } while (iVar4 == 1);
    if (piVar2[2] < 0) {
      if (param_3[2] == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = _ipc_port_dncancel(piVar2,param_2,param_3[2]);
        param_3[2] = 0;
        if ((*param_3 & 0x400000) != 0) {
          _ipc_space_release(param_1);
          iVar4 = 0;
        }
      }
      LOCK();
      *piVar2 = 0;
      UNLOCK();
      param_3[1] = 0;
      _ipc_entry_dealloc(param_1,param_2,param_3);
      LOCK();
      *(undefined4 *)(param_1 + 8) = 0;
      UNLOCK();
      _ipc_notify_send_once(piVar2);
      if (iVar4 == 0) {
        return 0;
      }
      _ipc_notify_port_deleted(iVar4,param_2);
      return 0;
    }
    LOCK();
    *piVar2 = 0;
    UNLOCK();
    uVar3 = *param_3;
    if ((uVar3 & 0x10000) != 0) {
      if ((uVar3 & 0x200000) != 0) {
        uVar3 = uVar3 & 0xffdfffff;
        _ipc_marequest_cancel(param_1,param_2);
      }
      _ipc_hash_delete(param_1,piVar2,param_2,param_3);
    }
    _ipc_object_release(piVar2);
    if ((uVar3 & 0x400000) == 0) {
      uVar3 = uVar3 & 0xffe0ffff | 0x100000;
      if (param_3[2] != 0) {
        param_3[2] = 0;
        uVar3 = uVar3 + 1;
      }
      *param_3 = uVar3;
      param_3[1] = 0;
    }
    else {
      param_3[2] = 0;
      param_3[1] = 0;
      _ipc_entry_dealloc(param_1,param_2,param_3);
    }
  }
  if ((local_8 & 0x400000) != 0) {
    LOCK();
    *(undefined4 *)(param_1 + 8) = 0;
    UNLOCK();
    return 0xf;
  }
  local_8 = *param_3;
LAB_0014e43e:
  if ((short)local_8 == 1) {
    _ipc_entry_dealloc(param_1,param_2,param_3);
  }
  else {
    *param_3 = local_8 - 1;
  }
  LOCK();
  *(undefined4 *)(param_1 + 8) = 0;
  UNLOCK();
  return 0;
}


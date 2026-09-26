/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014fecc */

undefined4
_ipc_right_copyin_compat
          (int param_1,undefined4 param_2,uint *param_3,int param_4,int param_5,undefined4 *param_6)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int local_10;
  int local_c;
  uint local_8;
  
  local_8 = *param_3;
  if (param_4 == 5) {
    if (param_5 != 0) {
      local_c = 0;
      local_10 = 0;
      if ((local_8 & 0x20000) == 0) goto LAB_0015033c;
      piVar4 = (int *)param_3[1];
      do {
        do {
        } while (*piVar4 != 0);
        LOCK();
        iVar2 = *piVar4;
        *piVar4 = 1;
        UNLOCK();
      } while (iVar2 == 1);
      if (param_3[2] == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = _ipc_port_dncancel(piVar4,param_2,param_3[2]);
        param_3[2] = 0;
        if ((*param_3 & 0x400000) != 0) {
          _ipc_space_release(param_1);
          iVar2 = 0;
        }
      }
      if ((local_8 & 0x200000) != 0) {
        _ipc_marequest_cancel(param_1,param_2);
      }
      param_3[1] = 0;
      _ipc_entry_dealloc(param_1,param_2,param_3);
      LOCK();
      *(undefined4 *)(param_1 + 8) = 0;
      UNLOCK();
      if ((((local_8 & 0x10000) != 0) && (iVar1 = piVar4[7], piVar4[7] = iVar1 + -1, iVar1 == 1)) &&
         (local_c = piVar4[9], local_c != 0)) {
        piVar4[9] = 0;
        local_10 = piVar4[6];
      }
      _ipc_port_clear_receiver(piVar4);
      piVar4[4] = 0;
      piVar4[3] = 0;
      LOCK();
      *piVar4 = 0;
      UNLOCK();
      if (local_c != 0) {
        _ipc_notify_no_senders(local_c,local_10);
      }
      if (iVar2 != 0) {
        _ipc_notify_port_deleted(iVar2,param_2);
      }
      goto LAB_00150323;
    }
    if ((local_8 & 0x20000) == 0) goto LAB_0015033c;
    piVar4 = (int *)param_3[1];
    do {
      do {
      } while (*piVar4 != 0);
      LOCK();
      iVar2 = *piVar4;
      *piVar4 = 1;
      UNLOCK();
    } while (iVar2 == 1);
    if ((local_8 & 0x10000) == 0) {
      piVar4[7] = piVar4[7] + 1;
      local_8 = local_8 | 0x10001;
    }
    _ipc_hash_insert(param_1,piVar4,param_2,param_3);
    *param_3 = local_8 & 0xfffdffff;
    LOCK();
    *(undefined4 *)(param_1 + 8) = 0;
    UNLOCK();
    _ipc_port_clear_receiver(piVar4);
    piVar4[4] = 0;
    piVar4[3] = 0;
LAB_0015031c:
    piVar4[1] = piVar4[1] + 1;
    LOCK();
    *piVar4 = 0;
    UNLOCK();
LAB_00150323:
    *param_6 = piVar4;
    return 0;
  }
  if (param_4 != 6) {
                    /* WARNING: Subroutine does not return */
    _panic(s_ipc_right_copyin_compat__strange_001dea42);
  }
  if (param_5 == 0) {
    if ((local_8 & 0x30000) == 0) goto LAB_0015033c;
    piVar4 = (int *)param_3[1];
    do {
      do {
      } while (*piVar4 != 0);
      LOCK();
      iVar2 = *piVar4;
      *piVar4 = 1;
      UNLOCK();
    } while (iVar2 == 1);
    if (piVar4[2] < 0) {
      LOCK();
      *(undefined4 *)(param_1 + 8) = 0;
      UNLOCK();
      if ((local_8 & 0x10000) == 0) {
        piVar4[6] = piVar4[6] + 1;
      }
      piVar4[7] = piVar4[7] + 1;
      goto LAB_0015031c;
    }
    LOCK();
    *piVar4 = 0;
    UNLOCK();
    uVar3 = *param_3;
    if ((uVar3 & 0x10000) != 0) {
      if ((uVar3 & 0x200000) != 0) {
        uVar3 = uVar3 & 0xffdfffff;
        _ipc_marequest_cancel(param_1,param_2);
      }
      _ipc_hash_delete(param_1,piVar4,param_2,param_3);
    }
    _ipc_object_release(piVar4);
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
    if ((local_8 & 0x1f0000) != 0x10000) goto LAB_0015033c;
    piVar4 = (int *)param_3[1];
    do {
      do {
      } while (*piVar4 != 0);
      LOCK();
      iVar2 = *piVar4;
      *piVar4 = 1;
      UNLOCK();
    } while (iVar2 == 1);
    if (piVar4[2] < 0) {
      if (param_3[2] == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = _ipc_port_dncancel(piVar4,param_2,param_3[2]);
        param_3[2] = 0;
        if ((*param_3 & 0x400000) != 0) {
          _ipc_space_release(param_1);
          iVar2 = 0;
        }
      }
      LOCK();
      *piVar4 = 0;
      UNLOCK();
      if ((local_8 & 0x200000) != 0) {
        _ipc_marequest_cancel(param_1,param_2);
      }
      _ipc_hash_delete(param_1,piVar4,param_2,param_3);
      param_3[1] = 0;
      _ipc_entry_dealloc(param_1,param_2,param_3);
      LOCK();
      *(undefined4 *)(param_1 + 8) = 0;
      UNLOCK();
      if (iVar2 != 0) {
        _ipc_notify_port_deleted(iVar2,param_2);
      }
      *param_6 = piVar4;
      return 0;
    }
    LOCK();
    *piVar4 = 0;
    UNLOCK();
    uVar3 = *param_3;
    if ((uVar3 & 0x10000) != 0) {
      if ((uVar3 & 0x200000) != 0) {
        uVar3 = uVar3 & 0xffdfffff;
        _ipc_marequest_cancel(param_1,param_2);
      }
      _ipc_hash_delete(param_1,piVar4,param_2,param_3);
    }
    _ipc_object_release(piVar4);
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
LAB_0015033c:
  LOCK();
  *(undefined4 *)(param_1 + 8) = 0;
  UNLOCK();
  return 0x11;
}


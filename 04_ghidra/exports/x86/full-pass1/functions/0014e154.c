/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014e154 */

undefined4 _ipc_right_destroy(int param_1,undefined4 param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  int local_14;
  int local_10;
  int local_c;
  
  uVar2 = *param_3;
  uVar4 = uVar2 & 0x1f0000;
  if (uVar4 == 0x30000) {
LAB_0014e21c:
    piVar3 = (int *)param_3[1];
    local_c = 0;
    local_10 = 0;
    if ((uVar2 & 0x200000) != 0) {
      _ipc_marequest_cancel(param_1,param_2);
    }
    if (uVar4 == 0x10000) {
      _ipc_hash_delete(param_1,piVar3,param_2,param_3);
    }
    do {
      do {
      } while (*piVar3 != 0);
      LOCK();
      iVar1 = *piVar3;
      *piVar3 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    if (piVar3[2] < 0) {
      if (param_3[2] == 0) {
        local_14 = 0;
      }
      else {
        local_14 = _ipc_port_dncancel(piVar3,param_2,param_3[2]);
        param_3[2] = 0;
        if ((*param_3 & 0x400000) != 0) {
          _ipc_space_release(param_1);
          local_14 = 0;
        }
      }
      param_3[1] = 0;
      _ipc_entry_dealloc(param_1,param_2,param_3);
      LOCK();
      *(undefined4 *)(param_1 + 8) = 0;
      UNLOCK();
      if ((((uVar2 & 0x10000) != 0) && (iVar1 = piVar3[7], piVar3[7] = iVar1 + -1, iVar1 == 1)) &&
         (local_c = piVar3[9], local_c != 0)) {
        piVar3[9] = 0;
        local_10 = piVar3[6];
      }
      if ((uVar2 & 0x20000) == 0) {
        if ((uVar2 & 0x40000) == 0) {
          piVar3[1] = piVar3[1] + -1;
          LOCK();
          *piVar3 = 0;
          UNLOCK();
        }
        else {
          LOCK();
          *piVar3 = 0;
          UNLOCK();
          _ipc_notify_send_once(piVar3);
        }
      }
      else {
        _ipc_port_clear_receiver(piVar3);
        _ipc_port_destroy(piVar3);
      }
      if (local_c != 0) {
        _ipc_notify_no_senders(local_c,local_10);
      }
      if (local_14 != 0) {
        _ipc_notify_port_deleted(local_14,param_2);
      }
    }
    else {
      iVar1 = piVar3[1];
      piVar3[1] = iVar1 + -1;
      LOCK();
      *piVar3 = 0;
      UNLOCK();
      if (iVar1 == 1) {
        _zfree((&_ipc_object_zones)[*(ushort *)((int)piVar3 + 10) & 0x7fff],piVar3);
      }
      param_3[2] = 0;
      param_3[1] = 0;
      _ipc_entry_dealloc(param_1,param_2,param_3);
      LOCK();
      *(undefined4 *)(param_1 + 8) = 0;
      UNLOCK();
      if ((uVar2 & 0x400000) != 0) {
        return 0xf;
      }
    }
    return 0;
  }
  if (uVar4 < 0x30001) {
    if ((uVar4 == 0x10000) || (uVar4 == 0x20000)) goto LAB_0014e21c;
  }
  else {
    if (uVar4 == 0x80000) {
      piVar3 = (int *)param_3[1];
      param_3[1] = 0;
      _ipc_entry_dealloc(param_1,param_2,param_3);
      do {
        do {
        } while (*piVar3 != 0);
        LOCK();
        iVar1 = *piVar3;
        *piVar3 = 1;
        UNLOCK();
      } while (iVar1 == 1);
      LOCK();
      *(undefined4 *)(param_1 + 8) = 0;
      UNLOCK();
      _ipc_pset_destroy(piVar3);
      return 0;
    }
    if (uVar4 < 0x80001) {
      if (uVar4 == 0x40000) goto LAB_0014e21c;
    }
    else if (uVar4 == 0x100000) {
      _ipc_entry_dealloc(param_1,param_2,param_3);
      LOCK();
      *(undefined4 *)(param_1 + 8) = 0;
      UNLOCK();
      return 0;
    }
  }
                    /* WARNING: Subroutine does not return */
  _panic(s_ipc_right_destroy__strange_type_001de978);
}


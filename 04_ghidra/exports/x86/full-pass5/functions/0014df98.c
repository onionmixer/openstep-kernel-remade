/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014df98 */

int __regparm1 _ipc_right_clean(int param_1,undefined4 param_2,undefined4 param_3,uint *param_4)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int local_c;
  int local_8;
  
  uVar1 = *param_4;
  uVar5 = uVar1 & 0x1f0000;
  if (uVar5 == 0x30000) {
LAB_0014e01c:
    piVar2 = (int *)param_4[1];
    local_8 = 0;
    local_c = 0;
    do {
      do {
      } while (*piVar2 != 0);
      LOCK();
      iVar4 = *piVar2;
      *piVar2 = 1;
      UNLOCK();
    } while (iVar4 == 1);
    if (piVar2[2] < 0) {
      if (param_4[2] == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = _ipc_port_dncancel(piVar2,param_3,param_4[2]);
        param_4[2] = 0;
        if ((*param_4 & 0x400000) != 0) {
          _ipc_space_release(param_2);
          iVar4 = 0;
        }
      }
      if ((((uVar1 & 0x10000) != 0) && (iVar3 = piVar2[7], piVar2[7] = iVar3 + -1, iVar3 == 1)) &&
         (local_8 = piVar2[9], local_8 != 0)) {
        piVar2[9] = 0;
        local_c = piVar2[6];
      }
      if ((uVar1 & 0x20000) == 0) {
        if ((uVar1 & 0x40000) == 0) {
          piVar2[1] = piVar2[1] + -1;
          LOCK();
          iVar3 = *piVar2;
          *piVar2 = 0;
          UNLOCK();
        }
        else {
          LOCK();
          *piVar2 = 0;
          UNLOCK();
          iVar3 = _ipc_notify_send_once(piVar2);
        }
      }
      else {
        _ipc_port_clear_receiver(piVar2);
        iVar3 = _ipc_port_destroy(piVar2);
      }
      if (local_8 != 0) {
        iVar3 = _ipc_notify_no_senders(local_8,local_c);
      }
      if (iVar4 != 0) {
        iVar3 = _ipc_notify_port_deleted(iVar4,param_3);
      }
    }
    else {
      iVar3 = piVar2[1];
      piVar2[1] = iVar3 + -1;
      iVar3 = iVar3 + -1;
      LOCK();
      *piVar2 = 0;
      UNLOCK();
      if (iVar3 == 0) {
        iVar3 = _zfree((&_ipc_object_zones)[*(ushort *)((int)piVar2 + 10) & 0x7fff],piVar2);
      }
    }
    return iVar3;
  }
  if (uVar5 < 0x30001) {
    if ((uVar5 == 0x10000) || (uVar5 == 0x20000)) goto LAB_0014e01c;
  }
  else {
    if (uVar5 == 0x80000) {
      piVar2 = (int *)param_4[1];
      do {
        do {
        } while (*piVar2 != 0);
        LOCK();
        iVar4 = *piVar2;
        *piVar2 = 1;
        UNLOCK();
      } while (iVar4 == 1);
      iVar4 = _ipc_pset_destroy(piVar2);
      return iVar4;
    }
    if (uVar5 < 0x80001) {
      if (uVar5 == 0x40000) goto LAB_0014e01c;
    }
    else if (uVar5 == 0x100000) {
      return param_1;
    }
  }
                    /* WARNING: Subroutine does not return */
  _panic(s_ipc_right_clean__strange_type_001de95a);
}


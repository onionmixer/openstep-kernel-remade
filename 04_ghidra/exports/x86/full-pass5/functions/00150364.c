/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00150364 */

undefined4
_ipc_right_copyin_header
          (int param_1,undefined4 param_2,uint *param_3,undefined4 *param_4,undefined4 *param_5)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  uVar1 = *param_3;
  uVar2 = uVar1 & 0x1f0000;
  if (uVar2 == 0x30000) {
LAB_001503f0:
    piVar5 = (int *)param_3[1];
    do {
      do {
      } while (*piVar5 != 0);
      LOCK();
      iVar3 = *piVar5;
      *piVar5 = 1;
      UNLOCK();
    } while (iVar3 == 1);
    if (piVar5[2] < 0) {
      LOCK();
      *(undefined4 *)(param_1 + 8) = 0;
      UNLOCK();
LAB_001504c3:
      piVar5[7] = piVar5[7] + 1;
      piVar5[1] = piVar5[1] + 1;
      LOCK();
      *piVar5 = 0;
      UNLOCK();
      *param_4 = piVar5;
      *param_5 = 0x11;
      return 0;
    }
    LOCK();
    *piVar5 = 0;
    UNLOCK();
    uVar2 = *param_3;
    if ((uVar2 & 0x10000) != 0) {
      if ((uVar2 & 0x200000) != 0) {
        uVar2 = uVar2 & 0xffdfffff;
        _ipc_marequest_cancel(param_1,param_2);
      }
      _ipc_hash_delete(param_1,piVar5,param_2,param_3);
    }
    _ipc_object_release(piVar5);
    if ((uVar2 & 0x400000) == 0) {
      uVar2 = uVar2 & 0xffe0ffff | 0x100000;
      if (param_3[2] != 0) {
        param_3[2] = 0;
        uVar2 = uVar2 + 1;
      }
      *param_3 = uVar2;
      param_3[1] = 0;
    }
    else {
      param_3[2] = 0;
      param_3[1] = 0;
      _ipc_entry_dealloc(param_1,param_2,param_3);
    }
  }
  else {
    if (uVar2 < 0x30001) {
      if (uVar2 != 0x10000) {
        if (uVar2 != 0x20000) goto LAB_00150678;
        piVar5 = (int *)param_3[1];
        do {
          do {
          } while (*piVar5 != 0);
          LOCK();
          iVar3 = *piVar5;
          *piVar5 = 1;
          UNLOCK();
        } while (iVar3 == 1);
        LOCK();
        *(undefined4 *)(param_1 + 8) = 0;
        UNLOCK();
        piVar5[6] = piVar5[6] + 1;
        goto LAB_001504c3;
      }
      goto LAB_001503f0;
    }
    if (uVar2 == 0x80000) goto LAB_00150688;
    if (0x80000 < uVar2) {
      if (uVar2 != 0x100000) goto LAB_00150678;
      goto LAB_00150688;
    }
    if (uVar2 != 0x40000) {
LAB_00150678:
                    /* WARNING: Subroutine does not return */
      _panic(s_ipc_right_copyin_header__strange_001dea6a);
    }
    piVar5 = (int *)param_3[1];
    do {
      do {
      } while (*piVar5 != 0);
      LOCK();
      iVar3 = *piVar5;
      *piVar5 = 1;
      UNLOCK();
    } while (iVar3 == 1);
    if (piVar5[2] < 0) {
      if (param_3[2] == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = _ipc_port_dncancel(piVar5,param_2,param_3[2]);
        param_3[2] = 0;
        if ((*param_3 & 0x400000) != 0) {
          _ipc_space_release(param_1);
          iVar3 = 0;
        }
      }
      LOCK();
      *piVar5 = 0;
      UNLOCK();
      param_3[1] = 0;
      _ipc_entry_dealloc(param_1,param_2,param_3);
      iVar4 = _ipc_port_copy_send(*(undefined4 *)(param_1 + 0x44));
      LOCK();
      *(undefined4 *)(param_1 + 8) = 0;
      UNLOCK();
      if (iVar3 != 0) {
        _ipc_notify_port_deleted(iVar3,param_2);
      }
      if ((iVar4 != 0) && (iVar4 != -1)) {
        _ipc_notify_port_deleted_compat(iVar4,param_2);
      }
      *param_4 = piVar5;
      *param_5 = 0x12;
      return 0;
    }
    LOCK();
    *piVar5 = 0;
    UNLOCK();
    uVar2 = *param_3;
    if ((uVar2 & 0x10000) != 0) {
      if ((uVar2 & 0x200000) != 0) {
        uVar2 = uVar2 & 0xffdfffff;
        _ipc_marequest_cancel(param_1,param_2);
      }
      _ipc_hash_delete(param_1,piVar5,param_2,param_3);
    }
    _ipc_object_release(piVar5);
    if ((uVar2 & 0x400000) == 0) {
      uVar2 = uVar2 & 0xffe0ffff | 0x100000;
      if (param_3[2] != 0) {
        param_3[2] = 0;
        uVar2 = uVar2 + 1;
      }
      *param_3 = uVar2;
      param_3[1] = 0;
    }
    else {
      param_3[2] = 0;
      param_3[1] = 0;
      _ipc_entry_dealloc(param_1,param_2,param_3);
    }
  }
  if ((uVar1 & 0x400000) != 0) {
    LOCK();
    *(undefined4 *)(param_1 + 8) = 0;
    UNLOCK();
    return 0xf;
  }
LAB_00150688:
  LOCK();
  *(undefined4 *)(param_1 + 8) = 0;
  UNLOCK();
  return 0x11;
}


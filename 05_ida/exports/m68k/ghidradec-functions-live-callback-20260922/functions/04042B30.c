
undefined4
_ipc_right_copyin_compat
          (undefined4 param_1,undefined4 param_2,uint *param_3,int param_4,int param_5,uint *param_6
          )

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  
  uVar4 = *param_3;
  if (param_4 == 5) {
    if (param_5 != 0) {
      iVar5 = 0;
      iVar3 = 0;
      iVar6 = 0;
      if ((uVar4 & 0x20000) == 0) {
        return 0x11;
      }
      piVar7 = (int *)param_3[1];
      if (param_3[2] != 0) {
        iVar5 = _ipc_right_dncancel(param_1,piVar7,param_2,param_3);
      }
      if ((uVar4 & 0x200000) != 0) {
        _ipc_marequest_cancel(param_1,param_2);
      }
      param_3[1] = 0;
      _ipc_entry_dealloc(param_1,param_2,param_3);
      if ((((uVar4 & 0x10000) != 0) && (iVar2 = piVar7[6], piVar7[6] = iVar2 + -1, iVar2 == 1)) &&
         (iVar3 = piVar7[8], iVar3 != 0)) {
        piVar7[8] = 0;
        iVar6 = piVar7[5];
      }
      _ipc_port_clear_receiver(piVar7);
      piVar7[3] = 0;
      piVar7[2] = 0;
      if (iVar3 != 0) {
        _ipc_notify_no_senders(iVar3,iVar6);
      }
      if (iVar5 != 0) {
        _ipc_notify_port_deleted(iVar5,param_2);
      }
      goto loc_4042D2C;
    }
    if ((uVar4 & 0x20000) == 0) {
      return 0x11;
    }
    piVar7 = (int *)param_3[1];
    if ((uVar4 & 0x10000) == 0) {
      piVar7[6] = piVar7[6] + 1;
      uVar4 = uVar4 | 0x10001;
    }
    _ipc_hash_insert(param_1,piVar7,param_2,param_3);
    *param_3 = uVar4 & 0xfffdffff;
    _ipc_port_clear_receiver(piVar7);
    piVar7[3] = 0;
    piVar7[2] = 0;
  }
  else {
    if (param_4 != 6) {
                    /* WARNING: Subroutine does not return */
      _panic(aIpcRightCopyin_1);
    }
    if (param_5 != 0) {
      if ((uVar4 & 0x1f0000) != 0x10000) {
        return 0x11;
      }
      uVar1 = param_3[1];
      iVar3 = _ipc_right_check(param_1,uVar1,param_2,param_3);
      if (iVar3 == 0) {
        if (param_3[2] == 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = _ipc_right_dncancel(param_1,uVar1,param_2,param_3);
        }
        if ((uVar4 & 0x200000) != 0) {
          _ipc_marequest_cancel(param_1,param_2);
        }
        _ipc_hash_delete(param_1,uVar1,param_2,param_3);
        param_3[1] = 0;
        _ipc_entry_dealloc(param_1,param_2,param_3);
        if (iVar3 != 0) {
          _ipc_notify_port_deleted(iVar3,param_2);
        }
        *param_6 = uVar1;
        return 0;
      }
loc_4042C1E:
      if ((uVar4 & 0x400000) == 0) {
        return 0x11;
      }
      return 0xf;
    }
    if ((uVar4 & 0x30000) == 0) {
      return 0x11;
    }
    piVar7 = (int *)param_3[1];
    iVar3 = _ipc_right_check(param_1,piVar7,param_2,param_3);
    if (iVar3 != 0) goto loc_4042C1E;
    if ((uVar4 & 0x10000) == 0) {
      piVar7[5] = piVar7[5] + 1;
    }
    piVar7[6] = piVar7[6] + 1;
  }
  *piVar7 = *piVar7 + 1;
loc_4042D2C:
  *param_6 = (uint)piVar7;
  return 0;
}


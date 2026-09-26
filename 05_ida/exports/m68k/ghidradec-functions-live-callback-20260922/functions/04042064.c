
undefined4
_ipc_right_delta(undefined4 param_1,undefined4 param_2,uint *param_3,undefined4 param_4,int param_5)

{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  uVar6 = *param_3;
  switch(param_4) {
  case :
    iVar7 = 0;
    iVar4 = 0;
    iVar8 = 0;
    if ((uVar6 & 0x10000) == 0) {
      return 0x11;
    }
    uVar3 = uVar6 & 0xffff;
    if ((param_5 < 0) && (uVar3 < (uint)-param_5)) {
      return 0x12;
    }
    if (0 < param_5) {
      uVar1 = uVar3 + 1 + param_5;
      if (uVar1 <= uVar3 + 1) {
        return 0x13;
      }
      if (0xffff < uVar1) {
        return 0x13;
      }
    }
    piVar2 = (int *)param_3[1];
    iVar5 = _ipc_right_check(param_1,piVar2,param_2,param_3);
    if (iVar5 != 0) goto loc_404231C;
    if (param_5 + uVar3 == 0) {
      iVar5 = piVar2[6];
      piVar2[6] = iVar5 + -1;
      if ((iVar5 == 1) && (iVar4 = piVar2[8], iVar4 != 0)) {
        piVar2[8] = 0;
        iVar8 = piVar2[5];
      }
      if ((uVar6 & 0x20000) != 0) {
        uVar6 = uVar6 & 0xfffe0000;
        goto loc_40423BA;
      }
      if (param_3[2] == 0) {
        iVar7 = 0;
      }
      else {
        iVar7 = _ipc_right_dncancel(param_1,piVar2,param_2,param_3);
      }
      _ipc_hash_delete(param_1,piVar2,param_2,param_3);
      if ((uVar6 & 0x200000) != 0) {
        _ipc_marequest_cancel(param_1,param_2);
      }
      *piVar2 = *piVar2 + -1;
      param_3[1] = 0;
      _ipc_entry_dealloc(param_1,param_2,param_3);
    }
    else {
      uVar6 = param_5 + uVar6;
loc_40423BA:
      *param_3 = uVar6;
    }
    if (iVar4 != 0) {
      _ipc_notify_no_senders(iVar4,iVar8);
    }
    if (iVar7 != 0) {
      _ipc_notify_port_deleted(iVar7,param_2);
    }
    break;
  case :
    iVar4 = 0;
    if ((uVar6 & 0x20000) == 0) {
      return 0x11;
    }
    if (param_5 != 0) {
      if (param_5 != -1) {
        return 0x12;
      }
      if ((uVar6 & 0x200000) != 0) {
        uVar6 = uVar6 & 0xffdfffff;
        _ipc_marequest_cancel(param_1,param_2);
      }
      uVar3 = param_3[1];
      if ((uVar6 & 0x400000) == 0) {
        if ((uVar6 & 0x10000) == 0) {
          if (param_3[2] != 0) {
            iVar4 = _ipc_right_dncancel(param_1,uVar3,param_2,param_3);
          }
          param_3[1] = 0;
          _ipc_entry_dealloc(param_1,param_2,param_3);
        }
        else {
          uVar6 = uVar6 & 0xffe0ffff | 0x100000;
          if (param_3[2] != 0) {
            param_3[2] = 0;
            uVar6 = uVar6 + 1;
          }
          *param_3 = uVar6;
          param_3[1] = 0;
        }
      }
      else {
        iVar4 = _ipc_right_dncancel(param_1,uVar3,param_2,param_3);
        param_3[1] = 0;
        _ipc_entry_dealloc(param_1,param_2,param_3);
      }
      _ipc_port_clear_receiver(uVar3);
      _ipc_port_destroy(uVar3);
      if (iVar4 != 0) {
        _ipc_notify_port_deleted(iVar4,param_2);
      }
    }
    break;
  case :
    if ((uVar6 & 0x40000) == 0) {
      return 0x11;
    }
    if (1 < param_5 + 1U) {
      return 0x12;
    }
    uVar3 = param_3[1];
    iVar4 = _ipc_right_check(param_1,uVar3,param_2,param_3);
    if (iVar4 == 0) {
      if (param_5 == 0) {
        return 0;
      }
      if (param_3[2] == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = _ipc_right_dncancel(param_1,uVar3,param_2,param_3);
      }
      param_3[1] = 0;
      _ipc_entry_dealloc(param_1,param_2,param_3);
      _ipc_notify_send_once(uVar3);
      if (iVar4 == 0) {
        return 0;
      }
      _ipc_notify_port_deleted(iVar4,param_2);
      return 0;
    }
loc_404231C:
    if ((uVar6 & 0x400000) == 0) {
      return 0x11;
    }
    return 0xf;
  case :
    if ((uVar6 & 0x80000) == 0) {
      return 0x11;
    }
    if (param_5 == 0) {
      return 0;
    }
    if (param_5 == -1) {
      uVar6 = param_3[1];
      param_3[1] = 0;
      _ipc_entry_dealloc(param_1,param_2,param_3);
      _ipc_pset_destroy(uVar6);
      return 0;
    }
    return 0x12;
  case :
    if ((uVar6 & 0x50000) == 0) {
      if ((uVar6 & 0x100000) == 0) {
        return 0x11;
      }
    }
    else {
      iVar4 = _ipc_right_check(param_1,param_3[1],param_2,param_3);
      if (iVar4 == 0) {
        return 0x11;
      }
      if ((uVar6 & 0x400000) != 0) {
        return 0xf;
      }
      uVar6 = *param_3;
    }
    uVar3 = uVar6 & 0xffff;
    if ((param_5 < 0) && (uVar3 < (uint)-param_5)) {
      return 0x12;
    }
    if ((0 < param_5) && ((param_5 + uVar3 <= uVar3 || (0xffff < param_5 + uVar3)))) {
      return 0x13;
    }
    if (param_5 + uVar3 == 0) {
      _ipc_entry_dealloc(param_1,param_2,param_3);
    }
    else {
      *param_3 = param_5 + uVar6;
    }
    break;
  :
                    /* WARNING: Subroutine does not return */
    _panic(aIpcRightDeltaS);
  }
  return 0;
}



undefined4 _ipc_right_dealloc(undefined4 param_1,undefined4 param_2,uint *param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  uVar5 = *param_3;
  uVar2 = uVar5 & 0x1f0000;
  if (uVar2 == 0x30000) {
    iVar7 = 0;
    uVar4 = 0;
    uVar2 = param_3[1];
    if ((sword)uVar5 == 1) {
      iVar8 = *(int *)(uVar2 + 0x18);
      *(int *)(uVar2 + 0x18) = iVar8 + -1;
      if ((iVar8 == 1) && (iVar7 = *(int *)(uVar2 + 0x20), iVar7 != 0)) {
        *(undefined4 *)(uVar2 + 0x20) = 0;
        uVar4 = *(undefined4 *)(uVar2 + 0x14);
      }
      uVar5 = uVar5 & 0xfffe0000;
    }
    else {
      uVar5 = uVar5 - 1;
    }
    *param_3 = uVar5;
    if (iVar7 != 0) {
      _ipc_notify_no_senders(iVar7,uVar4);
    }
loc_4042054:
    uVar4 = 0;
  }
  else {
    if (uVar2 < 0x30001) {
      if (uVar2 == 0x10000) {
        iVar6 = 0;
        iVar7 = 0;
        iVar8 = 0;
        piVar1 = (int *)param_3[1];
        iVar3 = _ipc_right_check(param_1,piVar1,param_2,param_3);
        if (iVar3 == 0) {
          if ((sword)uVar5 == 1) {
            iVar3 = piVar1[6];
            piVar1[6] = iVar3 + -1;
            if ((iVar3 == 1) && (iVar7 = piVar1[8], iVar7 != 0)) {
              piVar1[8] = 0;
              iVar8 = piVar1[5];
            }
            if (param_3[2] == 0) {
              iVar6 = 0;
            }
            else {
              iVar6 = _ipc_right_dncancel(param_1,piVar1,param_2,param_3);
            }
            _ipc_hash_delete(param_1,piVar1,param_2,param_3);
            if ((uVar5 & 0x200000) != 0) {
              _ipc_marequest_cancel(param_1,param_2);
            }
            *piVar1 = *piVar1 + -1;
            param_3[1] = 0;
            _ipc_entry_dealloc(param_1,param_2,param_3);
          }
          else {
            *param_3 = uVar5 - 1;
          }
          if (iVar7 != 0) {
            _ipc_notify_no_senders(iVar7,iVar8);
          }
          if (iVar6 != 0) {
            _ipc_notify_port_deleted(iVar6,param_2);
          }
        }
        else {
loc_4041F54:
          if ((uVar5 & 0x400000) != 0) {
            return 0xf;
          }
          uVar5 = *param_3;
loc_4041EAE:
          if ((sword)uVar5 == 1) {
            _ipc_entry_dealloc(param_1,param_2,param_3);
          }
          else {
            *param_3 = uVar5 - 1;
          }
        }
        goto loc_4042054;
      }
    }
    else {
      if (uVar2 == 0x40000) {
        uVar2 = param_3[1];
        iVar7 = _ipc_right_check(param_1,uVar2,param_2,param_3);
        if (iVar7 != 0) goto loc_4041F54;
        if (param_3[2] == 0) {
          iVar7 = 0;
        }
        else {
          iVar7 = _ipc_right_dncancel(param_1,uVar2,param_2,param_3);
        }
        param_3[1] = 0;
        _ipc_entry_dealloc(param_1,param_2,param_3);
        _ipc_notify_send_once(uVar2);
        if (iVar7 != 0) {
          _ipc_notify_port_deleted(iVar7,param_2);
        }
        goto loc_4042054;
      }
      if (uVar2 == 0x100000) goto loc_4041EAE;
    }
    uVar4 = 0x11;
  }
  return uVar4;
}


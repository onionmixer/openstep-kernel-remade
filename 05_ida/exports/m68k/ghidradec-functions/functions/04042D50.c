
undefined4
_ipc_right_copyin_header
          (int param_1,undefined4 param_2,uint *param_3,uint *param_4,undefined4 *param_5)

{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  
  uVar1 = *param_3;
  uVar3 = uVar1 & 0x1f0000;
  if (uVar3 != 0x30000) {
    if (0x30000 < uVar3) {
      if (uVar3 == 0x80000) {
        return 0x11;
      }
      if (0x80000 < uVar3) {
        if (uVar3 == 0x100000) {
          return 0x11;
        }
loc_4042E84:
                    /* WARNING: Subroutine does not return */
        _panic(aIpcRightCopyin_2);
      }
      if (uVar3 != 0x40000) goto loc_4042E84;
      uVar3 = param_3[1];
      iVar4 = _ipc_right_check(param_1,uVar3,param_2,param_3);
      if (iVar4 == 0) {
        if (param_3[2] == 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = _ipc_right_dncancel(param_1,uVar3,param_2,param_3);
        }
        param_3[1] = 0;
        _ipc_entry_dealloc(param_1,param_2,param_3);
        iVar5 = _ipc_port_copy_send(*(undefined4 *)(param_1 + 0x3c));
        if (iVar4 != 0) {
          _ipc_notify_port_deleted(iVar4,param_2);
        }
        if ((iVar5 != 0) && (iVar5 != -1)) {
          _ipc_notify_port_deleted_compat(iVar5,param_2);
        }
        *param_4 = uVar3;
        uVar6 = 0x12;
        goto loc_4042E7E;
      }
      goto loc_4042E0E;
    }
    if (uVar3 != 0x10000) {
      if (uVar3 != 0x20000) goto loc_4042E84;
      piVar2 = (int *)param_3[1];
      piVar2[5] = piVar2[5] + 1;
      piVar2[6] = piVar2[6] + 1;
      *piVar2 = *piVar2 + 1;
      *param_4 = (uint)piVar2;
      uVar6 = 0x11;
      goto loc_4042E7E;
    }
  }
  piVar2 = (int *)param_3[1];
  iVar4 = _ipc_right_check(param_1,piVar2,param_2,param_3);
  if (iVar4 == 0) {
    piVar2[6] = piVar2[6] + 1;
    *piVar2 = *piVar2 + 1;
    *param_4 = (uint)piVar2;
    uVar6 = 0x11;
loc_4042E7E:
    *param_5 = uVar6;
    return 0;
  }
loc_4042E0E:
  if ((uVar1 & 0x400000) == 0) {
    return 0x11;
  }
  return 0xf;
}

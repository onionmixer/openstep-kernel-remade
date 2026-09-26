
undefined4
_ipc_right_copyin(undefined4 param_1,undefined4 param_2,uint *param_3,undefined4 param_4,int param_5
                 ,uint *param_6,undefined4 *param_7)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int *piVar5;
  
  uVar4 = *param_3;
  switch(param_4) {
  case :
    uVar3 = 0;
    if ((uVar4 & 0x20000) == 0) {
      return 0x11;
    }
    piVar5 = (int *)param_3[1];
    if ((uVar4 & 0x10000) == 0) {
      if (param_3[2] != 0) {
        uVar3 = _ipc_right_dncancel(param_1,piVar5,param_2,param_3);
      }
      if ((uVar4 & 0x200000) != 0) {
        _ipc_marequest_cancel(param_1,param_2);
      }
      param_3[1] = 0;
    }
    else {
      _ipc_hash_insert(param_1,piVar5,param_2,param_3);
      *piVar5 = *piVar5 + 1;
    }
    *param_3 = uVar4 & 0xfffdffff;
    _ipc_port_clear_receiver(piVar5);
    piVar5[3] = 0;
    piVar5[2] = 0;
loc_40426FC:
    *param_6 = (uint)piVar5;
    *param_7 = uVar3;
    return 0;
  case :
    uVar3 = 0;
    if ((uVar4 & 0x100000) == 0) {
      if ((uVar4 & 0x50000) == 0) {
        return 0x11;
      }
      piVar5 = (int *)param_3[1];
      iVar2 = _ipc_right_check(param_1,piVar5,param_2,param_3);
      if (iVar2 == 0) {
        if ((uVar4 & 0x10000) == 0) {
          return 0x11;
        }
        if ((sword)uVar4 == 1) {
          if ((uVar4 & 0x20000) == 0) {
            if (param_3[2] != 0) {
              uVar3 = _ipc_right_dncancel(param_1,piVar5,param_2,param_3);
            }
            _ipc_hash_delete(param_1,piVar5,param_2,param_3);
            if ((uVar4 & 0x200000) != 0) {
              _ipc_marequest_cancel(param_1,param_2);
            }
            param_3[1] = 0;
          }
          else {
            *piVar5 = *piVar5 + 1;
          }
          uVar4 = uVar4 & 0xfffe0000;
        }
        else {
          piVar5[6] = piVar5[6] + 1;
          *piVar5 = *piVar5 + 1;
          uVar4 = uVar4 - 1;
        }
        *param_3 = uVar4;
        goto loc_40426FC;
      }
loc_4042730:
      if ((uVar4 & 0x400000) != 0) {
        return 0xf;
      }
      uVar4 = *param_3;
    }
    break;
  case :
    if ((uVar4 & 0x100000) == 0) {
      if ((uVar4 & 0x50000) == 0) {
        return 0x11;
      }
      uVar1 = param_3[1];
      iVar2 = _ipc_right_check(param_1,uVar1,param_2,param_3);
      if (iVar2 == 0) {
        if ((uVar4 & 0x40000) != 0) {
          if (param_3[2] == 0) {
            uVar3 = 0;
          }
          else {
            uVar3 = _ipc_right_dncancel(param_1,uVar1,param_2,param_3);
          }
          param_3[1] = 0;
          *param_3 = uVar4 & 0xfffbffff;
          *param_6 = uVar1;
          *param_7 = uVar3;
          return 0;
        }
        return 0x11;
      }
      goto loc_4042730;
    }
    break;
  case :
    if ((uVar4 & 0x100000) == 0) {
      if ((uVar4 & 0x50000) == 0) {
        return 0x11;
      }
      piVar5 = (int *)param_3[1];
      iVar2 = _ipc_right_check(param_1,piVar5,param_2,param_3);
      if (iVar2 == 0) {
        if ((uVar4 & 0x10000) == 0) {
          return 0x11;
        }
        piVar5[6] = piVar5[6] + 1;
        *piVar5 = *piVar5 + 1;
        *param_6 = (uint)piVar5;
        goto loc_4042794;
      }
      if ((uVar4 & 0x400000) != 0) {
        return 0xf;
      }
    }
    if (param_5 == 0) {
      return 0x11;
    }
    goto loc_4042790;
  case :
    if ((uVar4 & 0x20000) == 0) {
      return 0x11;
    }
    piVar5 = (int *)param_3[1];
    piVar5[5] = piVar5[5] + 1;
    piVar5[6] = piVar5[6] + 1;
    goto loc_404259A;
  case :
    if ((uVar4 & 0x20000) == 0) {
      return 0x11;
    }
    piVar5 = (int *)param_3[1];
    piVar5[7] = piVar5[7] + 1;
loc_404259A:
    *piVar5 = *piVar5 + 1;
    *param_6 = (uint)piVar5;
    goto loc_4042794;
  :
                    /* WARNING: Subroutine does not return */
    _panic(aIpcRightCopyin_0);
  }
  if (param_5 == 0) {
    return 0x11;
  }
  if ((sword)uVar4 == 1) {
    uVar4 = uVar4 & 0xffefffff;
  }
  else {
    uVar4 = uVar4 - 1;
  }
  *param_3 = uVar4;
loc_4042790:
  *param_6 = 0xffffffff;
loc_4042794:
  *param_7 = 0;
  return 0;
}


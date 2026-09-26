
undefined4
_ipc_right_copyout(int param_1,int param_2,uint *param_3,uint param_4,int param_5,int *param_6)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = *param_3;
  if (param_4 == 0x11) {
    if ((uVar1 & 0x10000) == 0) {
      if ((uVar1 & 0x20000) == 0) {
        _ipc_hash_insert(param_1,param_6,param_2,param_3);
      }
      else {
        *param_6 = *param_6 + -1;
      }
    }
    else {
      if ((sword)uVar1 == -2) {
        if (param_5 != 0) {
          param_6[6] = param_6[6] + -1;
          *param_6 = *param_6 + -1;
          return 0;
        }
        return 0x13;
      }
      param_6[6] = param_6[6] + -1;
      *param_6 = *param_6 + -1;
    }
    *param_3 = (uVar1 | 0x10000) + 1;
  }
  else if (param_4 < 0x12) {
    if (param_4 != 0x10) {
loc_40429E6:
                    /* WARNING: Subroutine does not return */
      _panic(aIpcRightCopyou);
    }
    iVar2 = param_6[2];
    param_6[3] = param_2;
    param_6[2] = param_1;
    if ((uVar1 & 0x10000) != 0) {
      *param_6 = *param_6 + -1;
      _ipc_hash_delete(param_1,param_6,param_2,param_3);
    }
    *param_3 = uVar1 | 0x20000;
    if (iVar2 != 0) {
      _ipc_object_release(iVar2);
    }
  }
  else {
    if (param_4 != 0x12) goto loc_40429E6;
    *param_3 = uVar1 | 0x40001;
  }
  return 0;
}


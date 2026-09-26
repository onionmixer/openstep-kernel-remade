
undefined4 _ipc_right_copyin_check(undefined4 param_1,undefined4 param_2,uint *param_3,int param_4)

{
  uint uVar1;
  
  uVar1 = *param_3;
  switch(param_4) {
  case :
  case :
  case :
    uVar1 = uVar1 & 0x20000;
    break;
  case :
  case :
  case :
    if ((uVar1 & 0x100000) != 0) {
      return 1;
    }
    if ((uVar1 & 0x50000) == 0) {
      return 0;
    }
    if (-1 < *(int *)(param_3[1] + 4)) {
      if ((uVar1 & 0x400000) != 0) {
        return 0;
      }
      return 1;
    }
    if (param_4 == 0x12) {
      uVar1 = uVar1 & 0x40000;
    }
    else {
      uVar1 = uVar1 & 0x10000;
    }
    break;
  :
                    /* WARNING: Subroutine does not return */
    _panic(aIpcRightCopyin);
  }
  if (uVar1 != 0) {
    return 1;
  }
  return 0;
}

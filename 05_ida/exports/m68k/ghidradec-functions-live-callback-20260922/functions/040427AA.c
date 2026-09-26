
void _ipc_right_copyin_undo
               (undefined4 param_1,undefined4 param_2,uint *param_3,int param_4,int param_5,
               int param_6)

{
  uint uVar1;
  
  uVar1 = *param_3;
  if (param_6 == 0) {
    if ((uVar1 & 0x1f0000) == 0) {
      *param_3 = uVar1 & 0xff800000 | 0x100001;
    }
    else if ((uVar1 & 0x1f0000) == 0x100000) {
      if (param_4 != 0x13) {
        *param_3 = uVar1 + 1;
      }
    }
    else {
      if (param_4 != 0x13) {
        *param_3 = uVar1 + 1;
      }
      _ipc_right_check(param_1,param_5,param_2,param_3);
    }
  }
  else {
    *param_3 = uVar1 & 0xff800000 | 0x100002;
  }
  if (param_5 != -1) {
    _ipc_object_release(param_5);
  }
  return;
}


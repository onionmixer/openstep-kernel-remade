
undefined4 _ipc_right_check(undefined4 param_1,int param_2,undefined4 param_3,uint *param_4)

{
  undefined4 uVar1;
  uint uVar2;
  
  if (*(int *)(param_2 + 4) < 0) {
    uVar1 = 0;
  }
  else {
    uVar2 = *param_4;
    if ((uVar2 & 0x10000) != 0) {
      if ((uVar2 & 0x200000) != 0) {
        uVar2 = uVar2 & 0xffdfffff;
        _ipc_marequest_cancel(param_1,param_3);
      }
      _ipc_hash_delete(param_1,param_2,param_3,param_4);
    }
    _ipc_object_release(param_2);
    if ((uVar2 & 0x400000) == 0) {
      uVar2 = uVar2 & 0xffe0ffff | 0x100000;
      if (param_4[2] != 0) {
        param_4[2] = 0;
        uVar2 = uVar2 + 1;
      }
      *param_4 = uVar2;
      param_4[1] = 0;
    }
    else {
      param_4[2] = 0;
      param_4[1] = 0;
      _ipc_entry_dealloc(param_1,param_3,param_4);
    }
    uVar1 = 1;
  }
  return uVar1;
}


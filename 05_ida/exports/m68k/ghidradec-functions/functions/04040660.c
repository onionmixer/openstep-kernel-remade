
int _ipc_object_copyout_name
              (undefined4 param_1,uint param_2,int param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  undefined auStack_10 [4];
  int iStack_c;
  uint *puStack_8;
  
  iVar1 = _ipc_entry_alloc_name(param_1,param_5,&puStack_8);
  if (iVar1 != 0) {
    return iVar1;
  }
  if ((param_3 == 0x12) ||
     (iVar1 = _ipc_right_reverse(param_1,param_2,&iStack_c,auStack_10), iVar1 == 0)) {
    iVar1 = _ipc_right_inuse(param_1,param_5,puStack_8);
    if (iVar1 != 0) {
      return 0xd;
    }
    if (-1 < *(int *)(param_2 + 4)) {
      _ipc_entry_dealloc(param_1,param_5,puStack_8);
      return 0x14;
    }
    puStack_8[1] = param_2;
  }
  else if (param_5 != iStack_c) {
    if ((*puStack_8 & 0x1f0000) == 0) {
      _ipc_entry_dealloc(param_1,param_5,puStack_8);
    }
    return 0x15;
  }
  iVar1 = _ipc_right_copyout(param_1,param_5,puStack_8,param_3,param_4,param_2);
  return iVar1;
}

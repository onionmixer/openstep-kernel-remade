
int _ipc_object_rename(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uStack_8;
  
  iVar1 = _ipc_entry_alloc_name(param_1,param_3,&uStack_8);
  if (iVar1 == 0) {
    iVar1 = _ipc_right_inuse(param_1,param_3,uStack_8);
    if (iVar1 == 0) {
      if ((param_3 != param_2) && (iVar1 = _ipc_entry_lookup(param_1,param_2), iVar1 != 0)) {
        iVar1 = _ipc_right_rename(param_1,param_2,iVar1,param_3,uStack_8);
        return iVar1;
      }
      _ipc_entry_dealloc(param_1,param_3,uStack_8);
      iVar1 = 0xf;
    }
    else {
      iVar1 = 0xd;
    }
  }
  return iVar1;
}


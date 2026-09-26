
int _ipc_object_alloc_dead_name(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  uint *puStack_8;
  
  iVar1 = _ipc_entry_alloc_name(param_1,param_2,&puStack_8);
  if (iVar1 == 0) {
    iVar1 = _ipc_right_inuse(param_1,param_2,puStack_8);
    if (iVar1 == 0) {
      *puStack_8 = *puStack_8 | 0x100001;
      iVar1 = 0;
    }
    else {
      iVar1 = 0xd;
    }
  }
  return iVar1;
}


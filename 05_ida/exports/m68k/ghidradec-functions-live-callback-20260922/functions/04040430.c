
int _ipc_object_copyin(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iStack_c;
  uint *puStack_8;
  
  iVar1 = _ipc_right_lookup_write(param_1,param_2,&puStack_8);
  if (iVar1 == 0) {
    iVar1 = _ipc_right_copyin(param_1,param_2,puStack_8,param_3,1,param_4,&iStack_c);
    if ((*puStack_8 & 0x1f0000) == 0) {
      _ipc_entry_dealloc(param_1,param_2,puStack_8);
    }
    if ((iVar1 == 0) && (iStack_c != 0)) {
      _ipc_notify_port_deleted(iStack_c,param_2);
    }
  }
  return iVar1;
}



int _ipc_object_copyout_name_compat(uint param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uStack_14;
  undefined auStack_10 [4];
  undefined auStack_c [4];
  int iStack_8;
  
  while( true ) {
    iVar1 = _ipc_entry_alloc_name(param_1,param_4,&iStack_8);
    if (iVar1 != 0) {
      return iVar1;
    }
    iVar1 = _ipc_right_inuse(param_1,param_4,iStack_8);
    if (iVar1 != 0) {
      return 0xd;
    }
    if ((param_3 != 0x12) &&
       (iVar1 = _ipc_right_reverse(param_1,param_2,auStack_c,auStack_10), iVar1 != 0)) {
      _ipc_entry_dealloc(param_1,param_4,iStack_8);
      return 0x15;
    }
    if (-1 < *(int *)(param_2 + 4)) {
      _ipc_entry_dealloc(param_1,param_4,iStack_8);
      return 0x14;
    }
    iVar1 = _ipc_port_dnrequest(param_2,param_4,param_1 | 1,&uStack_14);
    if (iVar1 == 0) break;
    _ipc_entry_dealloc(param_1,param_4,iStack_8);
    iVar1 = _ipc_port_dngrow(param_2);
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  _ipc_space_reference(param_1);
  *(int *)(iStack_8 + 4) = param_2;
  *(undefined4 *)(iStack_8 + 8) = uStack_14;
  *(byte *)(iStack_8 + 1) = *(byte *)(iStack_8 + 1) | 0x40;
  iVar1 = _ipc_right_copyout(param_1,param_4,iStack_8,param_3,1,param_2);
  return iVar1;
}


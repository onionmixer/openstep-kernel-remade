
int _ipc_object_copyout_compat(uint param_1,int param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uStack_10;
  int iStack_c;
  undefined4 uStack_8;
  
  do {
    if (*(int *)(param_1 + 4) == 0) {
      return 0x10;
    }
    if ((param_3 != 0x12) &&
       (iVar1 = _ipc_right_reverse(param_1,param_2,&uStack_8,&iStack_c), iVar1 != 0)) {
loc_4040A06:
      iVar1 = _ipc_right_copyout(param_1,uStack_8,iStack_c,param_3,1,param_2);
      if (iVar1 != 0) {
        return iVar1;
      }
      *param_4 = uStack_8;
      return 0;
    }
    iVar1 = _ipc_entry_get(param_1,&uStack_8,&iStack_c);
    if (iVar1 == 0) {
      if (-1 < *(int *)(param_2 + 4)) {
        _ipc_entry_dealloc(param_1,uStack_8,iStack_c);
        return 0x14;
      }
      iVar1 = _ipc_port_dnrequest(param_2,uStack_8,param_1 | 1,&uStack_10);
      if (iVar1 == 0) {
        _ipc_space_reference(param_1);
        *(int *)(iStack_c + 4) = param_2;
        *(undefined4 *)(iStack_c + 8) = uStack_10;
        *(byte *)(iStack_c + 1) = *(byte *)(iStack_c + 1) | 0x40;
        goto loc_4040A06;
      }
      _ipc_entry_dealloc(param_1,uStack_8,iStack_c);
      iVar1 = _ipc_port_dngrow(param_2);
    }
    else {
      iVar1 = _ipc_entry_grow_table(param_1);
    }
    if (iVar1 != 0) {
      return iVar1;
    }
  } while( true );
}


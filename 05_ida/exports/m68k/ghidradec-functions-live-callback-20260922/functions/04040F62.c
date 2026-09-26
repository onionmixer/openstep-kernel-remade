
void _ipc_port_delete_compat(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iStack_8;
  
  iVar1 = _ipc_right_lookup_write(param_2,param_3,&iStack_8);
  if (iVar1 == 0) {
    if (*(int *)(iStack_8 + 4) == param_1) {
      iVar1 = _ipc_port_copy_send(*(undefined4 *)(param_2 + 0x3c));
      _ipc_right_destroy(param_2,param_3,iStack_8);
    }
    else {
      iVar1 = 0;
    }
    if ((iVar1 != 0) && (iVar1 != -1)) {
      _ipc_notify_port_deleted_compat(iVar1,param_3);
    }
  }
  _ipc_space_release(param_2);
  return;
}



int _port_set_deallocate(int param_1,undefined4 param_2)

{
  int iVar1;
  int iStack_8;
  
  if (param_1 != 0) {
    iVar1 = _ipc_right_lookup_write(param_1,param_2,&iStack_8);
    if (iVar1 != 0) {
      return iVar1;
    }
    if ((*(byte *)(iStack_8 + 1) & 8) != 0) {
      iVar1 = _ipc_right_destroy(param_1,param_2,iStack_8);
      return iVar1;
    }
  }
  return 4;
}


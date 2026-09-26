
undefined4 _port_deallocate(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined auStack_10 [4];
  uint uStack_c;
  undefined4 uStack_8;
  
  if ((((param_1 != 0) && (iVar1 = _ipc_right_lookup_write(param_1,param_2,&uStack_8), iVar1 == 0))
      && (iVar1 = _ipc_right_info(param_1,param_2,uStack_8,&uStack_c,auStack_10), iVar1 == 0)) &&
     ((uStack_c & 0x170000) != 0)) {
    _ipc_right_destroy(param_1,param_2,uStack_8);
    return 0;
  }
  return 4;
}


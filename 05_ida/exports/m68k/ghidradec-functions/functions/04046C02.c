
undefined4 _port_translate_compat(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined auStack_10 [4];
  uint uStack_c;
  int iStack_8;
  
  iVar1 = _ipc_right_lookup_write(param_1,param_2,&iStack_8);
  if ((iVar1 != 0) ||
     (iVar1 = _ipc_right_info(param_1,param_2,iStack_8,&uStack_c,auStack_10), iVar1 != 0)) {
    return 4;
  }
  if ((uStack_c & 0x20000) != 0) {
    *param_3 = *(undefined4 *)(iStack_8 + 4);
    return 0;
  }
  if ((uStack_c & 0x170000) == 0) {
    return 4;
  }
  return 7;
}

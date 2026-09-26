
undefined4 _port_set_remove(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined auStack_10 [4];
  uint uStack_c;
  int iStack_8;
  
  if (((param_1 == 0) || (iVar1 = _ipc_right_lookup_write(param_1,param_2,&iStack_8), iVar1 != 0))
     || (iVar1 = _ipc_right_info(param_1,param_2,iStack_8,&uStack_c,auStack_10), iVar1 != 0)) {
    return 4;
  }
  if ((uStack_c & 0x20000) != 0) {
    uVar2 = _ipc_pset_move(param_1,*(undefined4 *)(iStack_8 + 4),0);
    return uVar2;
  }
  if ((uStack_c & 0x170000) == 0) {
    return 4;
  }
  return 7;
}


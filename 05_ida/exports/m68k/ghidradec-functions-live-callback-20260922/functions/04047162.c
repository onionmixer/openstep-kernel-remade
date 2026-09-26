
undefined4 _port_set_add(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined auStack_10 [4];
  uint uStack_c;
  int iStack_8;
  
  if (((param_1 != 0) && (iVar1 = _ipc_right_lookup_write(param_1,param_3,&iStack_8), iVar1 == 0))
     && (iVar1 = _ipc_right_info(param_1,param_3,iStack_8,&uStack_c,auStack_10), iVar1 == 0)) {
    if ((uStack_c & 0x20000) == 0) {
      if ((uStack_c & 0x170000) == 0) {
        return 4;
      }
      return 7;
    }
    uVar2 = *(undefined4 *)(iStack_8 + 4);
    iStack_8 = _ipc_entry_lookup(param_1,param_2);
    if ((iStack_8 != 0) && ((*(byte *)(iStack_8 + 1) & 8) != 0)) {
      uVar2 = _ipc_pset_move(param_1,uVar2,*(undefined4 *)(iStack_8 + 4));
      return uVar2;
    }
  }
  return 4;
}


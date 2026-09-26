
int _ipc_splay_traverse_next(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uStack_18;
  undefined auStack_14 [4];
  undefined4 uStack_10;
  undefined auStack_c [4];
  int iStack_8;
  
  iVar4 = *(int *)(param_1 + 8);
  iVar1 = *(int *)(param_1 + 0x10);
  iStack_8 = iVar4;
  iVar3 = iVar1;
  if (param_2 == 0) {
loc_40438D8:
    iVar4 = *(int *)(iStack_8 + 0x1c);
    if (iVar4 != 0) {
      *(int *)(iStack_8 + 0x1c) = iVar1;
      iVar3 = iStack_8;
      iStack_8 = iVar4;
loc_40438B6:
      while (iVar4 = *(int *)(iStack_8 + 0x18), iVar4 != 0) {
        *(int *)(iStack_8 + 0x18) = iVar3;
        iVar3 = iStack_8;
        iStack_8 = iVar4;
      }
      goto loc_40438C6;
    }
  }
  else {
    iVar2 = *(int *)(iVar4 + 0x18);
    if (iVar2 == 0) {
      iStack_8 = *(int *)(iVar4 + 0x1c);
      if (iStack_8 != 0) {
        _zfree(_ipc_tree_entry_zone,iVar4);
        goto loc_40438B6;
      }
      if (iVar1 == 0) {
        iStack_8 = iVar4;
        _zfree(_ipc_tree_entry_zone,iVar4);
        *(undefined4 *)(param_1 + 4) = 0;
        return 0;
      }
      if (*(uint *)(iVar4 + 0x10) < *(uint *)(iVar1 + 0x10)) {
        iStack_8 = iVar4;
        _zfree(_ipc_tree_entry_zone,iVar4);
        iVar3 = *(int *)(iVar1 + 0x18);
        *(undefined4 *)(iVar1 + 0x18) = 0;
        iStack_8 = iVar1;
        goto loc_40438C6;
      }
      iStack_8 = iVar4;
      _zfree(_ipc_tree_entry_zone,iVar4);
      iVar3 = *(int *)(iVar1 + 0x1c);
      *(undefined4 *)(iVar1 + 0x1c) = 0;
      iStack_8 = iVar1;
    }
    else {
      if (*(int *)(iVar4 + 0x1c) != 0) {
        sub_404310C(0xffffffff,iVar2,&iStack_8,auStack_c,&uStack_10,auStack_14,&uStack_18);
        sub_40431D2(iStack_8,auStack_c,uStack_10,auStack_14,uStack_18);
        *(undefined4 *)(iStack_8 + 0x1c) = *(undefined4 *)(iVar4 + 0x1c);
        _zfree(_ipc_tree_entry_zone,iVar4);
        goto loc_40438D8;
      }
      iStack_8 = iVar2;
      _zfree(_ipc_tree_entry_zone,iVar4);
    }
  }
  while( true ) {
    iVar4 = iVar3;
    if (iVar4 == 0) {
      *(int *)(param_1 + 4) = iStack_8;
      return 0;
    }
    if (*(uint *)(iStack_8 + 0x10) < *(uint *)(iVar4 + 0x10)) break;
    iVar3 = *(int *)(iVar4 + 0x1c);
    *(int *)(iVar4 + 0x1c) = iStack_8;
    iStack_8 = iVar4;
  }
  iVar3 = *(int *)(iVar4 + 0x18);
  *(int *)(iVar4 + 0x18) = iStack_8;
  iStack_8 = iVar4;
loc_40438C6:
  *(int *)(param_1 + 8) = iStack_8;
  *(int *)(param_1 + 0x10) = iVar3;
  return iStack_8;
}


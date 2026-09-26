
int _mach_port_move_member(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iStack_8;
  
  if (param_1 == 0) {
    return 0x10;
  }
  iVar2 = _ipc_right_lookup_write(param_1,param_2,&iStack_8);
  if (iVar2 != 0) {
    return iVar2;
  }
  if ((*(byte *)(iStack_8 + 1) & 2) == 0) {
loc_4046950:
    iVar2 = 0x11;
  }
  else {
    uVar1 = *(undefined4 *)(iStack_8 + 4);
    if (param_3 == 0) {
      uVar3 = 0;
    }
    else {
      iStack_8 = _ipc_entry_lookup(param_1,param_3);
      if (iStack_8 == 0) {
        return 0xf;
      }
      if ((*(byte *)(iStack_8 + 1) & 8) == 0) goto loc_4046950;
      uVar3 = *(undefined4 *)(iStack_8 + 4);
    }
    iVar2 = _ipc_pset_move(param_1,uVar1,uVar3);
  }
  return iVar2;
}


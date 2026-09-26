
undefined4 _ipc_right_lookup_write(int param_1,undefined4 param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 4) == 0) {
    uVar1 = 0x10;
  }
  else {
    iVar2 = _ipc_entry_lookup(param_1,param_2);
    if (iVar2 == 0) {
      uVar1 = 0xf;
    }
    else {
      *param_3 = iVar2;
      uVar1 = 0;
    }
  }
  return uVar1;
}

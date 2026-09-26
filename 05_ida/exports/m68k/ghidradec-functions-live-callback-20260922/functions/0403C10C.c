
int _ipc_entry_alloc(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  while( true ) {
    if (*(int *)(param_1 + 4) == 0) {
      return 0x10;
    }
    iVar1 = _ipc_entry_get(param_1,param_2,param_3);
    if (iVar1 == 0) break;
    iVar1 = _ipc_entry_grow_table(param_1);
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  return 0;
}


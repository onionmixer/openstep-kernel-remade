
undefined4 _ipc_hash_lookup(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = _ipc_hash_local_lookup(param_1,param_2,param_3,param_4);
  if (iVar1 == 0) {
    if (*(int *)(param_1 + 0x38) == 0) {
      return 0;
    }
    iVar1 = _ipc_hash_global_lookup(param_1,param_2,param_3,param_4);
    if (iVar1 == 0) {
      return 0;
    }
  }
  return 1;
}


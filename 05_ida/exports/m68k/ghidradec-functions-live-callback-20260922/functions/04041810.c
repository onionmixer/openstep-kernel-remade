
undefined4 _ipc_right_reverse(int param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (*(int *)(param_2 + 4) < 0) {
    if (param_1 == *(int *)(param_2 + 8)) {
      uVar1 = *(undefined4 *)(param_2 + 0xc);
      uVar2 = _ipc_entry_lookup(param_1,uVar1);
      *param_3 = uVar1;
      *param_4 = uVar2;
      return 1;
    }
    iVar3 = _ipc_hash_lookup(param_1,param_2,param_3,param_4);
    if (iVar3 != 0) {
      return 1;
    }
  }
  return 0;
}


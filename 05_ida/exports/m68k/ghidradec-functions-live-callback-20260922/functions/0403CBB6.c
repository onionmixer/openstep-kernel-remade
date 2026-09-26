
uint _ipc_hash_info(int *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  
  if (_ipc_hash_global_size < param_2) {
    param_2 = _ipc_hash_global_size;
  }
  uVar3 = 0;
  piVar4 = _ipc_hash_global_table;
  if (param_2 != 0) {
    do {
      iVar2 = 0;
      for (iVar1 = *piVar4; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xc)) {
        iVar2 = iVar2 + 1;
      }
      *param_1 = iVar2;
      uVar3 = uVar3 + 1;
      param_1 = param_1 + 1;
      piVar4 = piVar4 + 1;
    } while (uVar3 < param_2);
  }
  return _ipc_hash_global_size;
}


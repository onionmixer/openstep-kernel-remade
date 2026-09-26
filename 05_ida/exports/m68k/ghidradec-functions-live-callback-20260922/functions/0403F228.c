
uint _ipc_marequest_info(undefined4 *param_1,int *param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  
  if (_ipc_marequest_size < param_3) {
    param_3 = _ipc_marequest_size;
  }
  uVar3 = 0;
  piVar4 = _ipc_marequest_table;
  if (param_3 != 0) {
    do {
      iVar2 = 0;
      for (iVar1 = *piVar4; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xc)) {
        iVar2 = iVar2 + 1;
      }
      *param_2 = iVar2;
      uVar3 = uVar3 + 1;
      param_2 = param_2 + 1;
      piVar4 = piVar4 + 1;
    } while (uVar3 < param_3);
  }
  *param_1 = _ipc_marequest_max;
  return _ipc_marequest_size;
}


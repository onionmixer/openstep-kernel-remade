
void _ipc_hash_global_insert(uint param_1,uint param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  
  *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + 1;
  piVar1 = (int *)(_ipc_hash_global_table +
                  (_ipc_hash_global_mask & (param_2 >> 6) + (param_1 >> 4)) * 4);
  *(int *)(param_4 + 0xc) = *piVar1;
  *piVar1 = param_4;
  return;
}


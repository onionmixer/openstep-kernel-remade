
void _ipc_hash_global_delete(uint param_1,uint param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  
  *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + -1;
  piVar2 = (int *)(_ipc_hash_global_table +
                  (_ipc_hash_global_mask & (param_2 >> 6) + (param_1 >> 4)) * 4);
  while( true ) {
    iVar1 = *piVar2;
    if (iVar1 == 0) {
      return;
    }
    if (param_4 == iVar1) break;
    piVar2 = (int *)(iVar1 + 0xc);
  }
  *piVar2 = *(int *)(iVar1 + 0xc);
  return;
}

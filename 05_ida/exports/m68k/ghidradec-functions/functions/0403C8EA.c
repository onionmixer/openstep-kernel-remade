
int _ipc_hash_global_lookup(uint param_1,uint param_2,undefined4 *param_3,int *param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  piVar1 = (int *)(_ipc_hash_global_table +
                  (_ipc_hash_global_mask & (param_2 >> 6) + (param_1 >> 4)) * 4);
  iVar3 = *piVar1;
  if (iVar3 != 0) {
    if ((param_2 != *(uint *)(iVar3 + 4)) || (param_1 != *(uint *)(iVar3 + 0x14))) {
      do {
        piVar2 = (int *)(iVar3 + 0xc);
        iVar3 = *piVar2;
        if (iVar3 == 0) goto loc_403C958;
      } while ((param_2 != *(uint *)(iVar3 + 4)) || (param_1 != *(uint *)(iVar3 + 0x14)));
      *piVar2 = *(int *)(iVar3 + 0xc);
      *(int *)(iVar3 + 0xc) = *piVar1;
      *piVar1 = iVar3;
    }
    *param_3 = *(undefined4 *)(iVar3 + 0x10);
    *param_4 = iVar3;
  }
loc_403C958:
  return -(int)-(iVar3 != 0);
}

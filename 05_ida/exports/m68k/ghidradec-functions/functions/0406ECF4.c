
undefined4 sub_406ECF4(int param_1,int param_2)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x168) == *(int *)(param_2 + 0x168)) &&
     ((*(uint *)(param_2 + 0x176) & 3) == (*(uint *)(param_1 + 0x176) & 3))) {
    if ((*(uint *)(param_1 + 0x176) & 2) != 0) {
      if (*(int *)(*(int *)(param_1 + 0x14) + 0x28) != *(int *)(*(int *)(param_2 + 0x14) + 0x28)) {
        return 1;
      }
      iVar1 = _strncmp(*(int *)(param_1 + 0x14) + 0xc,*(int *)(param_2 + 0x14) + 0xc,0x18);
      if (iVar1 != 0) {
        return 1;
      }
    }
    if (((*(byte *)(param_1 + 0x179) & 1) == 0) ||
       ((*(int *)(param_1 + 0x186) == *(int *)(param_2 + 0x186) &&
        (*(int *)(param_1 + 0x17a) == *(int *)(param_2 + 0x17a))))) {
      return 0;
    }
  }
  return 1;
}

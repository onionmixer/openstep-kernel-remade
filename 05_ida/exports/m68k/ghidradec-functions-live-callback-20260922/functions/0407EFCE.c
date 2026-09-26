
undefined4 sub_407EFCE(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  if (((**(int **)(param_1 + 0xca) != **(int **)(param_2 + 0xca)) ||
      ((*(int **)(param_1 + 0xca))[1] != (*(int **)(param_2 + 0xca))[1])) ||
     (uVar1 = *(uint *)(param_1 + 8) & 4, (*(uint *)(param_2 + 8) & 4) != uVar1)) {
    return 1;
  }
  if (uVar1 != 0) {
    if (*(int *)(*(int *)(param_1 + 0xd2) + 0x28) != *(int *)(*(int *)(param_2 + 0xd2) + 0x28)) {
      return 1;
    }
    iVar2 = _strncmp(*(int *)(param_1 + 0xd2) + 0xc,*(int *)(param_2 + 0xd2) + 0xc,0x18);
    if (iVar2 != 0) {
      return 1;
    }
  }
  return 0;
}


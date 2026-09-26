
void _pn_skipslash(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 8) != 0) {
    do {
      if (**(char **)(param_1 + 4) != '/') {
        return;
      }
      *(char **)(param_1 + 4) = *(char **)(param_1 + 4) + 1;
      iVar1 = *(int *)(param_1 + 8);
      *(int *)(param_1 + 8) = iVar1 + -1;
    } while (iVar1 != 1);
  }
  return;
}


/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ccd18 */

int FUN_001ccd18(int param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  do {
    if (*(int *)(param_1 + 0x18) != 0) {
      iVar2 = *(int *)(param_1 + 0x18) + 4;
      for (iVar3 = 0; iVar3 < **(int **)(param_1 + 0x18); iVar3 = iVar3 + 1) {
        iVar1 = _strcmp(param_2,*(char **)(iVar2 + iVar3 * 0xc));
        if (iVar1 == 0) {
          return iVar2 + iVar3 * 0xc;
        }
      }
    }
    param_1 = *(int *)(param_1 + 4);
  } while (param_1 != 0);
  return 0;
}


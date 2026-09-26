/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ca754 */

undefined4 FUN_001ca754(int param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_3 != 0) {
    iVar2 = _strcmp(*(char **)(param_3 + 4),*(char **)(param_1 + 4));
    if (iVar2 == 0) {
      return 1;
    }
    if (*(int *)(param_1 + 8) != 0) {
      iVar4 = 0;
      iVar2 = *(int *)(param_1 + 8);
      if (0 < *(int *)(iVar2 + 4)) {
        do {
          iVar2 = *(int *)(iVar2 + 8 + iVar4 * 4);
          iVar3 = _strcmp(*(char **)(param_3 + 4),*(char **)(iVar2 + 4));
          if (iVar3 == 0) {
            return 1;
          }
          cVar1 = _objc_msgSend(iVar2,PTR_s_conformsTo__001f9238,param_3);
          if (cVar1 != '\0') {
            return 1;
          }
          iVar4 = iVar4 + 1;
          iVar2 = *(int *)(param_1 + 8);
        } while (iVar4 < *(int *)(iVar2 + 4));
      }
    }
  }
  return 0;
}


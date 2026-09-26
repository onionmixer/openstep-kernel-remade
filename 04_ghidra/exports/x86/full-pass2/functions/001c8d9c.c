/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c8d9c */

int FUN_001c8d9c(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(param_1 + 0x14);
  iVar2 = *(int *)(param_1 + 0x10);
  while (iVar2 = iVar2 + -1, iVar2 != -1) {
    if (*piVar1 != 0) {
      _free((void *)piVar1[1]);
    }
    *piVar1 = 0;
    piVar1[1] = 0;
    piVar1 = piVar1 + 2;
  }
  *(undefined4 *)(param_1 + 4) = 0;
  return param_1;
}


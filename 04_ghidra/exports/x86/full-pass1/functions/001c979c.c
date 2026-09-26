/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c979c */

int FUN_001c979c(int param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 4);
  piVar1 = piVar2 + *(int *)(param_1 + 8);
  while( true ) {
    if (piVar1 <= piVar2) {
      return -1;
    }
    if (*piVar2 == param_3) break;
    piVar2 = piVar2 + 1;
  }
  return (int)piVar2 - *(int *)(param_1 + 4) >> 2;
}


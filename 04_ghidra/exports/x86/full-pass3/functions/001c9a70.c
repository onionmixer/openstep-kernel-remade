/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c9a70 */

int FUN_001c9a70(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int *piVar1;
  int *piVar2;
  
  if (param_4 != 0) {
    piVar2 = *(int **)(param_1 + 4);
    piVar1 = piVar2 + *(int *)(param_1 + 8);
    for (; piVar2 < piVar1; piVar2 = piVar2 + 1) {
      if (*piVar2 == param_3) {
        *piVar2 = param_4;
        return param_3;
      }
    }
  }
  return 0;
}


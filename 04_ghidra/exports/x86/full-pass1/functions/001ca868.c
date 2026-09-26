/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ca868 */

int * FUN_001ca868(int *param_1,int param_2)

{
  int iVar1;
  
  if ((param_1 != (int *)0x0) && (iVar1 = 0, 0 < *param_1)) {
    do {
      if (param_1[iVar1 * 2 + 1] == param_2) {
        return param_1 + iVar1 * 2 + 1;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < *param_1);
  }
  return (int *)0x0;
}


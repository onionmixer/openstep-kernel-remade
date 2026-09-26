/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011cb58 */

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


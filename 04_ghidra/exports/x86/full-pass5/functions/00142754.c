/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00142754 */

void FUN_00142754(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 != 0) {
    iVar1 = *(int *)(param_1 + 0x18);
    if (iVar1 == 0) {
      *(int *)(param_1 + 0x18) = param_2;
      return;
    }
    for (; *(int *)(iVar1 + 0x18) != 0; iVar1 = *(int *)(iVar1 + 0x18)) {
    }
    *(int *)(iVar1 + 0x18) = param_2;
  }
  return;
}


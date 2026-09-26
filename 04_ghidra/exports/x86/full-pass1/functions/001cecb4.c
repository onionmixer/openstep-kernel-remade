/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cecb4 */

undefined4 FUN_001cecb4(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (**(char **)(param_3 + 8) == **(char **)(param_2 + 8)) {
    iVar1 = _strcmp(*(char **)(param_2 + 8),*(char **)(param_3 + 8));
    if (iVar1 == 0) {
      uVar2 = 1;
    }
  }
  return uVar2;
}


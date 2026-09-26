/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c9dc4 */

undefined4 FUN_001c9dc4(int *param_1,undefined4 param_2,char *param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    iVar2 = _strcmp(param_3,*(char **)(iVar1 + 8));
    if (iVar2 == 0) break;
    iVar1 = *(int *)(iVar1 + 4);
  }
  return 1;
}


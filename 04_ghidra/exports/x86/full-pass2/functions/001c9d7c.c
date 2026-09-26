/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c9d7c */

undefined4 FUN_001c9d7c(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = *param_1;
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    if (iVar1 == param_3) break;
    iVar1 = *(int *)(iVar1 + 4);
  }
  return 1;
}


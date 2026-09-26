/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00142780 */

undefined4 FUN_00142780(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = &param_1;
  while( true ) {
    if (param_1 == 0) {
      return 0;
    }
    iVar2 = *piVar1;
    if (iVar2 == param_2) break;
    piVar1 = (int *)(iVar2 + 0x18);
    param_1 = *(int *)(iVar2 + 0x18);
  }
  *piVar1 = *(int *)(iVar2 + 0x18);
  return 1;
}


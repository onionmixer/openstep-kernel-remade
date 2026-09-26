/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cbab8 */

undefined4 _NXNextHashState(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = *(int *)(param_1 + 0xc);
  iVar1 = param_2[1];
  while( true ) {
    if (iVar1 != 0) {
      param_2[1] = param_2[1] + -1;
      piVar3 = (int *)(iVar2 + *param_2 * 8);
      if (*piVar3 == 1) {
        iVar2 = piVar3[1];
      }
      else {
        iVar2 = *(int *)(piVar3[1] + param_2[1] * 4);
      }
      *param_3 = iVar2;
      return 1;
    }
    if (*param_2 == 0) break;
    *param_2 = *param_2 + -1;
    iVar1 = *(int *)(iVar2 + *param_2 * 8);
    param_2[1] = iVar1;
  }
  return 0;
}

